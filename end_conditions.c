//
// Created by Jason Lok on 30/04/2021.
//
#include "library.h"

//function for end condition checker
void end_conditions(void){

    //end condition: if board is filled
    if((black.score+white.score)==64){
        //black is winner
        if(black.score>white.score){
            winner = 1;
        }
        //white is winner
        else if(white.score>black.score){
            winner = 2;
        }
        //tie
        else{
            winner =3;
        }
    }

    //end condition: if two passes have occurred
    if(pass_counter==2){
        //black wins
        if(black.score>white.score){
            winner = 1;
        }
        //white wins
        else if(white.score>black.score){
            winner = 2;
        }
        //tie
        else{
            winner = 3;
        }
    }
}