#include "draw.h"

void prepareCanvas(Win *app)
{
    SDL_SetRenderDrawColor(app->renderer, 96, 128, 255, 255);
    SDL_RenderClear(app->renderer);
}

void presentCanvas(Win *app)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture *loadTexture(Win *app, char *img_path) 
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading: %s", img_path);
    texture = IMG_LoadTexture(app->renderer, img_path);
    if (texture == NULL) {
        printf("Failed to load texture %s\n", IMG_GetError());
    }
    return texture;
}

void drawEntity(Win *app, Entity *entity)
{
    SDL_Rect dest = {entity->pos_x, entity->pos_y, entity->width, entity->height};

    SDL_RenderCopy(app->renderer, entity->texture, NULL, &dest);
}