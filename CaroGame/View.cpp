#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ
#include "View.h"
#include<Windows.h>
#include<iostream>
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
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
void DrawBoard(int pSize) {
	GotoXY(0, 0);
	for (int i = 0; i <= LEFT + 4 * BOARD_SIZE + 1; i++)
	{
		if (i == 0) putchar(201);
		else if (i == LEFT + 4 * BOARD_SIZE + 1) putchar(187);
		else putchar(205);

	}
	for (int i = 1; i <= TOP + 2 * BOARD_SIZE; i++)
	{
		GotoXY(0, i); putchar(186);
		GotoXY(LEFT + 4 * BOARD_SIZE + 1, i); putchar(186);
	}
	GotoXY(0, TOP + 2 * BOARD_SIZE + 1);
	for (int i = 0; i <= LEFT + 4 * BOARD_SIZE + 1; i++)
	{
		if (i == 0) putchar(200);
		else if (i == LEFT + 4 * BOARD_SIZE + 1) putchar(188);
		else putchar(205);
	}
		for (int i = 0; i <= pSize; i++) {
				for (int j = 0; j <= pSize; j++) {
					GotoXY(LEFT + 4 * i, TOP + 2 * j);
					printf(".");
				}
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 0);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 * BOARD_SIZE + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(201);
			else if (i == LEFT + 4 * BOARD_SIZE + 100) putchar(187);
			else putchar(205);
		}
		for (int i = 1; i <= 8; i++)
		{
			GotoXY(LEFT + 4 * BOARD_SIZE + 10, i); putchar(186);
			GotoXY(LEFT + 4 * BOARD_SIZE + 100, i); putchar(186);
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 8);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 * BOARD_SIZE + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(200);
			else if (i == LEFT + 4 * BOARD_SIZE + 100) putchar(188);
			else putchar(205);
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 10);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 * BOARD_SIZE + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(201);
			else if (i == LEFT +4 * BOARD_SIZE + 100) putchar(187);
			else putchar(205);
		}
		for (int i = 11; i <= 16; i++)
		{
			GotoXY(LEFT + 4 * BOARD_SIZE + 10, i); putchar(186);
			GotoXY(LEFT + 4 * BOARD_SIZE + 100, i); putchar(186);
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 17);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 * BOARD_SIZE + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(200);
			else if (i == LEFT + 4 * BOARD_SIZE + 100) putchar(188);
			else putchar(205);
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 18);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 * BOARD_SIZE + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(201);
			else if (i == LEFT + 4 * BOARD_SIZE + 100) putchar(187);
			else putchar(205);
		}
		for (int i = 19; i <= 33; i++)
		{
			GotoXY(LEFT + 4 * BOARD_SIZE + 10, i); putchar(186);
			GotoXY(LEFT + 4 * BOARD_SIZE + 100, i); putchar(186);
		}
		GotoXY(LEFT + 4 * BOARD_SIZE + 10, 33);
		for (int i = LEFT + 4 * BOARD_SIZE + 10; i <= LEFT + 4 *  + 100; i++)
		{
			if (i == LEFT + 4 * BOARD_SIZE + 10) putchar(200);
			else if (i == LEFT + 4 * BOARD_SIZE + 100) putchar(188);
			else putchar(205);
		}

}
void StartGame() {
		system("cls");
		ResetData(); // Khởi tạo dữ liệu gốc
		DrawBoard(BOARD_SIZE); // Vẽ màn hình game
}