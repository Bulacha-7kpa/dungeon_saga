#ifndef PLAYER_H
#define PLAYER_H

#include "item_node.h"

typedef struct Player {
    char nome[MAX_NAME_GERAL];
    int hp, atk;
    Pos position;
    ItemNode *inventory;
} Player;

#endif