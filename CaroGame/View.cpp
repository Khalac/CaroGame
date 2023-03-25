#include "View.h"
using namespace std;
//define cac ky tu dung trong ham DrawBoard
#define Line (char)196//dau gach:-
#define Connect (char)197//dau thap gia, noi cac o voi nhau.
#define Vertical (char)179//dau gach thang: |
#define Topleft (char)218//dau bo goc tren cung ben trai
#define Topright (char)191//dau bo goc tren cung ben phai
#define Botright (char)217//dau bo goc cuoi ben phai
#define Botleft (char)192//dau bo goc cuoi ben trai
#define Connecttop (char)194//dau noi cua vien tren, co dang hinh thap gia bi mat canh tren
#define Connectleft (char)195//dau noi cua vien trai, co dang hinh thap gia bi mat canh ben trai
#define Connectright (char)180//dau noi cua vien phai, co dang hinh thap gia bi mat canh ben phai
#define Connectbot (char)193//dau noi cau vien duoi, co dang hinh thap gia bi mat canh duoi
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


void DrawBoard()//ve ban co (Toa do:x=61, y=31)
{
	//VE KHUNG NGOAI:
	for (int i = 0; i <= 31; i++)//ve vien tren cung + tao khoang cach voi le cua console
	{
		for (int j = 0; j <= 18; j++)
		{
			if (i < 1)//tao khoang cach ben tren
			{
				cout << " ";
			}
			if (i == 1)//Ve vien tren cung
			{
				GoToXY(1, 1);
				cout << Topleft;
				GoToXY(61, 1);
				cout << Topright;
				for (int k = 2; k < 61; k++)
				{
					GoToXY(k, 1);
					cout << Line;
				}
				for (int k = 5; k < 61; )
				{
					GoToXY(k, 1);
					cout << Connecttop;
					k += 4;
				}
			}

			else if (j < 1)//Tao khoang cach ben trai
			{
				cout << " ";
			}
			cout << endl;
		}
	}
	for (int i = 2; i < 31; i++)//ve vien ben trai
	{
		if (i % 2 == 1)
		{
			GoToXY(1, i);
			cout << Connectleft;
		}
		if (i % 2 == 0)
		{
			GoToXY(1, i);
			cout << Vertical;
		}
	}
	GoToXY(61, 31);// ve vien ben phai
	cout << Botright;
	for (int m = 2; m < 31; m++)
	{
		if (m % 2 == 1)
		{
			GoToXY(61, m);
			cout << Connectright;
		}
		if (m % 2 == 0)
		{
			GoToXY(61, m);
			cout << Vertical;
		}
	}
	GoToXY(1, 31);//ve vien ben duoi
	cout << Botleft;
	for (int k = 2; k < 61; k++)
	{
		GoToXY(k, 31);
		cout << Line;

	}
	for (int m = 5; m < 61; )
	{
		GoToXY(m, 31);
		cout << Connectbot;
		m += 4;
	}
	//VE CAC DUONG THANG BEN TRONG BAN CO:
	for (int j = 3; j < 31; j++)//Ve cac duong ngang
	{
		if (j % 2 == 1)
		{
			for (int i = 2; i < 61;)
			{
				GoToXY(i, j);
				cout << Line << Line << Line;
				i += 3;
				GoToXY(i, j);
				if (i < 61)
				{
					cout << Connect;
					i++;
				}
			}
		}
	}
	for (int j = 2; j < 31; j++)//ve cac duong doc
	{
		if (j % 2 == 0)
		{
			for (int i = 5; i < 61;)
			{
				GoToXY(i, j);
				cout << Vertical;
				i += 4;
			}
		}
	}
	cout << endl;
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
