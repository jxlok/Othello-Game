//
// Created by Jason Lok on 30/04/2021.
//

#include "library.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

//function to determine winner
void determine_winner(void){

    FILE *fp;

    //if winner is player 1
    if(winner==1){
        //display winner, acquire winner's name and scores
        printf("\n%s wins!!\n", black.name);
        strcpy(winner1, black.name);
        winner_score = black.score;
        loser_score = white.score;

        //print final board
        printf("\nFinal board:");
        print_board();
    }

    //if player 2 wins
    else if (winner==2){
        //print player 2's name, acquire name and scores
        printf("\n%s wins!!\n", white.name);
        strcpy(winner1, white.name);
        winner_score = white.score;
        loser_score = black.score;
        //print final board
        printf("\nFinal board:");
        print_board();
    }
    //tie
    else {
        //print tie and set no winner and final score
        printf("\nTie!\n");
        strcpy(winner1, "Tie");
        winner_score = black.score;
        loser_score = white.score;
        printf("\nFinal board:");
        print_board();
    }

    //opens file
    if((fp = fopen("othello-results.txt", "a"))==NULL){
        puts("Could not append results to file.");
    }
    else{
        //appends to file winner, winners score and losers score
        fprintf(fp, "Winner:%s Score:%d-%d\n\n", winner1, winner_score, loser_score);
    }

    fclose(fp);
}