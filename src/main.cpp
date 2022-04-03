/*
 * File: csgo-simple-linux-cheat.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 31.03.2022 22:52:29
 * Author: 3urobeat
 * 
 * Last Modified: 03.04.2022 13:56:46
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2022 3urobeat <https://github.com/HerrEurobeat>
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include <thread>
#include "main.h"


//Called by entry point in a new thread
void MainThread() {

    //initialize interfaces
    Interfaces::hookInterfaces();

    //initialize hooks
    Hooks::initHooks();
    
}


//Called on unload
void __attribute__((destructor)) Shutdown() {

    //unload hooks
    Hooks::unloadHooks();

}


//Entrypoint, is called on load
int __attribute__((constructor)) Startup() {
    std::thread mainThread(MainThread); //run cheat itself in new thread
    
    //...and detach thread
	mainThread.detach();
    return 0;
}