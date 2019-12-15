#include "tic_tac.h"
/**
 * print_board - prints game board
 * Return: void
 */
void print_board(void)
{
	int i, j;

	printf("\n-------------------\n");
	for (i = 0; i < 3; i++)
	{
		printf("|     |     |     |\n");
		for (j = 0; j < 3; j++)
		{
			if ( args.board[i][j] > 10)
				printf("|  %c  ", args.board[i][j]);
			else
				printf("|  %d  ", args.board[i][j]);
		}
		printf("|\n");
		printf("|     |     |     |\n");
		printf("-------------------\n");
	}
}
/**
 * init - initializes args
 * Return: void
 */
void init(void)
{
	int i, j, k = 1;
	int **board_1;
	int ***matrix_1;

	board_1 = malloc(sizeof(int *) * 3);
	if (!board_1)
		exit(1);
	for (i = 0; i < 3; i++)
	{
		board_1[i] = malloc(sizeof(int) * 3);
		if (!board_1[i])
			exit(1);
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++, k++)
		{
			board_1[i][j] = k;
		}
	}
	matrix_1 = malloc(sizeof(int *) * 2);
	if (!matrix_1)
		exit(1);
	for (i = 0; i < 2; i++)
	{
		matrix_1[i] = malloc(sizeof(int *) * 3);
		if (!matrix_1[i])
			exit(1);
		for (j = 0; j < 3; j++)
		{
			matrix_1[i][j] = malloc(sizeof(int) * 3);
			if (!matrix_1[i][j])
				exit(1);
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				matrix_1[i][j][k] = 0;
			}
		}
	}

	args.board = board_1;
	args.matrix = matrix_1;
	args.turns = 0;
	print_board();
}
/**
 * game_summerize - display the summerization of the game
 * Return: void
 */
void game_summerize(void)
{
	printf("\n--------------- Game Summerization -------------\n");
	printf("\t-Total: %d game(s) -DRAW: %d game(s)\n\n", args.count, args.draw);
	printf("\tPlayer_A-{X}: %s :", args.player_0);
	printf("-WIN: %d game(s)\n", args.player_0_win);
	printf("\twin pecentage: %2.1f%%\n\n", (double)args.player_0_win / args.count * 100);
	printf("\tPlayer_B-{O}: %s :", args.player_1);
	printf("-WIN: %d game(s)\n", args.player_1_win);
	printf("\twin pecentage: %2.1f%%\n", (double)args.player_1_win / args.count * 100);
}
/**
 * check_validation - check the input value whether valid or not
 * @ch: input ascii value
 * Return: 0 on good, otherwise -1
 */
int check_validation(char ch, int char_0)
{
	data_t b_array[] = {
		{1, &args.board[0][0], &args.matrix[0][0][0], &args.matrix[1][0][0]},
		{2, &args.board[0][1], &args.matrix[0][0][1], &args.matrix[1][0][1]},
		{3, &args.board[0][2], &args.matrix[0][0][2], &args.matrix[1][0][2]},
		{4, &args.board[1][0], &args.matrix[0][1][0], &args.matrix[1][1][0]},
		{5, &args.board[1][1], &args.matrix[0][1][1], &args.matrix[1][1][1]},
		{6, &args.board[1][2], &args.matrix[0][1][2], &args.matrix[1][1][2]},
		{7, &args.board[2][0], &args.matrix[0][2][0], &args.matrix[1][2][0]},
		{8, &args.board[2][1], &args.matrix[0][2][1], &args.matrix[1][2][1]},
		{9, &args.board[2][2], &args.matrix[0][2][2], &args.matrix[1][2][2]}
	};

	if (ch < 49 || ch > 57)
	{
		return (-1);
	}
	if (b_array[ch - 49].square == *(b_array[ch - 49].board_2))
	{
		*(b_array[ch - 49].board_2) = char_0;
		if (char_0 == 88)
			*(b_array[ch - 49].matrix_2) = 1;
		else
			*(b_array[ch - 49].matrix_3) = 1;
		args.turns++;
		return (0);
	}
	return (-1);
}

/**
 * check_winner - check who is winner
 * Return: 1 when game over, otherwise 0;
 */
