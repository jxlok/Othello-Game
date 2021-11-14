//
// Created by Jason Lok on 27/04/2021.
//
#include <stdio.h>
#include "library.h"

//function to acquire names of players
void initialise_player(void) {

    //player 1's name
    printf("Enter name of Player 1 (Black):");
    scanf("%s", black.name);

    //player 2's name
    printf("Enter name of Player 2 (White):");
    scanf("%s", white.name);
}