/* 
 * Copyright (C) 2005,2006 MaNGOS <http://www.mangosproject.org/>
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

#ifndef __UNIT_H
#define __UNIT_H

#include "Common.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "Opcodes.h"
#include "Mthread.h"
#include "SpellAuraDefines.h"

#include <list>

#define CREATURE_MAX_SPELLS     4
#define PLAYER_MAX_SKILLS       127
#define PLAYER_SKILL(x)         (PLAYER_SKILL_INFO_START + (x*3))
// DWORD definitions gathered from windows api
#define SKILL_VALUE(x)          uint16(x)
#define SKILL_MAX(x)            uint16((uint32(x) >> 16))
#define MAKE_SKILL_VALUE(v, m) ((uint32)(((uint16)(v)) | (((uint32)((uint16)(m))) << 16)))

#define NOSWING                     0
#define SINGLEHANDEDSWING           1
#define TWOHANDEDSWING              2

#define VICTIMSTATE_UNKNOWN1        0
#define VICTIMSTATE_NORMAL          1
#define VICTIMSTATE_DODGE           2
#define VICTIMSTATE_PARRY           3
#define VICTIMSTATE_UNKNOWN2        4
#define VICTIMSTATE_BLOCKS          5
#define VICTIMSTATE_EVADES          6
#define VICTIMSTATE_IS_IMMUNE       7
#define VICTIMSTATE_DEFLECTS        8

#define HITINFO_NORMALSWING         0x00
#define HITINFO_NORMALSWING2        0x02
#define HITINFO_LEFTSWING           0x04
#define HITINFO_MISS                0x10
#define HITINFO_HITSTRANGESOUND1    0x20                    //maybe linked to critical hit
#define HITINFO_HITSTRANGESOUND2    0x40                    //maybe linked to critical hit
#define HITINFO_CRITICALHIT         0x80
#define HITINFO_GLANCING            0x4000
#define HITINFO_CRUSHING            0x8000
#define HITINFO_NOACTION            0x10000
#define HITINFO_SWINGNOHITSOUND     0x80000

#define NULL_BAG                    0
#define NULL_SLOT                   255

struct FactionTemplateEntry;
struct Modifier;
struct SpellEntry;

class Aura;
class Creature;
class Spell;
class DynamicObject;

struct DamageShield
{
    uint32 m_spellId;
    uint32 m_damage;
    Unit *m_caster;
};

struct ProcTriggerDamage
{
    uint64 caster;
    uint32 procDamage;
    uint32 procChance;
    uint32 procFlags;
    uint32 procCharges;
};

struct ProcTriggerSpell
{
    uint32 trigger;
    uint32 spellId;
    uint64 caster;
    uint32 procChance;
    uint32 procFlags;
    uint32 procCharges;
};

struct SpellCritSchool
{
    uint32 spellId;
    int32 school;
    int32 chance;
};

struct ReflectSpellSchool
{
    uint32 spellId;
    int32 school;
    int32 chance;
};

struct DamageDoneCreature
{
    uint32 spellId;
    uint32 creaturetype;
    int32 damage;
};

enum DeathState
{
    ALIVE = 0,
    JUST_DIED,
    CORPSE,
    DEAD
};

enum UnitState
{
    UNIT_STAT_STOPPED       = 0,
    UNIT_STAT_DIED          = 1,
    UNIT_STAT_ATTACKING     = 2,                            // player is attacking someone
    UNIT_STAT_ATTACK_BY     = 4,                            // player is attack by someone
                                                            // player is in combat mode
    UNIT_STAT_IN_COMBAT     = (UNIT_STAT_ATTACKING | UNIT_STAT_ATTACK_BY),
    UNIT_STAT_STUNDED       = 8,
    UNIT_STAT_ROAMING       = 16,
    UNIT_STAT_CHASE         = 32,
    UNIT_STAT_SEARCHING     = 64,
    UNIT_STAT_FLEEING       = 128,
    UNIT_STAT_MOVING        = (UNIT_STAT_ROAMING | UNIT_STAT_CHASE | UNIT_STAT_SEARCHING | UNIT_STAT_FLEEING),
    UNIT_STAT_IN_FLIGHT     = 256,                          // player is i n flight mode
    UNIT_STAT_FOLLOW        = 512,
    UNIT_STAT_ROOT          = 1024,
    UNIT_STAT_CONFUSED      = 2048,
    UNIT_STAT_ALL_STATE     = 0xffff                        //(UNIT_STAT_STOPPED | UNIT_STAT_MOVING | UNIT_STAT_IN_COMBAT | UNIT_STAT_IN_FLIGHT)
};

// Value masks for UNIT_FIELD_FLAGS
#define UNIT_FLAG_NONE           0x0000000
#define UNIT_FLAG_DISABLE_MOVE   0x0000004
#define UNIT_FLAG_NOT_IN_PVP     0x0000008
#define UNIT_FLAG_RESTING        0x0000020
#define UNIT_FLAG_MOUNT          0x0002000
#define UNIT_FLAG_DISABLE_ROTATE 0x0040000
#define UNIT_FLAG_ATTACKING      0x0080000
#define UNIT_FLAG_SKINNABLE      0x4000000

//To all Immune system,if target has immunes,
//some spell that related to ImmuneToDispel or ImmuneToSchool or ImmuneToDamage type can't cast to it,
//some spell_effects that related to ImmuneToEffect<effect>(only this effect in the spell) can't cast to it,
//some aura(related to ImmuneToMechanic or ImmuneToState<aura>) can't apply to it.
enum ImmuneToMechanic
{
    IMMUNE_MECHANIC_CHARM            =1,
    IMMUNE_MECHANIC_CONFUSED         =2,
    IMMUNE_MECHANIC_DISARM           =3,
    IMMUNE_MECHANIC_UNKOWN4          =4,
    IMMUNE_MECHANIC_FEAR             =5,
    IMMUNE_MECHANIC_UNKOWN6          =6,
    IMMUNE_MECHANIC_ROOT             =7,
    IMMUNE_MECHANIC_UNKOWN8          =8,
    IMMUNE_MECHANIC_UNKOWN9          =9,
    IMMUNE_MECHANIC_SLEEP            =10,
    IMMUNE_MECHANIC_CHASE            =11,
    IMMUNE_MECHANIC_STUNDED          =12,
    IMMUNE_MECHANIC_FREEZE           =13,
    IMMUNE_MECHANIC_KNOCKOUT         =14,
    IMMUNE_MECHANIC_BLEED            =15,
    IMMUNE_MECHANIC_HEAL             =16,
    IMMUNE_MECHANIC_POLYMORPH        =17,
    IMMUNE_MECHANIC_BANISH           =18,
    IMMUNE_MECHANIC_SHIELDED         =19,
    IMMUNE_MECHANIC_UNKOWN20         =20,
    IMMUNE_MECHANIC_MOUNT            =21,
    IMMUNE_MECHANIC_UNKOWN22         =22,
    IMMUNE_MECHANIC_UNKOWN23         =23,
    IMMUNE_MECHANIC_HORROR           =24,
    IMMUNE_MECHANIC_INVULNERABILITY  =25,
    IMMUNE_MECHANIC_UNKOWN26         =26
};

enum ImmuneToDispel
{
    IMMUNE_DISPEL_MAGIC        =1,
    IMMUNE_DISPEL_CURSE        =2,
    IMMUNE_DISPEL_DISEASE      =3,
    IMMUNE_DISPEL_POISON       =4,
    IMMUNE_DISPEL_STEALTH      =5,
    IMMUNE_DISPEL_INVISIBILITY =6,
    IMMUNE_DISPEL_ALL          =7,
    IMMUNE_DISPEL_SPE_NPC_ONLY =8,
    IMMUNE_DISPEL_CRAZY        =9,
    IMMUNE_DISPEL_ZG_TICKET    =10
};

enum ImmuneToDamage
{
    IMMUNE_DAMAGE_PHYSICAL     =1,
    IMMUNE_DAMAGE_MAGIC        =126
};

enum ImmuneToSchool
{
    IMMUNE_SCHOOL_PHYSICAL     =1,
    IMMUNE_SCHOOL_HOLY         =2,
    IMMUNE_SCHOOL_FIRE         =4,
    IMMUNE_SCHOOL_NATURE       =8,
    IMMUNE_SCHOOL_FROST        =16,
    IMMUNE_SCHOOL_SHADOW       =32,
    IMMUNE_SCHOOL_ARCANE       =64,
    IMMUNE_SCHOOL_MAGIC        =126
};

struct Hostil
{
    Hostil(uint64 _UnitGuid, float _Hostility) : UnitGuid(_UnitGuid), Hostility(_Hostility) {}

    uint64 UnitGuid;
    float Hostility;
    bool operator <(Hostil item)
    {
        if(Hostility < item.Hostility)
            return true;
        else
            return false;
    };
};

typedef std::list<Hostil> HostilList;

enum MeleeHitOutcome
{
    MELEE_HIT_MISS, MELEE_HIT_DODGE, MELEE_HIT_BLOCK, MELEE_HIT_PARRY, MELEE_HIT_GLANCING,
    MELEE_HIT_CRIT, MELEE_HIT_NORMAL
};

class MANGOS_DLL_SPEC Unit : public Object
{
    public:
        typedef std::set<Unit*> AttackerSet;
        typedef std::pair<uint32, uint32> spellEffectPair;
        typedef std::map< spellEffectPair, Aura*> AuraMap;
        virtual ~Unit ( );

        virtual void Update( uint32 time );

        void setAttackTimer(uint32 time, bool rangeattack = false);
        uint32 getAttackTimer() const { return m_attackTimer; }
        bool isAttackReady() const { return m_attackTimer == 0; }
        bool canReachWithAttack(Unit *pVictim) const;

        void _addAttacker(Unit *pAttacker)                  // must be called only from Unit::Attack(Unit*)
        {
            AttackerSet::iterator itr = m_attackers.find(pAttacker);
            if(itr == m_attackers.end())
                m_attackers.insert(pAttacker);
            addUnitState(UNIT_STAT_ATTACK_BY);
        }
        void _removeAttacker(Unit *pAttacker)               // must be called only from Unit::AttackStop()
        {
            AttackerSet::iterator itr = m_attackers.find(pAttacker);
            if(itr != m_attackers.end())
                m_attackers.erase(itr);

            if (m_attackers.size() == 0)
                clearUnitState(UNIT_STAT_ATTACK_BY);
        }
        Unit * getAttackerForHelper()                       // If someone wants to help, who to give them
        {
            if (getVictim() != NULL)
                return getVictim();

            if (m_attackers.size() > 0)
                return *(m_attackers.begin());

            return NULL;
        }
        bool Attack(Unit *victim);
        bool AttackStop();
        void RemoveAllAttackers();
        bool isInCombatWithPlayer() const;
        Unit* getVictim() const { return m_attacking; }

        void addUnitState(uint32 f) { m_state |= f; };
        bool hasUnitState(const uint32 f) const { return (m_state & f); }
        void clearUnitState(uint32 f) { m_state &= ~f; };

        uint32 getLevel() const { return (GetUInt32Value(UNIT_FIELD_LEVEL)); };
        uint8 getRace() const { return (uint8)m_uint32Values[ UNIT_FIELD_BYTES_0 ] & 0xFF; };
        uint32 getRaceMask() const { return 1 << (getRace()-1); };
        uint8 getClass() const { return (uint8)(m_uint32Values[ UNIT_FIELD_BYTES_0 ] >> 8) & 0xFF; };
        uint32 getClassMask() const { return 1 << (getClass()-1); };
        uint8 getGender() const { return (uint8)(m_uint32Values[ UNIT_FIELD_BYTES_0 ] >> 16) & 0xFF; };
        uint8 getPowerType() const { return (uint8)(m_uint32Values[ UNIT_FIELD_BYTES_0 ] >> 24) & 0xFF; };
        void setPowerType(uint8 PowerType);

        // function template id
        uint32 getFaction() const { return GetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE); }
        void setFaction(uint32 faction) { SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, faction ); }
        FactionTemplateEntry* getFactionTemplateEntry() const;

        uint8 getStandState() const { return (uint8)m_uint32Values[ UNIT_FIELD_BYTES_1 ] & 0xFF; };

        void DealDamage(Unit *pVictim, uint32 damage, uint32 procFlag, bool durabilityLoss);
        void DoAttackDamage(Unit *pVictim, uint32 *damage, uint32 *blocked_amount, uint32 *damageType, uint32 *hitInfo, uint32 *victimState,uint32 *absorbDamage,uint32 *resist);
        uint32 CalDamageAbsorb(Unit *pVictim,uint32 School,const uint32 damage,uint32 *resist);
        void HandleEmoteCommand(uint32 anim_id);
        void AttackerStateUpdate (Unit *pVictim);

        float GetUnitDodgeChance()    const { return GetTypeId() == TYPEID_PLAYER ? m_floatValues[ PLAYER_DODGE_PERCENTAGE ] : 5; }
        float GetUnitParryChance()    const { return GetTypeId() == TYPEID_PLAYER ? m_floatValues[ PLAYER_PARRY_PERCENTAGE ] : 5; }
        float GetUnitBlockChance()    const { return GetTypeId() == TYPEID_PLAYER ? m_floatValues[ PLAYER_BLOCK_PERCENTAGE ] : 5; }
        float GetUnitCriticalChance() const { return GetTypeId() == TYPEID_PLAYER ? m_floatValues[ PLAYER_CRIT_PERCENTAGE  ] : 5; }

        uint32 GetUnitBlockValue() const { return (uint32)m_uint32Values[ UNIT_FIELD_ARMOR ]; }
        uint32 GetUnitStrength()   const { return (uint32)m_uint32Values[ UNIT_FIELD_STR ]; }
        uint32 GetUnitMeleeSkill() const { return getLevel() * 5; }
        uint16 GetDefenceSkillValue() const;
        uint16 GetWeaponSkillValue() const;
        MeleeHitOutcome RollMeleeOutcomeAgainst (const Unit *pVictim) const;

        bool isVendor()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_VENDOR ); }
        bool isTrainer()      const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TRAINER ); }
        bool isQuestGiver()   const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER ); }
        bool isGossip()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP ); }
        bool isTaxi()         const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TAXIVENDOR ); }
        bool isGuildMaster()  const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_PETITIONER ); }
        bool isBattleMaster() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BATTLEFIELDPERSON ); }
        bool isBanker()       const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_BANKER ); }
        bool isInnkeeper()    const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_INNKEEPER ); }
        bool isSpiritHealer() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPIRITHEALER ); }
        bool isTabardVendor() const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_TABARDVENDOR ); }
        bool isAuctioner()    const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_AUCTIONEER ); }
        bool isArmorer()      const { return HasFlag( UNIT_NPC_FLAGS, UNIT_NPC_FLAG_ARMORER ); }
        //Need fix or use this
        bool isGuard() const  { return HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GUARD); }

        bool isStunned() const { return m_attackTimer == 0;};

        bool isInFlight()  const { return hasUnitState(UNIT_STAT_IN_FLIGHT); }
        bool isInCombat()  const { return hasUnitState(UNIT_STAT_IN_COMBAT); }
        bool isAttacking() const { return hasUnitState(UNIT_STAT_ATTACKING); }
        bool isAttacked()  const { return hasUnitState(UNIT_STAT_ATTACK_BY); }

        bool HasAuraType(uint32 auraType) const;
        bool isStealth() const                              // cache this in a bool someday
        {
            return HasAuraType(SPELL_AURA_MOD_STEALTH);
        }
        bool isTargetableForAttack() const { return isAlive() && !isInFlight() /*&& !isStealth()*/; }

        void PeriodicAuraLog(Unit *pVictim, SpellEntry *spellProto, Modifier *mod);
        void SpellNonMeleeDamageLog(Unit *pVictim, uint32 spellID, uint32 damage);
        void CastSpell(Unit* Victim, uint32 spellId, bool triggered);

        void DeMorph();

        void SendAttackStop(uint64 victimGuid);
        void SendAttackStateUpdate(uint32 HitInfo, uint64 targetGUID, uint8 SwingType, uint32 DamageType, uint32 Damage, uint32 AbsorbDamage, uint32 Resist, uint32 TargetState, uint32 BlockedAmount);
        void SendSpellNonMeleeDamageLog(uint64 targetGUID,uint32 SpellID,uint32 Damage, uint8 DamageType,uint32 AbsorbedDamage, uint32 Resist,bool PhysicalDamage, uint32 Blocked);

        void SendMonsterMove(float NewPosX, float NewPosY, float NewPosZ, bool Walkback, bool Run, uint32 Time);

        virtual void DealWithSpellDamage(DynamicObject &);
        virtual void MoveOutOfRange(Player &) {  };

        bool isAlive() const { return (m_deathState == ALIVE); };
        bool isDead() const { return ( m_deathState == DEAD || m_deathState == CORPSE ); };
        DeathState getDeathState() { return m_deathState; };
        virtual void setDeathState(DeathState s)
        {
            if (s != ALIVE)
            {
                if (isInCombat())
                {
                    AttackStop();
                    RemoveAllAttackers();
                }
            }
            if (s == JUST_DIED)
            {
                RemoveAllAuras();
            }
            m_deathState = s;
        }

        uint64 GetPetGUID() const { return  GetUInt64Value(UNIT_FIELD_SUMMON); }
        Creature* GetPet() const;
        void SetPet(Creature* pet);

        bool AddAura(Aura *aur, bool uniq = false);

        void RemoveFirstAuraByDispel(uint32 dispel_type);
        void RemoveAura(AuraMap::iterator &i);
        void RemoveAura(uint32 spellId, uint32 effindex);
        void RemoveAurasDueToSpell(uint32 spellId);
        void RemoveSpellsCausingAura(uint32 auraType);
        void RemoveRankAurasDueToSpell(uint32 spellId);
        bool RemoveNoStackAurasDueToAura(Aura *Aur);

        void RemoveAllAuras();
        //void SetAura(Aura* Aur){ m_Auras = Aur; }
        bool SetAurDuration(uint32 spellId, uint32 effindex, uint32 duration);
        uint32 GetAurDuration(uint32 spellId, uint32 effindex);

        void castSpell(Spell * pSpell);
        void InterruptSpell();
        Spell * m_currentSpell;
        Spell * m_currentMeleeSpell;
        uint32 m_addDmgOnce;
        uint64 m_TotemSlot1;
        uint64 m_TotemSlot2;
        uint64 m_TotemSlot3;
        uint64 m_TotemSlot4;
        uint32 m_triggerSpell;
        uint32 m_triggerDamage;
        uint32 m_canMove;
        uint32 m_immuneToMechanic;
        uint32 m_immuneToEffect;
        uint32 m_immuneToState;
        uint32 m_immuneToSchool;
        uint32 m_immuneToDmg;
        uint32 m_immuneToDispel;
        uint32 m_detectStealth;
        uint32 m_stealthvalue;
        float m_speed;
        uint32 m_ShapeShiftForm;
        uint32 m_form;
        int32 m_modDamagePCT;
        int32 m_RegenPCT;
        int32 m_modHitChance;
        int32 m_modSpellHitChance;
        int32 m_baseSpellCritChance;

        bool isInFront(Unit const* target,float distance);
        void SetInFront(Unit const* target);

        bool m_silenced;
        bool waterbreath;
        std::list<struct DamageShield> m_damageShields;
        std::list<struct DamageManaShield*> m_damageManaShield;
        std::list<struct SpellCritSchool*> m_spellCritSchool;
        std::list<Aura *> *GetSingleCastAuras() { return &m_scAuras; }
        std::list<struct ReflectSpellSchool*> m_reflectSpellSchool;
        std::list<struct DamageDoneCreature*> m_damageDoneCreature;

        float GetHostility(uint64 guid) const;
        float GetHostilityDistance(uint64 guid) const { return GetHostility( guid )/(3.5f * getLevel()+1.0f); }
        HostilList& GetHostilList() { return m_hostilList; }
        void AddHostil(uint64 guid, float hostility);
        Unit* SelectHostilTarget();

        Aura* GetAura(uint32 spellId, uint32 effindex);
        AuraMap const& GetAuras( ) {return m_Auras;}
        long GetTotalAuraModifier(uint32 ModifierID);
        void SendMoveToPacket(float x, float y, float z, bool run);
        void AddItemEnchant(uint32 enchant_id,bool apply);
        void setTransForm(uint32 spellid) { m_transform = spellid;}
        uint32 getTransForm() { return m_transform;}
        void AddDynObject(DynamicObject* dynObj);
        void RemoveDynObject(uint32 spellid);
        void AddGameObject(GameObject* gameObj);
        void RemoveGameObject(uint32 spellid, bool del);
        uint32 CalculateDamage(bool ranged);
        void SetStateFlag(uint32 index, uint32 newFlag );
        void RemoveStateFlag(uint32 index, uint32 oldFlag );
        void ApplyStats(bool apply);
        void UnsummonTotem(int8 slot = -1);

    protected:
        Unit ( );

        void _RemoveStatsMods();
        void _ApplyStatsMods();

        void _RemoveAllAuraMods();
        void _ApplyAllAuraMods();

        void _UpdateSpells(uint32 time);
        void _UpdateHostil( uint32 time );
        //void _UpdateAura();

        //Aura* m_aura;
        //uint32 m_auraCheck, m_removeAuraTimer;

        uint32 m_attackTimer;

        AttackerSet m_attackers;
        Unit* m_attacking;

        DeathState m_deathState;

        AuraMap m_Auras;

        std::list<Aura *> m_scAuras;                        // casted singlecast auras
        std::list<DynamicObject*> m_dynObj;
        std::list<GameObject*> m_gameObj;
        HostilList m_hostilList;
        uint32 m_transform;
        uint32 m_removedAuras;

        long m_AuraModifiers[TOTAL_AURAS];
        //std::list< spellEffectPair > AuraSpells[TOTAL_AURAS];  // TODO: use this if ok for mem

    private:
        uint32 m_state;                                     // Even derived shouldn't modify
};
#endif
