#include "player.h"
#include "map.h"

void menu_inicial(int selecionado) {

    char *border1 = draw_border('w', 20);
    printf(MAGENTA);
    center_text(border1, 100, 1);
    free(border1);

    printf("\n" RESET);

    center_text(" ", (106 - strlen("Novo Jogo")), 0);
    printf((selecionado == 0) ? INVERSE : RESET);
    printf("Novo Jogo\n" RESET);

    center_text(" ", (106 - strlen("Continuar Jogo")), 0);
    printf((selecionado == 1) ? INVERSE : RESET);
    printf("Continuar Jogo\n" RESET);

    center_text(" ", (106 - strlen("Credits")), 0);
    printf((selecionado == 2) ? INVERSE : RESET);
    printf("Credits\n" RESET);

    center_text(" ", (106 - strlen("Sair do Jogo")), 0);
    printf((selecionado == 3) ? INVERSE : RESET);
    printf("Sair do Jogo\n");

    printf(RESET);

    char *border2 = draw_border('s', 20);
    printf(MAGENTA);
    center_text(border2, 100, 1);
    printf(RESET);
    free(border2);

    return;
}

void show_credits() {
    system("cls");
    draw_ascii_file("./Assets/Images/title.txt", 0);
    printf("\n\n");

    char *border1 = draw_border('w', 30);
    printf(MAGENTA);
    center_text(border1, 100, 1);
    printf(RESET);
    free(border1);

    printf(RED "\n");
    center_text("Equipe Desenvolvedora: \n", 110, 0);
    printf("\n" RESET);
    center_text("Ph\n", 110, 0);
    center_text("Ane Ariely\n", 110, 0);
    center_text("Raul Gabriel\n", 110, 0);
    center_text("Thiago Henrique\n", 110, 0);
    center_text("Kauan Davi\n", 110, 0);
    printf("\n\n");
    center_text(YELLOW"Obrigado!\n"RESET, 120, 0);

    char *border2 = draw_border('s', 30);
    printf(MAGENTA);
    center_text(border2, 100, 1);
    printf(RESET);
    free(border2);

    printf("\n\n");
    center_text(" ", 85, 0);
    
    while (getch() != 13);
    return;
}

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Inicializa SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erro ao inicializar SDL_mixer: %s\n", Mix_GetError());
        SDL_Quit();
        return 1;
    }
    pause_terminal();

    SetConsoleOutputCP(65001); // Permitir caracteres UTF-8

    system("cls");
    printf(RED);
    draw_ascii_file("./Assets/Images/title.txt", 250); // 250

    Mix_Music *musica = Mix_LoadMUS("./Assets/Sound/bgm_menu_inicial.mp3");
    if (!musica) {
        printf("Erro ao carregar música: %s\n", Mix_GetError());
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    if (Mix_PlayMusic(musica, -1) < 0) {
        printf("Erro ao tocar música: %s\n", Mix_GetError());
        Mix_FreeMusic(musica);
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    printf("\n\n" RESET);
    draw_ascii_file("./Assets/Images/castle.txt", 10); // 150

    int selecionado = 0;

    while (1) {
        system("cls");

        printf(RED);
        draw_ascii_file("./Assets/Images/title.txt", 0);
        printf("\n\n" BLACK);
        draw_ascii_file("./Assets/Images/castle.txt", 0);

        printf("\n\n\n");

        menu_inicial(selecionado);

        char c = getch();

        selecionado += (c == 'w') ? (selecionado == 0) ? 0 : -1 : (c == 's') ? (selecionado == 3) ? 0 : 1 : 0;
        Mix_Chunk *se = Mix_LoadWAV("./Assets/Sound/se_typewriter.wav");
        if (!se) {
            printf("Erro ao carregar música: %s\n", Mix_GetError());
            Mix_CloseAudio();
            SDL_Quit();
            return 1;
        }

        Mix_VolumeChunk(se, 30);

        Mix_PlayChannel(-1, se, 0);

        if (c == 13) {
            if (selecionado == 0) break;
            else if (selecionado == 1);
            else if (selecionado == 2) show_credits();
            else if (selecionado == 3) {
                Mix_FreeMusic(musica);
                Mix_CloseAudio();
                SDL_Quit();
                return 0;
            } else {};
        }
    }
    system("cls");
    Sleep(2000);
    printf(MAGENTA);
    draw_ascii_file("./Assets/Images/gate.txt", 150);
    Sleep(2000);
    printf(YELLOW);
    datilografar(20, "\n\x1b[3;45H꧁•⊹٭Republica Antidemocratica Brazyliense٭⊹•꧂");
    printf(RESET);
    Sleep(1000);
    datilografar(60,"\x1b[6;40HEra uma vez... ");
    Sleep(1000);
    datilografar(40, "uma gloriosa vila de nome pintópoliz.\n");
    Sleep(500);
    datilografar(40, "\x1b[9;47HUma feliz vila cujo os poucos habitantes mal conseguem conter o excesso de dopamina!");
    Sleep(700);
    datilografar(40, "\x1b[10;45Hprincipalmente advinda das casas de investimento, ou como os ignorantes chamam, ꧁•⊹Cassino٭⊹•꧂   ;)");
    Sleep(1000);
    datilografar(60, "\x1b[13;40HInfelizmente pintópoliz está sendo atingida pelo mal do século... ");
    Sleep(500);
    datilografar(30, "o temido Vandalismo!");
    Sleep(1000);
    datilografar(40, "\x1b[14;43HDiversas galinhas e bacurins de raça já foram roubados, ");
    Sleep(500);
    datilografar(40, "e o prefeito Lulu Luliz III nada faz, como pode!?");
    Sleep(700);
    datilografar(40, "\x1b[17;46HEm meio a isso tudo, surge em pintópoliz uma nova figura de nome Maltus, ");
    Sleep(500);
    datilografar(40, "homem simples e justo.");
    Sleep(1000);
    datilografar(40, "\x1b[20;40HFelizmente para Maltus, os problemas de Pintópoliz não lhe convém.");
    Sleep(500);
    datilografar(40, "\x1b[21;43HSeu único objetivo é encontrar sua mulher perdida, ");
    Sleep(700);
    datilografar(70, "justo não?\n\n\n\n\n");

    pause_terminal();

    while (1) {

    }
    
    return 0;
}