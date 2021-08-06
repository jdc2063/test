#include <stdio.h>
#include "window.h"
#include "input.h"
#include "draw.h"
#include "init.h"
#include "entity.h"

int main()
{
    Win *app = malloc(sizeof(Win));
    Entity *player = malloc(sizeof(Entity));
    Entity *enemy1 = malloc(sizeof(Entity));
    Entity *enemy2 = malloc(sizeof(Entity));
    Entity *enemy3 = malloc(sizeof(Entity));
    Entity *gameover = malloc(sizeof(Entity));
    Entity *menu_pause = malloc(sizeof(Entity));
    Entity *background = malloc(sizeof(Entity));
    Mix_Music *musique;
    musique = Mix_LoadMUS("ressource/undertale-game-over-theme.mp3");
    if (musique== NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Erreur chargement de la musique : %s", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return -1;
    }
    if (initSDL(app) < 0) {
        return -1;
    }

    initiate_enemy(app, enemy1, "ressource/sans.png");
    initiate_enemy(app, enemy2, "ressource/papyrus.png");
    initiate_enemy(app, enemy3, "ressource/undyne.png");
    initiate_player(app, player);
    initiate_over(app, gameover, "ressource/game_over_undertale.png");
    initiate_over(app, menu_pause, "ressource/pause.png");
    initiate_over(app, background, "ressource/fond.jpg");

    int pause = 0;
    int input = input_handler(player, pause);
    int vie = 3;
    int fps = 20;
    while (input != -1)
    {
        switch (input)
        {
        case 1:
            if (pause == 0) {
                pause = 1;
            } else {
                pause = 0;
            }
            break;
        case 2:
            if (fps == 10) {
                fps = 20;
            } else {
                fps = 30;
            }
            break;
        case 3:
            if (fps == 30) {
                fps = 20;
            } else {
                fps = 10;
            }
            break;
        }
        if(vie > 0 && pause == 0) {
            prepareCanvas(app);
            drawEntity(app, background);
            drawEntity(app, player);
            vie = move_enemy(enemy1, player, vie);
            vie = move_enemy(enemy2, player, vie);
            vie = move_enemy(enemy3, player, vie);
            drawEntity(app, enemy1);
            drawEntity(app, enemy2);
            drawEntity(app, enemy3);
            presentCanvas(app);
            SDL_Delay(fps);
        } else if (pause == 1) {
            prepareCanvas(app);
            drawEntity(app, menu_pause);
            presentCanvas(app);
            SDL_Delay(fps);
        } else {
            prepareCanvas(app);
            Mix_PlayMusic(musique, 1);
            drawEntity(app, gameover);
            presentCanvas(app);
            SDL_Delay(fps);
        }
        input = input_handler(player, pause);
    }
    return 0;
}
