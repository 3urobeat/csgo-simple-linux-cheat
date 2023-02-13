/*
 * File: iBaseClientDLL.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 04.04.2022 20:04:28
 * Author: 3urobeat
 * 
 * Last Modified: 13.02.2023 16:50:04
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once

#include "../../definitions.h"
#include "../../misc.h"


struct RecvProp;


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/mp/src/public/dt_recv.h#L172
struct RecvTable {
	RecvProp *m_pProps;
	int m_nProps;
	void *m_pDecoder;
	char *m_pNetTableName;
	bool m_bInitialized;
	bool m_bInMainList;
};


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/mp/src/public/client_class.h#L38
class IClientNetworkable;
typedef IClientNetworkable* (*CreateClientClassFn)(int entnum, int serialNum);
typedef IClientNetworkable* (*CreateEventFn)();


class ClientClass {
    public:
        CreateClientClassFn m_pCreateFn;
        CreateEventFn *m_pCreateEventFn;
        char* m_pNetworkName;
        RecvTable *m_pRecvTable;
        ClientClass* m_pNext;
        EClassIds m_ClassID;
    };


class IBaseClientDLL {
    public:
        ClientClass* GetAllClasses() {
            typedef ClientClass* (* Fn)(void *);
            return getVirtualFunc<Fn>(this, 8)(this);
        }
};