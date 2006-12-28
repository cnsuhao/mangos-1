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

#include "DBCStores.h"
//#include "DataStore.h"
#include "Policies/SingletonImp.h"
#include "Log.h"
#include "ProgressBar.h"

#include "DBCfmt.cpp"

#include <map>

typedef std::map<uint16,uint32> AreaFlagByAreaID;

DBCStorage <AreaTableEntry> sAreaStore(AreaTableEntryfmt);
static AreaFlagByAreaID sAreaFlagByAreaID;

DBCStorage <BankBagSlotPricesEntry> sBankBagSlotPricesStore(BankBagSlotPricesEntryfmt);

DBCStorage <ChrClassesEntry> sChrClassesStore(ChrClassesEntryfmt);
DBCStorage <ChrRacesEntry> sChrRacesStore(ChrRacesEntryfmt);
DBCStorage <CreatureFamilyEntry> sCreatureFamilyStore(CreatureFamilyfmt);

DBCStorage <EmotesTextEntry> sEmotesTextStore(EmoteEntryfmt);

DBCStorage <FactionEntry> sFactionStore(FactionEntryfmt);
DBCStorage <FactionTemplateEntry> sFactionTemplateStore(FactionTemplateEntryfmt);

DBCStorage <ItemSetEntry> sItemSetStore(ItemSetEntryfmt);
DBCStorage <ItemDisplayInfoEntry> sItemDisplayInfoStore(ItemDisplayTemplateEntryfmt);
DBCStorage <ItemRandomPropertiesEntry> sItemRandomPropertiesStore(ItemRandomPropertiesfmt);

DBCStorage <LockEntry> sLockStore(LockEntryfmt);

DBCStorage <MapEntry> sMapStore(MapEntryfmt);

DBCStorage <SkillLineEntry> sSkillLineStore(SkillLinefmt);
DBCStorage <SkillLineAbilityEntry> sSkillLineAbilityStore(SkillLineAbilityfmt);

DBCStorage <SpellItemEnchantmentEntry> sSpellItemEnchantmentStore(SpellItemEnchantmentfmt);
DBCStorage <SpellEntry> sSpellStore(SpellEntryfmt);
DBCStorage <SpellCastTimesEntry> sCastTimesStore(SpellCastTimefmt);
DBCStorage <SpellDurationEntry> sSpellDurationStore(SpellDurationfmt);
//DBCStorage <SpellFocusObjectEntry> sSpellFocusObjectStore(SpellFocusObjectfmt);
DBCStorage <SpellRadiusEntry> sSpellRadiusStore(SpellRadiusfmt);
DBCStorage <SpellRangeEntry> sSpellRangeStore(SpellRangefmt);
DBCStorage <TalentEntry> sTalentStore(TalentEntryfmt);
DBCStorage <TalentTabEntry> sTalentTabStore(TalentTabEntryfmt);
DBCStorage <TaxiNodesEntry> sTaxiNodesStore(TaxiNodesEntryfmt);

// DBC used only for initialization sTaxiPathSetBySource at startup.
TaxiPathSetBySource sTaxiPathSetBySource;
struct TaxiPathEntry
{
    uint32    ID;
    uint32    from;
    uint32    to;
    uint32    price;
};
static DBCStorage <TaxiPathEntry> sTaxiPathStore(TaxiPathEntryfmt);

// DBC used only for initialization sTaxiPathSetBySource at startup.
TaxiPathNodesByPath sTaxiPathNodesByPath;
struct TaxiPathNodeEntry
{
    uint32    path;
    uint32    index;
    uint32    mapid;
    float     x;
    float     y;
    float     z;
    uint32    actionFlag;
    uint32    delay;
};
static DBCStorage <TaxiPathNodeEntry> sTaxiPathNodeStore(TaxiPathNodeEntryfmt);

DBCStorage <WorldSafeLocsEntry> sWorldSafeLocsStore(WorldSafeLocsEntryfmt);

typedef std::list<std::string> StoreProblemList;

static bool LoadDBC_assert_print(uint32 fsize,uint32 rsize, std::string filename)
{
    sLog.outError("ERROR: Size of '%s' setted by format string (%u) not equal size of C++ structure (%u).",filename.c_str(),fsize,rsize);

    // assert must fail after function call
    return false;
}

