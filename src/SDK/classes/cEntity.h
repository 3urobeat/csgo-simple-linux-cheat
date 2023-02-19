/*
 * File: cEntity.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 16.02.2023 21:41:39
 * Author: 3urobeat
 * 
 * Last Modified: 19.02.2023 21:04:19
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


#include "../interfaces/files/ivModelRenderer.h"
#include "../netvarManager.h"
#include "../helpers/vector.h"


class ICollideable {
    public:
        virtual void pad0();
        virtual const Vector& OBBMins() const;
        virtual const Vector& OBBMaxs() const;
};


class CEntity {
    public:
        // Note because I might be stupid: This works, don't change it
        virtual void *networkable() = 0;
        virtual void *renderable() = 0;
        virtual ClientClass *clientClass() = 0;
        virtual bool dormant() = 0;
        virtual int index() = 0;
        virtual model_t* model() = 0;
        virtual bool setupBones(matrix3x4_t* pBoneMatrix, int nMaxBones, int nBoneMask, float flCurTime = 0) = 0;
        virtual bool shouldDraw() = 0;
        virtual const Vector& origin() = 0;
        virtual bool isPlayer() = 0;

        NETVAR(collideable, "CBaseEntity->m_Collision", ICollideable);
        NETVAR(team, "CBaseEntity->m_iTeamNum", int);
        NETVAR(spotted, "CBaseEntity->m_bSpotted", bool);
};


// CPlayer inherits from CEntity
class CPlayer : public CEntity {
    public:

};