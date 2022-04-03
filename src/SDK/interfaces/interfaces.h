/*
 * File: interfaces.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 03.04.2022 12:51:04
 * Author: 3urobeat
 * 
 * Last Modified: 03.04.2022 15:19:53
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "headers/iClientMode.h"
#include "headers/ivEngineClient.h"


namespace Interfaces {

    void hookInterfaces();

    inline IClientMode* clientMode;
    inline IVEngineClient* engine;

}



//Source: https://github.com/seksea/gamesneeze/blob/7ec40e08a9964549672da6c735567ff613262097/src/sdk/interfaces/interfaces.hpp

typedef void* (*InstantiateInterfaceFn)();
// https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/public/tier1/interface.h#L72
class InterfaceReg {
public:
    InstantiateInterfaceFn m_CreateFn;
    const char* m_pName;
    InterfaceReg* m_pNext;
};
template <typename T>
T* getInterface(const char* file, const char* name, bool includeVersion = false) {
    void* lib = dlopen(file, RTLD_NOLOAD | RTLD_NOW | RTLD_LOCAL);
    if (lib) {
        // https://github.com/ValveSoftware/source-sdk-2013/blob/0d8dceea4310fde5706b3ce1c70609d72a38efdf/sp/src/tier1/interface.cpp#L46
        InterfaceReg* interfaceReg = *reinterpret_cast<InterfaceReg**>(dlsym(lib, "s_pInterfaceRegs"));
        dlclose(lib);

        // loop through each interface in interfaceReg linked list
        for (InterfaceReg* cur = interfaceReg; cur; cur = cur->m_pNext) {
            // If current interface equals input name without the 3 version numbers so if an interface version changes we dont have to care
            if ((strstr(cur->m_pName, name) && strlen(cur->m_pName)-3 == strlen(name)) || 
                (includeVersion && (strstr(cur->m_pName, name) && strlen(cur->m_pName) == strlen(name)))) {
                T* iface = reinterpret_cast<T*>(cur->m_CreateFn());
                return iface;
            }
        }
    }

    dlclose(lib);
    return nullptr;
}