template<class T>
inline void LoadDBC(barGoLink& bar, StoreProblemList& errlist, DBCStorage<T>& storage, std::string filename)
{
    // compatibility format and C++ structure sizes
    assert(DBCFile::GetFormatRecordSize(storage.fmt) == sizeof(T) || LoadDBC_assert_print(DBCFile::GetFormatRecordSize(storage.fmt),sizeof(T),filename));

    if(storage.Load(filename.c_str()))
        bar.step();
    else
    {
        // sort problematic dbc to (1) non compatible and (2) non-existed
        FILE * f=fopen(filename.c_str(),"rb");
        if(f)
        {
            char buf[100];
            snprintf(buf,100," (exist, but have %d fields instead %d) Wrong client version DBC file?",storage.fieldCount,strlen(storage.fmt));
            errlist.push_back(filename + buf);
            fclose(f);
        }else
        errlist.push_back(filename);
    }
}

void LoadDBCStores(std::string dataPath)
{
    std::string tmpPath="";

    const uint32 DBCFilesCount = 27;

    barGoLink bar( DBCFilesCount );

    StoreProblemList bad_dbc_files;

    LoadDBC(bar,bad_dbc_files,sAreaStore,                dataPath+"dbc/AreaTable.dbc");

    for(uint32 i = 1; i <= sAreaStore.nCount; ++i)
        if(AreaTableEntry* area = sAreaStore.LookupEntry(i))
            sAreaFlagByAreaID.insert(AreaFlagByAreaID::value_type(area->ID,area->exploreFlag));

    LoadDBC(bar,bad_dbc_files,sBankBagSlotPricesStore,   dataPath+"dbc/BankBagSlotPrices.dbc");
    LoadDBC(bar,bad_dbc_files,sChrClassesStore,          dataPath+"dbc/ChrClasses.dbc");
    LoadDBC(bar,bad_dbc_files,sChrRacesStore,            dataPath+"dbc/ChrRaces.dbc");
    LoadDBC(bar,bad_dbc_files,sCreatureFamilyStore,      dataPath+"dbc/CreatureFamily.dbc");
    LoadDBC(bar,bad_dbc_files,sEmotesTextStore,          dataPath+"dbc/EmotesText.dbc");
    LoadDBC(bar,bad_dbc_files,sFactionStore,             dataPath+"dbc/Faction.dbc");
    LoadDBC(bar,bad_dbc_files,sFactionTemplateStore,     dataPath+"dbc/FactionTemplate.dbc");
    LoadDBC(bar,bad_dbc_files,sItemDisplayInfoStore,     dataPath+"dbc/ItemDisplayInfo.dbc");
    LoadDBC(bar,bad_dbc_files,sItemRandomPropertiesStore,dataPath+"dbc/ItemRandomProperties.dbc");
    LoadDBC(bar,bad_dbc_files,sItemSetStore,             dataPath+"dbc/ItemSet.dbc");
    LoadDBC(bar,bad_dbc_files,sLockStore,                dataPath+"dbc/Lock.dbc");
    LoadDBC(bar,bad_dbc_files,sMapStore,                 dataPath+"dbc/Map.dbc");
    LoadDBC(bar,bad_dbc_files,sSkillLineStore,           dataPath+"dbc/SkillLine.dbc");
    LoadDBC(bar,bad_dbc_files,sSkillLineAbilityStore,    dataPath+"dbc/SkillLineAbility.dbc");
    LoadDBC(bar,bad_dbc_files,sSpellStore,               dataPath+"dbc/Spell.dbc");
    LoadDBC(bar,bad_dbc_files,sCastTimesStore,           dataPath+"dbc/SpellCastTimes.dbc");
    LoadDBC(bar,bad_dbc_files,sSpellDurationStore,       dataPath+"dbc/SpellDuration.dbc");
    //LoadDBC(bar,bad_dbc_files,sSpellFocusObjectStore,    dataPath+"dbc/SpellFocusObject.dbc");
    LoadDBC(bar,bad_dbc_files,sSpellItemEnchantmentStore,dataPath+"dbc/SpellItemEnchantment.dbc");
    LoadDBC(bar,bad_dbc_files,sSpellRadiusStore,         dataPath+"dbc/SpellRadius.dbc");
    LoadDBC(bar,bad_dbc_files,sSpellRangeStore,          dataPath+"dbc/SpellRange.dbc");
    LoadDBC(bar,bad_dbc_files,sTalentStore,              dataPath+"dbc/Talent.dbc");
    LoadDBC(bar,bad_dbc_files,sTalentTabStore,           dataPath+"dbc/TalentTab.dbc");
    LoadDBC(bar,bad_dbc_files,sTaxiNodesStore,           dataPath+"dbc/TaxiNodes.dbc");

    //## TaxiPath.dbc ## Loaded only for initialization different structures
    LoadDBC(bar,bad_dbc_files,sTaxiPathStore,            dataPath+"dbc/TaxiPath.dbc");
    for(uint32 i = 1; i <= sTaxiPathStore.nCount; ++i)
        if(TaxiPathEntry* entry = sTaxiPathStore.LookupEntry(i))
            sTaxiPathSetBySource[entry->from][entry->to] = TaxiPathBySourceAndDestination(entry->ID,entry->price);
    uint32 pathCount = sTaxiPathStore.nCount;
    sTaxiPathStore.Clear();

    //## TaxiPathNode.dbc ## Loaded only for initialization different structures
    LoadDBC(bar,bad_dbc_files,sTaxiPathNodeStore,        dataPath+"dbc/TaxiPathNode.dbc");
    // Calculate path nodes count
    std::vector<uint32> pathLength;
    pathLength.resize(pathCount+1);                         // 0 and some other indexes not used
    for(uint32 i = 1; i <= sTaxiPathNodeStore.nCount; ++i)
        if(TaxiPathNodeEntry* entry = sTaxiPathNodeStore.LookupEntry(i))
            ++pathLength[entry->path];
    // Set path length
    sTaxiPathNodesByPath.resize(pathCount+1);               // 0 and some other indexes not used
    for(uint32 i = 1; i < sTaxiPathNodesByPath.size(); ++i)
        sTaxiPathNodesByPath[i].resize(pathLength[i]);
    // fill data
    for(uint32 i = 1; i <= sTaxiPathNodeStore.nCount; ++i)
        if(TaxiPathNodeEntry* entry = sTaxiPathNodeStore.LookupEntry(i))
            sTaxiPathNodesByPath[entry->path][entry->index] = TaxiPathNode(entry->mapid,entry->x,entry->y,entry->z,entry->actionFlag,entry->delay);
    sTaxiPathNodeStore.Clear();

    LoadDBC(bar,bad_dbc_files,sWorldSafeLocsStore,       dataPath+"dbc/WorldSafeLocs.dbc");

    // error checks
    if(bad_dbc_files.size() >= DBCFilesCount )
    {
        sLog.outError("\nIncorrect DataDir value in mangosd.conf or ALL required *.dbc files (%d) not found by path: %sdbc",DBCFilesCount,dataPath.c_str());
        exit(1);
    }
    else if(bad_dbc_files.size() > 0 )
    {

        std::string str;
        for(std::list<std::string>::iterator i = bad_dbc_files.begin(); i != bad_dbc_files.end(); ++i)
            str += *i + "\n";

        sLog.outError("\nSome required *.dbc files (%u from %d) not found or not compatible:\n%s",bad_dbc_files.size(),DBCFilesCount,str.c_str());
        exit(1);
    }

    sLog.outString( "" );
    sLog.outString( ">> Loaded %d data stores", DBCFilesCount );
    sLog.outString( "" );
}

