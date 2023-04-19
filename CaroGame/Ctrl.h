#pragma once
#include"View.h"


void Ctrl(int& x, int& y); 
void StartGame(enum Stone game[15][15], int stepPlayer1, int stepPlayer2,int playerTurn,int updateStep,ToaDo now,Player P1, Player P2,bool checkLoad);

void ExitGame();


bool hasWon(enum Stone board[][15], int size, int luot);

void makeMove(enum Stone board[][15], int size, ToaDo playerMove, int luot);

bool checkMakeMove(enum Stone board[][15], int size, ToaDo now);
bool CheckMark(Mark* z, int x, int y);

bool CheckFileExists(string filename);

void SaveData(enum Stone game[15][15], int stepPlayer1, int stepPlayer2, int playerTurn, int updateStep,ToaDo now, Player P1, Player P2, string filename);
bool CheckFileExists(string filename);
void SaveGame(enum Stone game[15][15], int stepPlayer1, int stepPlayer2, int playerTurn, int updateStep, ToaDo now, Player P1, Player P2);

bool checkdraw(enum Stone game[15][15]);


