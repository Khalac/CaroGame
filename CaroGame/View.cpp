﻿#include "View.h"
void CreateConsoleWindow(int pWidth, int pHeight)
{
	HWND consoleWindow = GetConsoleWindow();
	RECT r;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 240);
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, pWidth, pHeight, TRUE);
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}
void GoToXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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


void DrawBoard()
{
	const char TL = 218;
	const char TR = 191;
	const char R = 196;
	for (int i = 0; i <= 27; i++)
	{
		for (int j = 0; j <= 16; j++)
		{
			if (i < 1)//tao khoang cach ben tren
			{
				cout<<(" ");
			}
			if (i == 1)//Ve vien tren cung
			{
				GoToXY(1, 1);
				cout << TL;
				GoToXY(53, 1);//57
				cout << TR;
				for (int k = 2; k < 53; k++)
				{
					GoToXY(k, 1);
					cout << R;

				}
				for (int k = 5; k < 53; )
				{
					GoToXY(k, 1);
					printf("%c", 194);
					k += 4;

				}
			}

			else if (j < 1)//Tao khoang cach ben trai
			{
				printf(" ");
			}
			else if (i % 2 == 1 && j > 1 && j < 15 && i>1) {
				printf("%c%c%c%c", 197, 196, 196, 196);

			}
			else if (i % 2 == 0 && j > 1 && j < 15 && i>1)
			{
				printf("%c   ", 179);

			}

			else if (i % 2 == 1 && j == 15 && i > 1 && j > 2 && i < 27)
				printf("%c", 197);
			else if (i % 2 == 0 && j == 15 && i > 1 && i < 27)
				printf("%c", 179);

		}

		printf("\n");
	}
	for (int i = 3; i < 27; i++)//ve vien ben trai
	{
		if (i % 2 == 1)
		{
			GoToXY(1, i);
			printf("%c", 195);
		}
	}
	GoToXY(53, 27);// ve vien ben phai
	printf("%c", 217);
	for (int m = 3; m < 27; m++)
	{
		if (m % 2 == 1)
		{
			GoToXY(53, m);
			printf("%c", 180);
		}
	}
	GoToXY(1, 27);//ve vien ben duoi
	printf("%c", 192);
	for (int k = 2; k < 53; k++)
	{
		GoToXY(k, 27);
		printf("%c", 196);

	}
	for (int m = 5; m < 53; )
	{
		GoToXY(m, 27);
		printf("%c", 193);
		m += 4;
	}
	GoToXY(51, 27);
	printf("%c", 196);
	GoToXY(52, 27);
	printf("%c", 196);
	GoToXY(53, 27);
	printf("%c", 217);
}

void BangTinhDiem()//Ve bang tinh diem
{
	char TL = 218;
	char TR = 191;
	char BL = 192;
	char BR = 217;
	char R = 196;
	char C = 179;
	char ngang = 205;
	char doc = 186;
	GoToXY(54, 1);
	cout << TL;
	for (int j = 2; j < 27; j++)//Ve bien doc ben trai
	{
		GoToXY(54, j);
		cout << C;
	}
	for (int i = 55; i < 120; i++)//Ve bien ngang tren
	{
		GoToXY(i, 1);
		cout << R;
	}
	GoToXY(119, 1);
	cout << TR;//Ve goc ben phai
	for (int j = 2; j < 28; j++)//Ve bien doc ben phai
	{
		GoToXY(119, j);
		cout << C;
	}
	for (int i = 54; i < 119; i++)//Ve bien ngang duoi
	{
		GoToXY(i, 27);
		cout << R;
	}
	GoToXY(54, 27);//Ve goc ben trai
	cout << BL;
	GoToXY(119, 27);
	cout << BR;
	for (int i = 55; i < 119; i++)//Chia bang lam 2 theo chieu ngang
	{
		GoToXY(i, 8);
		cout << ngang;
	}
	for (int j = 9; j < 13; j++)//Chia bang lam 2 theo chieu doc
	{
		GoToXY(87, j);
		cout << doc;
	}
	for (int i = 55; i < 119; i++)//Ke duong ngang cho bang thu 2
	{
		GoToXY(i, 15);
		cout << ngang;
	}
	for (int j = 10; j < 23; j++)
	{
		GoToXY(87, j);
		cout << doc;
	}
	for (int i = 55; i < 119; i++)
	{
		GoToXY(i, 23);
		cout << ngang;
	}
	GoToXY(68, 5);
	cout << "PLAYER 1\t";
	GoToXY(101, 5);
	cout<<"PLAYER 2";
	//VIET CHU STEP AND SCORE
	GoToXY(68, 18);
	cout << "STEP:";
	GoToXY(68, 19);
	cout << "SCORE:";
	GoToXY(100, 18);
	cout << "STEP:";
	GoToXY(100, 19);
	cout << "SCORE:";
	//GoToXY(68, 9);//VE CHU X
	//cout << R << "     " << R << "\n";
	GoToXY(68, 9);
	cout<<"*     *\n";
	GoToXY(68, 10);
	cout << " *   *";
	GoToXY(68, 11);
	cout << "  * *";
	GoToXY(68, 12);
	cout << "   *";
	GoToXY(68, 13);
	cout << "  * *";
	GoToXY(68, 14);
	cout << " *   *";
	//VE CHU O
	GoToXY(100, 9);//VE CHU O
	cout<<"  ****\n";
	GoToXY(100, 10);
	cout<<" *    *\n";
	GoToXY(100, 11);
	cout<<" *    *\n";
	GoToXY(100, 12);
	cout<<" *    *\n";
	GoToXY(100, 13);
	cout<<" *    *\n";
	GoToXY(100, 14);
	cout<<"  ****\n";
	GoToXY(83, 25);
	cout<<"GOOD LUCK!!";
	GoToXY(0, 28);
	

}
