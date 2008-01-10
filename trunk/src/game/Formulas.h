/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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

#ifndef MANGOS_FORMULAS_H
#define MANGOS_FORMULAS_H

#include "World.h"

namespace MaNGOS
{
    namespace XP
    {
        typedef enum XPColorChar { RED, ORANGE, YELLOW, GREEN, GRAY };

        inline uint32 GetGrayLevel(uint32 pl_level)
        {
            if( pl_level <= 5 )
                return 0;
            else if( pl_level <= 39 )
                return pl_level - 5 - pl_level/10;
            else if( pl_level <= 59 )
                return pl_level - 1 - pl_level/5;
            else
                return pl_level - 9;
        }

        inline XPColorChar GetColorCode(uint32 pl_level, uint32 mob_level)
        {
            if( mob_level >= pl_level + 5 )
                return RED;
            else if( mob_level >= pl_level + 3 )
                return ORANGE;
            else if( mob_level >= pl_level - 2 )
                return YELLOW;
            else if( mob_level > GetGrayLevel(pl_level) )
                return GREEN;
            else
                return GRAY;
        }

        inline uint32 GetZeroDifference(uint32 pl_level)
        {
            if( pl_level < 8 )  return 5;
            if( pl_level < 10 ) return 6;
            if( pl_level < 12 ) return 7;
            if( pl_level < 16 ) return 8;
            if( pl_level < 20 ) return 9;
            if( pl_level < 30 ) return 11;
            if( pl_level < 40 ) return 12;
            if( pl_level < 45 ) return 13;
            if( pl_level < 50 ) return 14;
            if( pl_level < 55 ) return 15;
            if( pl_level < 60 ) return 16;
            return 17;
        }

        inline uint32 BaseGain(uint32 pl_level, uint32 mob_level)
        {
            if( mob_level >= pl_level )
                return ((pl_level*5 + 45) * (20 + mob_level - pl_level)/10 + 1)/2;
            else
            {
                uint32 gray_level = GetGrayLevel(pl_level);
                if( mob_level > gray_level )
                {
                    uint32 ZD = GetZeroDifference(pl_level);
                    return (pl_level*5 + 45) * (ZD + mob_level - pl_level)/ZD;
                }
                return 0;
            }
        }

        inline uint32 Gain(Player *pl, Unit *u)
        {
            if(u->GetTypeId()==TYPEID_UNIT && ((Creature*)u)->isTotem() || ((Creature*)u)->isPet())
                return 0;

            uint32 xp_gain= BaseGain(pl->getLevel(), u->getLevel());
            if( xp_gain == 0 )
                return 0;

            if(u->GetTypeId()==TYPEID_UNIT && ((Creature*)u)->isElite())
                xp_gain *= 2;

            return (uint32)(xp_gain*sWorld.getRate(RATE_XP_KILL));
        }

        inline uint32 xp_Diff(uint32 lvl)
        {
            if( lvl < 29 )
                return 0;
            if( lvl == 29 )
                return 1;
            if( lvl == 30 )
                return 3;
            if( lvl == 32 )
                return 6;
            else
                return (5*(lvl-30));
        }

        inline uint32 mxp(uint32 lvl)
        {
            if (lvl < 60)
            {
                return (45 + (5*lvl));
            }
            else
            {
                return (235 + (5*lvl));
            }
        }

        inline uint32 xp_to_level(uint32 lvl)
        {
            uint32 xp = 0;
            if (lvl < 60)
            {
                xp = (8*lvl + xp_Diff(lvl)) * mxp(lvl);
            }
            else if (lvl == 60)
            {
                xp = (155 + mxp(lvl) * (1344 - 69 - ((69 - lvl) * (7 + (69 - lvl) * 8 - 1)/2)));
            }
            else
            {
                xp = (155 + mxp(lvl) * (1344 - ((69-lvl) * (7 + (69 - lvl) * 8 - 1)/2)));
            }
            // The XP to Level is always rounded to the nearest 100 points (50 rounded to low).
            return ((xp + 49) / 100) * 100;                 // use additional () for prevent free association operations in C++
        }

        inline float xp_in_group_rate(uint32 count, bool isRaid)
        {
            if(isRaid)
            {
                // FIX ME: must apply decrease modifiers dependent from raid size
                return 1.0f;
            }
            else
            {
                switch(count)
                {
                    case 0:
                    case 1:
                    case 2:
                        return 1.0f;
                    case 3:
                        return 1.166f;
                    case 4:
                        return 1.3f;
                    case 5:
                    default:
                        return 1.4f;
                }
            }
        }
    }
}
#endif
