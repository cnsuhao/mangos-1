/* 
 * Copyright (C) 2005,2006,2007 MaNGOS <http://www.mangosproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_GRIDNOTIFIERSIMPL_H
#define MANGOS_GRIDNOTIFIERSIMPL_H

#include "GridNotifiers.h"
#include "WorldPacket.h"
#include "Corpse.h"
#include "Player.h"
#include "UpdateData.h"
#include "CreatureAI.h"
#include "SpellAuras.h"

template<class T>
inline void
MaNGOS::VisibleNotifier::Visit(GridRefManager<T> &m)
{
    for(typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        i_player.UpdateVisibilityOf(iter->getSource(),i_data,i_data_updates);
        i_clientGUIDs.erase(iter->getSource()->GetGUID());
    }
}

inline void
MaNGOS::ObjectUpdater::Visit(CreatureMapType &m)
{
    for(CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
        if(!iter->getSource()->isSpiritService())
            iter->getSource()->Update(i_timeDiff);
}

inline void
MaNGOS::PlayerRelocationNotifier::Visit(PlayerMapType &m)
{
    for(PlayerMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        if(&i_player==iter->getSource())
            continue;

        // visibility for players updated by ObjectAccessor::UpdateVisibilityFor calls in appropriate places

        // Cancel Trade
        if(i_player.GetTrader()==iter->getSource())
                                                            // iteraction distance
            if(!i_player.IsWithinDistInMap(iter->getSource(), 5))
                i_player.GetSession()->SendCancelTrade();   // will clode both side trade windows
    }
}

inline void PlayerCreatureRelocationWorker(Player* pl, Creature* c)
{
    // update creature visibility at player/creature move
    pl->UpdateVisibilityOf(c);

    // Creature AI reaction
    if(!c->hasUnitState(UNIT_STAT_CHASE | UNIT_STAT_SEARCHING | UNIT_STAT_FLEEING))
    {
        if( c->AI() && c->AI()->IsVisible(pl) && !c->IsInEvadeMode() )
            c->AI()->MoveInLineOfSight(pl);
    }
}

inline void CreatureCreatureRelocationWorker(Creature* c1, Creature* c2)
{
    if(!c1->hasUnitState(UNIT_STAT_CHASE | UNIT_STAT_SEARCHING | UNIT_STAT_FLEEING))
    {
        if( c1->AI() && c1->AI()->IsVisible(c2) && !c1->IsInEvadeMode() )
            c1->AI()->MoveInLineOfSight(c2);
    }

    if(!c2->hasUnitState(UNIT_STAT_CHASE | UNIT_STAT_SEARCHING | UNIT_STAT_FLEEING))
    {
        if( c2->AI() && c2->AI()->IsVisible(c1) && !c2->IsInEvadeMode() )
            c2->AI()->MoveInLineOfSight(c1);
    }
}

inline void
MaNGOS::PlayerRelocationNotifier::Visit(CreatureMapType &m)
{
    if(!i_player.isAlive() || i_player.isInFlight())
        return;

    for(CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
        if( iter->getSource()->isAlive())
            PlayerCreatureRelocationWorker(&i_player,iter->getSource());
}

template<>
inline void
MaNGOS::CreatureRelocationNotifier::Visit(PlayerMapType &m)
{
    if(!i_creature.isAlive())
        return;

    for(PlayerMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
        if( iter->getSource()->isAlive() && !iter->getSource()->isInFlight())
            PlayerCreatureRelocationWorker(iter->getSource(), &i_creature);
}

template<>
inline void
MaNGOS::CreatureRelocationNotifier::Visit(CreatureMapType &m)
{
    if(!i_creature.isAlive())
        return;

    for(CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
        if( iter->getSource()->isAlive())
            CreatureCreatureRelocationWorker(iter->getSource(), &i_creature);
}

inline void MaNGOS::DynamicObjectUpdater::VisitHelper(Unit* target)
{
    if(!target->isAlive() || target->isInFlight() )
        return;

    if(target->GetTypeId()==TYPEID_UNIT && ((Creature*)target)->isTotem())
        return;

    if (!i_dynobject.IsWithinDistInMap(target, i_dynobject.GetRadius()))
        return;

    //Check targets for not_selectable unit flag and remove
    if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
        return;

    // Evade target
    if( target->GetTypeId()==TYPEID_UNIT && ((Creature*)target)->IsInEvadeMode() )
        return;

    //Check player targets and remove if in GM mode or GM invisibility (for not self casting case)
    if( target->GetTypeId()==TYPEID_PLAYER && target != i_check && (((Player*)target)->isGameMaster() || ((Player*)target)->GetVisibility()==VISIBILITY_OFF) )
        return;

    if( i_check->GetTypeId()==TYPEID_PLAYER )
    {
        if (i_check->IsFriendlyTo( target ))
            return;
    }
    else
    {
        if (!i_check->IsHostileTo( target ))
            return;
    }

    if (i_dynobject.IsAffecting(target))
        return;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(i_dynobject.GetSpellId());
    PersistentAreaAura* Aur = new PersistentAreaAura(spellInfo, i_dynobject.GetEffIndex(), NULL, target, i_dynobject.GetCaster());
    target->AddAura(Aur);
    i_dynobject.AddAffected(target);
}

template<>
inline void
MaNGOS::DynamicObjectUpdater::Visit(CreatureMapType  &m)
{
    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        VisitHelper(itr->getSource());
}

template<>
inline void
MaNGOS::DynamicObjectUpdater::Visit(PlayerMapType  &m)
{
    for(PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        VisitHelper(itr->getSource());
}

// SEARCHERS & LIST SEARCHERS & WORKERS

// WorldObject searchers & workers

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if(i_object) return;

    for(GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if(i_object) return;

    for(PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object) return;

    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(CorpseMapType &m)
{
    // already found
    if(i_object) return;

    for(CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    // already found
    if(i_object) return;

    for(DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(PlayerMapType &m)
{
    for(PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(CreatureMapType &m)
{
    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(CorpseMapType &m)
{
    for(CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for(GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    for(DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

// Gameobject searchers

template<class Check>
void MaNGOS::GameObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if(i_object) return;

    for(GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::GameObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for(GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

// Unit searchers

template<class Check>
void MaNGOS::UnitSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object) return;

    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::UnitSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if(i_object) return;

    for(PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::UnitListSearcher<Check>::Visit(PlayerMapType &m)
{
    for(PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

template<class Check>
void MaNGOS::UnitListSearcher<Check>::Visit(CreatureMapType &m)
{
    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}

// Creature searchers

template<class Check>
void MaNGOS::CreatureSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object) return;

    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::CreatureListSearcher<Check>::Visit(CreatureMapType &m)
{
    for(CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(i_check(itr->getSource()))
            i_objects.push_back(itr->getSource());
}
#endif                                                      // MANGOS_GRIDNOTIFIERSIMPL_H
