#include "game_aux.h"
#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char square_to_char(square s){
    if(s == S_BLANK) return ' ';
    else if(s == S_LIGHTBULB) return '*';
    else if(s == S_BLACK0) return '0';
    else if(s == S_BLACK1) return '1';
    else if(s == S_BLACK2) return '2';
    else if(s == S_BLACK3) return '3';
    else if(s == S_BLACK4) return '4';
    else if(s == S_BLACKU) return 'w';
    else if(s == S_MARK) return '-';
    else if(s == F_LIGHTED) return '.';
    else return ' ';
}

void game_print(cgame g){
    printf("    0123456\n");
    printf("    -------\n");
    for(int i=0; i<DEFAULT_SIZE; i++){
        printf("%d  |", i);
        for(int j=0; j<DEFAULT_SIZE; j++) {
            square s = game_get_square(g, i, j);
            printf("%c", square_to_char(s));
        }
        printf("|\n");
    };
    printf("    -------\n");
}
game game_default(void) {
    game current_game = game_new_empty();
    square **tab = malloc(DEFAULT_SIZE * sizeof(square *));
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        tab[i] = malloc(DEFAULT_SIZE * sizeof(square));
    }
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            tab[i][j] = S_BLANK;
        }
    }
    tab[0][3] = S_BLACK1;
    tab[0][5] = S_BLACK0;
    tab[1][0] = S_BLACKU;
    tab[2][2] = S_BLACKU;
    tab[2][4] = S_BLACKU;
    tab[3][0] = S_BLACKU;
    tab[3][6] = S_BLACKU;
    tab[4][2] = S_BLACKU;
    tab[4][4] = S_BLACK3;
    tab[5][6] = S_BLACKU;
    tab[6][1] = S_BLACK3;
    tab[6][3] = S_BLACK2;
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            game_set_square(current_game, i, j, tab[i][j]);
        }
    }
    return current_game;
}

game game_default_solution(void){
    game current_game = game_new_empty();
    square **tab = malloc(DEFAULT_SIZE * sizeof(square *));
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        tab[i] = malloc(DEFAULT_SIZE * sizeof(square));
    }
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            tab[i][j] = F_LIGHTED;
        }
    }
    tab[0][3] = S_BLACK1;
    tab[0][5] = S_BLACK0;
    tab[1][0] = S_BLACKU;
    tab[2][2] = S_BLACKU;
    tab[2][4] = S_BLACKU;
    tab[3][0] = S_BLACKU;
    tab[3][6] = S_BLACKU;
    tab[4][2] = S_BLACKU;
    tab[4][4] = S_BLACK3;
    tab[5][6] = S_BLACKU;
    tab[6][1] = S_BLACK3;
    tab[6][3] = S_BLACK2;

    tab[0][2] = S_LIGHTBULB;
    tab[1][4] = S_LIGHTBULB;
    tab[2][0] = S_LIGHTBULB;
    tab[2][6] = S_LIGHTBULB;
    tab[3][4] = S_LIGHTBULB;
    tab[4][3] = S_LIGHTBULB;
    tab[4][5] = S_LIGHTBULB;
    tab[5][1] = S_LIGHTBULB;
    tab[6][0] = S_LIGHTBULB;
    tab[6][2] = S_LIGHTBULB;
    tab[6][4] = S_LIGHTBULB;

    for (int i = 0; i < DEFAULT_SIZE; i++) {
        for (int j = 0; j < DEFAULT_SIZE; j++) {
            game_set_square(current_game, i, j, tab[i][j]);
        }
    }
    return current_game;
}
