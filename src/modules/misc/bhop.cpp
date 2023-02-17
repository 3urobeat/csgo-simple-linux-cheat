/*
 * File: bhop.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 02.04.2022 20:31:50
 * Author: 3urobeat
 * 
 * Last Modified: 17.02.2023 16:10:25
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "../modules.h"


/**
 * Misc: Bunny Hop module
 * @param cmd createMove cmd that will be send to the server
 */
void Modules::Bhop::run(CUserCmd *cmd) {
    
    // Check if this module should run
    if (!Config::Misc::bhopEnabled) return;            // Check if module is enabled
    if (!ImGui::IsKeyDown(ImGuiKey_Space)) return; // Only bother if user tries to bhop (aka holding space bar) (using ImGui's key press functions to make checking easier)

    // Send jump command
    cmd->buttons &= ~IN_JUMP;

}