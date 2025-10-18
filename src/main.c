#include "player.h"
#include "map.h"

int main() {

    int opc;
    Map *mapa[2];

    mapa[0] = build_map(10, 10);
    mapa[1] = build_map(10, 5);

    while (1) {
        show_title(10, 6);

        datilografar(DELAY_DATI, "Qual mapa quer desenhar (0, 1)? ");
        scanf(" %i", &opc);
        fflush(stdin);

        draw_map(*mapa[opc]);

        pause_terminal();

        pause_terminal();
    }
    
    return 0;
}