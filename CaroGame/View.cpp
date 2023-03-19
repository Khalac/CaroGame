#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ
#include "View.h"
#include<Windows.h>
#include<iostream>
#include"Board.h"
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Khai báo kiểu dữ liệu
_POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
bool _TURN; //true là lượt người thứ nhất và false là lượt người thứ hai
int _COMMAND; // Biến nhận giá trị phím người dùng nhập
int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ
void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			//định như sau: -1 là lượt true đánh, 1 là lượt false đánh
		}
	}
	_TURN = true; _COMMAND = -1; // Gán lượt và phím mặc định _X = _A[0][0].x; _Y = _A[0][0].y;
}
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); //Làm màu 
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void UnNocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void StartGame() {
		system("cls");
		ResetData(); // Khởi tạo dữ liệu gốc
        draw(); // Vẽ màn hình game
        bangtinhdiem();
}
void bangtinhdiem()//Ve bang tinh diem
{
	gotoxy(54, 1);
	printf("%c", 218);
	for (int j = 2; j < 27; j++)
	{
		gotoxy(54, j);
		printf("%c", 179);
	}
	for (int i = 55; i < 120; i++)
	{
		gotoxy(i, 1);
		printf("%c", 196);
	}
	gotoxy(119, 1);
	printf("%c", 191);
	for (int i = 2; i < 28; i++)
	{
		gotoxy(119, i);
		printf("%c", 179);
	}
	for (int i = 54; i < 119; i++)
	{
		gotoxy(i, 27);
		printf("%c", 196);
	}
	gotoxy(54, 27);
	printf("%c", 192);
	gotoxy(119, 27);
	printf("%c", 217);
	for (int i = 55; i < 119; i++)//Chia bang lam 2 theo chieu ngang
	{
		gotoxy(i, 8);
		printf("%c", 205);
	}
	for (int j = 9; j < 13; j++)//Chia bang lam 2 theo chieu doc
	{
		gotoxy(87, j);
		printf("%c", 186);
	}
	for (int i = 55; i < 119; i++)//Ke duong ngang cho bang thu 2
	{
		gotoxy(i, 13);
		printf("%c", 205);
	}
	for (int j = 10; j < 23; j++)
	{
		gotoxy(87, j);
		printf("%c", 186);
	}
	for (int i = 55; i < 119; i++)
	{
		gotoxy(i, 23);
		printf("%c", 205);
	}
	system("color 2");
	gotoxy(66, 5);
	printf("PLAYER 1\t");
	gotoxy(101, 5);
	printf("PLAYER 2");
}
