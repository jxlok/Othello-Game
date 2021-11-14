cmake_minimum_required(VERSION 3.17)
project(Assignment_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment_2 main.c library.h initialise_player.c initialise_board.c print_board.c player_move.c validate_move.c possible_move.c capture_piece.c end_conditions.c determine_winner.c)