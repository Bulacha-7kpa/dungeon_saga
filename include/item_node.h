#ifndef ITEM_NODE_H
#define ITEM_NODE_H

#include "utils.h"

typedef struct ItemNode {
    char name[MAX_NAME_GERAL];
    int quant;
    struct ItemNode *next;
} ItemNode;

#endif