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
void SetColor(int color) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
void TextColor(int x)//X lla ma mau
{

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
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

void PrintString(string s, int color, int x, int y)//In text
{
	GoToXY(x, y);
	SetColor(color);
	cout << s;

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
				if (arr[i][j] == NA) cout << " _ " << VERT;
				if (arr[i][j] == X)cout << " X " << VERT;
				if (arr[i][j] == O) cout << " O " << VERT;
			}
			else
			{
				if (arr[i][j] == NA) cout << "   " << VERT;
				if (arr[i][j] == X)cout << " X " << VERT;
				if (arr[i][j] == O) cout << " O " << VERT;
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
	GoToXY(70, 1);
	cout << TL;
	for (int j = 2; j < 27; j++)//Ve bien doc ben trai
	{
		GoToXY(70, j);
		cout << C;
	}
	for (int i = 71; i < 136; i++)//Ve bien ngang tren
	{
		GoToXY(i, 1);
		cout << R;
	}
	GoToXY(135, 1);
	cout << TR;//Ve goc ben phai
	for (int j = 2; j < 28; j++)//Ve bien doc ben phai
	{
		GoToXY(135, j);
		cout << C;
	}
	for (int i = 70; i < 135; i++)//Ve bien ngang duoi
	{
		GoToXY(i, 27);
		cout << R;
	}
	GoToXY(70, 27);//Ve goc ben trai
	cout << BL;
	GoToXY(135, 27);
	cout << BR;
	for (int i = 71; i < 135; i++)//Chia bang lam 2 theo chieu ngang
	{
		GoToXY(i, 8);
		cout << ngang;
	}
	for (int j = 9; j < 13; j++)//Chia bang lam 2 theo chieu doc
	{
		GoToXY(103, j);
		cout << doc;
	}
	for (int i = 71; i < 135; i++)//Ke duong ngang cho bang thu 2
	{
		GoToXY(i, 15);
		cout << ngang;
	}
	for (int j = 10; j < 23; j++)
	{
		GoToXY(103, j);
		cout << doc;
	}
	for (int i = 71; i < 135; i++)
	{
		GoToXY(i, 23);
		cout << ngang;
	}
	GoToXY(84, 5);
	cout << "PLAYER 1\t";
	GoToXY(117, 5);
	cout<<"PLAYER 2";
	//VIET CHU STEP AND SCORE
	GoToXY(84, 18);
	cout << "STEP:";
	GoToXY(84, 19);
	cout << "SCORE:";
	GoToXY(116, 18);
	cout << "STEP:";
	GoToXY(116, 19);
	cout << "SCORE:";
	//GoToXY(68, 9);//VE CHU X
	//cout << R << "     " << R << "\n";
	GoToXY(84, 9);
	cout<<"*     *\n";
	GoToXY(84, 10);
	cout << " *   *";
	GoToXY(84, 11);
	cout << "  * *";
	GoToXY(84, 12);
	cout << "   *";
	GoToXY(84, 13);
	cout << "  * *";
	GoToXY(84, 14);
	cout << " *   *";
	//VE CHU O
	GoToXY(116, 9);//VE CHU O
	cout<<"  ****\n";
	GoToXY(116, 10);
	cout<<" *    *\n";
	GoToXY(116, 11);
	cout<<" *    *\n";
	GoToXY(116, 12);
	cout<<" *    *\n";
	GoToXY(116, 13);
	cout<<" *    *\n";
	GoToXY(116, 14);
	cout<<"  ****\n";
	GoToXY(99, 25);
	cout<<"GOOD LUCK!!";
	GoToXY(16, 28);
	
}

void PrintFile(string filename, int color, int x, int y) //In du lieu tep tin
{
	fstream f;
	f.open(filename, ios::in);

	string line;
	vector<string> subline;
	while (!f.eof())
	{
		getline(f, line);
		subline.push_back(line);
	}
	for (int i = 0; i < subline.size(); i++)
		PrintString(subline[i], color, x, y++);
	f.close();
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


/*void MainMenu() {
	Menu menu;
	
	menu.choices = 5; // man hinh meny co 5 su lua chon
	menu.x = WIDTH_CENTER - 15;
	menu.y = HEIGHT_CENTER;

	system("cls");
	PrintFile("Carotext.txt",253,40,3);

	PrintString("    Welcome to Caro Game   ", 253, menu.x, menu.y - 2);
	PrintString("         Start Game        ", 253, menu.x, menu.y +1);
	PrintString("         Load Game         ", 253, menu.x, menu.y + 2);
	PrintString("          Ranking          ", 253, menu.x, menu.y + 3);
	PrintString("           Help            ", 253, menu.x, menu.y + 4);
	PrintString("         Exit Game         ", 253, menu.x, menu.y + 5);
}*/
void thanh_sang(int x, int y, int w, int h, int b_color, string nd)//de len de nguoi dung biet dang chon muc nao
{
	TextColor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			GoToXY(ix, iy); cout << " ";
		}
	}
	//SetColor(7);
	GoToXY(x + 1, y + 1);
	cout << nd;
}
void demau(int x, int y, int w, int h, int b_color, string nd)
{
	TextColor(b_color);
	for (int iy = y; iy <= y + h; iy++)
	{
		for (int ix = x; ix <= x + w; ix++)
		{
			GoToXY(ix, iy); cout << " ";
		}
	}
	//SetColor(7);
	GoToXY(x + 1, y + 1);
	cout << nd;
}

