#include "player.h"
#include "map.h"

int main() {
    system("cls");
    Sleep(2000);
    draw_ascii_file("./Assets/Images/title.txt", 250);
    printf("\n\n");
    draw_ascii_file("./Assets/Images/castle.txt", 250);
    pause_terminal();

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
        print_line('=', 60);
        draw_ascii_file("./Assets/Images/pikachu.txt", 1000);

        pause_terminal();
    }
    
    return 0;
}