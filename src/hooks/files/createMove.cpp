/*
 * File: createmove.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 03.04.2022 00:17:28
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 18:05:36
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "../hooks.h"


// Hooks createMove, which is called on every tick, and can "send" commands
bool Hooks::CreateMove::createMoveFunc(void *thisptr, float flInputSampleTime, CUserCmd *cmd) {

    // Call the original function before doing anything else
    const bool res = originalCreateMove(thisptr, flInputSampleTime, cmd); 
    

    if (!cmd->tick_count != 0) {
        
        // https://www.unknowncheats.me/forum/counterstrike-global-offensive/290258-updating-bsendpacket-linux.html
        uintptr_t *rbp;
        asm volatile("mov %%rbp, %0" : "=r"(rbp));
        bool *sendPacket = ((*(bool **)rbp) - (int)24);
        CreateMove::sendPacket = true;


        // Call our modules
        Modules::Bhop::run(cmd);

    }

    return res;
}
