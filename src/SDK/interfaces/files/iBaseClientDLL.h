/*
 * File: iBaseClientDLL.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 04.04.2022 20:04:28
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 18:34:34
 * Modified By: 3urobeat
 */


#pragma once

#include "../interfaces.h"

#include "../../../hooks/misc.h"


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