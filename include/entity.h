#ifndef ENTITY
#define ENTITY

#include "window.h"
#include "draw.h"

void initiate_player(Win *app, Entity *test);
void initiate_enemy(Win *app, Entity *test, char *path);
int move_enemy(Entity *enemy, Entity *player, int vie);
int verif_collision(Entity *enemy, Entity *player);
void verif_out(Entity *enemy);
void reset(Entity *enemy);
void initiate_over(Win *app, Entity *over, char *fond);

#endif /* ENTITY */
