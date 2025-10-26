#pragma GCC diagnostic ignored "-Wunknown-pragmas"

#ifndef UTILS_H
#define UTILS_H

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#pragma region Colors
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1b[35m"
#define BLACK "\x1b[30m"
#define WHITE "\x1b[37m"
#define CYAN "\x1b[36m"
#define INVISIBLE "\x1b[8m"
#define PISCA "\x1b[5m"
#define INVERSE "\x1b[7m"
#pragma endregion

#define MAX_NAME_GERAL 32   // Tamanho máximo para o nome de qualquer coisa (jogador, item, etc.)
#define MAX_PRINTLINE  100  // Tamanho máximo para o tamanho do print da função print_line()
#define DELAY_DATI 20     // Tempo padrão pro dalay da função datilografar()

typedef struct Position {
    int x, y;
} Pos;

void print_line(const char caracter, int lenght);
void pause_terminal();
void datilografar(int time, const char *texto);
void draw_ascii_file(const char *path, int time);
char *draw_border(int dir, int lenght);
void center_text(const char *txt, const int width, const int is_utf);

#endif