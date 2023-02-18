/*
 * File: main.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 02.04.2022 11:55:11
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 13:27:31
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


// Libs
#include <iostream>
#include <string>
#include <thread>
#include <dlfcn.h>
#include <stdint.h>
#include <cstring>
#include <cstdint>
#include <unistd.h>
#include <unordered_map>
#include <sys/mman.h>
#include <SDL2/SDL.h>


// Export functions declared in main.cpp
extern void logger(const char* str);
extern void logger(std::string str);


// Import subfolder files
#include "menu/config.h"
#include "SDK/helpers/misc.h"
#include "SDK/sdk.h"
#include "modules/modules.h"
#include "hooks/hooks.h"
#include "menu/menu.h"


inline std::string version = "0.0.1";

inline int screenSizeX;
inline int screenSizeY;


extern void libUnload();