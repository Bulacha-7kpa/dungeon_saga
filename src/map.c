#include "map.h"

Map *build_map(int width, int height) {
    Map *map = malloc(sizeof(Map));

    map->height = height;
    map->width = width;

    map->tiles = (char **) malloc(sizeof(char*) * height);

    if (map->tiles == NULL) {
        print_line('=', MAX_PRINTLINE);
        printf("[ ERROR ] Something went wrong while creating the map.");
        print_line('=', MAX_PRINTLINE);
        pause_terminal();
    }

    for (int i=0; i < height; i++) {
        map->tiles[i] = (char *) malloc(sizeof(char) * width);
        for (int j=0; j < width; j++) {
            map->tiles[i][j] = '.';
        }
    }
    
    return map;
}

void draw_map(Map map, Player *player) {
    //print_line('=', MAX_PRINTLINE);
    draw_border('w', map.width*5);
    putchar('\n');
    for (int y=0; y<map.height; y++) {
        printf("║");
        for (int x=0; x<map.width; x++) {
            if (player->position.x == x && player->position.y == y) {
                printf(BLUE "  ⚉  " RESET);
            } else {
                printf(INVISIBLE "  %c  ", map.tiles[y][x]);
                printf(RESET);
            }
        }
        printf("║\n║");
        for (int i=0; i<map.width*5; i++) {
            printf(" ");
        }
        printf("║\n");
    }
    draw_border('s', map.width * 5);

    print_line('=', MAX_PRINTLINE);
    
    return;
}
















