#include "game_aux.h"
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

square char_to_square(char c){
    if(c == 'l'){
        return S_LIGHTBULB;
    } else if(c == 'm') {
        return S_MARK;
    } else if(c == 'b'){
        return S_BLANK;
    } else {
        return S_BLACK0;
    }
}

void game_print(cgame g){
    printf("    0123456\n");
    printf("    -------\n");
    for(int i=0; i<DEFAULT_SIZE; i++){
        printf("%d  |", i);
        for(int j=0; j<DEFAULT_SIZE; j++) {
            int state = game_get_square(g, i, j);
            if(state == 0){
                printf(" ");
            } else{
                printf("%d", state);
            }
        }
        printf("|\n");
    };
    printf("    -------\n");
}
game game_default(void) {
    /*square *squares = malloc(DEFAULT_SIZE * DEFAULT_SIZE * sizeof(square));
    for(int i=0; i<DEFAULT_SIZE * DEFAULT_SIZE; i++){
        squares[i] = S_BLANK;
    }*/
    game current_game = game_new_empty();
    game_print(current_game);
    printf("? [help] press h for help \n");
    printf("? [new Empty Game] press r to restart game \n");
    printf("? [quit] press q to quit the game \n");
    bool win_game = false;
    while (1) {
        char c;
        int ret = scanf(" %c", &c);
        if (c == 'q') {
            win_game = false;
            return 0;
        } else if (c == 'h') {
            printf("Commande sous forme <c> <i> <j> \n");
            continue;
        } else if (c == 'r') {
            game_restart(current_game);
            current_game = game_new_empty();
            printf("Le jeu est reinitialise \n");
            continue;
        } else {
            char *s = malloc(3 * sizeof(char));
            for (int k = 0; k < 3; k++) {
                char l;
                int r = scanf(" %c", &l);
                s[k] = l;
            }
            printf("here \n");
            uint i = (uint)s[1] - '0';
            printf(" i = %u \n", i);
            uint j = (uint)s[2] - '0';
            printf(" j = %u \n", j);
            square current_square = char_to_square(s[0]);
            bool true_or_false = game_check_move(current_game, i, j, current_square);
            printf("MOVE POSSIBLE = %d \n", true_or_false ? 1: 0);
            if (true_or_false) {
                game_set_square(current_game, i, j, current_square);
                //game_play_move(current_game, i, j, current_square);
            }
        }
        printf("");
        game_print(current_game);
        printf("? [help] press h for help \n");
        printf("? [new Empty Game] press r to restart game \n");
        printf("? [quit] press q to quit the game \n");
    }
}
game game_default_solution(void){
    return NULL;
}
