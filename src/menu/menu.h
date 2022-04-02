/*
 * File: menu.h
 * Project: menu
 * Created Date: 01.04.2022 15:54:37
 * Author: 3urobeat
 * 
 * Last Modified: 02.04.2022 18:31:29
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


namespace Menu {
    inline bool isInit = false;
    inline bool active = true; //change to false later

    inline auto openKey = SDL_SCANCODE_INSERT;

    void showMenu();
    void onPollEvent(SDL_Event* event, const int result);
    void onSwapWindow(SDL_Window* window);

    void showAimbotPage();
    void showVisualsPage();
    void showMiscPage();
    void showInfoPage();
}