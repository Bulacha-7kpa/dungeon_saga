#include "player.h"
#include "map.h"

int main() {

    int opc;
    Map *mapa[2];

    mapa[0] = build_map(10, 10);
    mapa[1] = build_map(10, 5);

    //mapa[0] = build_map(10, 10);

    while (1) {
        show_title(10, 6);
        printf("Qual mapa quer desenhar (0, 1, 2)? ");
        scanf(" %i", &opc);
        draw_map(*mapa[opc]);
        pause_terminal();
        system("pause");
    }
    
    return 0;
}