int check_winner(void)
{
	int i, j;
	int sum_0 = 0, sum_1 = 0;

	/* check winner */
	if (args.matrix[0][0][0] + args.matrix[0][1][1] + args.matrix[0][2][2] == 3)
	{
		printf("Player_A: %s WIN!....GAME OVER!!!\n", args.player_0);
		args.player_0_win++;
		return (1);
	}
	if (args.matrix[1][0][0] + args.matrix[1][1][1] + args.matrix[1][2][2] == 3)
	{
		printf("Player_B: %s WIN!....GAME OVER!!!\n", args.player_1);
		args.player_1_win++;
		return (1);
	}

	if (args.matrix[0][2][0] + args.matrix[0][1][1] + args.matrix[0][0][2] == 3)
	{
		printf("Player_A: %s WIN!....GAME OVER!!!\n", args.player_0);
		args.player_0_win++;
		return (1);
	}
	if (args.matrix[1][2][0] + args.matrix[1][1][1] + args.matrix[1][0][2] == 3)
	{
		printf("Player_B: %s WIN!....GAME OVER!!!\n", args.player_1);
		args.player_1_win++;
		return (1);
	}

	for (i = 0; i < 3; i++)
	{
		sum_0 = 0;
		for (j = 0; j < 3; j++)
		{
			sum_0 += args.matrix[0][i][j];
		}
		if (sum_0 == 3)
		{
			printf("Player_A: %s WIN!....GAME OVER!!!\n", args.player_0);
			args.player_0_win++;
			return (1);
		}
	}

	for (i = 0; i < 3; i++)
	{
		sum_0 = 0;
		for (j = 0; j < 3; j++)
		{
			sum_0 += args.matrix[0][j][i];
		}
		if (sum_0 == 3)
		{
			printf("Player_A: %s WIN!....GAME OVER!!!\n", args.player_0);
			args.player_0_win++;
			return (1);
		}
	}

	for (i = 0; i < 3; i++)
	{
		sum_1 = 0;
		for (j = 0; j < 3; j++)
		{
			sum_1 += args.matrix[1][i][j];
		}
		if (sum_1 == 3)
		{
			printf("Player_B: %s WIN!....GAME OVER!!!\n", args.player_1);
			args.player_1_win++;
			return (1);
		}
	}

	for (i = 0; i < 3; i++)
	{
		sum_1 = 0;
		for (j = 0; j < 3; j++)
		{
			sum_1 += args.matrix[1][j][i];
		}
		if (sum_1 == 3)
		{
			printf("Player_B: %s WIN!....GAME OVER!!!\n", args.player_1);
			args.player_1_win++;
			return (1);
		}
	}

	/* check is whether full board */
	if (args.turns == 9)
	{
		printf("DRAW!.....GAME OVER!!!\n");
		args.draw++;
		return (1);
	}
	return (0);
}

/**
 * play_game - play the game
 * Return: void
 */
void play_game(void)
{
	char chr[2] = {0}, ch;

	while (args.turns != 9)
	{
		do
		{
			printf("\e[1; 1H\e[2J");
			print_board();
			printf("Player_A: %s, Please select square number: ", args.player_0);
			fgets(chr, 2, stdin);
			ch = chr[0];
		}while (check_validation(ch, 88) == -1);
		if (check_winner() == 1)
			return;
		do
		{
			printf("\e[1; 1H\e[2J");
			print_board();
			printf("Player_B: %s, Please select square number: ", args.player_1);
			fgets(chr, 2, stdin);
			ch = chr[0];
		}while (check_validation(ch, 79) == -1);
		if (check_winner() == 1)
			return;
	}
}

/**
 * main - the game function entry
 * Return: 0 on success, otherwise 1
 */
int main(void)
{
	char ch;
	char str_0[25] = {0}, str_1[25] = {0}, str_3[10] = {0};
	int i;

	/* clear screen */
	/*printf("\e[1; 1H\e[2J");*/
	system("clear");
	printf("\n---------Welcome to Play Tic Tac Toe Game ---------\n");
	printf("\t\t\t\t\t\t-----(written by Bill Huang)\n\n");
	printf("Plaese input Player_A Name: ");
	fgets(str_0, 25, stdin);
	for (i = 0; str_0[i] != '\n'; i++)
		;
	str_0[i] = '\0';
	args.player_0 = str_0;
	printf("(Player_A: %s take first turn, notation: X)\n", args.player_0);
	printf("\nPlaese input Player_B Name: ");
	fgets(str_1, 25, stdin);
	for (i = 0; str_1[i] != '\n'; i++)
		;
	str_1[i] = '\0';
	args.player_1 = str_1;

	while (1)
	{
		printf("\e[1; 1H\e[2J");
		init();

		play_game();
		args.count++;

		game_summerize();
		args.flag = 1;
		print_board();
		fflush(stdin);
		if (args.flag == 1)
			fgets(str_3, 10, stdin);
		printf("Play Next Round? (Y/N): ");
		fgets(str_3, 10, stdin);
		ch = str_3[0];
		if (ch != 89 && ch != 121)
			return (0);
	}
}
