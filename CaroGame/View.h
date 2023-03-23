#pragma once
#include "Data.h"

#include "Model.h"
//Function for console
void CreateConsoleWindow(int pWidth, int pHeight);
void FixConsoleWindow();

//Move cursor pointer
void GoToXY(int x, int y);

//Draw board
void DrawBoard();



void TextColor(int color);
void UnNocursortype();
void Nocursortype();



void BangTinhDiem();
