#ifndef BULLE_H_INCLUDED
#define BULLE_H_INCLUDED

#include "text.h"
#include "cube.h"

typedef struct bulle{
    circle circle;
    textObject text;

}bulle;

void INIT_bulle(bulle * bulle, int x, int y, int h, int rayon, SDL_Renderer * renderer);

void INIT_bulle(bulle * bulle, int x, int y, int h, int rayon, SDL_Renderer * renderer)
{
    static int i = 1;
    INIT_circle(&bulle->circle, x + h /1.4, y+1.6*h, rayon, renderer);
    INIT_text(renderer, 90, &bulle->text, "FreeMono.ttf");

    char str[50];
    sprintf(str, "%d", i);
    set_text(renderer, &bulle->text, str);

    move_text(renderer, &bulle->text, x ,y);
}

void RENDER_bulle(SDL_Renderer * renderer, SDL_Window * window,  bulle * bulle)
{
    DrawCircle(renderer, window, &bulle->circle);
    SDL_RenderCopy(renderer, bulle->text.texture, NULL, &bulle->text.pos);
}

#endif // BULLE_H_INCLUDED
