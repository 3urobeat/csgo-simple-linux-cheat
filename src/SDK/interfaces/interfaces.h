/*
 * File: interfaces.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 03.04.2022 12:51:04
 * Author: 3urobeat
 * 
 * Last Modified: 03.04.2022 18:29:11
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
    #include "getInterface.h"

    inline IVEngineClient* engine;

    void hookInterfaces();
    
}