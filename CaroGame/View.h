#pragma once
void FixConsoleWindow();
void GotoXY(int x, int y);
void gotoxy(int x, int y);//gotoxy fake
struct _POINT { int x, y, c; }; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
void ResetData();
void StartGame();
void draw();
void TextColor(int color);
void UnNocursortype();
void Nocursortype();
void bangtinhdiem();//Bang ben canh ban co