/*
 * File: main.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 02.04.2022 11:55:11
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 15:55:01
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include <iostream>
#include <string>
#include <SDL2/SDL.h>

void logger(const char* str);
void logger(std::string str);


#include "menu/menu.h"
#include "menu/config.h"

#include "SDK/interfaces/interfaces.h"
#include "hooks/hooks.h"

#include "modules/modules.h"


inline std::string version = "0.0.1";

inline int screenSizeX;
inline int screenSizeY;


extern void libUnload();