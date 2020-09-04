#include<SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Setting the window resolution for 640x480

const int SCREEN_WIDTH = 640;
const int SCREE_HEIGHT = 480;

int main(int argc, char* args[]){
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    // Initializating SDL

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL couldn't intitializate! SDL_ERROR: " << SDL_GetError() << std::endl;
    }
    else {

        // Set the window title and create thew window

        window = SDL_CreateWindow("SDL Program", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREE_HEIGHT, SDL_WINDOW_SHOWN);

        // Check if can create an window

        if(window == NULL){
            std::cout << "Window couldn't be created! SDL_ERROR: " << SDL_GetError() << std::endl;
        }

        else {

            screenSurface = SDL_GetWindowSurface(window);

            // Fill the full window in white color

            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);

            // Wait 5 seconds to close the SDL window
            SDL_Delay(5000);
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
