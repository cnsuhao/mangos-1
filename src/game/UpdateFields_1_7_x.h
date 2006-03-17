/* 
 * Copyright (C) 2005 MaNGOS <http://www.magosproject.org/>
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

#ifdef _VERSION_1_7_0_

#pragma once

#ifndef _UPDATEFIELDS_H
#define _UPDATEFIELDS_H

enum DamageType
{
DMG_PHYSICAL = 0,
DMG_HOLY,
DMG_FIRE,
DMG_NATURE,
DMG_FROST,
DMG_SHADOW,
DMG_ARCANE
};

#define ver 171


enum ObjectUpdateFields
{
OBJECT_FIELD_GUID = 0,
OBJECT_FIELD_TYPE = OBJECT_FIELD_GUID+2,
OBJECT_FIELD_ENTRY,
OBJECT_FIELD_SCALE_X,
OBJECT_FIELD_PADDING,
OBJECT_END
};
enum ItemUpdateFields
{
ITEM_FIELD_OWNER = OBJECT_FIELD_PADDING+1, 
ITEM_FIELD_CONTAINED = ITEM_FIELD_OWNER+2, 
ITEM_FIELD_CREATOR = ITEM_FIELD_CONTAINED+2, 
ITEM_FIELD_GIFTCREATOR = ITEM_FIELD_CREATOR+2, 
ITEM_FIELD_STACK_COUNT = ITEM_FIELD_GIFTCREATOR+2, 
ITEM_FIELD_DURATION, 
ITEM_FIELD_SPELL_CHARGES, 
ITEM_FIELD_FLAGS = ITEM_FIELD_SPELL_CHARGES+5, 
ITEM_FIELD_ENCHANTMENT, 
ITEM_FIELD_PROPERTY_SEED = ITEM_FIELD_ENCHANTMENT+21, 
ITEM_FIELD_RANDOM_PROPERTIES_ID, 
ITEM_FIELD_ITEM_TEXT_ID, 
ITEM_FIELD_DURABILITY, 
ITEM_FIELD_MAXDURABILITY, 
ITEM_END
};
enum ContainerUpdateFields
{
CONTAINER_FIELD_NUM_SLOTS = ITEM_FIELD_MAXDURABILITY+1,
CONTAINER_ALIGN_PAD,
CONTAINER_FIELD_SLOT_1,
CONTAINER_END
};
enum UnitUpdateFields
{
UNIT_FIELD_CHARM = OBJECT_FIELD_PADDING+1,
UNIT_FIELD_SUMMON = UNIT_FIELD_CHARM+2,
UNIT_FIELD_CHARMEDBY = UNIT_FIELD_SUMMON+2,
UNIT_FIELD_SUMMONEDBY = UNIT_FIELD_CHARMEDBY+2,
UNIT_FIELD_CREATEDBY = UNIT_FIELD_SUMMONEDBY+2,
UNIT_FIELD_TARGET = UNIT_FIELD_CREATEDBY+2,
UNIT_FIELD_PERSUADED = UNIT_FIELD_TARGET+2,
UNIT_FIELD_CHANNEL_OBJECT = UNIT_FIELD_PERSUADED+2,
UNIT_FIELD_HEALTH = UNIT_FIELD_CHANNEL_OBJECT+2,
UNIT_FIELD_POWER1,
UNIT_FIELD_POWER2,
UNIT_FIELD_POWER3,
UNIT_FIELD_POWER4,
UNIT_FIELD_POWER5,
UNIT_FIELD_MAXHEALTH,
UNIT_FIELD_MAXPOWER1,
UNIT_FIELD_MAXPOWER2,
UNIT_FIELD_MAXPOWER3,
UNIT_FIELD_MAXPOWER4,
UNIT_FIELD_MAXPOWER5,
UNIT_FIELD_LEVEL,
UNIT_FIELD_FACTIONTEMPLATE,
UNIT_FIELD_BYTES_0,
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY,
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_02, 
UNIT_VIRTUAL_ITEM_INFO = UNIT_VIRTUAL_ITEM_SLOT_DISPLAY+3,
UNIT_FIELD_FLAGS = UNIT_VIRTUAL_ITEM_INFO+6,
UNIT_FIELD_AURA,
UNIT_FIELD_AURAFLAGS = UNIT_FIELD_AURA + 64,
UNIT_FIELD_AURALEVELS = UNIT_FIELD_AURAFLAGS + 8,
UNIT_FIELD_AURAAPPLICATIONS = UNIT_FIELD_AURALEVELS + 8,
UNIT_FIELD_AURASTATE = UNIT_FIELD_AURAAPPLICATIONS + 16,
UNIT_FIELD_BASEATTACKTIME,
UNIT_FIELD_RANGEDATTACKTIME = UNIT_FIELD_BASEATTACKTIME+2,
UNIT_FIELD_BOUNDINGRADIUS,
UNIT_FIELD_COMBATREACH,
UNIT_FIELD_DISPLAYID,
UNIT_FIELD_NATIVEDISPLAYID,
UNIT_FIELD_MOUNTDISPLAYID,
UNIT_FIELD_MINDAMAGE,
UNIT_FIELD_MAXDAMAGE,
UNIT_FIELD_MINOFFHANDDAMAGE,
UNIT_FIELD_MAXOFFHANDDAMAGE,
UNIT_FIELD_BYTES_1,
UNIT_FIELD_PETNUMBER,
UNIT_FIELD_PET_NAME_TIMESTAMP,
UNIT_FIELD_PETEXPERIENCE,
UNIT_FIELD_PETNEXTLEVELEXP,
UNIT_DYNAMIC_FLAGS,
UNIT_CHANNEL_SPELL,
UNIT_MOD_CAST_SPEED,
UNIT_CREATED_BY_SPELL,
UNIT_NPC_FLAGS,
UNIT_NPC_EMOTESTATE,
UNIT_TRAINING_POINTS,

UNIT_FIELD_STAT0,
UNIT_FIELD_STR = UNIT_FIELD_STAT0,
UNIT_FIELD_STAT1,
UNIT_FIELD_AGILITY = UNIT_FIELD_STAT1,
UNIT_FIELD_STAT2,
UNIT_FIELD_STAMINA = UNIT_FIELD_STAT2,
UNIT_FIELD_STAT3,
UNIT_FIELD_SPIRIT = UNIT_FIELD_STAT3,
UNIT_FIELD_STAT4,
UNIT_FIELD_IQ = UNIT_FIELD_STAT4,
UNIT_FIELD_ARMOR = UNIT_FIELD_STAT4, 
UNIT_FIELD_RESISTANCES,
UNIT_FIELD_RESISTANCES_01,
UNIT_FIELD_RESISTANCES_02,
UNIT_FIELD_RESISTANCES_03,
UNIT_FIELD_RESISTANCES_04,
UNIT_FIELD_RESISTANCES_05,
UNIT_FIELD_RESISTANCES_06,
UNIT_FIELD_ATTACKPOWER = UNIT_FIELD_RESISTANCES+7,
UNIT_FIELD_BASE_MANA,
UNIT_FIELD_BASE_HEALTH,
UNIT_FIELD_ATTACK_POWER_MODS,
UNIT_FIELD_BYTES_2,
UNIT_FIELD_RANGEDATTACKPOWER,
UNIT_FIELD_RANGED_ATTACK_POWER_MODS,
UNIT_FIELD_MINRANGEDDAMAGE,
UNIT_FIELD_MAXRANGEDDAMAGE,
UNIT_FIELD_POWER_COST_MODIFIER,
UNIT_FIELD_POWER_COST_MULTIPLIER,
UNIT_FIELD_PADDING,
UNIT_END
};
#define PLAYER_VISIBLE_ITEM_SIZE 12
enum PlayerUpdateFields
{
PLAYER_SELECTION = UNIT_FIELD_PADDING+12+1,
PLAYER_DUEL_ARBITER = PLAYER_SELECTION+2,
PLAYER_FLAGS = PLAYER_DUEL_ARBITER+2,
PLAYER_GUILDID,
PLAYER_GUILDRANK,
PLAYER_BYTES,
PLAYER_BYTES_2,
PLAYER_BYTES_3,
PLAYER_DUEL_TEAM,
PLAYER_GUILD_TIMESTAMP,
PLAYER_QUEST_LOG_1_1,
PLAYER_QUEST_LOG_1_2,
PLAYER_QUEST_LOG_2_1 = PLAYER_QUEST_LOG_1_2+2,
PLAYER_QUEST_LOG_2_2,
PLAYER_QUEST_LOG_3_1 = PLAYER_QUEST_LOG_2_2+2,
PLAYER_QUEST_LOG_3_2,
PLAYER_QUEST_LOG_4_1 = PLAYER_QUEST_LOG_3_2+2,
PLAYER_QUEST_LOG_4_2,
PLAYER_QUEST_LOG_5_1 = PLAYER_QUEST_LOG_4_2+2,
PLAYER_QUEST_LOG_5_2,
PLAYER_QUEST_LOG_6_1 = PLAYER_QUEST_LOG_5_2+2,
PLAYER_QUEST_LOG_6_2,
PLAYER_QUEST_LOG_7_1 = PLAYER_QUEST_LOG_6_2+2,
PLAYER_QUEST_LOG_7_2,
PLAYER_QUEST_LOG_8_1 = PLAYER_QUEST_LOG_7_2+2,
PLAYER_QUEST_LOG_8_2,
PLAYER_QUEST_LOG_9_1 = PLAYER_QUEST_LOG_8_2+2,
PLAYER_QUEST_LOG_9_2,
PLAYER_QUEST_LOG_10_1 = PLAYER_QUEST_LOG_9_2+2,
PLAYER_QUEST_LOG_10_2,
PLAYER_QUEST_LOG_11_1 = PLAYER_QUEST_LOG_10_2+2,
PLAYER_QUEST_LOG_11_2,
PLAYER_QUEST_LOG_12_1 = PLAYER_QUEST_LOG_11_2+2,
PLAYER_QUEST_LOG_12_2,
PLAYER_QUEST_LOG_13_1 = PLAYER_QUEST_LOG_12_2+2,
PLAYER_QUEST_LOG_13_2,
PLAYER_QUEST_LOG_14_1 = PLAYER_QUEST_LOG_13_2+2,
PLAYER_QUEST_LOG_14_2,
PLAYER_QUEST_LOG_15_1 = PLAYER_QUEST_LOG_14_2+2,
PLAYER_QUEST_LOG_15_2,
PLAYER_QUEST_LOG_16_1 = PLAYER_QUEST_LOG_15_2+2,
PLAYER_QUEST_LOG_16_2,
PLAYER_QUEST_LOG_17_1 = PLAYER_QUEST_LOG_16_2+2,
PLAYER_QUEST_LOG_17_2,
PLAYER_QUEST_LOG_18_1 = PLAYER_QUEST_LOG_17_2+2,
PLAYER_QUEST_LOG_18_2,
PLAYER_QUEST_LOG_19_1 = PLAYER_QUEST_LOG_18_2+2,
PLAYER_QUEST_LOG_19_2,
PLAYER_QUEST_LOG_20_1 = PLAYER_QUEST_LOG_19_2+2,
PLAYER_QUEST_LOG_20_2,
PLAYER_VISIBLE_ITEM_1_CREATOR = PLAYER_QUEST_LOG_20_2+2,
PLAYER_VISIBLE_ITEM_1_0 = PLAYER_VISIBLE_ITEM_1_CREATOR+2,
PLAYER_VISIBLE_ITEM_1_PROPERTIES = PLAYER_VISIBLE_ITEM_1_0+8,
PLAYER_VISIBLE_ITEM_1_PAD,
PLAYER_VISIBLE_ITEM_2_CREATOR,
PLAYER_VISIBLE_ITEM_2_0 = PLAYER_VISIBLE_ITEM_2_CREATOR+2,
PLAYER_VISIBLE_ITEM_2_PROPERTIES = PLAYER_VISIBLE_ITEM_2_0+8,
PLAYER_VISIBLE_ITEM_2_PAD,
PLAYER_VISIBLE_ITEM_3_CREATOR,
PLAYER_VISIBLE_ITEM_3_0 = PLAYER_VISIBLE_ITEM_3_CREATOR+2,
PLAYER_VISIBLE_ITEM_3_PROPERTIES = PLAYER_VISIBLE_ITEM_3_0+8,
PLAYER_VISIBLE_ITEM_3_PAD,
PLAYER_VISIBLE_ITEM_4_CREATOR,
PLAYER_VISIBLE_ITEM_4_0 = PLAYER_VISIBLE_ITEM_4_CREATOR+2,
PLAYER_VISIBLE_ITEM_4_PROPERTIES = PLAYER_VISIBLE_ITEM_4_0+8,
PLAYER_VISIBLE_ITEM_4_PAD,
PLAYER_VISIBLE_ITEM_5_CREATOR,
PLAYER_VISIBLE_ITEM_5_0 = PLAYER_VISIBLE_ITEM_5_CREATOR+2,
PLAYER_VISIBLE_ITEM_5_PROPERTIES = PLAYER_VISIBLE_ITEM_5_0+8,
PLAYER_VISIBLE_ITEM_5_PAD,
PLAYER_VISIBLE_ITEM_6_CREATOR,
PLAYER_VISIBLE_ITEM_6_0 = PLAYER_VISIBLE_ITEM_6_CREATOR+2,
PLAYER_VISIBLE_ITEM_6_PROPERTIES = PLAYER_VISIBLE_ITEM_6_0+8,
PLAYER_VISIBLE_ITEM_6_PAD,
PLAYER_VISIBLE_ITEM_7_CREATOR,
PLAYER_VISIBLE_ITEM_7_0 = PLAYER_VISIBLE_ITEM_7_CREATOR+2,
PLAYER_VISIBLE_ITEM_7_PROPERTIES = PLAYER_VISIBLE_ITEM_7_0+8,
PLAYER_VISIBLE_ITEM_7_PAD,
PLAYER_VISIBLE_ITEM_8_CREATOR,
PLAYER_VISIBLE_ITEM_8_0 = PLAYER_VISIBLE_ITEM_8_CREATOR+2,
PLAYER_VISIBLE_ITEM_8_PROPERTIES = PLAYER_VISIBLE_ITEM_8_0+8,
PLAYER_VISIBLE_ITEM_8_PAD,
PLAYER_VISIBLE_ITEM_9_CREATOR,
PLAYER_VISIBLE_ITEM_9_0 = PLAYER_VISIBLE_ITEM_9_CREATOR+2,
PLAYER_VISIBLE_ITEM_9_PROPERTIES = PLAYER_VISIBLE_ITEM_9_0+8,
PLAYER_VISIBLE_ITEM_9_PAD,
PLAYER_VISIBLE_ITEM_10_CREATOR,
PLAYER_VISIBLE_ITEM_10_0 = PLAYER_VISIBLE_ITEM_10_CREATOR+2,
PLAYER_VISIBLE_ITEM_10_PROPERTIES = PLAYER_VISIBLE_ITEM_10_0+8,
PLAYER_VISIBLE_ITEM_10_PAD,
PLAYER_VISIBLE_ITEM_11_CREATOR,
PLAYER_VISIBLE_ITEM_11_0 = PLAYER_VISIBLE_ITEM_11_CREATOR+2,
PLAYER_VISIBLE_ITEM_11_PROPERTIES = PLAYER_VISIBLE_ITEM_11_0+8,
PLAYER_VISIBLE_ITEM_11_PAD,
PLAYER_VISIBLE_ITEM_12_CREATOR,
PLAYER_VISIBLE_ITEM_12_0 = PLAYER_VISIBLE_ITEM_12_CREATOR+2,
PLAYER_VISIBLE_ITEM_12_PROPERTIES = PLAYER_VISIBLE_ITEM_12_0+8,
PLAYER_VISIBLE_ITEM_12_PAD,
PLAYER_VISIBLE_ITEM_13_CREATOR,
PLAYER_VISIBLE_ITEM_13_0 = PLAYER_VISIBLE_ITEM_13_CREATOR+2,
PLAYER_VISIBLE_ITEM_13_PROPERTIES = PLAYER_VISIBLE_ITEM_13_0+8,
PLAYER_VISIBLE_ITEM_13_PAD,
PLAYER_VISIBLE_ITEM_14_CREATOR,
PLAYER_VISIBLE_ITEM_14_0 = PLAYER_VISIBLE_ITEM_14_CREATOR+2,
PLAYER_VISIBLE_ITEM_14_PROPERTIES = PLAYER_VISIBLE_ITEM_14_0+8,
PLAYER_VISIBLE_ITEM_14_PAD,
PLAYER_VISIBLE_ITEM_15_CREATOR,
PLAYER_VISIBLE_ITEM_15_0 = PLAYER_VISIBLE_ITEM_15_CREATOR+2,
PLAYER_VISIBLE_ITEM_15_PROPERTIES = PLAYER_VISIBLE_ITEM_15_0+8,
PLAYER_VISIBLE_ITEM_15_PAD,
PLAYER_VISIBLE_ITEM_16_CREATOR,
PLAYER_VISIBLE_ITEM_16_0 = PLAYER_VISIBLE_ITEM_16_CREATOR+2,
PLAYER_VISIBLE_ITEM_16_PROPERTIES = PLAYER_VISIBLE_ITEM_16_0+8,
PLAYER_VISIBLE_ITEM_16_PAD,
PLAYER_VISIBLE_ITEM_17_CREATOR,
PLAYER_VISIBLE_ITEM_17_0 = PLAYER_VISIBLE_ITEM_17_CREATOR+2,
PLAYER_VISIBLE_ITEM_17_PROPERTIES = PLAYER_VISIBLE_ITEM_17_0+8,
PLAYER_VISIBLE_ITEM_17_PAD,
PLAYER_VISIBLE_ITEM_18_CREATOR,
PLAYER_VISIBLE_ITEM_18_0 = PLAYER_VISIBLE_ITEM_18_CREATOR+2,
PLAYER_VISIBLE_ITEM_18_PROPERTIES = PLAYER_VISIBLE_ITEM_18_0+8,
PLAYER_VISIBLE_ITEM_18_PAD,
PLAYER_VISIBLE_ITEM_19_CREATOR,
PLAYER_VISIBLE_ITEM_19_0 = PLAYER_VISIBLE_ITEM_19_CREATOR+2,
PLAYER_VISIBLE_ITEM_19_PROPERTIES = PLAYER_VISIBLE_ITEM_19_0+8,
PLAYER_VISIBLE_ITEM_19_PAD,
PLAYER_FIELD_INV_SLOT_HEAD,
PLAYER_FIELD_PACK_SLOT_1 = PLAYER_FIELD_INV_SLOT_HEAD+46,
PLAYER_FIELD_BANK_SLOT_1 = PLAYER_FIELD_PACK_SLOT_1+32,
PLAYER_FIELD_BANKBAG_SLOT_1 = PLAYER_FIELD_BANK_SLOT_1+48,
PLAYER_FIELD_VENDORBUYBACK_SLOT = PLAYER_FIELD_BANKBAG_SLOT_1+12,
PLAYER_FARSIGHT = PLAYER_FIELD_VENDORBUYBACK_SLOT+2,
PLAYER__FIELD_COMBO_TARGET = PLAYER_FARSIGHT+2,
PLAYER_FIELD_BUYBACK_NPC = PLAYER__FIELD_COMBO_TARGET+2,
PLAYER_XP = PLAYER_FIELD_BUYBACK_NPC+2,
PLAYER_NEXT_LEVEL_XP,
PLAYER_SKILL_INFO_1_1,
PLAYER_SKILL_INFO_1_1_381  = PLAYER_SKILL_INFO_1_1+381, 
PLAYER_CHARACTER_POINTS1 = PLAYER_SKILL_INFO_1_1+384,
PLAYER_CHARACTER_POINTS2,
PLAYER_TRACK_CREATURES,
PLAYER_TRACK_RESOURCES,
PLAYER_BLOCK_PERCENTAGE,
PLAYER_DODGE_PERCENTAGE,
PLAYER_PARRY_PERCENTAGE,
PLAYER_CRIT_PERCENTAGE,
PLAYER_RANGED_CRIT_PERCENTAGE,
PLAYER_EXPLORED_ZONES_1,
PLAYER_REST_STATE_EXPERIENCE = PLAYER_EXPLORED_ZONES_1+64,
PLAYER_FIELD_COINAGE,
PLAYER_FIELD_POSSTAT0,
PLAYER_FIELD_POSSTAT1,
PLAYER_FIELD_POSSTAT2,
PLAYER_FIELD_POSSTAT3,
PLAYER_FIELD_POSSTAT4,
PLAYER_FIELD_NEGSTAT0,
PLAYER_FIELD_NEGSTAT1,
PLAYER_FIELD_NEGSTAT2,
PLAYER_FIELD_NEGSTAT3,
PLAYER_FIELD_NEGSTAT4,
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE,
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_01, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_02, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_03, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_04, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_05, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_06, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE = PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE+7,
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_01, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_02, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_03, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_04, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_05, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_06, 
PLAYER_FIELD_MOD_DAMAGE_DONE_POS = PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE+7,
PLAYER_FIELD_MOD_DAMAGE_DONE_NEG = PLAYER_FIELD_MOD_DAMAGE_DONE_POS+7,
PLAYER_FIELD_MOD_DAMAGE_DONE_PCT = PLAYER_FIELD_MOD_DAMAGE_DONE_NEG+7,
PLAYER_FIELD_BYTES = PLAYER_FIELD_MOD_DAMAGE_DONE_PCT+7,
PLAYER_AMMO_ID,
PLAYER_SELF_RES_SPELL,
PLAYER_FIELD_PVP_MEDALS,
PLAYER_FIELD_BUYBACK_ITEM_ID,
PLAYER_FIELD_BUYBACK_RANDOM_PROPERTIES_ID,
PLAYER_FIELD_BUYBACK_SEED,
PLAYER_FIELD_BUYBACK_PRICE,
PLAYER_FIELD_BUYBACK_DURABILITY,
PLAYER_FIELD_BUYBACK_COUNT,

PLAYER_FIELD_SESSION_KILLS,
PLAYER_FIELD_YESTERDAY_KILLS,
PLAYER_FIELD_LAST_WEEK_KILLS,
PLAYER_FIELD_THIS_WEEK_KILLS,
PLAYER_FIELD_THIS_WEEK_CONTRIBUTION,
PLAYER_FIELD_LIFETIME_HONORBALE_KILLS,
PLAYER_FIELD_LIFETIME_DISHONORBALE_KILLS,
PLAYER_FIELD_YESTERDAY_CONTRIBUTION,
PLAYER_FIELD_LAST_WEEK_CONTRIBUTION,
PLAYER_FIELD_LAST_WEEK_RANK,
PLAYER_FIELD_BYTES2,
PLAYER_FIELD_PADDING,
PLAYER_END
};
enum GameObjectUpdateFields
{






OBJECT_FIELD_CREATED_BY = OBJECT_FIELD_PADDING+1, 

GAMEOBJECT_DISPLAYID = OBJECT_FIELD_CREATED_BY+2,
GAMEOBJECT_FLAGS,
GAMEOBJECT_ROTATION,
GAMEOBJECT_STATE = GAMEOBJECT_ROTATION+4,
GAMEOBJECT_TIMESTAMP,
GAMEOBJECT_POS_X,
GAMEOBJECT_POS_Y,
GAMEOBJECT_POS_Z,
GAMEOBJECT_FACING,
GAMEOBJECT_DYN_FLAGS,
GAMEOBJECT_FACTION,
GAMEOBJECT_TYPE_ID,
GAMEOBJECT_LEVEL,
GAMEOBJECT_END
};
enum DynamicObjectUpdateFields
{






DYNAMICOBJECT_CASTER = OBJECT_FIELD_PADDING+1,
DYNAMICOBJECT_BYTES = DYNAMICOBJECT_CASTER+2,
DYNAMICOBJECT_SPELLID,
DYNAMICOBJECT_RADIUS,
DYNAMICOBJECT_POS_X,
DYNAMICOBJECT_POS_Y,
DYNAMICOBJECT_POS_Z,
DYNAMICOBJECT_FACING,
DYNAMICOBJECT_PAD,
DYNAMICOBJECT_END
};

enum CorpseUpdateFields
{






CORPSE_FIELD_OWNER = OBJECT_FIELD_PADDING+1,
CORPSE_FIELD_FACING = CORPSE_FIELD_OWNER+2,
CORPSE_FIELD_POS_X,
CORPSE_FIELD_POS_Y,
CORPSE_FIELD_POS_Z,
CORPSE_FIELD_DISPLAY_ID,
CORPSE_FIELD_ITEM,
CORPSE_FIELD_BYTES_1 = CORPSE_FIELD_ITEM+19,
CORPSE_FIELD_BYTES_2,
CORPSE_FIELD_GUILD,
CORPSE_FIELD_FLAGS,
CORPSE_FIELD_DYNAMIC_FLAGS,
CORPSE_FIELD_PAD,
CORPSE_END
};


#endif

#endif 

#ifndef _UPDATEFIELDS_H
#define _UPDATEFIELDS_H

enum DamageType
{
DMG_PHYSICAL = 0,
DMG_HOLY,
DMG_FIRE,
DMG_NATURE,
DMG_FROST,
DMG_SHADOW,
DMG_ARCANE
};

#define ver 171


enum ObjectUpdateFields
{
OBJECT_FIELD_GUID = 0,
OBJECT_FIELD_TYPE = OBJECT_FIELD_GUID+2,
OBJECT_FIELD_ENTRY,
OBJECT_FIELD_SCALE_X,
OBJECT_FIELD_PADDING,
OBJECT_END
};
enum ItemUpdateFields
{
ITEM_FIELD_OWNER = OBJECT_FIELD_PADDING+1, 
ITEM_FIELD_CONTAINED = ITEM_FIELD_OWNER+2, 
ITEM_FIELD_CREATOR = ITEM_FIELD_CONTAINED+2, 
ITEM_FIELD_GIFTCREATOR = ITEM_FIELD_CREATOR+2, 
ITEM_FIELD_STACK_COUNT = ITEM_FIELD_GIFTCREATOR+2, 
ITEM_FIELD_DURATION, 
ITEM_FIELD_SPELL_CHARGES, 
ITEM_FIELD_FLAGS = ITEM_FIELD_SPELL_CHARGES+5, 
ITEM_FIELD_ENCHANTMENT, 
ITEM_FIELD_PROPERTY_SEED = ITEM_FIELD_ENCHANTMENT+21, 
ITEM_FIELD_RANDOM_PROPERTIES_ID, 
ITEM_FIELD_ITEM_TEXT_ID, 
ITEM_FIELD_DURABILITY, 
ITEM_FIELD_MAXDURABILITY, 
ITEM_END
};
enum ContainerUpdateFields
{
CONTAINER_FIELD_NUM_SLOTS = ITEM_FIELD_MAXDURABILITY+1,
CONTAINER_ALIGN_PAD,
CONTAINER_FIELD_SLOT_1,
CONTAINER_END
};
enum UnitUpdateFields
{
UNIT_FIELD_CHARM = OBJECT_FIELD_PADDING+1,
UNIT_FIELD_SUMMON = UNIT_FIELD_CHARM+2,
UNIT_FIELD_CHARMEDBY = UNIT_FIELD_SUMMON+2,
UNIT_FIELD_SUMMONEDBY = UNIT_FIELD_CHARMEDBY+2,
UNIT_FIELD_CREATEDBY = UNIT_FIELD_SUMMONEDBY+2,
UNIT_FIELD_TARGET = UNIT_FIELD_CREATEDBY+2,
UNIT_FIELD_PERSUADED = UNIT_FIELD_TARGET+2,
UNIT_FIELD_CHANNEL_OBJECT = UNIT_FIELD_PERSUADED+2,
UNIT_FIELD_HEALTH = UNIT_FIELD_CHANNEL_OBJECT+2,
UNIT_FIELD_POWER1,
UNIT_FIELD_POWER2,
UNIT_FIELD_POWER3,
UNIT_FIELD_POWER4,
UNIT_FIELD_POWER5,
UNIT_FIELD_MAXHEALTH,
UNIT_FIELD_MAXPOWER1,
UNIT_FIELD_MAXPOWER2,
UNIT_FIELD_MAXPOWER3,
UNIT_FIELD_MAXPOWER4,
UNIT_FIELD_MAXPOWER5,
UNIT_FIELD_LEVEL,
UNIT_FIELD_FACTIONTEMPLATE,
UNIT_FIELD_BYTES_0,
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY,
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_01, 
UNIT_VIRTUAL_ITEM_SLOT_DISPLAY_02, 
UNIT_VIRTUAL_ITEM_INFO = UNIT_VIRTUAL_ITEM_SLOT_DISPLAY+3,
UNIT_FIELD_FLAGS = UNIT_VIRTUAL_ITEM_INFO+6,
UNIT_FIELD_AURA,
UNIT_FIELD_AURAFLAGS = UNIT_FIELD_AURA + 64,
UNIT_FIELD_AURALEVELS = UNIT_FIELD_AURAFLAGS + 8,
UNIT_FIELD_AURAAPPLICATIONS = UNIT_FIELD_AURALEVELS + 8,
UNIT_FIELD_AURASTATE = UNIT_FIELD_AURAAPPLICATIONS + 16,
UNIT_FIELD_BASEATTACKTIME,
UNIT_FIELD_RANGEDATTACKTIME = UNIT_FIELD_BASEATTACKTIME+2,
UNIT_FIELD_BOUNDINGRADIUS,
UNIT_FIELD_COMBATREACH,
UNIT_FIELD_DISPLAYID,
UNIT_FIELD_NATIVEDISPLAYID,
UNIT_FIELD_MOUNTDISPLAYID,
UNIT_FIELD_MINDAMAGE,
UNIT_FIELD_MAXDAMAGE,
UNIT_FIELD_MINOFFHANDDAMAGE,
UNIT_FIELD_MAXOFFHANDDAMAGE,
UNIT_FIELD_BYTES_1,
UNIT_FIELD_PETNUMBER,
UNIT_FIELD_PET_NAME_TIMESTAMP,
UNIT_FIELD_PETEXPERIENCE,
UNIT_FIELD_PETNEXTLEVELEXP,
UNIT_DYNAMIC_FLAGS,
UNIT_CHANNEL_SPELL,
UNIT_MOD_CAST_SPEED,
UNIT_CREATED_BY_SPELL,
UNIT_NPC_FLAGS,
UNIT_NPC_EMOTESTATE,
UNIT_TRAINING_POINTS,

UNIT_FIELD_STAT0,
UNIT_FIELD_STR = UNIT_FIELD_STAT0,
UNIT_FIELD_STAT1,
UNIT_FIELD_AGILITY = UNIT_FIELD_STAT1,
UNIT_FIELD_STAT2,
UNIT_FIELD_STAMINA = UNIT_FIELD_STAT2,
UNIT_FIELD_STAT3,
UNIT_FIELD_SPIRIT = UNIT_FIELD_STAT3,
UNIT_FIELD_STAT4,
UNIT_FIELD_IQ = UNIT_FIELD_STAT4,
UNIT_FIELD_ARMOR = UNIT_FIELD_STAT4, 
UNIT_FIELD_RESISTANCES,
UNIT_FIELD_RESISTANCES_01,
UNIT_FIELD_RESISTANCES_02,
UNIT_FIELD_RESISTANCES_03,
UNIT_FIELD_RESISTANCES_04,
UNIT_FIELD_RESISTANCES_05,
UNIT_FIELD_RESISTANCES_06,
UNIT_FIELD_ATTACKPOWER = UNIT_FIELD_RESISTANCES+7,
UNIT_FIELD_BASE_MANA,
UNIT_FIELD_BASE_HEALTH,
UNIT_FIELD_ATTACK_POWER_MODS,
UNIT_FIELD_BYTES_2,
UNIT_FIELD_RANGEDATTACKPOWER,
UNIT_FIELD_RANGED_ATTACK_POWER_MODS,
UNIT_FIELD_MINRANGEDDAMAGE,
UNIT_FIELD_MAXRANGEDDAMAGE,
UNIT_FIELD_POWER_COST_MODIFIER,
UNIT_FIELD_POWER_COST_MULTIPLIER,
UNIT_FIELD_PADDING,
UNIT_END
};
#define PLAYER_VISIBLE_ITEM_SIZE 12
enum PlayerUpdateFields
{
PLAYER_SELECTION = UNIT_FIELD_PADDING+12+1,
PLAYER_DUEL_ARBITER = PLAYER_SELECTION+2,
PLAYER_FLAGS = PLAYER_DUEL_ARBITER+2,
PLAYER_GUILDID,
PLAYER_GUILDRANK,
PLAYER_BYTES,
PLAYER_BYTES_2,
PLAYER_BYTES_3,
PLAYER_DUEL_TEAM,
PLAYER_GUILD_TIMESTAMP,
PLAYER_QUEST_LOG_1_1,
PLAYER_QUEST_LOG_1_2,
PLAYER_QUEST_LOG_2_1 = PLAYER_QUEST_LOG_1_2+2,
PLAYER_QUEST_LOG_2_2,
PLAYER_QUEST_LOG_3_1 = PLAYER_QUEST_LOG_2_2+2,
PLAYER_QUEST_LOG_3_2,
PLAYER_QUEST_LOG_4_1 = PLAYER_QUEST_LOG_3_2+2,
PLAYER_QUEST_LOG_4_2,
PLAYER_QUEST_LOG_5_1 = PLAYER_QUEST_LOG_4_2+2,
PLAYER_QUEST_LOG_5_2,
PLAYER_QUEST_LOG_6_1 = PLAYER_QUEST_LOG_5_2+2,
PLAYER_QUEST_LOG_6_2,
PLAYER_QUEST_LOG_7_1 = PLAYER_QUEST_LOG_6_2+2,
PLAYER_QUEST_LOG_7_2,
PLAYER_QUEST_LOG_8_1 = PLAYER_QUEST_LOG_7_2+2,
PLAYER_QUEST_LOG_8_2,
PLAYER_QUEST_LOG_9_1 = PLAYER_QUEST_LOG_8_2+2,
PLAYER_QUEST_LOG_9_2,
PLAYER_QUEST_LOG_10_1 = PLAYER_QUEST_LOG_9_2+2,
PLAYER_QUEST_LOG_10_2,
PLAYER_QUEST_LOG_11_1 = PLAYER_QUEST_LOG_10_2+2,
PLAYER_QUEST_LOG_11_2,
PLAYER_QUEST_LOG_12_1 = PLAYER_QUEST_LOG_11_2+2,
PLAYER_QUEST_LOG_12_2,
PLAYER_QUEST_LOG_13_1 = PLAYER_QUEST_LOG_12_2+2,
PLAYER_QUEST_LOG_13_2,
PLAYER_QUEST_LOG_14_1 = PLAYER_QUEST_LOG_13_2+2,
PLAYER_QUEST_LOG_14_2,
PLAYER_QUEST_LOG_15_1 = PLAYER_QUEST_LOG_14_2+2,
PLAYER_QUEST_LOG_15_2,
PLAYER_QUEST_LOG_16_1 = PLAYER_QUEST_LOG_15_2+2,
PLAYER_QUEST_LOG_16_2,
PLAYER_QUEST_LOG_17_1 = PLAYER_QUEST_LOG_16_2+2,
PLAYER_QUEST_LOG_17_2,
PLAYER_QUEST_LOG_18_1 = PLAYER_QUEST_LOG_17_2+2,
PLAYER_QUEST_LOG_18_2,
PLAYER_QUEST_LOG_19_1 = PLAYER_QUEST_LOG_18_2+2,
PLAYER_QUEST_LOG_19_2,
PLAYER_QUEST_LOG_20_1 = PLAYER_QUEST_LOG_19_2+2,
PLAYER_QUEST_LOG_20_2,
PLAYER_VISIBLE_ITEM_1_CREATOR = PLAYER_QUEST_LOG_20_2+2,
PLAYER_VISIBLE_ITEM_1_0 = PLAYER_VISIBLE_ITEM_1_CREATOR+2,
PLAYER_VISIBLE_ITEM_1_PROPERTIES = PLAYER_VISIBLE_ITEM_1_0+8,
PLAYER_VISIBLE_ITEM_1_PAD,
PLAYER_VISIBLE_ITEM_2_CREATOR,
PLAYER_VISIBLE_ITEM_2_0 = PLAYER_VISIBLE_ITEM_2_CREATOR+2,
PLAYER_VISIBLE_ITEM_2_PROPERTIES = PLAYER_VISIBLE_ITEM_2_0+8,
PLAYER_VISIBLE_ITEM_2_PAD,
PLAYER_VISIBLE_ITEM_3_CREATOR,
PLAYER_VISIBLE_ITEM_3_0 = PLAYER_VISIBLE_ITEM_3_CREATOR+2,
PLAYER_VISIBLE_ITEM_3_PROPERTIES = PLAYER_VISIBLE_ITEM_3_0+8,
PLAYER_VISIBLE_ITEM_3_PAD,
PLAYER_VISIBLE_ITEM_4_CREATOR,
PLAYER_VISIBLE_ITEM_4_0 = PLAYER_VISIBLE_ITEM_4_CREATOR+2,
PLAYER_VISIBLE_ITEM_4_PROPERTIES = PLAYER_VISIBLE_ITEM_4_0+8,
PLAYER_VISIBLE_ITEM_4_PAD,
PLAYER_VISIBLE_ITEM_5_CREATOR,
PLAYER_VISIBLE_ITEM_5_0 = PLAYER_VISIBLE_ITEM_5_CREATOR+2,
PLAYER_VISIBLE_ITEM_5_PROPERTIES = PLAYER_VISIBLE_ITEM_5_0+8,
PLAYER_VISIBLE_ITEM_5_PAD,
PLAYER_VISIBLE_ITEM_6_CREATOR,
PLAYER_VISIBLE_ITEM_6_0 = PLAYER_VISIBLE_ITEM_6_CREATOR+2,
PLAYER_VISIBLE_ITEM_6_PROPERTIES = PLAYER_VISIBLE_ITEM_6_0+8,
PLAYER_VISIBLE_ITEM_6_PAD,
PLAYER_VISIBLE_ITEM_7_CREATOR,
PLAYER_VISIBLE_ITEM_7_0 = PLAYER_VISIBLE_ITEM_7_CREATOR+2,
PLAYER_VISIBLE_ITEM_7_PROPERTIES = PLAYER_VISIBLE_ITEM_7_0+8,
PLAYER_VISIBLE_ITEM_7_PAD,
PLAYER_VISIBLE_ITEM_8_CREATOR,
PLAYER_VISIBLE_ITEM_8_0 = PLAYER_VISIBLE_ITEM_8_CREATOR+2,
PLAYER_VISIBLE_ITEM_8_PROPERTIES = PLAYER_VISIBLE_ITEM_8_0+8,
PLAYER_VISIBLE_ITEM_8_PAD,
PLAYER_VISIBLE_ITEM_9_CREATOR,
PLAYER_VISIBLE_ITEM_9_0 = PLAYER_VISIBLE_ITEM_9_CREATOR+2,
PLAYER_VISIBLE_ITEM_9_PROPERTIES = PLAYER_VISIBLE_ITEM_9_0+8,
PLAYER_VISIBLE_ITEM_9_PAD,
PLAYER_VISIBLE_ITEM_10_CREATOR,
PLAYER_VISIBLE_ITEM_10_0 = PLAYER_VISIBLE_ITEM_10_CREATOR+2,
PLAYER_VISIBLE_ITEM_10_PROPERTIES = PLAYER_VISIBLE_ITEM_10_0+8,
PLAYER_VISIBLE_ITEM_10_PAD,
PLAYER_VISIBLE_ITEM_11_CREATOR,
PLAYER_VISIBLE_ITEM_11_0 = PLAYER_VISIBLE_ITEM_11_CREATOR+2,
PLAYER_VISIBLE_ITEM_11_PROPERTIES = PLAYER_VISIBLE_ITEM_11_0+8,
PLAYER_VISIBLE_ITEM_11_PAD,
PLAYER_VISIBLE_ITEM_12_CREATOR,
PLAYER_VISIBLE_ITEM_12_0 = PLAYER_VISIBLE_ITEM_12_CREATOR+2,
PLAYER_VISIBLE_ITEM_12_PROPERTIES = PLAYER_VISIBLE_ITEM_12_0+8,
PLAYER_VISIBLE_ITEM_12_PAD,
PLAYER_VISIBLE_ITEM_13_CREATOR,
PLAYER_VISIBLE_ITEM_13_0 = PLAYER_VISIBLE_ITEM_13_CREATOR+2,
PLAYER_VISIBLE_ITEM_13_PROPERTIES = PLAYER_VISIBLE_ITEM_13_0+8,
PLAYER_VISIBLE_ITEM_13_PAD,
PLAYER_VISIBLE_ITEM_14_CREATOR,
PLAYER_VISIBLE_ITEM_14_0 = PLAYER_VISIBLE_ITEM_14_CREATOR+2,
PLAYER_VISIBLE_ITEM_14_PROPERTIES = PLAYER_VISIBLE_ITEM_14_0+8,
PLAYER_VISIBLE_ITEM_14_PAD,
PLAYER_VISIBLE_ITEM_15_CREATOR,
PLAYER_VISIBLE_ITEM_15_0 = PLAYER_VISIBLE_ITEM_15_CREATOR+2,
PLAYER_VISIBLE_ITEM_15_PROPERTIES = PLAYER_VISIBLE_ITEM_15_0+8,
PLAYER_VISIBLE_ITEM_15_PAD,
PLAYER_VISIBLE_ITEM_16_CREATOR,
PLAYER_VISIBLE_ITEM_16_0 = PLAYER_VISIBLE_ITEM_16_CREATOR+2,
PLAYER_VISIBLE_ITEM_16_PROPERTIES = PLAYER_VISIBLE_ITEM_16_0+8,
PLAYER_VISIBLE_ITEM_16_PAD,
PLAYER_VISIBLE_ITEM_17_CREATOR,
PLAYER_VISIBLE_ITEM_17_0 = PLAYER_VISIBLE_ITEM_17_CREATOR+2,
PLAYER_VISIBLE_ITEM_17_PROPERTIES = PLAYER_VISIBLE_ITEM_17_0+8,
PLAYER_VISIBLE_ITEM_17_PAD,
PLAYER_VISIBLE_ITEM_18_CREATOR,
PLAYER_VISIBLE_ITEM_18_0 = PLAYER_VISIBLE_ITEM_18_CREATOR+2,
PLAYER_VISIBLE_ITEM_18_PROPERTIES = PLAYER_VISIBLE_ITEM_18_0+8,
PLAYER_VISIBLE_ITEM_18_PAD,
PLAYER_VISIBLE_ITEM_19_CREATOR,
PLAYER_VISIBLE_ITEM_19_0 = PLAYER_VISIBLE_ITEM_19_CREATOR+2,
PLAYER_VISIBLE_ITEM_19_PROPERTIES = PLAYER_VISIBLE_ITEM_19_0+8,
PLAYER_VISIBLE_ITEM_19_PAD,
PLAYER_FIELD_INV_SLOT_HEAD,
PLAYER_FIELD_PACK_SLOT_1 = PLAYER_FIELD_INV_SLOT_HEAD+46,
PLAYER_FIELD_BANK_SLOT_1 = PLAYER_FIELD_PACK_SLOT_1+32,
PLAYER_FIELD_BANKBAG_SLOT_1 = PLAYER_FIELD_BANK_SLOT_1+48,
PLAYER_FIELD_VENDORBUYBACK_SLOT = PLAYER_FIELD_BANKBAG_SLOT_1+12,
PLAYER_FARSIGHT = PLAYER_FIELD_VENDORBUYBACK_SLOT+2,
PLAYER__FIELD_COMBO_TARGET = PLAYER_FARSIGHT+2,
PLAYER_FIELD_BUYBACK_NPC = PLAYER__FIELD_COMBO_TARGET+2,
PLAYER_XP = PLAYER_FIELD_BUYBACK_NPC+2,
PLAYER_NEXT_LEVEL_XP,
PLAYER_SKILL_INFO_1_1,
PLAYER_SKILL_INFO_1_1_381  = PLAYER_SKILL_INFO_1_1+381, 
PLAYER_CHARACTER_POINTS1 = PLAYER_SKILL_INFO_1_1+384,
PLAYER_CHARACTER_POINTS2,
PLAYER_TRACK_CREATURES,
PLAYER_TRACK_RESOURCES,
PLAYER_BLOCK_PERCENTAGE,
PLAYER_DODGE_PERCENTAGE,
PLAYER_PARRY_PERCENTAGE,
PLAYER_CRIT_PERCENTAGE,
PLAYER_RANGED_CRIT_PERCENTAGE,
PLAYER_EXPLORED_ZONES_1,
PLAYER_REST_STATE_EXPERIENCE = PLAYER_EXPLORED_ZONES_1+64,
PLAYER_FIELD_COINAGE,
PLAYER_FIELD_POSSTAT0,
PLAYER_FIELD_POSSTAT1,
PLAYER_FIELD_POSSTAT2,
PLAYER_FIELD_POSSTAT3,
PLAYER_FIELD_POSSTAT4,
PLAYER_FIELD_NEGSTAT0,
PLAYER_FIELD_NEGSTAT1,
PLAYER_FIELD_NEGSTAT2,
PLAYER_FIELD_NEGSTAT3,
PLAYER_FIELD_NEGSTAT4,
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE,
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_01, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_02, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_03, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_04, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_05, 
PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE_06, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE = PLAYER_FIELD_RESISTANCEBUFFMODSPOSITIVE+7,
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_01, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_02, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_03, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_04, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_05, 
PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE_06, 
PLAYER_FIELD_MOD_DAMAGE_DONE_POS = PLAYER_FIELD_RESISTANCEBUFFMODSNEGATIVE+7,
PLAYER_FIELD_MOD_DAMAGE_DONE_NEG = PLAYER_FIELD_MOD_DAMAGE_DONE_POS+7,
PLAYER_FIELD_MOD_DAMAGE_DONE_PCT = PLAYER_FIELD_MOD_DAMAGE_DONE_NEG+7,
PLAYER_FIELD_BYTES = PLAYER_FIELD_MOD_DAMAGE_DONE_PCT+7,
PLAYER_AMMO_ID,
PLAYER_SELF_RES_SPELL,
PLAYER_FIELD_PVP_MEDALS,
PLAYER_FIELD_BUYBACK_ITEM_ID,
PLAYER_FIELD_BUYBACK_RANDOM_PROPERTIES_ID,
PLAYER_FIELD_BUYBACK_SEED,
PLAYER_FIELD_BUYBACK_PRICE,
PLAYER_FIELD_BUYBACK_DURABILITY,
PLAYER_FIELD_BUYBACK_COUNT,

PLAYER_FIELD_SESSION_KILLS,
PLAYER_FIELD_YESTERDAY_KILLS,
PLAYER_FIELD_LAST_WEEK_KILLS,
PLAYER_FIELD_THIS_WEEK_KILLS,
PLAYER_FIELD_THIS_WEEK_CONTRIBUTION,
PLAYER_FIELD_LIFETIME_HONORBALE_KILLS,
PLAYER_FIELD_LIFETIME_DISHONORBALE_KILLS,
PLAYER_FIELD_YESTERDAY_CONTRIBUTION,
PLAYER_FIELD_LAST_WEEK_CONTRIBUTION,
PLAYER_FIELD_LAST_WEEK_RANK,
PLAYER_FIELD_BYTES2,
PLAYER_FIELD_PADDING,
PLAYER_END
};
enum GameObjectUpdateFields
{






OBJECT_FIELD_CREATED_BY = OBJECT_FIELD_PADDING+1, 

GAMEOBJECT_DISPLAYID = OBJECT_FIELD_CREATED_BY+2,
GAMEOBJECT_FLAGS,
GAMEOBJECT_ROTATION,
GAMEOBJECT_STATE = GAMEOBJECT_ROTATION+4,
GAMEOBJECT_TIMESTAMP,
GAMEOBJECT_POS_X,
GAMEOBJECT_POS_Y,
GAMEOBJECT_POS_Z,
GAMEOBJECT_FACING,
GAMEOBJECT_DYN_FLAGS,
GAMEOBJECT_FACTION,
GAMEOBJECT_TYPE_ID,
GAMEOBJECT_LEVEL,
GAMEOBJECT_END
};
enum DynamicObjectUpdateFields
{






DYNAMICOBJECT_CASTER = OBJECT_FIELD_PADDING+1,
DYNAMICOBJECT_BYTES = DYNAMICOBJECT_CASTER+2,
DYNAMICOBJECT_SPELLID,
DYNAMICOBJECT_RADIUS,
DYNAMICOBJECT_POS_X,
DYNAMICOBJECT_POS_Y,
DYNAMICOBJECT_POS_Z,
DYNAMICOBJECT_FACING,
DYNAMICOBJECT_PAD,
DYNAMICOBJECT_END
};

enum CorpseUpdateFields
{






CORPSE_FIELD_OWNER = OBJECT_FIELD_PADDING+1,
CORPSE_FIELD_FACING = CORPSE_FIELD_OWNER+2,
CORPSE_FIELD_POS_X,
CORPSE_FIELD_POS_Y,
CORPSE_FIELD_POS_Z,
CORPSE_FIELD_DISPLAY_ID,
CORPSE_FIELD_ITEM,
CORPSE_FIELD_BYTES_1 = CORPSE_FIELD_ITEM+19,
CORPSE_FIELD_BYTES_2,
CORPSE_FIELD_GUILD,
CORPSE_FIELD_FLAGS,
CORPSE_FIELD_DYNAMIC_FLAGS,
CORPSE_FIELD_PAD,
CORPSE_END
};


#endif 