float GetRadius(SpellRadiusEntry const *radius)
{
    if(radius)
        return radius->Radius;
    else
        return 0;
}

uint32 GetCastTime(SpellCastTimesEntry const *time)
{
    if(time)
        return time->CastTime;
    else
        return 0;
}

float GetMaxRange(SpellRangeEntry const *range)
{
    if(range)
        return range->maxRange;
    else
        return 0;
}

float GetMinRange(SpellRangeEntry const *range)
{
    if(range)
        return range->minRange;
    else
        return 0;
}

int32 GetDuration(SpellEntry const *spellInfo)
{
    if(!spellInfo)
        return 0;
    SpellDurationEntry const *du = sSpellDurationStore.LookupEntry(spellInfo->DurationIndex);
    if(!du)
        return 0;
    return (du->Duration[0] == -1) ? -1 : abs(du->Duration[0]);
}

int32 GetMaxDuration(SpellEntry const *spellInfo)
{
    if(!spellInfo)
        return 0;
    SpellDurationEntry const *du = sSpellDurationStore.LookupEntry(spellInfo->DurationIndex);
    if(!du)
        return 0;
    return (du->Duration[2] == -1) ? -1 : abs(du->Duration[2]);
}

char* GetPetName(uint32 petfamily)
{
    if(!petfamily)
        return NULL;
    CreatureFamilyEntry const *pet_family = sCreatureFamilyStore.LookupEntry(petfamily);
    if(!pet_family)
        return NULL;
    return pet_family->Name?pet_family->Name:NULL;
}

