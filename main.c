#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdio.h>
#include <math.h>
#include "bulle.h"

int main(int argc, char *argv[])
{
    SDL_Window *windowGraph;
    SDL_Renderer *renderGraph;
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Event event;


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return 3;
    }

    if (SDL_CreateWindowAndRenderer(880, 750, SDL_WINDOW_RESIZABLE, &windowGraph, &renderGraph)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }

    surface = IMG_Load("totue.png");
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create surface from image: %s", SDL_GetError());
        return 3;
    }
    texture = SDL_CreateTextureFromSurface(renderGraph, surface);
    if (!texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create texture from surface: %s", SDL_GetError());
        return 3;
    }
    SDL_FreeSurface(surface);

    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    bulle bulles;
    INIT_bulle(&bulles, 50, 50, 30, 50, renderGraph);

    while (1) {
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
            SDL_SetWindowFullscreen(windowGraph, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }

        /*********************
            MOUSE INPUTS
        *********************/
        int mouseX = 0;
        int mouseY = 0;
        if (SDL_GetGlobalMouseState(&mouseX, &mouseY))
        {

        }

        SDL_SetRenderDrawColor(renderGraph, 255, 255, 255, 0);
        SDL_RenderClear(renderGraph);

        RENDER_bulle(renderGraph, windowGraph, &bulles);

        SDL_RenderPresent(renderGraph);
    }
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderGraph);
    SDL_DestroyWindow(windowGraph);

    SDL_Quit();

    return 0;
}

