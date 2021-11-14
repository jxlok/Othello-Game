//
// Created by Jason Lok on 27/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H

#define SIZE 8

void initialise_player(void);
void initialise_board(void);
void print_board(void);
void player_move(int player);
int validate_move(char position[3], int player);
int possible_move(int player);
void capture_piece(const char position[3], int player);
void end_conditions(void);
void determine_winner(void);

struct player{
    char name[15];
    int score;
};

struct slot{
    char disc[2];
    char charposition[3];
    int intposition;
};

struct player white;
struct player black;
struct slot board[SIZE][SIZE];

int player_turn;
int counter;
char available_moves[64][3];
int winner;
int pass_counter;
char winner1[15];
int winner_score;
int loser_score;
int k, l;
#endif //ASSIGNMENT_2_LIBRARY_H
