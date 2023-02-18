/*
 * File: csgo-simple-linux-cheat.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 31.03.2022 22:52:29
 * Author: 3urobeat
 * 
 * Last Modified: 18.02.2023 15:44:21
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "main.h"


// Make a logger call slightly shorter
void logger(const char* str) { std::cout << str << std::endl; }
void logger(std::string str) { std::cout << str.c_str() << std::endl; }


// Assigning lib load and unload functions
void __attribute__((constructor)) libLoad();
void __attribute__((destructor))  libUnload();


// Called by entry point in a new thread
void MainThread() {

    logger("Loading hooks & interfaces...");

    // Initialize interfaces
    Interfaces::initInterfaces();

    // Initialize netvars
    NetvarManager::setup();

    // Initialize hooks
    Hooks::initHooks();

    
    // Temporary main loop for modules which aren't createMove dependent
    while(true) {
        Modules::Radar::run();
    }
    
}


// Entrypoint, is called on load
void libLoad() {

    std::thread mainThread(MainThread); // Run the cheat itself in a new thread
    
    // ...and detach thread
    mainThread.detach();

}


// Called on unload (does somehow not work atm)
void libUnload() {

    logger("Unloading hooks...");

    // Unload hooks
    Hooks::unloadHooks();

}