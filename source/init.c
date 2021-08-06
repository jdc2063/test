#include "init.h"

int initSDL(Win *app)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Couldn't initiqlize SDL:  %s\n", SDL_GetError());
        return -1;
    }


    
    app->window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
    WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!app->window)
    {
        printf("failed to open %d x %d Windows : %s\n", WINDOW_WIDTH, WINDOW_HEIGHT, SDL_GetError());
        return -1;
    }

    app->renderer = SDL_CreateRenderer(app->window, -1, SDL_RENDERER_ACCELERATED);
    if (!app->renderer) {
        printf("failed to create renderer: %s\n", SDL_GetError());
        return -1;
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0) //Initialisation de l'API Mixer
    {
         printf("%s", Mix_GetError());
    }
    return 0;
}   