#ifndef MAP_H
#define MAP_H

#include "utils.h"
#include "player.h"

typedef struct Map {
    int width, height;
    char **tiles;
} Map;


Map *build_map(int width, int height);
void draw_map(Map map, Player *player);

#endif