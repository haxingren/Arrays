#define _CRT_SECURE_NO_WARNINGS

#include "minesweeper.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------------BOARD-------------------\n");
	for (j = 0; j <= row; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void PutMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	while (i <= row)
	{
		x = (rand() % row) + 1;
		y = (rand() % col) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			i++;
		}
	}
}


int CountMine(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1, count = 0; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
				count++;
		}
	}
	return count;
}

void WideFind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1, count = 0; j <= 1; j++)
		{
			//检查坐标是不是*，是才进行
			if (x + i >= 1 && x + i <= row)
			{
				if (show[x + i][y + j] == '*')
				{
					count = CountMine(mine, x + i, y + j);
					if (count == 0)
					{
						show[x + i][y + j] = ' ';
						WideFind(mine, show, ROW, COL, x + i, y + j);
					}
					else
					{
						show[x + i][y + j] = count + '0';
						break;
					}
				}
			}
			
		}
		if(count != 0)
			break;
	}
}

int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int vic = 0;
	int count = 0;
	while (1)
	{
		int q = 0;
		q++;
		if (q == 10)
			break;

		int num = -1;
		printf("please enter the coordinate:>");
		scanf("%d %d", &x, &y);//输入正数判断是不是雷，输入负数标记该位置为雷
		if (x >= 1 && x <= row && y >= 1 && y <= col && show[x][y] == '*')
		{
			if (mine[x][y] == '1')
			{
				printf("booooom\n");
				break;
			}
			count = CountMine(mine, x, y);
			//展开一片的函数
			//当count返回0时，继续检测周围坐标的周围
		}
		else
			printf("invalid coordinate, please enter again\n");
		if (count == 0)
			show[x][y] = ' ';
		else
			show[x][y] = count + '0';//count本来是个整型，加上'0'就能转换成数字字符
		if (count == 0)
		{
			WideFind(mine, show, ROW, COL, x, y);
		}
		if (x < 0 && x > -10 && y < 0 && y > -10)
		{
			if (show[-x][-y] == '*')
			{
				show[-x][-y] = '#';
				if (mine[-x][-y] == '1')
				{
					vic++;
				}
			}
		}
		DisplayBoard(show, ROW, COL);

		//找到所有地雷后退出
		if (vic == row)
			break;


	}
	return vic;
}