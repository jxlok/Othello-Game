//
// Created by Jason Lok on 28/04/2021.
//
#include <stdio.h>
#include <string.h>
#include "library.h"

//function to validate the move
int validate_move(char position[3], int player){

    //if user input is "p"
    if(strcmp(position, "p")==0){
        //passes if available moves counter is empty
        if(counter==0){
            return 0;
        }
        //otherwise fails
        else{
            printf("Cannot pass.\n");
            return 1;
        }
    }

    //position (ld) inputted, loop through available_moves
    for(size_t i=0;i<counter;i++){
        //check if inputted move is within available moves
        if(strcmp(available_moves[i], position)==0){
            //captures position and prints board
            capture_piece(position, player);
            print_board();
            return 0;
        }
    }
    //otherwise isn't an available move and fails
    printf("Invalid move.\n");
    return 1;
}