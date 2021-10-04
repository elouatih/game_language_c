#include<stdio.h>
#include<stdlib.h>
#include "game_aux.h"
#include "game.h"

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

int main(void){
    game current_game = game_default();
    game solution_default = game_default_solution();
    game copy_init = game_copy(current_game);
    game_print(current_game);
    printf("? [help] press h for help \n");
    uint *old_i, *old_j;
    old_i = malloc(DEFAULT_SIZE * DEFAULT_SIZE * sizeof(uint));
    old_j = malloc(DEFAULT_SIZE * DEFAULT_SIZE * sizeof(uint));
    int count = 0;
    while (1) {
        char *s = malloc(5 * sizeof(char));
        //Boucle du jeu
        s[1] = ' ';
        s[3] = ' ';
        for(int i=0; i<5; i+=2){
            char c;
            scanf(" %c", &c);
            if(c == 'q'){
                printf("action : quit the game \n");
                printf("What a shame : you quit\n");
                return EXIT_SUCCESS;
            } else if (c == 'r'){
                current_game = copy_init;
                printf("action : restart the game \n");
                game_print(current_game);
                break;
            } else if (c == 'h'){
                printf("action : help \n");
                printf("press 'l <i> <j>' to put a light bulb at square (i,j)\n");
                printf("press 'm <i> <j>' to put a mark at square (i,j)\n");
                printf("press 'b <i> <j>' to blank square (i,j)\n");
                printf("press 'r' to restart\n");
                printf("press 'q' to quit\n");
                break;
            } else {
                s[i] = c;
            }
        }
        if(s[0] == 'l' || s[0] == 'm' || s[0] == 'b'){
            uint i = (uint)s[2] - '0';
            uint j = (uint)s[4] - '0';
            square current_square = char_to_square(s[0]);
            if (game_check_move(current_game, i, j, current_square)) {
                game_play_move(current_game, i, j, current_square);
                if(count > 0){
                    for(int y = 0; y<count; y++){
                        game_set_square(current_game, old_i[y], old_j[y], current_square);
                    }
                }
                game_set_square(current_game, i, j, current_square);
                if(current_square == S_LIGHTBULB){
                    old_i[count] = i;
                    old_j[count] = j;
                    count++;
                }
            }
            printf("? [help] press h for help \n");
            game_print(current_game);
            for(int z=0; z<DEFAULT_SIZE; z++){
                for(int l=0; l<DEFAULT_SIZE; l++){
                    if(game_has_error(current_game, z, l)){
                        printf("Error flag in square (%d, %d) \n", l, z);
                    }
                }
            }
        }
        if(game_equal(current_game, solution_default)){
            printf("Congratulations !!! You win. \n");
            return EXIT_SUCCESS;
        }
    }
}
