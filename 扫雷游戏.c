#define _CRT_SECURE_NO_WARNINGS

#include "minesweeper.h"

void menu()
{
	printf("*********************\n");
	printf("*****   1.play  *****\n");
	printf("*****   0.exit  *****\n");
	printf("*********************\n");
}

void game()
{
	//创建棋盘
	//一个放地雷，一个放扫雷信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化数组为 '0' '*'
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	//DisplayBoard(show, ROW, COL);
	//随机放置地雷
	PutMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//输入坐标，查看该坐标是不是雷，是雷打印boom并结束游戏，不是雷则显示数字，表示其周围8格内有几个雷
	int vic = FindMine(mine, show, ROW, COL);
	if (vic == ROW)
	{
		printf("------------victory------------\n");
	}

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit game\n");
			break;
		default:
			printf("error, please choose again\n");
			break;
		}
	} while (input);
	return 0;
}