#include "window.h"
#include "draw.h"
#include <stdio.h>
#include "input.h"
#include "init.h"
#include "entity.h"

void initiate_enemy(Win *app, Entity *enemy, char *path) {
    int random = 0;
    while (random < WINDOW_WIDTH) {
        random = rand() % 800;
    }
    int height_max = WINDOW_HEIGHT - enemy->height;
    enemy->width = 50;
    enemy->height = 50;
    enemy->pos_x = random;
    enemy->pos_y = rand() % height_max;
    enemy->texture = loadTexture(app, path);
}

void initiate_player(Win *app, Entity *player){
    player->pos_x = 50;
    player->pos_y = 100;
    player->width = 50;
    player->height = 50;
    player->texture = loadTexture(app, "ressource/soul.png");
    
}

int move_enemy(Entity *enemy, Entity *player, int vie) {
    enemy->pos_x -= 1;
    int collision = verif_collision(enemy, player);
    if(collision == 0) {
        verif_out(enemy);
    } else {
        vie -= 1;
        reset(enemy);
    }
    return vie;
}

int verif_collision(Entity *enemy, Entity *player) {
    int width_e = enemy->pos_x;
    int width_max_e = enemy->pos_x + enemy->width;    
    int height_e = enemy->pos_y;
    int height_max_e = enemy->pos_y + enemy->height;    
    int width_p = player->pos_x;
    int width_max_p = player->pos_x + player->width;    
    int height_p = player->pos_y;
    int height_max_p = player->pos_y + player->height;

    if((width_p >= width_e && width_p <= width_max_e)
        || (width_max_p >= width_e && width_max_p <= width_max_e) ) {  
        if((height_p >= height_e && height_p <= height_max_e)
            || (height_max_p >= height_e && height_max_p <= height_max_e)) {
            return 1;
        }
    }
    return 0;
}

void verif_out(Entity *enemy) {
    if(enemy->pos_x + enemy->width < 0) {
        reset(enemy);
    }
}

void reset(Entity *enemy) {
    int random = 0;
    while (random < WINDOW_WIDTH) {
        random = rand() % 800;
    }
    int height_max = WINDOW_HEIGHT - enemy->height;
    enemy->pos_x = random;
    enemy->pos_y = rand() % height_max;
}

void initiate_over(Win *app, Entity *over, char *fond) {
    over->width = WINDOW_WIDTH;
    over->height = WINDOW_HEIGHT;
    over->pos_x = 0;
    over->pos_y = 0;
    over->texture = loadTexture(app, fond);
}