#ifndef PLAYER_H
#define PLAYER_H

#include "item_node.h"

typedef struct Player {
    char nome[MAX_NAME_GERAL];
    int hp, atk, mana, gold;
    Pos position;
    ItemNode *weapon, *armor;
    ItemNode *inventory;
} Player;

#endif