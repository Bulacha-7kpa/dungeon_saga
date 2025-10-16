#include "utils.h"

void print_line(const char caracter, int lenght) {
    printf("\n" MAGENTA);
    for (int i=0; i<lenght; i++) {
        putchar(caracter);
    }
    printf("\n" RESET);
}

void show_title(int hp, int atk) {
    system("cls");
    print_line('=', MAX_PRINTLINE);                                           //
    printf(YELLOW "                   Dungeon Saga v1.0                 \n" RESET);
    printf(RED    "                      By: B7K (PH)                   " RESET);
    print_line('=', MAX_PRINTLINE);
    printf("move: WASD | i: inventory | p: pickup | q: quit" RESET);
    print_line('-', MAX_PRINTLINE);                   //
    printf("Player:          HP: %i  |  ATK: %i ~ %i\n        ", hp, atk / 2, atk);
}

void pause_terminal() {
    printf("Press ENTER to continue...");

    while (getchar() != '\n');
    
    return;
}










