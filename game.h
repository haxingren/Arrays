#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//初始化棋盘
void Init_Board(char board[ROW][COL], int row, int col);
//打印棋盘
void Display_Board(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char EndGame(char board[ROW][COL], int row, int col);

//判断平局
int IsFull(char board[ROW][COL], int row, int col);