// SDL hooks for adding our ImGUI window to an existing OpenGL window (csgo)
// I did not create this file. Source: https://github.com/seksea/gamesneeze/blob/7ec40e08a9964549672da6c735567ff613262097/src/core/hooks/sdlhook.cpp


#include "../hooks.h"


template <typename T>
static constexpr auto relativeToAbsolute(uintptr_t address) noexcept
{
    return (T)(address + 4 + *reinterpret_cast<std::int32_t*>(address));
}


int Hooks::SDL::PollEvent(SDL_Event* event) {
    const auto result = pollEvent(event);
    if (Menu::isInit) {
        Menu::onPollEvent(event, result);
    }
    return result;
    return 1;
}

void Hooks::SDL::SwapWindow(SDL_Window* window) {
    Menu::onSwapWindow(window);
    swapWindow(window);
}


// Hook SDL, called on load
void Hooks::SDL::hookSDL() {
    const auto libSDL = dlopen("libSDL2-2.0.so.0", RTLD_LAZY | RTLD_NOLOAD);

    swapWindowAddr = relativeToAbsolute<uintptr_t>(uintptr_t(dlsym(libSDL, "SDL_GL_SwapWindow")) + 2);
    if (swapWindowAddr) {
        swapWindow = *reinterpret_cast<decltype(swapWindow)*>(swapWindowAddr);
        *reinterpret_cast<decltype(SwapWindow)**>(swapWindowAddr) = SwapWindow;
    } // Add else for error handling

    pollEventAddr = relativeToAbsolute<uintptr_t>(uintptr_t(dlsym(libSDL, "SDL_PollEvent")) + 2);
    if (pollEventAddr) {
        pollEvent = *reinterpret_cast<decltype(pollEvent)*>(pollEventAddr);
        *reinterpret_cast<decltype(PollEvent)**>(pollEventAddr) = PollEvent;
    } // Add else for error handling
}


// Unhook SDL, called on unload
void Hooks::SDL::unhookSDL() {
    *reinterpret_cast<decltype(swapWindow) *>(swapWindowAddr) = swapWindow;
    *reinterpret_cast<decltype(pollEvent) *>(pollEventAddr) = pollEvent;
    
    /* if (*reinterpret_cast<decltype(swapWindow)*>(swapWindowAddr)!=swapWindow || *reinterpret_cast<decltype(pollEvent)*>(pollEventAddr)!=pollEvent) {
        //Error
    } */
}