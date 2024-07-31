#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char board[ROWS][COLS], int row, int col);

void PutMine(char board[ROWS][COLS], int row, int col);

int FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

int CountMine(char mine[ROWS][COLS], int x, int y);

void WideFind(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);
