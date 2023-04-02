#pragma once
#include "Data.h"
#include "Model.h"

//Function for console
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();

//Move cursor pointer
void GoToXY(int x, int y);





void SetColor(int color);
void UnNocursortype();
void Nocursortype();


void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot);

void BangTinhDiem();


void DrawXWIN();
void DrawOWIN();
void LoadingBar();

void PrintFile(string filename, int color, int x, int y); //In du lieu file txt



void MainMenu();