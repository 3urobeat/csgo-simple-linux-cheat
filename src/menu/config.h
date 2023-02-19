/*
 * File: config.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 02.04.2022 19:50:19
 * Author: 3urobeat
 * 
 * Last Modified: 19.02.2023 11:58:06
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


// Stores all module settings in one place
namespace Config {

    namespace Aimbot {
        inline bool  enabled = false;
        inline float fov = 0.0;
        inline float smoothness = 0.0;
        inline int   hitboxSelected = 0; // Order: Head, Neck, Chest, Stomach, Pelvis
        inline bool  silentAimEnabled = false;

        inline bool triggerbotEnabled = false;
        inline int  triggerbotDelay = 0;
    }

    namespace Visuals {
        inline bool espEnabled = false;
    }

    namespace Misc {
        inline bool bhopEnabled = false;

        inline bool radarEnabled = false;
    }
    
}