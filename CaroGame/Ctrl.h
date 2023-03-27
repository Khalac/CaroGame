#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include"View.h"
#include<string.h>
#include<conio.h>
#define MAX_SIZE 15
const char HORZ = 196;
const char VERT = 179;
const char TL = 218;
const char TM = 194;
const char TR = 191;
const char BL = 192;
const char BM = 193;
const char BR = 217;
const int numW = 3;
const int charW = 1;
const int numPerLine = 15;
const char VERT_START = 195;
const char VERT_END = 180;
const char VERT_MID = 197;
enum Stone { NA, X, O };
struct ToaDo
{
    int i;
    int j;
};
struct Move {
    int row;
    int col;
    enum Stone stone;
};
void StartGame(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND);

void ExitGame();

static char* lineString(char left, char mid, char right, char horz, int wcell, int ncell);

bool hasWon(enum Stone board[][15], int size, int luot);

void makeMove(enum Stone board[][15], int size, ToaDo playerMove, int luot);

bool checkMakeMove(enum Stone board[][15], int size, ToaDo now);

void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot);
