﻿#pragma once
void FixConsoleWindow();
void GotoXY(int x, int y);
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
void ResetData();
void DrawBoard(int pSize);
void StartGame();