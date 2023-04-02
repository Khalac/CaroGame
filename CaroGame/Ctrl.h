#pragma once
#include"View.h"
#include<string.h>
#include<conio.h>

void StartGame(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND);

void ExitGame();


bool hasWon(enum Stone board[][15], int size, int luot);

void makeMove(enum Stone board[][15], int size, ToaDo playerMove, int luot);

bool checkMakeMove(enum Stone board[][15], int size, ToaDo now);

void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot);
