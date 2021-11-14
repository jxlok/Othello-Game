//
// Created by Jason Lok on 29/04/2021.
//
#include "library.h"
#include <stdio.h>
#include <string.h>

//function to capture pieces on the board
void capture_piece(const char position[3], int player) {

    //variables for score, player colour, and opponents colour
    int score=0;
    char mycolour[2];
    char othercolour[2];

    //acquires position of move in terms of 2dimensional array
    int i = position[1] - '1';
    int j = position[0] - 'a';

    struct slot *positionPtr = &board[i][j];

    //if player 1's turn, sets mycolour to b and othercolour to w
    if(player==1) {
        strcpy(mycolour, "b");
        strcpy(othercolour, "w");
    }
    //else if player 2's turn, sets mycolour to w and othercolour to b
    else if(player==2){
        strcpy(mycolour, "w");
        strcpy(othercolour, "b");
    }

    //places the new piece and adds to score tracker
    strcpy(positionPtr->disc, mycolour);
    score+=1;

    //checks bottom if opponents colour
    if (strcmp(board[i + 1][j].disc, othercolour) == 0) {
        //continues checking down position
        for (k = i + 2; k < 8; k++) {
            //if opponents colour, continue checking
            if (strcmp(board[k][j].disc, othercolour) == 0) {
                continue;
            }
            //if mycolour,
            else if (strcmp(board[k][j].disc, mycolour) == 0) {
                //loop back and change tiles
                for(size_t p=k-1;p>i;p--){
                    strcpy(board[p][j].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot
            else {
                break;
            }
        }
    }

    //check upwards position if opponents colour
    if(strcmp(board[i-1][j].disc, othercolour)==0){

        //continue checking upwards
        for(k=i-2;k>=0;k--){

            //if opponents colour, continue upwards
            if(strcmp(board[k][j].disc, othercolour)==0){
                continue;
            }
            //if mycolour,
            else if(strcmp(board[k][j].disc, mycolour)==0){
                //loop back and change tiles
                for(size_t p=k+1;p<i;p++){
                    strcpy(board[p][j].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot and cant capture
            else{
                break;
            }
        }
    }

    //check left position if opponents colour
    if(strcmp(board[i][j-1].disc, othercolour)==0){

        //continue checking left position
        for(k=j-2;k>=0;k--){
            //if opponents colour continue checking left
            if(strcmp(board[i][k].disc, othercolour)==0){
                continue;
            }
            //if mycolour
            else if(strcmp(board[i][k].disc, mycolour)==0){
                //loop back and capture tiles
                for(size_t p=k+1;p<j;p++){
                    strcpy(board[i][p].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot and cant capture
            else{
                break;
            }
        }
    }

    //check right position if opponents colour
    if(strcmp(board[i][j+1].disc, othercolour)==0){
        //continues checking right positions
        for(k=j+2;k<8;k++){
            //if opponents colour, continue checking right
            if(strcmp(board[i][k].disc, othercolour)==0){
                continue;
            }
            //if my colour,
            else if(strcmp(board[i][k].disc, mycolour)==0){
                //loops back and captures tiles
                for(size_t p=k-1;p>j;p--){
                    strcpy(board[i][p].disc, mycolour);
                    //adds to score
                    score+=1;
                }
                break;
            }
            //else empty slot and can't capture
            else{
                break;
            }
        }
    }

    //checks bottom right position for opponents colour
    if(strcmp(board[i+1][j+1].disc, othercolour)==0){
        l= i+2;
        //continues checking bottom right
        for(k=j+2;k<8 && l<8;k++){
            //if opponents colour, continue
            if(strcmp(board[l][k].disc, othercolour)==0){
                l++;
                continue;
            }
            //if my colour,
            else if(strcmp(board[l][k].disc, mycolour)==0){
                //loop back and capture tiles
                for(size_t p=k-1;p>j;p--){
                    strcpy(board[--l][p].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot and can't capture
            else{
                break;
            }
        }
    }

    //checks top right position for opponents colour
    if(strcmp(board[i-1][j+1].disc, othercolour)==0){
        l= i-2;
        //loop checking top right positions
        for(k=j+2;k<8 && l>=0;k++){
            //if opponents colour, continue checking top right
            if(strcmp(board[l][k].disc, othercolour)==0){
                l--;
                continue;
            }
            //if mycolour,
            else if(strcmp(board[l][k].disc, mycolour)==0){
                //loop back and capture tiles
                for(size_t p=k-1;p>j;p--){
                    strcpy(board[++l][p].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot and can't capture any
            else{
                break;
            }
        }
    }

    //check if top left position is opponents colour
    if(strcmp(board[i-1][j-1].disc, othercolour)==0){
        l= i-2;
        //loops top leftward
        for(k=j-2;k>=0 && l>=0;k--){
            //if opponents colour, continue check top left
            if(strcmp(board[l][k].disc, othercolour)==0){
                l--;
                continue;
            }
            //if mycolour,
            else if(strcmp(board[l][k].disc, mycolour)==0){
                //loop back and capture tiles
                for(size_t p=k+1;p<j;p++){
                    strcpy(board[++l][p].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty slot and cannot capture
            else{
                break;
            }
        }
    }
    //checks bottom left position if opponents colour
    if(strcmp(board[i+1][j-1].disc, othercolour)==0){
        l= i+2;
        //loops bottom leftward
        for(k=j-2;k>=0 && l<8;k--){
            //if opponents colour, continue bottom left
            if(strcmp(board[l][k].disc, othercolour)==0){
                l++;
                continue;
            }
            //if mycolour,
            else if(strcmp(board[l][k].disc, mycolour)==0){
                //loop back and capture tiles
                for(size_t p=k+1;p<j;p++){
                    strcpy(board[--l][p].disc, mycolour);
                    //add to score
                    score+=1;
                }
                break;
            }
            //else empty tile and cannot capture in that direction
            else{
                break;
            }
        }
    }

    //if player 1, add to player 1's score
    if (player==1){
        black.score += score;
        white.score -= score-1;
    }
    //if player 2, add to player 2's score
    else if(player==2){
        white.score += score;
        black.score -= score-1;
    }

}