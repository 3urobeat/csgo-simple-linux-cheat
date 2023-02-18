/*
 * File: netvarManager.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 18.02.2023 12:58:50
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 15:45:24
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


#include "interfaces/files/iBaseClientDLL.h"
#include "helpers/fnv.h"


namespace NetvarManager {

    /**
     * Recursively dump all netvars in a table
     * Tutorial used to understand what's happening: https://www.youtube.com/watch?v=VCsNZ0GRVzo
     * @param baseClass Network Name of the client class
     * @param table RecvTable of the client class
     * @param offset Pass 0 on initial call, gets incremented by recursive call
     */
    void dump(const char *baseClass, RecvTable *table, uint32_t offset);

    // Dumps all netvars
    void setup();

    // Map which stores all the offsets we retreived
    inline std::unordered_map<uint32_t, uint32_t> netvarMap;

}


// Macro to access our retreived netvars (backslashes are for multi-line)
//#define NETVAR(func, netvar, type) type& func() {return *reinterpret_cast<type*>(uintptr_t(this) + NetvarManager::netvarMap[fnv::hashConst(netvar)]);}; type* func##_ptr() {return reinterpret_cast<type*>(uintptr_t(this) + NetvarManager::netvarMap[fnv::hashConst(netvar)]);}
#define NETVAR(funcName, netvar, type) type& funcName() { \
    static auto offset = NetvarManager::netvarMap[fnv::hashConst(netvar)]; \
    return *reinterpret_cast<type *>((uintptr_t) this + offset); \
}
