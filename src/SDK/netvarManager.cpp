/*
 * File: netvarManager.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 16.02.2023 16:28:14
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 13:01:28
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "sdk.h"


/**
 * Recursively dump all netvars in a table
 * Tutorial used to understand what's happening: https://www.youtube.com/watch?v=VCsNZ0GRVzo
 * @param baseClass Network Name of the client class
 * @param table RecvTable of the client class
 * @param offset Pass 0 on initial call, gets incremented by recursive call
 */
void NetvarManager::dump(const char *baseClass, RecvTable *table, uint32_t offset) {

    // Iterate over all props this table contains
    for (uint32_t i = 0; i < table->m_nProps; i++) { // m_nProps is the amount of total props

        // Get the prop we are looking at in this iteration 
        RecvProp *thisProp = &table->m_pProps[i];

        // Skip this iteration if prop is null, has a digit as first char or matches "baseclass"
        if (!thisProp || isdigit(thisProp->m_pVarName[0])) continue;
        if (fnv::hash(thisProp->m_pVarName) == fnv::hashConst("baseclass")) continue; // Some props store base classes which contain other props and we only care about the props themselves

        // Recursively call dump() again if this prop is a table
        if (thisProp->m_RecvType == 6 && thisProp->m_pDataTable && thisProp->m_pDataTable->m_pNetTableName[0] == 'D') {
            dump(baseClass, thisProp->m_pDataTable, thisProp->m_Offset + offset);
        }

        // Get content of this prop and store it in our map
        char name[128] = "";

        snprintf(name, 128, "%s->%s", baseClass, thisProp->m_pVarName);

        netvarMap[fnv::hash(name)] = thisProp->m_Offset + offset;


        // TODO: What does proxy spotted thing do?
    }
}


/**
 * Calls dump() for all classes in clientClass
 */
void NetvarManager::setup() {
    
    logger("Getting netvars...");

    // Iterate over all classes until we reached the end of the linked list
    for (ClientClass *clientClass = Interfaces::client->GetAllClasses(); clientClass; clientClass = clientClass->m_pNext) { // m_pNext is a pointer that points to the next linked list entry

        // Check if table is valid and dump everything it contains
        if (clientClass->m_pRecvTable) dump(clientClass->m_pNetworkName, clientClass->m_pRecvTable, 0);

    }

}