void MainMenu() {
	Menu menu;
	Nocursortype();//xoa con tro nhap nhay tren man hinh.
	menu.choices = 5; // man hinh meny co 5 su lua chon
	menu.x = WIDTH_CENTER - 15;
	menu.y = HEIGHT_CENTER;

	system("cls");
	ShowCursor(0);
	PrintFile("Carotext.txt", 253, 40, 3);

	PrintString("    Welcome to Caro Game   ", 253, menu.x, menu.y - 5);

	int background_bright = 75;
	//ve cac hop co chua chu truoc
	string x = "         START GAME        ";

	demau(menu.x, menu.y - 3, 28, 2, 94, x);//chu duoc in o x+1 va y+1


	string b = "         LOAD GAME         ";
	demau(menu.x, menu.y + 1, 28, 2, 94, b);

	string c = "          RANKING          ";
	demau(menu.x, menu.y + 5, 28, 2, 94, c);

	string d = "           HELP            ";
	demau(menu.x, menu.y + 9, 28, 2, 94, d);

	string e = "         EXITGAME          ";
	demau(menu.x, menu.y + 13, 28, 2, 94, e);
	

	string str = "ERROR";//luu giu string cua toa do dang tro toi
	int choice = 0;//lua chon 
	int toado = menu.y - 2;//luu giu toa do
	int odau = 0;

	//thanh_sang(menu.x, menu.y - 3, 28, 2, 240, x);//de len truoc o dau
	demau(menu.x, menu.y - 3, 28, 2, 75, x);
	while (choice != 3)
	{
		char a = _getch();
		if (a == 80 || a == 's' || a == 'S' || a == '2')
		{
			choice = 1;//nhan nut xuong
			if (odau == 0)
			{
				demau(menu.x, menu.y - 3, 28, 2, 94, x);
			}
			else if (str != "ERROR" && toado < menu.y + 13)//de dua o tro ve trang thai binh thuong 
			{
				demau(menu.x, toado - 1, 28, 2, 94, str);

			}
			odau += 1;

		}
		else if (a == 72 || a == 'w' || a == 'W' || a == '8')
		{
			choice = 2;//nhan nut len
			if (str != "ERROR" && toado > menu.y - 2)
			{
				demau(menu.x, toado - 1, 28, 2, 94, str);

			}
		}
		else if (a == 13 || a == 'e' || a == 'e' || a == '5') choice = 3;//nhan nut enter
		else choice = 0;//trong truong hop khong phai nut du chuyen cach nhau 4 don vi moi o//tong 19 o
		if (choice == 1 && toado < menu.y + 13)
		{
			toado += 4;
		}
		if (choice == 2 && toado > menu.y - 2)
		{
			toado -= 4;
		}
		if (toado == menu.y - 2)
		{
			//thanh_sang(menu.x, menu.y-3 , 28, 2, 240, x);
			demau(menu.x, menu.y - 3, 28, 2, 75, x);

			str = x;
		}
		if (toado == menu.y + 2)
		{
			//thanh_sang(menu.x, menu.y + 1, 28, 2, 240, b);
			demau(menu.x, menu.y + 1, 28, 2, 75, b);

			str = b;
		}
		if (toado == menu.y + 6)
		{
			//thanh_sang(menu.x, menu.y + 5, 28, 2, 240, c);
			demau(menu.x, menu.y + 5, 28, 2, 75, c);
			str = c;

		}
		if (toado == menu.y + 10)
		{
			//thanh_sang(menu.x, menu.y + 9, 28, 2, 240, d);
			demau(menu.x, menu.y + 9, 28, 2, 75, d);
			str = d;


		}
		if (toado == menu.y + 14)
		{
			//thanh_sang(menu.x, menu.y + 13, 28, 2, 240, e);
			demau(menu.x, menu.y + 13, 28, 2, 75, e);
			str = e;

		}
	}
	system("cls");
}