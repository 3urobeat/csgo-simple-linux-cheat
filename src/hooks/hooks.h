/*
 * File: hooks.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 01.04.2022 17:38:16
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 15:16:05
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#pragma once


#include "../main.h"


namespace Hooks {
    void initHooks();
    void unloadHooks();


    // SDL hooks
    namespace SDL {
        void hookSDL();
        void unhookSDL();

        inline uintptr_t swapWindowAddr;
        inline std::add_pointer_t<void(SDL_Window*)> swapWindow;
        inline uintptr_t pollEventAddr;
        inline std::add_pointer_t<int(SDL_Event*)> pollEvent;
        
        void SwapWindow(SDL_Window* window);
        int PollEvent(SDL_Event* event);
    }


    // VMT hook
    namespace VMT {
        void *hookVMT(void *interface, void *hookFunction, int offset);
    }


    // createMove hook
    namespace CreateMove {
        using  createMoveFuncSignature = bool (*)(void *thisptr, float flInputSampleTime, CUserCmd *cmd);

        bool   createMoveFunc(void *thisptr, float flInputSampleTime, CUserCmd *cmd);
        inline createMoveFuncSignature originalCreateMove;

        inline bool sendPacket;
    }
}