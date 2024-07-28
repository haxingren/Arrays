#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("***********************\n");
	printf("********1. play********\n");
	printf("********0. exit********\n");
	printf("***********************\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	Init_Board (board, ROW, COL);
	//打印棋盘
	Display_Board(board, ROW, COL);

	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		//判断输赢
		ret = EndGame(board, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		Display_Board(board, ROW, COL);
		printf("\n");
		//电脑下棋
		ComputerMove(board, ROW, COL);
		//判断输赢
		ret = EndGame(board, ROW, COL);
		if (ret != 'c')
			break;
		Display_Board(board, ROW, COL);
		printf("\n");
	}
	if (ret == '*')
		printf("player wins\n");
	else if (ret == '#')
		printf("player lose\n");
	else
		printf("draw\n");
	Display_Board(board, ROW, COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("continue game?(1/0):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("game\n");
			game();
			break;
		case 0:
			printf("exit game\n");
			break;
		default:\
			printf("error, please type again\n");
			break;
		}
	} while (input);
	return 0;
}