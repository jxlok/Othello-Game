//
// Created by Jason Lok on 27/04/2021.
//
#include <stdio.h>
#include <string.h>
#include "library.h"

//function to take a players move
void player_move(int player){

    char move[3];

    //player 1's turn
    if(player==1){

        printf("__Black's move__\n");

        //function call to acquire possible moves
        possible_move(player);

        //if no possible moves available
        if(counter==0){
            printf("No available moves.\n");
            pass_counter++;
        }

        //if a move available
        else{
            printf("Available moves: ");
            //prints available moves
            for(size_t i=0;i<counter;i++){
                printf("%s ", available_moves[i]);
            }
            puts("");
            //resets pass counter
            pass_counter=0;
        }
        //beckons for user input for move and validates move
        do{
            printf("Enter slot to place black piece (ld) or pass (p) if no moves available:");
            scanf("%s", move);
        }while(validate_move(move, player));

        //next players turn
        player_turn=2;
    }

    //player 2's turn
    else if(player==2){

        printf("__White's move__\n");

        //acquires possible moves
        possible_move(player);

        //no moves available
        if(counter==0){
            printf("No available moves.\n");
            pass_counter++;
        }

        //a move available
        else{
            printf("Available moves: ");

            //prints available moves
            for(size_t i=0;i<counter;i++){
                printf("%s ", available_moves[i]);
            }
            puts("");

            //reset pass counter
            pass_counter=0;
        }

        //asks for user input for move and validates
        do{
            printf("Enter slot to place white piece (ld) or pass (p) if no moves available:");
            scanf("%s", move);

        }while(validate_move(move, player));

        //next player's turn
        player_turn=1;
    }

    //function call to check if end conditions have been met
    end_conditions();

}