//
// Created by Jason Lok on 28/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "library.h"

//function to acquire a list of possible moves
int possible_move(int player){

    //variables for player's colour and oponents colour
    char mycolour[2];
    char othercolour[2];

    //counter for list size
    counter=0;

    //change mycolour to b and othercolour to w if player 1's turn
    if(player==1) {
        strcpy(mycolour, "b");
        strcpy(othercolour, "w");
    }

    //or change mycolour to w and othercolour to b if player 2's turn
    else if(player==2){
        strcpy(mycolour, "w");
        strcpy(othercolour, "b");
    }

    //loops through each position
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {

            //resets boolean for position passing rules to false
            bool pass = false;
            struct slot *positionPtr = &board[i][j];

            //if position is empty, check if adjacent positions may be captured
            if (*positionPtr->disc == '\0') {

                //checks down position if opponents colour
                if (strcmp(board[i + 1][j].disc, othercolour) == 0) {

                    //continues checking further down
                    for (k = i + 2; k < 8; k++) {
                        //if opponents colour continues checking down again
                        if (strcmp(board[k][j].disc, othercolour) == 0) {
                            continue;
                        }
                        //if mycolour, position passes and may be placed here
                        else if (strcmp(board[k][j].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //else if blank and cant be captured
                        else {
                            break;
                        }
                    }
                }

                //checks up position if opponents colour
                if (strcmp(board[i - 1][j].disc, othercolour) == 0) {

                    //continues checking up
                    for (k = i - 2; k >= 0; k--) {
                        //if opponents colour, continue up
                        if (strcmp(board[k][j].disc, othercolour) == 0) {
                            continue;
                        }
                        //if mycolour, position passes and may be placed here
                        else if (strcmp(board[k][j].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //otherwise empty and fails
                        else {
                            break;
                        }
                    }
                }

                //checks left position
                if (strcmp(board[i][j - 1].disc, othercolour) == 0) {

                    // continues checking left position
                    for (k = j - 2; k >= 0; k--) {
                        //if opponents colour, continues checking left
                        if (strcmp(board[i][k].disc, othercolour) == 0) {
                            continue;
                        }
                        //if my colour, position is a possible move
                        else if (strcmp(board[i][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //else empty slot and fails
                        else {
                            break;
                        }
                    }
                }

                //if right position is opponents colour
                if (strcmp(board[i][j + 1].disc, othercolour) == 0) {

                    //continues checking right
                    for (k = j + 2; k < 8; k++) {

                        //if opponents colour, continue checking right
                        if (strcmp(board[i][k].disc, othercolour) == 0) {
                            continue;
                        }
                        //if mycolour, position is a possible move
                        else if (strcmp(board[i][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //otherwise empty slot and fails
                        else {
                            break;
                        }
                    }
                }

                //checks bottom right position for opponents colour
                if (strcmp(board[i + 1][j + 1].disc, othercolour) == 0) {
                    l = i + 2;

                    //continues checking bottom right
                    for (k = j + 2; k < 8 && l < 8; k++) {
                        //if opponents colour, continue checking bottom right
                        if (strcmp(board[l][k].disc, othercolour) == 0) {
                            l++;
                            continue;
                        }
                        //if mycolour, position is a possible move
                        else if (strcmp(board[l][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //else empty slot and fails
                        else {
                            break;
                        }

                    }
                }

                //checks top right position
                if (strcmp(board[i - 1][j + 1].disc, othercolour) == 0) {
                    l = i - 2;
                    //continues checking top right position
                    for (k = j + 2; k < 8 && l >= 0; k++) {
                        //if opponents colour, continue checking
                        if (strcmp(board[l][k].disc, othercolour) == 0) {
                            l--;
                            continue;
                        }
                        //if mycolour, passes check
                        else if (strcmp(board[l][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //else empty and fails
                        else {
                            break;
                        }
                    }
                }

                //checks top left position if opponents colour
                if (strcmp(board[i - 1][j - 1].disc, othercolour) == 0) {
                    l = i - 2;

                    //continue checking top left position
                    for (k = j - 2; k >= 0 && l >= 0; k--) {
                        //if opponents colour, continue
                        if (strcmp(board[l][k].disc, othercolour) == 0) {
                            l--;
                            continue;
                        }
                        //if mycolour, passes check
                        else if (strcmp(board[l][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //otherwise empty and fails
                        else {
                            break;
                        }
                    }
                }

                //checks bottom left position if opponents colour
                if (strcmp(board[i + 1][j - 1].disc, othercolour) == 0) {
                    l = i + 2;

                    //continues checking bottom left
                    for (k = j - 2; k >= 0 && l < 8; k--) {
                        //if opponents colour, continue
                        if (strcmp(board[l][k].disc, othercolour) == 0) {
                            l++;
                            continue;
                        }
                        //if mycolour, passes checks
                        else if (strcmp(board[l][k].disc, mycolour) == 0) {
                            pass = true;
                            break;
                        }
                        //else empty and fails
                        else {
                            break;
                        }
                    }
                }

                //if position had passes check, add to array available_moves
                if (pass == true) {
                    available_moves[counter][0] = j + 'a';
                    available_moves[counter][1] = i + '1';
                    available_moves[counter++][2] = '\0';
                }

            }
        }
    }
    
}