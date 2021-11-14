//
// Created by Jason Lok on 27/04/2021.
//
#include <stdio.h>
#include "library.h"

//function to print the board
void print_board(void){

    //prints player names and scores
    printf("\nScore: %s (Black) %d:%d %s (White)", black.name, black.score, white.score, white.name);
    printf("\n  ");

    for(size_t i=0;i<48;i++){
        printf("-");
    }
    puts("");

    for(size_t i=0;i<SIZE;i++) {

        //prints int index (1-8)
        printf("%d|", i+1);

        for (size_t j = 0; j < SIZE; j++) {

            //prints each slot and whats in it
            struct slot *positionPtr = &board[i][j];
            if(*positionPtr->disc == '\0'){
                printf("     |", *positionPtr->disc);
            }
            else {
                printf("  %c  |", *positionPtr->disc);
            }
        }
        printf("\n  ");
        for(size_t k=0;k<48;k++){
            printf("-");
        }
        puts("");
    }

    printf(" ");

    //prints char index (a-h)
    for(size_t i=0;i<8;i++){
        printf("   %c  ", i + 'a');
    }
    printf("\n  ");
}