bool IsPassiveSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
        return false;
    return ((spellInfo->Attributes & (1<<6)) != 0);
}

bool IsRankSpellDueToSpell(SpellEntry const *spellInfo_1,uint32 spellId_2)
{
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return false;
    if(spellInfo_1->Id == spellId_2) return false;

    for(int i=0;i<8;i++)
        if (spellInfo_1->SpellName[i] && spellInfo_2->SpellName[i])
            if (strcmp(spellInfo_1->SpellName[i], spellInfo_2->SpellName[i]) != 0)
                return false;
    return true;
}

bool IsNoStackSpellDueToSpell(uint32 spellId_1, uint32 spellId_2)
{
    SpellEntry const *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);

    if(!spellInfo_1 || !spellInfo_2)
        return false;

    if(spellInfo_1->Id == spellId_2)
        return false;

    if (spellInfo_1->SpellIconID == spellInfo_2->SpellIconID &&
        spellInfo_1->SpellIconID != 0 && spellInfo_2->SpellIconID != 0)
    {
        bool isModifier = false;
        for (int i = 0; i < 3; i++)
        {
            if (spellInfo_1->EffectApplyAuraName[i] == 107 || spellInfo_1->EffectApplyAuraName[i] == 108 ||
                spellInfo_2->EffectApplyAuraName[i] == 107 || spellInfo_2->EffectApplyAuraName[i] == 108)
                isModifier = true;
        }
        if (!isModifier)
            return true;
    }

    if (IsRankSpellDueToSpell(spellInfo_1, spellId_2))
        return true;

    if (spellInfo_1->SpellFamilyName == 0 || spellInfo_2->SpellFamilyName == 0)
        return false;

    if (spellInfo_1->SpellFamilyName != spellInfo_2->SpellFamilyName)
        return false;

    for (int i = 0; i < 3; ++i)
        if (spellInfo_1->Effect[i] != spellInfo_2->Effect[i] ||
        spellInfo_1->EffectItemType[i] != spellInfo_2->EffectItemType[i] ||
        spellInfo_1->EffectMiscValue[i] != spellInfo_2->EffectMiscValue[i] ||
        spellInfo_1->EffectApplyAuraName[i] != spellInfo_2->EffectApplyAuraName[i])
            return false;

    return true;
}

bool IsNoStackAuraDueToAura(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2)
{
    SpellEntry const *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return false;
    if(spellInfo_1->Id == spellId_2) return false;

    if (spellInfo_1->Effect[effIndex_1] != spellInfo_2->Effect[effIndex_2] ||
        spellInfo_1->EffectItemType[effIndex_1] != spellInfo_2->EffectItemType[effIndex_2] ||
        spellInfo_1->EffectMiscValue[effIndex_1] != spellInfo_2->EffectMiscValue[effIndex_2] ||
        spellInfo_1->EffectApplyAuraName[effIndex_1] != spellInfo_2->EffectApplyAuraName[effIndex_2])
        return false;

    return true;
}

int32 CompareAuraRanks(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2)
{
    SpellEntry *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return 0;
    if (spellId_1 == spellId_2) return 0;

    int32 diff = spellInfo_1->EffectBasePoints[effIndex_1] - spellInfo_2->EffectBasePoints[effIndex_2];
    if (spellInfo_1->EffectBasePoints[effIndex_1]+1 < 0 && spellInfo_2->EffectBasePoints[effIndex_2]+1 < 0) return -diff;
    else return diff;
}

