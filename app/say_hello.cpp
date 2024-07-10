#include <iostream>
#include <app/say_hello.hpp>
#include <SDL2/SDL.h>

void sayHello() {
    SDL_version version;
    SDL_GetVersion(&version);

    std::cout << "SDL version: "
        << static_cast<unsigned int>(version.major) << "."
        << static_cast<unsigned int>(version.minor) << "."
        << static_cast<unsigned int>(version.patch) << std::endl;
    
    std::cout << "Everything works fine!" << std::endl;
}
