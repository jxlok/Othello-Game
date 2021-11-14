/*Assignment_2 written by Jason Lok, 20366363, 28/04/2021
 * Facilitating a game of othello with standard rules and keeps record of winners in othello-results.txt file
 * (this file can be found in cmake-build-debug)*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "library.h"

//structs for players and board of size 8x8
struct player white = {"", 2};
struct player black = {"", 2};
struct slot board[SIZE][SIZE]={"", "", 0};

//initialises basic trackers
int player_turn =  1;
int winner = 0;
int pass_counter=0;

int main() {

    //game starts
    printf("\t\t***\tWelcome to Othello!\t***\n");

    //submits start time to a file
    FILE *fp;

    time_t time1;

    //acquires current time
    time(&time1);

    //opens file
    if((fp = fopen("othello-results.txt", "a"))==NULL){
        puts("Could not append results to file.");
    }
    else{
        //appends current time
        fprintf(fp, "%s", ctime(&time1));
    }

    fclose(fp);

    //function call to initialise player
    initialise_player();

    //function call to initialise board
    initialise_board();

    //displays board
    print_board();

    //game continues until a winner is decided
    while (winner==0){
        player_move(player_turn);
    }

    //function call to display winner info
    determine_winner();
}
