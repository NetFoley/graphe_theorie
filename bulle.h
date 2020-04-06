#ifndef BULLE_H_INCLUDED
#define BULLE_H_INCLUDED

#include "text.h"
#include "cube.h"

typedef struct bulle{
    circle circle;
    textObject text;

}bulle;

typedef struct graphe{
	bulle * bulles;
	SDL_Renderer * renderer;
	int nbrBulles;

}graphe;

void ADD_bulle(graphe * g, int x, int y, int h, int rayon);
void INIT_graphe(graphe * g, SDL_Renderer * r);
void RENDER_graphe(SDL_Window * window,  graphe * g);

void INIT_graphe(graphe * g, SDL_Renderer * r)
{
    g->bulles =(bulle*)malloc(2*sizeof(bulle));
    g->renderer = r;
    g->nbrBulles = 0;
}

void ADD_bulle(graphe * g, int x, int y, int h, int rayon)
{
    g->bulles =(bulle*)realloc(g->bulles, (g->nbrBulles+2)*(sizeof(bulle)));
    INIT_circle(&g->bulles[g->nbrBulles].circle, x + h /1.4, y+1.6*h, rayon, g->renderer);
    INIT_text(g->renderer, 90, &g->bulles[g->nbrBulles].text, "FreeMono.ttf");

    char str[50];
    sprintf(str, "%d", g->nbrBulles+1);
    set_text(g->renderer, &g->bulles[g->nbrBulles].text, str);

    move_text(g->renderer, &g->bulles[g->nbrBulles].text, x ,y);
    g->nbrBulles++;
}

void RENDER_graphe(SDL_Window * window,  graphe * g)
{
    for(int i = 0; i < g->nbrBulles; i++)
    {
        DrawCircle(g->renderer, window, &g->bulles[i].circle);
        SDL_RenderCopy(g->renderer, g->bulles[i].text.texture, NULL, &g->bulles[i].text.pos);
    }
}

#endif // BULLE_H_INCLUDED
