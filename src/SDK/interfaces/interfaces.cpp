/*
 * File: interfaces.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 03.04.2022 13:48:11
 * Author: 3urobeat
 * 
 * Last Modified: 05.04.2022 20:10:45
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "../../main.h"

typedef IClientMode* (*getClientModeFunc)();


void Interfaces::hookInterfaces() {

    client = getInterface<IBaseClientDLL>("./csgo/bin/linux64/client_client.so", "VClient");

    //Get IClientMode - Source: https://github.com/seksea/gamesneeze/blob/master/src/sdk/interfaces/interfaces.cpp
    //TODO: Make myself
    uintptr_t hudProcessInput = reinterpret_cast<uintptr_t>(getVTable(client)[10]);
    getClientModeFunc GetClientMode = reinterpret_cast<getClientModeFunc>(getAbsoluteAddress(hudProcessInput + 11, 1, 5));

    clientMode = GetClientMode();
    
}