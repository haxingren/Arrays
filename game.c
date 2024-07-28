#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "game.h"

//初始化棋盘
void Init_Board(char board[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			board[r][c] = ' ';
		}
	}
}

//打印棋盘
void Display_Board(char board[ROW][COL], int row, int col)
{
	int input1 = 0;
	int input2 = 0;
	int r = 0;
	int c = 0;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)//每一次循环打印一行坐标
		{
			printf(" %c ", board[r][c]);
			if (c < col - 1)
				printf("|");
		}
		printf("\n");//换行
		if (r < row - 1)
		{
			for (c = 0; c < col - 1; c++)//每次循环打印分割线
			{
				printf("---|");
			}
			printf("---\n");
		}
	}
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	//判断坐标是否合法
	while (1)
	{
		printf("please choose a coordinate:>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
				printf("coordinate used, choose another\n");
		}
		else
			printf("coordinate invalid, choose again\n");
	}
}


//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//生成0~row-1的随机数
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}

}

//判断平局
int IsFull(char board[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	for (r = 0; r < row; r++)
	{
		for (c = 0; c < col; c++)
		{
			if (board[r][c] == ' ')
				return 0;
		}
	}
	return 1;
}
//判断输赢
// 玩家赢 = '*'
// 电脑赢 = '#'
// 平局 = 'd'
// 继续 = 'c'
char EndGame(char board[ROW][COL], int row, int col)
{
	int r = 0;
	int c = 0;
	int i = 0;
	int j = 0;
	int a = 0;
	//判断行
	//全部相同 
	//	是空格 返回c
	//	不是空格 返回*或#
	//不相同
	//	有空格 返回c
	//	没有空格 不返回
	for (r = 0, j = 0; r < row; r++)
	{
		for (c = 0, i = 0, j = 0; c < col; c++)
		{
			if (board[r][0] == board[r][c])
			{
				i++;
			}
			if (board[r][c] == ' ')
			{
				j++;
			}
		}
		//i不等于col代表不是全部相同
		//j不等于0代表有空格
		if (i == col && j == 0)
		{
			return board[r][0];
		}
		if (j != 0)
			j++;
	}
	//判断列
	for (c = 0, j = 0; c < col; c++)
	{
		for (r = 0, i = 0, j = 0; r < row; r++)
		{
			if (board[0][c] == board[r][c])
			{
				i++;
			}
			if (board[r][c] == ' ')
			{
				j++;
			}
		}
		//i不等于col代表不是全部相同
		//j不等于0代表有空格
		if (i == col && j == 0)
		{
			return board[0][c];
		}
		if (j != 0)
			j++;
	}

	//判断对角线
	int x = 0;
	int b=0;
	for (x = 0, i = 0, b = 0; x < row; x++)
	{
		if (board[0][0] == board[x][x])
			i++;
		if (board[x][x] == ' ')
			b++;
	}
	if (i == row && b == 0)
		return board[0][0];
	if (b != 0)
		j++;

	//判断对角线2
	for (r = 0, c = col - 1, i = 0, a = 0; r < row; r++, c--)
	{
		if (board[0][col-1] == board[r][c])
			i++;
		if (board[r][c] == ' ')
			a++;
	}
	if (i == row && a == 0)
		return board[0][col-1];
	if (a != 0)
		return 'c';

	//判断平局
	//满了，平局，返回1
	//没满， 继续，返回0
	if (IsFull(board, row, col))
	{
		return 'd';
	}
	else
	{
		return 'c';
	}
}


