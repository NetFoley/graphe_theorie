#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED

typedef struct textObject{
    SDL_Rect pos;
    TTF_Font * police;
    SDL_Texture * texture;
    SDL_Surface * surface;
    SDL_Color color;

}textObject;

void INIT_text(SDL_Renderer * renderer, int h, textObject * text, char police[50]);
void ADD_text(textObject * text, char input[50]);
void move_text(SDL_Renderer * renderer, textObject * text, int x, int y);

void INIT_text(SDL_Renderer * renderer, int h, textObject * text, char police[50])
{
    text->pos.x = 0;
    text->pos.y = 0;
    text->pos.w = 0;
    text->pos.h = h;

    text->police = TTF_OpenFont(police, h+10);
    SDL_Color couleurNoire = {0, 0, 0};
    text->color = couleurNoire;

    text->surface = NULL;
    text->surface = TTF_RenderText_Blended(text->police, "", text->color);

}

void set_text(SDL_Renderer * renderer, textObject * text, char input[50])
{
    text->pos.w = text->pos.h * strlen(input)/2;
    text->surface = TTF_RenderText_Blended(text->police, input, text->color);

    text->texture = SDL_CreateTextureFromSurface(renderer, text->surface);
    text->texture = SDL_CreateTextureFromSurface(renderer, text->surface);
}

void move_text(SDL_Renderer * renderer, textObject * text, int x, int y)
{
    text->pos.x = x;
    text->pos.y = y;
}

#endif // TEXT_H_INCLUDED
