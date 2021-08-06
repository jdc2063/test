#include "input.h"
#include "draw.h"
#include "window.h"
#include <stdio.h>

int input_handler(Entity *entity, int pause) {
    SDL_Event event;

    SDL_PollEvent(&event);

    switch (event.type)
    {
    case SDL_QUIT:
        return -1;
    case SDL_KEYDOWN:
        if (pause == 0){
            switch (event.key.keysym.sym)
            {
            case SDLK_DOWN:
                if(entity->pos_y + entity->height + 4 <= WINDOW_HEIGHT) {
                    entity->pos_y += 4;
                }
                break;
            case SDLK_UP:
                if(entity->pos_y - 4 >= 0) {
                    entity->pos_y -= 4;
                }
                break;
            case SDLK_RETURN:
                return 1;
            case SDLK_LEFT:
                return 2;
            case SDLK_RIGHT:
                return 3;
            default:
                break;
            }
        } else {
            if(event.key.keysym.sym == SDLK_RETURN) {
                return 1;
            }
        }
        break;
    case SDL_KEYUP:
        break;
    default:
        break;
    }
    return 0;
}