/*
 * File: menu.h
 * Project: csgo-simple-linux-cheat
 * Created Date: 01.04.2022 15:54:37
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 13:05:25
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

#include "ImGUI/imgui.h"
#include "ImGUI/GL/gl3w.h"
#include "ImGUI/imgui_impl_sdl.h"
#include "ImGUI/imgui_impl_opengl3.h"


namespace Menu {
    inline bool isInit = false;
    inline bool active = true; // Change to false later
    inline int currentPage = 0;

    inline auto openKey = SDL_SCANCODE_INSERT;

    inline auto buttonWidth = ImVec2(75, 20);

    void showMenu();
    void onPollEvent(SDL_Event* event, const int result);
    void onSwapWindow(SDL_Window* window);

    void showAimbotPage();
    void showVisualsPage();
    void showMiscPage();
    void showInfoPage();
}