SpellSpecific GetSpellSpecific(uint32 spellId)
{
    SpellEntry *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo) return SPELL_NORMAL;

    if(spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN)
    {
        // only paladin seals have this
        if (spellInfo->SpellVisual == 5622)
            return SPELL_SEAL;

        for (int i = 0; i < 3; i++)
        {
            // only paladin auras have this
            if (spellInfo->Effect[i] == 35)                 //SPELL_EFFECT_APPLY_AREA_AURA
                return SPELL_AURA;
            // only paladin blessings / greater blessings have this
            if (spellInfo->EffectImplicitTargetA[i] == 21   //TARGET_S_F
                ||spellInfo->EffectImplicitTargetA[i] == 57 //TARGET_S_F_2
                ||spellInfo->EffectImplicitTargetA[i] == 61)//TARGET_AF_PC
                return SPELL_BLESSING;
        }
    }

    // only warlock curses have this
    if(spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK)
        if (spellInfo->Dispel == 2)                         //IMMUNE_DISPEL_CURSE
            return SPELL_CURSE;

    if(spellInfo->SpellFamilyName == SPELLFAMILY_HUNTER)
    {
        // only hunter stings have this
        if (spellInfo->Dispel == 4)                         //IMMUNE_DISPEL_POISON
            return SPELL_STING;
        // only hunter aspects have this
        if (spellInfo->School == 3/*SPELL_SCHOOL_NATURE*/ && spellInfo->activeIconID == 122)
            return SPELL_ASPECT;
    }

    return SPELL_NORMAL;
}

bool IsSpellSingleEffectPerCaster(uint32 spellId)
{
    switch(GetSpellSpecific(spellId))
    {
        case SPELL_SEAL:
        case SPELL_BLESSING:
        case SPELL_AURA:
        case SPELL_STING:
        case SPELL_CURSE:
        case SPELL_ASPECT:
            return true;
        default:
            return false;
    }
}

bool IsPositiveEffect(uint32 spellId, uint32 effIndex)
{
    SpellEntry *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    switch(spellproto->EffectImplicitTargetA[effIndex])
    {
        case 6:                                             //TARGET_S_E:
        case 15:                                            //TARGET_AE_E:
        case 16:                                            //TARGET_AE_E_INSTANT:
        case 22:                                            //TARGET_AC_E:
        case 24:                                            //TARGET_INFRONT:
        case 25:                                            //TARGET_DUELVSPLAYER:
        case 28:                                            //TARGET_AE_E_CHANNEL:
        case 53:                                            //TARGET_AE_SELECTED:
            return false;
        default:
            return (spellproto->AttributesEx & (1<<7)) ? false : true;
    }
}

bool IsPositiveSpell(uint32 spellId)
{
    SpellEntry *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    // spells with atleast one negative effect are considered negative
    for (int i = 0; i < 3; i++)
        if (!IsPositiveEffect(spellId, i))
            return false;
    return true;
}

bool IsSingleTarget(uint32 spellId)
{
    SpellEntry *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo) return false;

    // cheap shot is an exception
    if ( spellId == 1833 || spellId == 14902 ) return false;

    // cannot be cast on another target while not cooled down anyway
    int32 duration = GetDuration(spellInfo);
    if ( duration < int32(spellInfo->RecoveryTime)) return false;
    if ( spellInfo->RecoveryTime == 0 && duration < int32(spellInfo->CategoryRecoveryTime)) return false;

    // all other single target spells have if it has AttributesEx
    if ( spellInfo->AttributesEx & (1<<18) ) return true;

    // other single target
                                                            //Fear
    if ((spellInfo->SpellIconID == 98 && spellInfo->SpellVisual == 336)
                                                            //Banish
        || (spellInfo->SpellIconID == 96 && spellInfo->SpellVisual == 1305)
        ) return true;
    // all other single target spells have if it has Attributes
    //if ( spellInfo->Attributes & (1<<30) ) return true;
    return false;
}

AreaTableEntry* GetAreaEntryByAreaID(uint32 area_id)
{
    AreaFlagByAreaID::iterator i = sAreaFlagByAreaID.find(area_id);
    if(i == sAreaFlagByAreaID.end())
        return NULL;

    return sAreaStore.LookupEntry(i->second);
}

AreaTableEntry* GetAreaEntryByAreaFlag(uint32 area_flag)
{
    return sAreaStore.LookupEntry(area_flag);
}
