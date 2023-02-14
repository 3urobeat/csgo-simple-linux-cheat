/*
 * File: modules.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 02.04.2022 20:12:38
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 18:13:14
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


// Registers all modules
namespace Modules {

    namespace Bhop {
        void run(CUserCmd* cmd);
    }
    
}