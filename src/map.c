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

void draw_map(Map map) {
    print_line('=', MAX_PRINTLINE);
    putchar('\n');

    for (int i=0; i<map.height; i++) {
        printf("  ");
        for (int j=0; j<map.width; j++) {
            printf("  %c  ", map.tiles[i][j]);
        }
        printf("\n\n");
    }

    print_line('=', MAX_PRINTLINE);
    
    return;
}
















