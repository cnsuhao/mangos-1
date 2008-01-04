-- MySQL dump 10.11
--
-- Host: localhost    Database: characters
-- ------------------------------------------------------
-- Server version	5.0.45-community-nt


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Definition of table `arena_team`
--

DROP TABLE IF EXISTS `arena_team`;
CREATE TABLE `arena_team` (
  `arenateamid` int(10) unsigned NOT NULL default '0',
  `name` char(255) NOT NULL,
  `captainguid` int(10) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `EmblemStyle` int(10) unsigned NOT NULL default '0',
  `EmblemColor` int(10) unsigned NOT NULL default '0',
  `BorderStyle` int(10) unsigned NOT NULL default '0',
  `BorderColor` int(10) unsigned NOT NULL default '0',
  `BackgroundColor` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`arenateamid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `arena_team`
--

/*!40000 ALTER TABLE `arena_team` DISABLE KEYS */;
/*!40000 ALTER TABLE `arena_team` ENABLE KEYS */;


--
-- Definition of table `arena_team_member`
--

DROP TABLE IF EXISTS `arena_team_member`;
CREATE TABLE `arena_team_member` (
  `arenateamid` int(10) unsigned NOT NULL default '0',
  `guid` int(10) unsigned NOT NULL default '0',
  `played_week` int(10) unsigned NOT NULL default '0',
  `wons_week` int(10) unsigned NOT NULL default '0',
  `played_season` int(10) unsigned NOT NULL default '0',
  `wons_season` int(10) unsigned NOT NULL default '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `arena_team_member`
--

/*!40000 ALTER TABLE `arena_team_member` DISABLE KEYS */;
/*!40000 ALTER TABLE `arena_team_member` ENABLE KEYS */;


--
-- Definition of table `arena_team_stats`
--

DROP TABLE IF EXISTS `arena_team_stats`;
CREATE TABLE `arena_team_stats` (
  `arenateamid` int(10) unsigned NOT NULL default '0',
  `rating` int(10) unsigned NOT NULL default '0',
  `games` int(10) unsigned NOT NULL default '0',
  `wins` int(10) unsigned NOT NULL default '0',
  `played` int(10) unsigned NOT NULL default '0',
  `wins2` int(10) unsigned NOT NULL default '0',
  `rank` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`arenateamid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `arena_team_stats`
--

/*!40000 ALTER TABLE `arena_team_stats` DISABLE KEYS */;
/*!40000 ALTER TABLE `arena_team_stats` ENABLE KEYS */;


--
-- Definition of table `auctionhouse`
--

DROP TABLE IF EXISTS `auctionhouse`;
CREATE TABLE `auctionhouse` (
  `id` int(11) unsigned NOT NULL default '0',
  `auctioneerguid` int(11) unsigned NOT NULL default '0',
  `itemguid` int(11) unsigned NOT NULL default '0',
  `item_template` int(11) unsigned NOT NULL default '0' COMMENT 'Item Identifier',
  `itemowner` int(11) unsigned NOT NULL default '0',
  `buyoutprice` int(11) NOT NULL default '0',
  `time` bigint(40) NOT NULL default '0',
  `buyguid` int(11) unsigned NOT NULL default '0',
  `lastbid` int(11) NOT NULL default '0',
  `startbid` int(11) NOT NULL default '0',
  `deposit` int(11) NOT NULL default '0',
  `location` tinyint(3) unsigned NOT NULL default '3',
  PRIMARY KEY  (`id`),
  UNIQUE KEY `item_guid` (`itemguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `auctionhouse`
--

/*!40000 ALTER TABLE `auctionhouse` DISABLE KEYS */;
/*!40000 ALTER TABLE `auctionhouse` ENABLE KEYS */;


--
-- Definition of table `bugreport`
--

DROP TABLE IF EXISTS `bugreport`;
CREATE TABLE `bugreport` (
  `id` int(11) NOT NULL auto_increment COMMENT 'Identifier',
  `type` varchar(255) NOT NULL default '',
  `content` varchar(255) NOT NULL default '',
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Debug System';

--
-- Dumping data for table `bugreport`
--

/*!40000 ALTER TABLE `bugreport` DISABLE KEYS */;
/*!40000 ALTER TABLE `bugreport` ENABLE KEYS */;


--
-- Definition of table `character`
--

DROP TABLE IF EXISTS `character`;
CREATE TABLE `character` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `account` int(11) unsigned NOT NULL default '0' COMMENT 'Account Identifier',
  `data` longtext,
  `name` varchar(12) NOT NULL default '',
  `race` tinyint(3) unsigned NOT NULL default '0',
  `class` tinyint(3) unsigned NOT NULL default '0',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `map` int(11) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  `orientation` float NOT NULL default '0',
  `taximask` longtext,
  `online` tinyint(3) unsigned NOT NULL default '0',
  `cinematic` tinyint(3) unsigned NOT NULL default '0',
  `totaltime` int(11) unsigned NOT NULL default '0',
  `leveltime` int(11) unsigned NOT NULL default '0',
  `logout_time` int(11) unsigned NOT NULL default '0',
  `is_logout_resting` tinyint(3) unsigned NOT NULL default '0',
  `rest_bonus` float NOT NULL default '0',
  `resettalents_cost` int(11) unsigned NOT NULL default '0',
  `resettalents_time` bigint(20) unsigned NOT NULL default '0',
  `trans_x` float NOT NULL default '0',
  `trans_y` float NOT NULL default '0',
  `trans_z` float NOT NULL default '0',
  `trans_o` float NOT NULL default '0',
  `transguid` bigint(20) unsigned NOT NULL default '0',
  `gmstate` tinyint(3) unsigned NOT NULL default '0',
  `stable_slots` tinyint(1) unsigned NOT NULL default '0',
  `at_login` int(11) unsigned NOT NULL default '0',
  `zone` int(11) unsigned NOT NULL default '0',
  `last_honor_date` int(11) unsigned NOT NULL default '0',
  `pending_honor` float NOT NULL default '0',
  `last_kill_date` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`),
  KEY `idx_account` (`account`),
  KEY `idx_online` (`online`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character`
--

/*!40000 ALTER TABLE `character` DISABLE KEYS */;
/*!40000 ALTER TABLE `character` ENABLE KEYS */;


--
-- Definition of table `character_action`
--

DROP TABLE IF EXISTS `character_action`;
CREATE TABLE `character_action` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `button` tinyint(3) unsigned NOT NULL default '0',
  `action` smallint(5) unsigned NOT NULL default '0',
  `type` tinyint(3) unsigned NOT NULL default '0',
  `misc` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`button`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_action`
--

/*!40000 ALTER TABLE `character_action` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_action` ENABLE KEYS */;


--
-- Definition of table `character_aura`
--

DROP TABLE IF EXISTS `character_aura`;
CREATE TABLE `character_aura` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `caster_guid` bigint(20) unsigned NOT NULL default '0' COMMENT 'Full Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0',
  `effect_index` int(11) unsigned NOT NULL default '0',
  `amount` int(11) NOT NULL default '0',
  `maxduration` int(11) NOT NULL default '0',
  `remaintime` int(11) NOT NULL default '0',
  `remaincharges` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`,`effect_index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_aura`
--

/*!40000 ALTER TABLE `character_aura` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_aura` ENABLE KEYS */;


--
-- Definition of table `character_gifts`
--

DROP TABLE IF EXISTS `character_gifts`;
CREATE TABLE `character_gifts` (
  `guid` int(20) unsigned NOT NULL default '0',
  `item_guid` int(11) unsigned NOT NULL default '0',
  `entry` int(20) unsigned NOT NULL default '0',
  `flags` int(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`item_guid`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `character_gifts`
--

/*!40000 ALTER TABLE `character_gifts` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_gifts` ENABLE KEYS */;


--
-- Definition of table `character_homebind`
--

DROP TABLE IF EXISTS `character_homebind`;
CREATE TABLE `character_homebind` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `map` int(11) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  `zone` int(11) unsigned NOT NULL default '0' COMMENT 'Zone Identifier',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_homebind`
--

/*!40000 ALTER TABLE `character_homebind` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_homebind` ENABLE KEYS */;


--
-- Definition of table `character_instance`
--

DROP TABLE IF EXISTS `character_instance`;
CREATE TABLE `character_instance` (
  `guid` int(11) unsigned NOT NULL default '0',
  `map` int(11) unsigned NOT NULL default '0',
  `instance` bigint(40) NOT NULL default '0',
  `leader` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`map`),
  KEY `instance` (`instance`),
  KEY `leader` (`leader`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `character_instance`
--

/*!40000 ALTER TABLE `character_instance` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_instance` ENABLE KEYS */;


--
-- Definition of table `character_inventory`
--

DROP TABLE IF EXISTS `character_inventory`;
CREATE TABLE `character_inventory` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `bag` int(11) unsigned NOT NULL default '0',
  `slot` tinyint(3) unsigned NOT NULL default '0',
  `item` int(11) unsigned NOT NULL default '0' COMMENT 'Item Global Unique Identifier',
  `item_template` int(11) unsigned NOT NULL default '0' COMMENT 'Item Identifier',
  PRIMARY KEY  (`item`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_inventory`
--

/*!40000 ALTER TABLE `character_inventory` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_inventory` ENABLE KEYS */;


--
-- Definition of table `character_kill`
--

DROP TABLE IF EXISTS `character_kill`;
CREATE TABLE `character_kill` (
  `guid` int(11) unsigned NOT NULL default '0',
  `victim_guid` int(11) unsigned NOT NULL default '0',
  `count` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`victim_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Kills Yesterday';

--
-- Dumping data for table `character_kill`
--

/*!40000 ALTER TABLE `character_kill` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_kill` ENABLE KEYS */;


--
-- Definition of table `character_pet`
--

DROP TABLE IF EXISTS `character_pet`;
CREATE TABLE `character_pet` (
  `id` int(11) unsigned NOT NULL default '0',
  `entry` int(11) unsigned NOT NULL default '0',
  `owner` int(11) unsigned NOT NULL default '0',
  `modelid` int(11) unsigned default '0',
  `CreatedBySpell` int(11) unsigned NOT NULL default '0',
  `PetType` tinyint(3) unsigned NOT NULL default '0',
  `level` int(11) unsigned NOT NULL default '1',
  `exp` int(11) unsigned NOT NULL default '0',
  `nextlvlexp` int(11) unsigned NOT NULL default '100',
  `Reactstate` tinyint(1) unsigned NOT NULL default '0',
  `Commandstate` tinyint(1) unsigned NOT NULL default '1',
  `loyaltypoints` int(11) NOT NULL default '0',
  `loyalty` int(11) unsigned NOT NULL default '0',
  `trainpoint` int(11) NOT NULL default '0',
  `name` varchar(100) default 'Pet',
  `renamed` tinyint(1) unsigned NOT NULL default '0',
  `slot` int(11) unsigned NOT NULL default '0',
  `curhealth` int(11) unsigned NOT NULL default '1',
  `curmana` int(11) unsigned NOT NULL default '0',
  `curhappiness` int(11) unsigned NOT NULL default '0',
  `savetime` bigint(20) unsigned NOT NULL default '0',
  `resettalents_cost` int(11) unsigned NOT NULL default '0',
  `resettalents_time` bigint(20) unsigned NOT NULL default '0',
  `ABData` longtext,
  `TeachSpelldata` longtext,
  PRIMARY KEY  (`id`),
  KEY `owner` (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

--
-- Dumping data for table `character_pet`
--

/*!40000 ALTER TABLE `character_pet` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_pet` ENABLE KEYS */;


--
-- Definition of table `character_queststatus`
--

DROP TABLE IF EXISTS `character_queststatus`;
CREATE TABLE `character_queststatus` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `quest` int(11) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  `status` int(11) unsigned NOT NULL default '0',
  `rewarded` tinyint(1) unsigned NOT NULL default '0',
  `explored` tinyint(1) unsigned NOT NULL default '0',
  `timer` bigint(20) unsigned NOT NULL default '0',
  `mobcount1` int(11) unsigned NOT NULL default '0',
  `mobcount2` int(11) unsigned NOT NULL default '0',
  `mobcount3` int(11) unsigned NOT NULL default '0',
  `mobcount4` int(11) unsigned NOT NULL default '0',
  `itemcount1` int(11) unsigned NOT NULL default '0',
  `itemcount2` int(11) unsigned NOT NULL default '0',
  `itemcount3` int(11) unsigned NOT NULL default '0',
  `itemcount4` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_queststatus`
--

/*!40000 ALTER TABLE `character_queststatus` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_queststatus` ENABLE KEYS */;


--
-- Definition of table `character_queststatus_daily`
--

DROP TABLE IF EXISTS `character_queststatus_daily`;
CREATE TABLE `character_queststatus_daily` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `quest` int(11) unsigned NOT NULL default '0' COMMENT 'Quest Identifier',
  `time` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_queststatus_daily`
--

/*!40000 ALTER TABLE `character_queststatus_daily` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_queststatus_daily` ENABLE KEYS */;


--
-- Definition of table `character_reputation`
--

DROP TABLE IF EXISTS `character_reputation`;
CREATE TABLE `character_reputation` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `faction` int(11) unsigned NOT NULL default '0',
  `standing` int(11) NOT NULL default '0',
  `flags` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`,`faction`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_reputation`
--

/*!40000 ALTER TABLE `character_reputation` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_reputation` ENABLE KEYS */;


--
-- Definition of table `character_social`
--

DROP TABLE IF EXISTS `character_social`;
CREATE TABLE `character_social` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `name` varchar(21) NOT NULL default '',
  `friend` int(11) unsigned NOT NULL default '0' COMMENT 'Character Global Unique Identifier',
  `flags` tinyint(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`friend`,`flags`),
  KEY (`guid`),
  KEY (`friend`),
  KEY `guid_flags` (`guid`,`flags`),
  KEY `friend_flags` (`friend`,`flags`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_social`
--

/*!40000 ALTER TABLE `character_social` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_social` ENABLE KEYS */;


--
-- Definition of table `character_spell`
--

DROP TABLE IF EXISTS `character_spell`;
CREATE TABLE `character_spell` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `slot` int(11) unsigned NOT NULL default '0',
  `active` tinyint(3) unsigned NOT NULL default '1',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_spell`
--

/*!40000 ALTER TABLE `character_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_spell` ENABLE KEYS */;


--
-- Definition of table `character_spell_cooldown`
--

DROP TABLE IF EXISTS `character_spell_cooldown`;
CREATE TABLE `character_spell_cooldown` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `item` int(11) unsigned NOT NULL default '0' COMMENT 'Item Identifier',
  `time` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `character_spell_cooldown`
--

/*!40000 ALTER TABLE `character_spell_cooldown` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_spell_cooldown` ENABLE KEYS */;


--
-- Definition of table `character_ticket`
--

DROP TABLE IF EXISTS `character_ticket`;
CREATE TABLE `character_ticket` (
  `ticket_id` int(11) unsigned NOT NULL auto_increment,
  `guid` int(11) unsigned NOT NULL default '0',
  `ticket_text` text,
  `ticket_category` int(1) NOT NULL default '0',
  PRIMARY KEY  (`ticket_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_ticket`
--

/*!40000 ALTER TABLE `character_ticket` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_ticket` ENABLE KEYS */;


--
-- Definition of table `character_tutorial`
--

DROP TABLE IF EXISTS `character_tutorial`;
CREATE TABLE `character_tutorial` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `tut0` int(11) unsigned NOT NULL default '0',
  `tut1` int(11) unsigned NOT NULL default '0',
  `tut2` int(11) unsigned NOT NULL default '0',
  `tut3` int(11) unsigned NOT NULL default '0',
  `tut4` int(11) unsigned NOT NULL default '0',
  `tut5` int(11) unsigned NOT NULL default '0',
  `tut6` int(11) unsigned NOT NULL default '0',
  `tut7` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Player System';

--
-- Dumping data for table `character_tutorial`
--

/*!40000 ALTER TABLE `character_tutorial` DISABLE KEYS */;
/*!40000 ALTER TABLE `character_tutorial` ENABLE KEYS */;


--
-- Definition of table `corpse`
--

DROP TABLE IF EXISTS `corpse`;
CREATE TABLE `corpse` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `player` int(11) unsigned NOT NULL default '0' COMMENT 'Character Global Unique Identifier',
  `position_x` float NOT NULL default '0',
  `position_y` float NOT NULL default '0',
  `position_z` float NOT NULL default '0',
  `orientation` float NOT NULL default '0',
  `zone` int(11) unsigned NOT NULL default '38' COMMENT 'Zone Identifier',
  `map` int(11) unsigned NOT NULL default '0' COMMENT 'Map Identifier',
  `data` longtext,
  `time` timestamp NOT NULL default '0000-00-00 00:00:00',
  `bones_flag` tinyint(3) NOT NULL default '0',
  `instance` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`),
  KEY `idx_bones_flag` (`bones_flag`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Death System';

--
-- Dumping data for table `corpse`
--

/*!40000 ALTER TABLE `corpse` DISABLE KEYS */;
/*!40000 ALTER TABLE `corpse` ENABLE KEYS */;


--
-- Definition of table `group`
--

DROP TABLE IF EXISTS `group`;
CREATE TABLE `group` (
  `leaderGuid` int(11) unsigned NOT NULL,
  `mainTank` int(11) unsigned NOT NULL,
  `mainAssistant` int(11) unsigned NOT NULL,
  `lootMethod` tinyint(4) unsigned NOT NULL,
  `looterGuid` int(11) unsigned NOT NULL,
  `lootThreshold` tinyint(4) unsigned NOT NULL,
  `icon1` int(11) unsigned NOT NULL,
  `icon2` int(11) unsigned NOT NULL,
  `icon3` int(11) unsigned NOT NULL,
  `icon4` int(11) unsigned NOT NULL,
  `icon5` int(11) unsigned NOT NULL,
  `icon6` int(11) unsigned NOT NULL,
  `icon7` int(11) unsigned NOT NULL,
  `icon8` int(11) unsigned NOT NULL,
  `isRaid` tinyint(1) unsigned NOT NULL,
  PRIMARY KEY  (`leaderGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Groups';

--
-- Dumping data for table `group`
--

/*!40000 ALTER TABLE `group` DISABLE KEYS */;
/*!40000 ALTER TABLE `group` ENABLE KEYS */;


--
-- Definition of table `group_member`
--

DROP TABLE IF EXISTS `group_member`;
CREATE TABLE `group_member` (
  `leaderGuid` int(11) unsigned NOT NULL,
  `memberGuid` int(11) unsigned NOT NULL,
  `assistant` tinyint(1) unsigned NOT NULL,
  `subgroup` smallint(6) unsigned NOT NULL,
  PRIMARY KEY  (`leaderGuid`,`memberGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Groups';

--
-- Dumping data for table `group_member`
--

/*!40000 ALTER TABLE `group_member` DISABLE KEYS */;
/*!40000 ALTER TABLE `group_member` ENABLE KEYS */;


--
-- Definition of table `guild`
--

DROP TABLE IF EXISTS `guild`;
CREATE TABLE `guild` (
  `guildid` int(6) unsigned NOT NULL default '0',
  `name` varchar(255) NOT NULL default '',
  `leaderguid` int(6) unsigned NOT NULL default '0',
  `EmblemStyle` int(5) NOT NULL default '0',
  `EmblemColor` int(5) NOT NULL default '0',
  `BorderStyle` int(5) NOT NULL default '0',
  `BorderColor` int(5) NOT NULL default '0',
  `BackgroundColor` int(5) NOT NULL default '0',
  `info` text NOT NULL,
  `MOTD` varchar(255) NOT NULL default '',
  `createdate` datetime default NULL,
  PRIMARY KEY  (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';

--
-- Dumping data for table `guild`
--

/*!40000 ALTER TABLE `guild` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild` ENABLE KEYS */;


--
-- Definition of table `guild_member`
--

DROP TABLE IF EXISTS `guild_member`;
CREATE TABLE `guild_member` (
  `guildid` int(6) unsigned NOT NULL default '0',
  `guid` int(11) unsigned NOT NULL default '0',
  `rank` tinyint(2) unsigned NOT NULL default '0',
  `Pnote` varchar(255) NOT NULL default '',
  `OFFnote` varchar(255) NOT NULL default ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Guild System';

--
-- Dumping data for table `guild_member`
--

/*!40000 ALTER TABLE `guild_member` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_member` ENABLE KEYS */;


--
-- Definition of table `guild_rank`
--

DROP TABLE IF EXISTS `guild_rank`;
CREATE TABLE `guild_rank` (
  `guildid` int(6) unsigned NOT NULL default '0',
  `rid` int(11) unsigned NOT NULL,
  `rname` varchar(255) NOT NULL default '',
  `rights` int(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guildid`,`rid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';

--
-- Dumping data for table `guild_rank`
--

/*!40000 ALTER TABLE `guild_rank` DISABLE KEYS */;
/*!40000 ALTER TABLE `guild_rank` ENABLE KEYS */;


--
-- Definition of table `instance`
--

DROP TABLE IF EXISTS `instance`;
CREATE TABLE `instance` (
  `id` int(11) unsigned NOT NULL default '0',
  `map` int(11) unsigned NOT NULL default '0',
  `resettime` bigint(40) NOT NULL default '0',
  `data` longtext,
  PRIMARY KEY  (`id`),
  KEY `map` (`map`),
  KEY `resettime` (`resettime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `instance`
--

/*!40000 ALTER TABLE `instance` DISABLE KEYS */;
/*!40000 ALTER TABLE `instance` ENABLE KEYS */;


--
-- Definition of table `item_instance`
--

DROP TABLE IF EXISTS `item_instance`;
CREATE TABLE `item_instance` (
  `guid` int(11) unsigned NOT NULL default '0',
  `owner_guid` int(11) unsigned NOT NULL default '0',
  `data` longtext,
  PRIMARY KEY  (`guid`),
  KEY `idx_owner_guid` (`owner_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Item System';

--
-- Dumping data for table `item_instance`
--

/*!40000 ALTER TABLE `item_instance` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_instance` ENABLE KEYS */;


--
-- Definition of table `item_text`
--

DROP TABLE IF EXISTS `item_text`;
CREATE TABLE `item_text` (
  `id` int(11) unsigned NOT NULL default '0',
  `text` longtext,
  PRIMARY KEY  (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Item System';

--
-- Dumping data for table `item_text`
--

/*!40000 ALTER TABLE `item_text` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_text` ENABLE KEYS */;


--
-- Definition of table `mail`
--

DROP TABLE IF EXISTS `mail`;
CREATE TABLE `mail` (
  `id` int(11) unsigned NOT NULL default '0' COMMENT 'Identifier',
  `messageType` tinyint(3) unsigned NOT NULL default '0',
  `stationery` tinyint(3) NOT NULL default '41',
  `sender` int(11) unsigned NOT NULL default '0' COMMENT 'Character Global Unique Identifier',
  `receiver` int(11) unsigned NOT NULL default '0' COMMENT 'Character Global Unique Identifier',
  `subject` longtext,
  `itemTextId` int(11) unsigned NOT NULL default '0',
  `has_items` tinyint(3) unsigned NOT NULL default '0',
  `expire_time` bigint(40) NOT NULL default '0',
  `deliver_time` bigint(40) NOT NULL default '0',
  `money` int(11) unsigned NOT NULL default '0',
  `cod` int(11) unsigned NOT NULL default '0',
  `checked` tinyint(3) unsigned NOT NULL default '0',
  PRIMARY KEY  (`id`),
  KEY `idx_receiver` (`receiver`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Mail System';

--
-- Dumping data for table `mail`
--

/*!40000 ALTER TABLE `mail` DISABLE KEYS */;
/*!40000 ALTER TABLE `mail` ENABLE KEYS */;

--
-- Definition of table `mail_items`
--

DROP TABLE IF EXISTS `mail_items`;
CREATE TABLE `mail_items` (
  `mail_id` int(11) NOT NULL default '0',
  `item_guid` int(11) NOT NULL default '0',
  `item_template` int(11) NOT NULL default '0',
  PRIMARY KEY  (`mail_id`,`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

--
-- Dumping data for table `mail_items`
--

/*!40000 ALTER TABLE `mail_items` DISABLE KEYS */;
/*!40000 ALTER TABLE `mail_items` ENABLE KEYS */;

--
-- Definition of table `pet_aura`
--

DROP TABLE IF EXISTS `pet_aura`;
CREATE TABLE `pet_aura` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `caster_guid` bigint(20) unsigned NOT NULL default '0' COMMENT 'Full Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0',
  `effect_index` int(11) unsigned NOT NULL default '0',
  `amount` int(11) NOT NULL default '0',
  `maxduration` int(11) NOT NULL default '0',
  `remaintime` int(11) NOT NULL default '0',
  `remaincharges` int(11) NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`,`effect_index`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

--
-- Dumping data for table `pet_aura`
--

/*!40000 ALTER TABLE `pet_aura` DISABLE KEYS */;
/*!40000 ALTER TABLE `pet_aura` ENABLE KEYS */;


--
-- Definition of table `pet_spell`
--

DROP TABLE IF EXISTS `pet_spell`;
CREATE TABLE `pet_spell` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `slot` int(11) unsigned NOT NULL default '0',
  `active` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Pet System';

--
-- Dumping data for table `pet_spell`
--

/*!40000 ALTER TABLE `pet_spell` DISABLE KEYS */;
/*!40000 ALTER TABLE `pet_spell` ENABLE KEYS */;


--
-- Definition of table `pet_spell_cooldown`
--

DROP TABLE IF EXISTS `pet_spell_cooldown`;
CREATE TABLE `pet_spell_cooldown` (
  `guid` int(11) unsigned NOT NULL default '0' COMMENT 'Global Unique Identifier, Low part',
  `spell` int(11) unsigned NOT NULL default '0' COMMENT 'Spell Identifier',
  `time` bigint(20) unsigned NOT NULL default '0',
  PRIMARY KEY  (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `pet_spell_cooldown`
--

/*!40000 ALTER TABLE `pet_spell_cooldown` DISABLE KEYS */;
/*!40000 ALTER TABLE `pet_spell_cooldown` ENABLE KEYS */;


--
-- Definition of table `petition`
--

DROP TABLE IF EXISTS `petition`;
CREATE TABLE `petition` (
  `ownerguid` int(10) unsigned NOT NULL,
  `petitionguid` int(10) unsigned default '0',
  `name` varchar(255) NOT NULL default '',
  `type` int(10) unsigned NOT NULL default '0',
  PRIMARY KEY  (`ownerguid`),
  UNIQUE KEY `index_ownerguid_petitionguid` (`ownerguid`,`petitionguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';

--
-- Dumping data for table `petition`
--

/*!40000 ALTER TABLE `petition` DISABLE KEYS */;
/*!40000 ALTER TABLE `petition` ENABLE KEYS */;


--
-- Definition of table `petition_sign`
--

DROP TABLE IF EXISTS `petition_sign`;
CREATE TABLE `petition_sign` (
  `ownerguid` int(10) unsigned NOT NULL,
  `petitionguid` int(11) unsigned NOT NULL default '0',
  `playerguid` int(11) unsigned NOT NULL default '0',
  `player_account` int(11) unsigned NOT NULL default '0',
  PRIMARY KEY  (`petitionguid`,`playerguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Guild System';

--
-- Dumping data for table `petition_sign`
--

/*!40000 ALTER TABLE `petition_sign` DISABLE KEYS */;
/*!40000 ALTER TABLE `petition_sign` ENABLE KEYS */;



/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
