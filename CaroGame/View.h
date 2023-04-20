#pragma once
#include "Data.h"
#include "Ctrl.h"


void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();


void GoToXY(int x, int y);





void SetColor(int color);
void TextColor(int x);

void UnNocursortype();
void Nocursortype();



void DrawBoard();
void displayBoard(enum Stone arr[][15], int size, ToaDo now, Player P1, Player P2);



void PrintFile(string filename, int color, int x, int y); 
void PrintString(string s, int color, int x, int y);
void demau(int x, int y, int w, int h, int b_color, string nd);
void MainMenu();


void BANGTINHDIEM(Player P1, Player P2);
void VeKhungChoInstruction();
void Instruction();

void LoadGame();

void xWin();
void oWin();
void drawnmatch();


void inputNameScreen(Player& P1, Player& P2);
void AfterGame();
