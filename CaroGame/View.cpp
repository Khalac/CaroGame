#include "View.h"
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

	for (int i = 0; i <= 27; i++)
	{
		for (int j = 0; j <= 16; j++)
		{
			if (i < 1)//tao khoang cach ben tren
			{
				printf(" ");
			}
			if (i == 1)//Ve vien tren cung
			{
				TextColor(1);
				GoToXY(1, 1);
				printf("%c", 218);
				GoToXY(53, 1);//57
				printf("%c", 191);
				for (int k = 2; k < 53; k++)
				{
					GoToXY(k, 1);
					printf("%c", 196);

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
	GoToXY(54, 1);
	printf("%c", 218);
	for (int j = 2; j < 27; j++)
	{
		GoToXY(54, j);
		printf("%c", 179);
	}
	for (int i = 55; i < 120; i++)
	{
		GoToXY(i, 1);
		printf("%c", 196);
	}
	GoToXY(119, 1);
	printf("%c", 191);
	for (int i = 2; i < 28; i++)
	{
		GoToXY(119, i);
		printf("%c", 179);
	}
	for (int i = 54; i < 119; i++)
	{
		GoToXY(i, 27);
		printf("%c", 196);
	}
	GoToXY(54, 27);
	printf("%c", 192);
	GoToXY(119, 27);
	printf("%c", 217);
	for (int i = 55; i < 119; i++)//Chia bang lam 2 theo chieu ngang
	{
		GoToXY(i, 8);
		printf("%c", 205);
	}
	for (int j = 9; j < 13; j++)//Chia bang lam 2 theo chieu doc
	{
		GoToXY(87, j);
		printf("%c", 186);
	}
	for (int i = 55; i < 119; i++)//Ke duong ngang cho bang thu 2
	{
		GoToXY(i, 15);
		printf("%c", 205);
	}
	for (int j = 10; j < 23; j++)
	{
		GoToXY(87, j);
		printf("%c", 186);
	}
	for (int i = 55; i < 119; i++)
	{
		GoToXY(i, 23);
		printf("%c", 205);
	}
	system("color 2");
	GoToXY(68, 5);
	printf("PLAYER 1\t");
	GoToXY(101, 5);
	printf("PLAYER 2");
	GoToXY(68, 9);//VE CHU X
	printf("%c     %c\n", 196, 196);
	GoToXY(68, 10);
	printf("%c %c %c %c\n", 92, 92, 47, 47);
	GoToXY(68, 11);
	printf(" %c V %c\n", 92, 47);
	GoToXY(68, 12);
	printf("  > <\n");
	GoToXY(68, 13);
	printf(" %c . %c\n", 47, 92);
	GoToXY(68, 14);
	printf("%c_%c %c_%c\n", 47, 47, 92, 92);
	GoToXY(100, 9);//VE CHU O
	printf("  ****\n");
	GoToXY(100, 10);
	printf(" *    *\n");
	GoToXY(100, 11);
	printf(" *    *\n");
	GoToXY(100, 12);
	printf(" *    *\n");
	GoToXY(100, 13);
	printf(" *    *\n");
	GoToXY(100, 14);
	printf("  ****\n");
	GoToXY(83, 25);
	printf("GOOD LUCK!!");
	GoToXY(0, 28);
}
