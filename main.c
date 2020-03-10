#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Event event;


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(880, 750, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    surface = IMG_Load("totue.png");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return 3;
    }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return 3;
    }
    SDL_FreeSurface(surface);

    while (1) {
        SDL_bool FC = SDL_FALSE;
        /*********************
            GET INPUTS
        *********************/
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT) {
            break;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
            break;
        }
        else if(event.key.keysym.scancode == SDL_SCANCODE_F11)
        {
            SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }

        /*********************
            MOUSE INPUTS
        *********************/
        int mouseX = 0;
        int mouseY = 0;
        if (SDL_GetGlobalMouseState(&mouseX, &mouseY))
        {

        }

        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

