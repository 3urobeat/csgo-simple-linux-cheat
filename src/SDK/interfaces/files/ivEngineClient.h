/*
 * File: ivEngineClient.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 19.02.2023 19:46:56
 * Author: 3urobeat
 * 
 * Last Modified: 19.02.2023 20:09:58
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


#include "../interfaces.h"


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/cdll_int.h#L194
class IVEngineClient {
    public:
        typedef struct player_info_s {
            int64_t __pad0;
            union {
                int64_t xuid;
                struct {
                    int xuidlow;
                    int xuidhigh;
                };
            };
            char          name[128];
            int           userid;
            char          guid[33];
            unsigned int  friendsid;
            char          friendsname[128];
            bool          fakeplayer;
            bool          ishltv;
            unsigned int  customfiles[4];
            unsigned char filesdownloaded;
        } player_info_t;

        void GetScreenSize(int &width, int &height) {
            typedef void (* oGetScreenSize)(void *, int &, int &);
            return getVirtualFunc<oGetScreenSize>(this, 5)(this, width, height);
        }

        bool GetPlayerInfo(int iIndex, player_info_t *pInfo) {
            typedef bool (* oGetPlayerInfo)(void *, int, player_info_t *);
            return getVirtualFunc<oGetPlayerInfo>(this, 8)(this, iIndex, pInfo);
        }

        int GetPlayerForUserID(int UserID) {
            typedef int (* oGetPlayerForUserID)(void *, int);
            return getVirtualFunc<oGetPlayerForUserID>(this, 9)(this, UserID);
        }

        int GetLocalPlayer() {
            typedef int (* oGetLocalPlayer)(void *);
            return getVirtualFunc<oGetLocalPlayer>(this, 12)(this);
        }

        void GetViewAngles(QAngle& angle) {
            typedef void (* oGetViewAngles)(void *, QAngle &);
            return getVirtualFunc<oGetViewAngles>(this, 18)(this, angle);
        }

        void SetViewAngles(QAngle& angle) {
            typedef void (* oSetViewAngles)(void *, QAngle &);
            return getVirtualFunc<oSetViewAngles>(this, 19)(this, angle);
        }

        int GetMaxClients() {
            typedef int (* oGetMaxClients)(void *);
            return getVirtualFunc<oGetMaxClients>(this, 20)(this);
        }

        bool IsInGame() {
            typedef bool (* oIsInGame)(void *);
            return getVirtualFunc<oIsInGame>(this, 26)(this);
        }

        const VMatrix &WorldToScreenMatrix() {
            typedef VMatrix &(* oWorldToScreenMatrix)(void *);
            return getVirtualFunc<oWorldToScreenMatrix>( this, 37 )( this );
        }

        bool IsTakingScreenshot() {
            typedef bool (* oIsTakingScreenshot)(void *);
            return getVirtualFunc<oIsTakingScreenshot>(this, 92)(this);
        }

        void ExecuteClientCmd(const char *szCmdString) {
            typedef void (* oExecuteClientCmd)(void *, const char *);
            return getVirtualFunc<oExecuteClientCmd>(this, 108)(this, szCmdString);
        }

        void ClientCmd_Unrestricted(const char *szCmdString) {
            typedef void (* oClientCmd_Unrestricted)(void *, const char *);
            return getVirtualFunc<oClientCmd_Unrestricted>(this, 113)(this, szCmdString);
        }
        
        bool IsVoiceRecording() {
            typedef bool (* Fn)(void *);
            return getVirtualFunc<Fn>(this, 225)(this);
        }
};