#include <iostream>
#include <SDL.h>
#include "GameTimer.h"
int main(int argc, char* argv[]) {
    float a =0;
    float start = 0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("MyWindow", 50, 50, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    GameTimer gameTimer;
    bool running = true;
    bool isKeyPressed = false;
    while (running) {
        SDL_Event event;
        if (a>5){
            running = false;
        }
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    isKeyPressed = true;
                    if (start == 0){
                        start = gameTimer.getCurrentTimeInSeconds();
                    }
                    break;
                case SDL_KEYUP:
                    isKeyPressed = false;
                    break;
            }
        }
        float deltaTime = gameTimer.run();
        if (isKeyPressed) {
            if (deltaTime > 0.0f) {
                a+=deltaTime;
                std::cout << "delta: " << deltaTime << std::endl;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
