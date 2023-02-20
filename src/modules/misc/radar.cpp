/*
 * File: radar.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 16.02.2023 21:33:28
 * Author: 3urobeat
 * 
 * Last Modified: 20.02.2023 13:35:39
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


    // Iterate over all entities (start at 1 as 0 is the world entity)
    for (int i = 1; i <= Interfaces::engineClient->GetMaxClients(); i++) {
        CEntity *entity = Interfaces::entityList->GetClientEntity(i); // Get this entity

        if (!entity) continue; // Ignore if invalid
        // TODO: Ignore if not a player
        // TODO: Ignore if dead

        entity->spotted() = true; // Set spotted to true so it will appear on the radar
    }

}