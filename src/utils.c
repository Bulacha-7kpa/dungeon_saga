#include "utils.h"

void print_line(const char caracter, int lenght) {
    printf("\n" MAGENTA);
    for (int i=0; i<lenght; i++) {
        putchar(caracter);
    }
    printf("\n" RESET);
}

void pause_terminal() {
    printf(RED "Press ENTER to continue..." RESET);

    while (getchar() != '\n');
    
    return;
}

void datilografar(int time, const char *texto) {

    Mix_Chunk *efeito = Mix_LoadWAV("./Assets/Sound/bgs_digitando.wav");
    if (!efeito) {
        printf("Erro ao carregar música: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    if (Mix_PlayChannel(-1, efeito, 0) < 0) {
        printf("Erro ao tocar música: %s\n", Mix_GetError());
        Mix_FreeChunk(efeito);
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    for (int i=0; texto[i] != '\0'; i++) {
        putchar(texto[i]);

        fflush(stdout);

        Sleep(time);
    }

    Mix_FreeChunk(efeito);

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

    Mix_Chunk *efeito = Mix_LoadWAV("./Assets/Sound/se_typewriter.wav");
    if (!efeito) {
        printf("Erro ao carregar música: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return;
    }

    Mix_VolumeChunk(efeito, 30);

    

    while (fgets(line, sizeof(line), arq) != NULL) {
        Mix_PlayChannel(-1, efeito, 0);
        printf("%s", line);
        Sleep(time);
        fflush(stdout);
    }

    Mix_FreeChunk(efeito);

    fclose(arq);
    return;
}

char *draw_border(int dir, int lenght) {

    char *border = malloc(4 + (lenght * 4) + 4 + 1);
    if (!border) return NULL;
    border[0] = '\0';
    
    //printf("%s", (dir == 'w' ? "╔" : "╚"));
    strcat(border, (dir == 'w' ? "╔" : "╚"));
 
    for (int i=0; i<lenght; i++) strcat(border, "═"); //printf("═");

    //printf("%s", (dir == 'w' ? "╗" : "╝"));
    strcat(border, (dir == 'w' ? "╗" : "╝"));

    return border;
}

void center_text(const char *txt, const int width, const int is_utf) {
    int len = strlen(txt);
    int padding = (is_utf == 1) ? (width - (len/4)) / 2 : (width - len) / 2;

    for (int i=0; i<padding; i++) printf(" ");

    printf("%s", txt);
}




