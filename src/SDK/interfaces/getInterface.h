/*
 * File: getInterface.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 03.04.2022 15:38:59
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 14:40:03
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


#include "../../main.h"


// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/tier1/interface.h#L69
typedef void* (*InstantiateInterfaceFn)();

class InterfaceReg {
public:
    InstantiateInterfaceFn m_CreateFn;
    const char* m_pName;
    InterfaceReg* m_pNext;
};


// Helper function to dynamically load interfaces
template <typename T>
T* getInterface(const char* libname, const char* name, bool exactVersion = false) {

    void* handle = dlopen(libname, RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL); // idk what the __mode param really does, the docs don't help much: https://www.ibm.com/docs/en/zos/2.3.0?topic=functions-dlopen-gain-access-dynamic-link-library  ...but gamesneeze & Kali uses those soooo :shrug:

    // Check if lib couldn't be found
    if (!handle) {
        logger("getInterface() error: Could not open library!");

        // Close lib and return nothing
        dlclose(handle);
        return nullptr;
    }

    // Get address of interface function
    void* addr = dlsym(handle, "s_pInterfaceRegs");

    // Check if function couldn't be found
    if (!addr) {
        logger("getInterface() error: Function address could not be found!");

        // Close lib and return nothing
        dlclose(handle);
        return nullptr;
    }

    // List all interfaces and close lib afterwards
    InterfaceReg* interfaces = *reinterpret_cast<InterfaceReg**>(addr);

    dlclose(handle);

    // Loop through all interfaces
    for (InterfaceReg* cur = interfaces; cur; cur = cur->m_pNext) {

        // Check if interface equals name, once with exact version and once without
        if (exactVersion) {
            if (strcmp(cur->m_pName, name) == 0) return reinterpret_cast<T*>(cur->m_CreateFn());
        } else {
            if (strstr(cur->m_pName, name) && strlen(cur->m_pName) - 3 == strlen(name)) return reinterpret_cast<T*>(cur->m_CreateFn());
        }

    }
}