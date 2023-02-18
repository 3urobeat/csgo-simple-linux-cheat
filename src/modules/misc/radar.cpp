/*
 * File: radar.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 16.02.2023 21:33:28
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 15:49:59
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "../modules.h"


/**
 * Misc: Radar Hack module which sets spotted of all entities to true
 */
void Modules::Radar::run() {

    // Check if this module should run
    if (!Config::Misc::radarEnabled) return; // Check if module is enabled


    // TODO: Don't hardcode 64?
    // Iterate over all entities that can be in one map
    for (int i = 0; i <= 64; i++) {
        CEntity *entity = Interfaces::entityList->GetClientEntity(i); // Get this entity

        if (!entity) continue; // Ignore if invalid
        // TODO: Ignore if not a player
        // TODO: Ignore if dead

        entity->spotted() = true; // Set spotted to true so it will appear on the radar
    }

}