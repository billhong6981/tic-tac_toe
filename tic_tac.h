#ifndef _TIC_TAC_H
#define _TIC_TAC_H
#include <stdio.h>
#include <stdlib.h>

/* data structure */
/**
 * struct arg_s - a function arguments collection struct
 *
 * @player_0: name of player number 1
 * @player_1: name of player number 2
 * @board: tic_tac_toe game board layout
 * @matrix: a data collection for players during the game
 * @turns: counter of taking turn of player, increased by one
 * Description: data struct for the game
 */
typedef struct arg_s
{
	char *player_0;
	char *player_1;
	int **board;
	int ***matrix;
	int turns;
	int flag;
	int player_0_win;
	int player_1_win;
	int draw;
	int count;
} arg_t;
extern arg_t args;
arg_t args = {NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0};

typedef struct data_s
{
	int square;
	int *board_2;
	int *matrix_2;
	int *matrix_3;
} data_t;
#endif /* _TIC_TAC_H */
