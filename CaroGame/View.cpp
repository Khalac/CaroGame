#include "View.h"
using namespace std;

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

void displayBoard(enum Stone arr[][15], int size, ToaDo now, int luot)
{
	cout << "    ";
	for (int i = 0; i < size; i++) {
		if ((i + 1) < 10)
			cout << " " << i + 1 << "  ";
		else cout << " " << i + 1 << " ";
	}
	cout << endl;
	cout << "   " << lineString(TL, TM, TR, HORZ, 3, numPerLine) << endl;
	for (int i = 0; i < size; i++)
	{
		printf("%2d %c", i + 1, VERT);
		for (int j = 0; j < size; j++)
		{
			if (i == now.i && j == now.j)
			{
				if (arr[i][j] == NA) printf(" _ %c", VERT);
				if (arr[i][j] == X) printf(" X %c", VERT);
				if (arr[i][j] == O) printf(" O %c", VERT);
			}
			else
			{
				if (arr[i][j] == NA) printf("   %c", VERT);
				if (arr[i][j] == X) printf(" X %c", VERT);
				if (arr[i][j] == O) printf(" O %c", VERT);
			}
		}
		cout << endl;
		if (i != size - 1)
			cout << "   " << lineString(VERT_START, VERT_MID, VERT_END, HORZ, 3, numPerLine) << endl;
	}
	cout << "   " << lineString(BL, BM, BR, HORZ, 3, numPerLine) << endl;
	if (luot != 0)
		cout << "Luot cua nguoi choi " << luot << "....";
	GoToXY(69, 1);
	BangTinhDiem();
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
void DrawCARO()//ve chu caro trong start game
{
	TextColor(11);
	cout << " ____________     ___________        _____________        ______________\n";
	cout << "/           ||   /           \\\\     |            \\\\      /              \\\\\n";
	cout << "|    _______||  |    ______   ||    |    ______   ||     |    ______    ||\n";
	TextColor(4);
	cout << "|   ||          |    |    ||  ||    |   |      |  ||     |   |      ||  ||\n";
	cout << "|   ||          |    |____||  ||    |   |______|  ||     |   |      ||  ||\n";
	cout << "|   ||          |    |____||  ||    |   |______\\  \\\\     |   |      ||  ||\n";
	TextColor(9);
	cout << "|   \\\\_______   |    |    ||  ||    |   |       \\  \\\\    |   |______||  ||\n";
	cout << "|            || |    |    ||  ||    |   |        \\  \\\\   |              ||\n";
	cout << "\\____________|| |____|    ||__||    |___|         \\__\\\\  \\______________//\n";
}
void DrawXWIN()
{
	cout << " __     __       __ __ __    ________  ___   __" << endl;
	cout << "/__/\\ /__/\\     /_//_//_/\\  /_______/\\/__/\\ /__/\\" << endl;
	cout << "\\ \\::\\\\:.\\ \\    \\:\\\\:\\\\:\\ \\ \\__.::._\\/\\::\\_\\\\  \\ \\" << endl;
	cout << " \\_\\::_\\:_\\/     \\:\\\\:\\\\:\\ \\   \\::\\ \\  \\:. `-\\  \\ \\" << endl;
	cout << "   _\\/__\\_\\_/\\    \\:\\\\:\\\\:\\ \\  _\\::\\ \\__\\:. _    \\ \\" << endl;
	cout << "   \\ \\ \\ \\::\\ \\    \\:\\\\:\\\\:\\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\" << endl;
	cout << "    \\_\\/  \\__\\/     \\_______\\/\\________\\/ \\__\\/ \\__\\/" << endl;
}
void DrawOWIN()
{
	cout << " ______       __ __ __    ________  ___   __      " << endl;
	cout << "/_____/\\     /_//_//_/\\  /_______/\\/__/\\ /__/\\    " << endl;
	cout << "\\:::_ \\ \\    \\:\\\\:\\\\:\\ \\ \\__.::._\\/\\::\\_\\\\  \\ \\   " << endl;
	cout << " \\:\\ \\ \\ \\    \\:\\\\:\\\\:\\ \\   \\::\\ \\  \\:. `-\\  \\ \\  " << endl;
	cout << "  \\:\\ \\ \\ \\    \\:\\\\:\\\\:\\ \\  _\\::\\ \\__\\:. _    \\ \\ " << endl;
	cout << "   \\:\\_\\ \\ \\    \\:\\\\:\\\\:\\ \\/__\\::\\__/\\\\. \\`-\\  \\ \\" << endl;
	cout << "    \\_____\\/     \\_______\\/\\________\\/ \\__\\/ \\__\\/" << endl;
}
void LoadingBar()//thanh loading truoc khi di vao giao dien.
{
	
	system("color 01");//blue

	// Initialize char for printing
	// loading bar
	char a = 177, b = 219;

	cout << "\n\n\n\n";
	cout << "\n\n\n\n\t\t\t\t\t";
	cout << "LOADING...\n\n";
	cout << "\t\t\t\t\t";

	// Print initial loading bar
	for (int i = 0; i < 26; i++)
		cout << a;

	// Set the cursor again starting
	// point of loading bar
	cout << "\r";
	cout << "\t\t\t\t\t";

	// Print loading bar progress
	for (int i = 0; i < 26; i++) {
		cout << b;
		Sleep(100);
	}
	system("cls");
}
