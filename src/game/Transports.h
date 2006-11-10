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

#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"

class Transport : public GameObject {
public:
    bool Create(uint32 guidlow, uint32 displayId, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress);
    void GenerateWaypoints(uint32 pathid);
    void Update(uint32 p_time);
    bool AddPassenger(Player* passenger);
    bool RemovePassenger(Player* passenger);
    string m_name;

private:
    struct WayPoint {
        WayPoint() : mapid(0), x(0), y(0), z(0), teleport(0) {}
        WayPoint(float _mapid, float _x, float _y, float _z, bool _teleport) : 
                mapid(_mapid), x(_x), y(_y), z(_z), teleport(_teleport) {}
        uint32 mapid;
        float x;
        float y;
        float z;
        float o;
        bool teleport;
    };

    map<uint32, WayPoint>::iterator m_curr;
    map<uint32, WayPoint>::iterator m_next;
    uint32 m_pathTime;
    uint32 m_timer;

    uint32 m_curMap;

    void TeleportTransport(uint32 oldMapid, uint32 newMapid, float x, float y, float z);

    set< Player * > m_passengers;

public:
    map< uint32, WayPoint> m_WayPoints;
    uint32 m_lastMovement;
    uint32 m_nextNodeTime;
    uint32 m_period;

private:
    map<uint32, WayPoint>::iterator GetNextWayPoint();
};

#endif
