/*
 * File: vmtHook.cpp
 * Project: csgo-simple-linux-cheat
 * Created Date: 05.04.2022 19:25:04
 * Author: 3urobeat
 * 
 * Last Modified: 14.02.2023 18:35:35
 * Modified By: 3urobeat
 * 
 * Copyright (c) 2023 3urobeat <https://github.com/HerrEurobeat>
 * 
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
 */


#include "../hooks.h"


int pageSize = sysconf(_SC_PAGE_SIZE);
int pageMask = ~(pageSize - 1);


/**
 * Hooks a function by intercepting virtual method calls
 * @param interface Pointer to the base address of the virtual table
 * @param hookFunction Pointer to the function that should be hooked
 * @param offset Position of the desired function in the virtual method table
 * @returns Pointer to the original function
 */
void *Hooks::VMT::hookVMT(void *interface, void *hookFunction, int offset) {

    // Get pointer to the first function in the vtable
    intptr_t vTableBase = *((intptr_t *) interface);

    // Add offset to our base pointer to find the function we are searching for
    intptr_t vTableFunc = vTableBase + sizeof(intptr_t) * offset;

    // Get the original function
    intptr_t vTableOriginalFunc = *((intptr_t *) vTableFunc);


    // Change protection of the memory area we'd like to modify by adding WRITE permission
    mprotect((void *) (vTableFunc & pageMask), pageSize, PROT_READ | PROT_WRITE | PROT_EXEC);

    // Overwrite the pointer to the original function in the VMT with the pointer to our function
    *((intptr_t *) vTableFunc) = (intptr_t) hookFunction;
    //memcpy(&vTableFunc, hookFunction, sizeof(intptr_t)); // Alternative?

    // Restore memory protection flags to rx only
    mprotect((void *) (vTableFunc & pageMask), pageSize, PROT_READ | PROT_EXEC);


    // Return pointer to the original function
    return (void *) vTableOriginalFunc;
}