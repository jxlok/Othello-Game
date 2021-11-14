//
// Created by Jason Lok on 27/04/2021.
//
#include <stdio.h>
#include <string.h>
#include "library.h"

//function to create the initial board
void initialise_board(void){
    int i, j;

    //loops through each slot and sets whats in it to \0, w or b depending on positions
    for(i=0;i<SIZE;i++){

        for (j=0;j<SIZE;j++){
            struct slot *positionPtr = &board[i][j];

            //for positions 4d and 5e put white and acquire position
            if((i==3 && j==3)||(i==4 && j==4)){
                *positionPtr->disc = 'w';
                *positionPtr->charposition = 'a'+j;
                positionPtr->intposition = i+1;
            }

            //for positions 4e and 5d put black and acquire position
            else if((i==3 && j==4)||(i==4 && j==3)){
                *positionPtr->disc = 'b';
                *positionPtr->charposition = 'a'+j;
                positionPtr->intposition = i+1;
            }

            //otherwise put null terminator and acquire position
            else{
                *positionPtr->disc = '\0';
                *positionPtr->charposition = 'a'+j;
                positionPtr->intposition = i+1;
            }

        }
    }
}