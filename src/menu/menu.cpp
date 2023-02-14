/*
 * File: menu.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 01.04.2022 15:50:14
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 18:31:28
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "menu.h"


// onPollEvent function from https://github.com/seksea/gamesneeze/blob/7ec40e08a9964549672da6c735567ff613262097/src/core/menu/menu.cpp
void Menu::onPollEvent(SDL_Event* event, const int result) {
    if (result && ImGui_ImplSDL2_ProcessEvent(event) && Menu::active) {
        event->type = 0;
    }
}

// onSwapWindow function (modified) from https://github.com/seksea/gamesneeze/blob/7ec40e08a9964549672da6c735567ff613262097/src/core/menu/menu.cpp
void Menu::onSwapWindow(SDL_Window* window) {
    // TODO: Write my own function

    // Run on first call
    if (!isInit) {
        gl3wInit();
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();
        ImGui_ImplOpenGL3_Init("#version 100");
        ImGui_ImplSDL2_InitForOpenGL(window, nullptr);

        isInit = true;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(window);

    ImGuiIO& io = ImGui::GetIO();

    int w, h;
    SDL_GetWindowSize(window, &w, &h);
    screenSizeX = w;
    screenSizeY = h;
    
    io.DisplaySize = ImVec2((float)w, (float)h);

    ImGui::NewFrame();

    // Show menu and cursor if menu was activated, otherwise hide cursor
    if (Menu::active) {
        io.MouseDrawCursor = true;
        Menu::showMenu();
    } else {
        io.MouseDrawCursor = false;
    }

    // Activate menu if openKey was pressed
    if (ImGui::IsKeyPressed(Menu::openKey, false)) {
        Menu::active = !Menu::active;
    }

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


/**
 * Draws the menu window
 */
void Menu::showMenu() {

    // Show title bar of window
    ImGui::Begin(("csgo-simple-linux-cheat v" + version + " by 3urobeat").c_str(), &Menu::active);


    // Show buttons for page selection that will change the currentPage value
    if (ImGui::Button("Aimbot", buttonWidth)) Menu::currentPage = 0;
    
    ImGui::SameLine();
    if (ImGui::Button("Visuals", buttonWidth)) Menu::currentPage = 1;
    
    ImGui::SameLine();
    if (ImGui::Button("Misc", buttonWidth)) Menu::currentPage = 2;

    ImGui::SameLine();
    if (ImGui::Button("Info", buttonWidth)) Menu::currentPage = 3;


    // Show desired page
    switch (currentPage) {
        case 1:
            Menu::showVisualsPage();
            break;
        case 2:
            Menu::showMiscPage();
            break;
        case 3:
            Menu::showInfoPage();
            break;
        default:
            Menu::showAimbotPage();
            Menu::currentPage = 0;
    }

    ImGui::End();
}