#pragma once
#include "Data.h"
#include "Ctrl.h"

//Function for console
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();

//Move cursor pointer
void GoToXY(int x, int y);





void SetColor(int color);
void UnNocursortype();
void Nocursortype();


//void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot);
void DrawBoard();
void displayBoard(enum Stone arr[][15], int size, ToaDo now, Player P1, Player P2);

void BangTinhDiem();


void DrawXWIN();
void DrawOWIN();
void LoadingBar();

void PrintFile(string filename, int color, int x, int y); //In du lieu file txt
void PrintString(string s, int color, int x, int y);
void thanh_sang(int x, int y, int w, int h, int b_color, string nd);
void demau(int x, int y, int w, int h, int b_color, string nd);
void MainMenu();

void TextColor(int x);
void BANGTINHDIEM(Player P1, Player P2);
void Instruction();

void LoadGame();

void xWin();
void oWin();

void inputNameScreen(Player& P1, Player& P2);