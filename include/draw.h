#ifndef DRAW
#define DRAW

#include "window.h"
#include <SDL2/SDL_image.h>

typedef struct {
    int         pos_x;
    int         pos_y;
    int         width;
    int         height;
    SDL_Texture *texture;
} Entity;

void prepareCanvas(Win *app);
void presentCanvas(Win *app);
SDL_Texture *loadTexture(Win *app, char *img_path);
void drawEntity(Win *app, Entity *entity);

#endif /* DRAW */