#pragma once
#include "Data.h"
#include "Model.h"

//Function for console
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();

//Move cursor pointer
void GoToXY(int x, int y);





void TextColor(int color);
void UnNocursortype();
void Nocursortype();


void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot);

void BangTinhDiem();


void DrawCARO();
void DrawXWIN();
void DrawOWIN();
void LoadingBar();
