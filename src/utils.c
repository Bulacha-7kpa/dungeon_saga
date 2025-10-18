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

    print_line('=', MAX_PRINTLINE);

    printf(YELLOW "                   D U G E O N   S A G A v1.0                 \n" RESET);
    printf(RED    "                      By: B7K (PH)                   " RESET);

    print_line('=', MAX_PRINTLINE);

    printf("move: WASD | i: inventory | p: pickup | q: quit" RESET);
    
    print_line('-', MAX_PRINTLINE);

    printf("Player:          HP: %i  |  ATK: %i ~ %i\n        ", hp, atk / 2, atk);
}

void pause_terminal() {
    printf("\nPress ENTER to continue...");

    while (getchar() != '\n');
    
    return;
}

void datilografar(int time, const char *texto) {

    for (int i=0; texto[i] != '\0'; i++) {
        putchar(texto[i]);

        fflush(stdout);

        Sleep(time);
    }

    return;
}

void draw_ascii_file(const char *path, int time) {
    FILE *arq = fopen(path, "r");
    if (arq == NULL) {
        print_line('=', MAX_PRINTLINE);
        printf("No files found.");
        print_line('=', MAX_PRINTLINE);
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), arq) != NULL) {
        printf("%s", line);
        Sleep(time);
        fflush(stdout);
    }

    fclose(arq);
    return;
}


