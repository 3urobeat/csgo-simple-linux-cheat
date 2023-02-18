/*
 * File: iBaseClientDLL.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 04.04.2022 20:04:28
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 14:39:00
 * Modified By: 3urobeat
 */


#pragma once


#include <cstdint>

#include "../../helpers/definitions.h"


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


struct DVariant {
	union {
		float m_Float;
		long m_Int;
		char *m_pString;
		void *m_pData;
		float m_Vector[3];
		int64_t m_Int64;
	};

	int m_Type;
};


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/dt_recv.h#L28
struct CRecvProxyData {
	const RecvProp* m_pRecvProp;
	DVariant m_Value;
	int m_iElement;
	int m_ObjectID;
};


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/dt_recv.h#L41
typedef void (*RecvVarProxyFn) (const CRecvProxyData *pData, void *pStruct, void *pOut);


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/mp/src/public/dt_recv.h#L87
struct RecvProp {
	char *m_pVarName;
	int m_RecvType;
	int m_Flags;
	int m_StringBufferSize;
	bool m_bInsideArray;
	const void *m_pExtraData;
	RecvProp *m_pArrayProp;
	void *m_ArrayLengthProxy;
	RecvVarProxyFn m_ProxyFn;
	void *m_DataTableProxyFn;
	RecvTable *m_pDataTable;
	int m_Offset;
	int m_ElementStride;
	int m_nElements;
	const char *m_pParentArrayPropName;
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