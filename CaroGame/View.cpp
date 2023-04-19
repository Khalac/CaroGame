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
void SetColor(int color) {
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}	
/*void TextColor(int x)//X lla ma mau
{

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}*/
void TextColor(int x)
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

void displayBoard(enum Stone arr[][15], int size, ToaDo now ,Player P1, Player P2)
{
	cout << "    ";
	Nocursortype();
	cout << endl;
	SetColor(252);
	cout << "   " << lineString(TL, TM, TR, HORZ, 3, numPerLine) << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "   " << VERT;
		for (int j = 0; j < size; j++)
		{
			if (i == now.i && j == now.j)
			{
				if (arr[i][j] == NA) cout << " _ " << VERT;
				if (arr[i][j] == X)
				{
					SetColor(250);
					cout << " X ";
					SetColor(252);
					cout << VERT;	
				}
				
				if (arr[i][j] == O)
				{
					SetColor(250);
					cout << " O ";
					SetColor(252);
					cout << VERT;
				}
				//SetColor(252);
			}
			else
			{
				if (arr[i][j] == NA) cout << "   " << VERT;
				
				if (arr[i][j] == X)
				{
					SetColor(253);
					cout << " X ";
					SetColor(252);
					cout << VERT;
				}
				
				if (arr[i][j] == O)
				{
					SetColor(240);
					cout << " O ";
					SetColor(252);
					cout << VERT;
				}
				SetColor(252);
			}
		}
		cout << endl;
		if (i != size - 1)
			cout << "   " << lineString(VERT_START, VERT_MID, VERT_END, HORZ, 3, numPerLine) << endl;
	}
	cout << "   " << lineString(BL, BM, BR, HORZ, 3, numPerLine) << endl;
	SetColor(252);
	GoToXY(69, 1);
	BANGTINHDIEM(P1,P2);
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
	for (int i = 0; i < subline.size(); i++) {
		PrintString(subline[i], color, x, y++);
	}
	f.close();
}

void LoadingBar()//thanh loading truoc khi di vao giao dien.
{
	
	system("color 94");//blue

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
	SetColor(253);
}

void MainMenu() {

	Menu menu;
	Nocursortype();//xoa con tro nhap nhay tren man hinh.
	menu.choices = 5; // man hinh meny co 5 su lua chon
	menu.x = WIDTH_CENTER - 15;
	menu.y = HEIGHT_CENTER;
	system("cls");
	
	ShowCursor(0);
	PrintFile("Carotext.txt", 253, 50, 3);

	PrintString("    Welcome to Caro Game   ", 253, menu.x, menu.y - 5);

	int background_bright = 75;
	//ve cac hop co chua chu truoc
	string x = "         START GAME        ";

	demau(menu.x, menu.y - 3, 28, 2, 94, x);//chu duoc in o x+1 va y+1


	string b = "         LOAD GAME         ";
	demau(menu.x, menu.y + 1, 28, 2, 94, b);

	string c = "           HELP            ";
	demau(menu.x, menu.y + 5, 28, 2, 94, c);

	string d = "         EXITGAME          ";
	demau(menu.x, menu.y + 9, 28, 2, 94, d);

	/*string e = "         EXITGAME          ";
	demau(menu.x, menu.y + 13, 28, 2, 94, e);*/
	

	string str = "ERROR";//luu giu string cua toa do dang tro toi
	int choice = 0;//lua chon 
	int toado = menu.y - 2;//luu giu toa do
	int odau = 0;

	demau(menu.x, menu.y - 3, 28, 2, 75, x);
	do
	{
		char a = _getch();
		if (a == 80 || a == 's' || a == 'S' || a == '2')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);

			choice = 1;//nhan nut xuong
			if (odau == 0)
			{
				demau(menu.x, menu.y - 3, 28, 2, 94, x);
			}
			else if (str != "ERROR" && toado < menu.y + 9)//de dua o tro ve trang thai binh thuong //+13
			{
				demau(menu.x, toado - 1, 28, 2, 94, str);

			}
			odau += 1;

		}
		else if (a == 72 || a == 'w' || a == 'W' || a == '8')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);

			choice = 2;//nhan nut len
			if (str != "ERROR" && toado > menu.y - 2)
			{
				demau(menu.x, toado - 1, 28, 2, 94, str);

			}
		}
		else if (a == 13 || a == 'e' || a == 'e' || a == '5')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);

			choice = 3;//nhan nut enter
		}
		else choice = 0;//trong truong hop khong phai nut du chuyen cach nhau 4 don vi moi o//tong 19 o
		if (choice == 1 && toado < menu.y + 9)
		{
			toado += 4;
		}
		if (choice == 2 && toado > menu.y - 2)
		{
			toado -= 4;
		}
		if (toado == menu.y - 2)
		{

			demau(menu.x, menu.y - 3, 28, 2, 75, x);

			str = x;
		}
		if (toado == menu.y + 2)
		{

			demau(menu.x, menu.y + 1, 28, 2, 75, b);

			str = b;
		}
		if (toado == menu.y + 6)
		{
			demau(menu.x, menu.y + 5, 28, 2, 75, c);
			str = c;

		}
		if (toado == menu.y + 10)
		{
			demau(menu.x, menu.y + 9, 28, 2, 75, d);
			str = d;
		}
		/*if (toado == menu.y + 14)
		{
			demau(menu.x, menu.y + 13, 28, 2, 75, e);
			str = e;

		}*/
	} while (choice != 3);
	system("cls");
	if (toado == menu.y - 2)
	{
		//start game
		enum Stone game[15][15];
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				game[i][j] = NA;
	
		GoToXY(0, 0);
		SetColor(253);
		ToaDo now;
		now.i = 0;
		now.j = 0;
		Player P1, P2;
		StartGame(game, 0, 0, 1, 0, now,P1,P2,0);
		
	}
	if (toado == menu.y + 2)
	{
		LoadGame();
	}
	if (toado == menu.y + 6)
	{
		Instruction();
	}
	if (toado == menu.y + 10) //Exit game
	{

		Sleep(1000);
	}
	/*if (toado == menu.y + 14)
	{
		Sleep(1000);
	}*/
}
void VeKhungChoInstruction()
{
	GoToXY(0, 0);//BO GOC TREN TRAI
	cout << char(201);
	for (int i = 0; i < 158; i++)//ve duong ngang tren
	{

		cout << char(205);
	}
	GoToXY(158, 0);
	cout << char(187);//BO GOC TREN PHAI
	for (int j = 1; j < 39; j++)//ve duong thang xuong duoi ben trai
	{

		GoToXY(0, j);
		cout << char(186);

	}
	GoToXY(0, 39);//BO GOC DUOI TRAI
	cout << char(200);
	for (int j = 1; j < 39; j++)//ve duong thang xuong duoi ben phai
	{

		GoToXY(158, j);
		cout << char(186);

	}

	for (int i = 1; i < 158; i++)//ve duong ngang duoi
	{

		GoToXY(i, 39);
		cout << char(205);

	}
	GoToXY(158, 39);//BO GOC DUOI PHAI
	cout << char(188);
}

void Instruction()
{
	do {
		VeKhungChoInstruction();
		GoToXY(45, 2);
		cout << " _   _  _   _  _____  _    _  ______    ____   _____  __    _ \n";
		GoToXY(45, 3);
		cout << "|  | |  ||  | |  ||       ||  |  | ||       |  |      | |   _   ||  |  | |\n";
		GoToXY(45, 4);
		cout << "|  |_|  ||  | |  ||   _   ||   |_| ||    ___|  |  _    ||  |_|  ||   |_| |\n";
		GoToXY(45, 5);
		cout << "|       ||  |_|  ||  | |  ||       ||   | __   | | |   ||       ||       |\n";
		GoToXY(45, 6);
		cout << "|       ||       ||  |_|  ||  _    ||   ||  |  | |_|   ||       ||  _    |\n";
		GoToXY(45, 7);
		cout << "|   _   ||       ||       || | |   ||   |_| |  |       ||   _   || | |   |\n";
		GoToXY(45, 8);
		cout << "|__| |__||_______||_______||_|  |__||_______|  |______| |__| |__||_|  |__|\n";
		GoToXY(50, 15);
		cout << "w  or  W:    DI LEN\n";
		GoToXY(50, 17);
		cout << "a  or  A:    SANG TRAI\n";
		GoToXY(90, 15);
		cout << "s  or  S:    DI XUONG\n";
		GoToXY(90, 17);
		cout << "d  or  D:    SANG PHAI\n";
		GoToXY(75, 19);
		cout << "ENTER:  CHOOSE\n";
		GoToXY(50, 21);
		cout << "LUAT CHOI\n";
		GoToXY(50, 23);
		cout << " -DI CHUYEN DEN O BAN MUON DANH VA NHAN ENTER, SAU DO DEN LUOT NGUOI CHOI KE TIEP.\n";
		GoToXY(50, 25);
		cout << " -TRONG 2 NGUOI, AI DANH DUOC 5 DIEM 'X' HAY 5 DIEM 'O' THANG HANG TRUOC THI SE GIANH CHIEN THANG.\n";
		GoToXY(50, 27);
		cout << " -NEU BAN MUON DAU HANG, VUI LONG NHAN PHIM 'g' hoac 'G'.\n";
		GoToXY(70, 29);
		cout << "An ESC de ve Main Menu'.\n";
	} while (_getch() != ESC);
	MainMenu();
}
void BANGTINHDIEM(Player P1, Player P2)//BANG TINH DIEM
{
	//ve o to nhat
	
	GoToXY(76, 15);
	cout << char(201);
	
	for (int i = 77; i < 149; i++)//ve duong ngang tren
	{
		cout << char(205); 
	}
	GoToXY(149, 15);
	cout << char(187);

	for (int j = 16; j < 31; j++)//ve duong thang xuong duoi ben trai
	{

		GoToXY(76, j);
		cout << char(186);
		
	}

	
	GoToXY(76, 31);
	cout << char(200);
	
	for (int j = 16; j < 31; j++)//ve duong thang xuong duoi ben phai
	{
		
		GoToXY(149, j);
		cout << char(186);
	
	}

	
	GoToXY(149, 31);
	cout << char(188);

	for (int i = 77; i < 149; i++)//ve duong ngang duoi
	{
		GoToXY(i, 31);
		cout << char(205);
		
	}

	//VE O NHO BEN TRAI
	//TextColor(233);
	GoToXY(73, 1);
	cout << char(201);
	//TextColor(252);
	for (int i = 74; i < 109; i++)//ve duong ngang tren
	{
		//TextColor(178);
		//TextColor(233);
		cout << char(205);
		//TextColor(252);
	}
	//TextColor(252);

	//TextColor(233);
	GoToXY(109, 1);
	cout << char(187);
	//TextColor(252);
	for (int j = 2; j < 13; j++)//ve duong thang xuong duoi ben trai
	{
		//TextColor(233);
		GoToXY(73, j);
		cout << char(186);
		//TextColor(252);
	}

	//TextColor(233);
	GoToXY(73, 13);
	cout << char(200);
	//TextColor(252);
	for (int j = 2; j < 13; j++)//ve duong thang xuong duoi ben phai
	{
		//TextColor(233);
		GoToXY(109, j);
		cout << char(186);
		//TextColor(252);
	}
	

	//TextColor(233);
	GoToXY(109, 13);
	cout << char(188);
	//TextColor(252);
	for (int i = 74; i < 109; i++)//ve duong ngang duoi
	{
		//TextColor(233);
		GoToXY(i, 13);
		cout << char(205);
		//TextColor(252);
	}
	//TextColor(252);
	
	//VE O NHO BEN PHAI
	//TextColor(233);
	GoToXY(116, 1);
	cout << char(201);
	//TextColor(252);
	for (int i = 117; i < 152; i++)//ve duong ngang tren
	{
		//TextColor(233);
		cout << char(205);
		//TextColor(252);
	}
	
	//TextColor(233);
	GoToXY(152, 1);
	cout << char(187);
	//TextColor(252);
	for (int j = 2; j < 13; j++)//ve duong thang xuong duoi ben phai
	{
		//TextColor(233);
		GoToXY(152, j);
		cout << char(186);
		//TextColor(252);
	}

	//TextColor(233);
	GoToXY(152, 13);
	cout << char(188);
	//TextColor(252);
	for (int j = 2; j < 13; j++)//ve duong thang xuong duoi ben trai
	{
		//TextColor(233);
		GoToXY(116, j);
		cout << char(186);
		//TextColor(252);
	}

	//TextColor(233);
	GoToXY(116, 13);
	cout << char(200);
	//TextColor(252);
	for (int i = 117; i < 152; i++)//ve duong ngang duoi
	{
		//TextColor(233);
		GoToXY(i, 13);
		cout << char(205);
		//TextColor(252);
	}

	SetColor(234);
	GoToXY(87, 3);//cap nhat luot danh.
	cout << P1.name;
	SetColor(252);


	GoToXY(75, 5);
	cout << "MOVE:";


	
	SetColor(234);
	GoToXY(87, 7);
	cout << P2.name;
	SetColor(252);
	GoToXY(75, 9);
	cout << "MOVE:";

	SetColor(234);
	GoToXY(130, 3);
	cout << "HUONG DAN";
	SetColor(252);
	GoToXY(120, 5);
	cout << "W: UP";
	GoToXY(137, 5);
	cout << "S: DOWN";
	GoToXY(120, 7);
	cout << "A: LEFT";
	GoToXY(137, 7);
	cout << "D: RIGHT";
	GoToXY(120, 9);
	cout << "ENTER: DANH QUAN CO";
	GoToXY(120, 11);
	cout << "P: SAVE       ESC: EXIT";

}
void DrawBoard() 
{
	//VE KHUNG NGOAI:
	for (int i = 0; i <= 31; i++)//ve vien tren cung+tao khoang cach voi le cua console
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
				cout << TL;
				GoToXY(61, 1);
				cout << TR;
				for (int k = 2; k < 61; k++)
				{
					GoToXY(k, 1);
					cout << HORZ;
				}
				for (int k = 5; k < 61; )
				{
					GoToXY(k, 1);
					cout << TM;
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
			cout << VERT_START;
		}
		if (i % 2 == 0)
		{
			GoToXY(1, i);
			cout << VERT;
		}
	}
	GoToXY(61, 31);// ve vien ben phai
	cout << BR;
	for (int m = 2; m < 31; m++)
	{
		if (m % 2 == 1)
		{
			GoToXY(61, m);
			cout << VERT_END;
		}
		if (m % 2 == 0)
		{
			GoToXY(61, m);
			cout << VERT;
		}
	}
	GoToXY(1, 31);//ve vien ben duoi
	cout << BL;
	for (int k = 2; k < 61; k++)
	{
		GoToXY(k, 31);
		cout << HORZ;

	}
	for (int m = 5; m < 61; )
	{
		GoToXY(m, 31);
		cout << BM;
		m += 4;
	}
	//VE BEN CAC DUONG THANG BEN TRONG BAN CO:
	for (int j = 3; j < 31; j++)//Ve cac duong ngang
	{
		if (j % 2 == 1)
		{
			for (int i = 2; i < 61;)
			{
				GoToXY(i, j);
				cout << HORZ << HORZ << HORZ;
				i += 3;
				GoToXY(i, j);
				if (i < 61)
				{
					cout << VERT_MID;
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
				cout << VERT;
				i += 4;
			}
		}
	}
	cout << endl;
	cout << endl;

}

void LoadGame() {
	system("cls");
	int stepPlayer1, stepPlayer2, playerTurn, updateStep;
	ToaDo now;
	Player P1, P2;
	enum Stone board[15][15];
	do {
		PrintString("[==========Saved Games===========]", 253, WIDTH_CENTER - 20, HEIGHT_CENTER - 10);
		fstream SavedFile;
		string filename;
		SavedFile.open("SavedFile.txt", ios::in);
		int i = 3;
		while (SavedFile >> filename) {
			PrintString(filename, 253, WIDTH_CENTER - 20, HEIGHT_CENTER - 10 + i);
			i += 2;
		}
		fstream SavedFileChoose;
		string filenameChoose;
		do {
			PrintString("Nhap ten file ban muon load: ", 253, WIDTH_CENTER - 20, HEIGHT_CENTER - 10 + i + 2);
			getline(cin, filenameChoose);
			filenameChoose += ".txt";
			if (!CheckFileExists(filenameChoose))
			{
				PrintString("File khong ton tai moi ban nhap lai : ", 253, WIDTH_CENTER - 20, HEIGHT_CENTER - 10 + i + 4);
			}
			else break;
		} while (true);
		SavedFileChoose.open(filenameChoose, ios::in);
		SavedFileChoose >> stepPlayer1;
		SavedFileChoose >> stepPlayer2;
		SavedFileChoose >> playerTurn;
		SavedFileChoose >> updateStep;
		SavedFileChoose >> now.i;
		SavedFileChoose >> now.j;
		SavedFileChoose >> P1.name;
		SavedFileChoose >> P2.name;


		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				int k;
				SavedFileChoose >> k ;
				if (k == 0) {
					board[i][j] = NA;
				}
				else if (k == 1) {
					board[i][j] = X;
				}
				else {
					board[i][j] = O;
				}
			}
		}
		break;

	} while (true);
	system("cls");
	StartGame(board, stepPlayer1, stepPlayer2, playerTurn, updateStep,now,P1,P2,1);
}

void xWin() {
	system("cls");
	int i = 240;
	PrintFile("Xwin.txt", i, WIDTH_CENTER - 40, HEIGHT_CENTER - 10);
	PlaySound(TEXT("WinSounds.wav"), NULL, SND_FILENAME);

	AfterGame();
}
void drawnmatch()
{
	system("cls");
	int i = 240;
	PrintFile("Drawnmatch.txt", i, WIDTH_CENTER - 40, HEIGHT_CENTER - 10);
	PlaySound(TEXT("drawnsound.wav"), NULL, SND_FILENAME);

	AfterGame();
}

void oWin() {
	system("cls");
	int i = 240;
	do {
		PrintFile("Owin.txt", i, WIDTH_CENTER - 40, HEIGHT_CENTER - 10);
		i++;
		if (i > 250) {
			i = 240;
		}
	} while (_getch() != ESC);
	MainMenu();
}

void inputNameScreen(Player& P1, Player& P2) {
	system("cls");
	do {
		PrintString("Input name for player 1 (1 - 10 characters): ", 240, WIDTH_CENTER - 30, HEIGHT_CENTER);
		getline(cin, P1.name);
	} while (P1.name.length() < 2 || P1.name.length() > 10);
	do {

		PrintString("Input name for player 2 (1 - 10 characters): ", 240, WIDTH_CENTER - 30, HEIGHT_CENTER + 2);
		getline(cin, P2.name);
	} while (P2.name.length() < 2 || P2.name.length() > 10 ||P1.name == P2.name);
}

void AfterGame()
{

	Menu menu;
	Nocursortype();//xoa con tro nhap nhay tren man hinh.
	menu.choices = 5; // man hinh meny co 5 su lua chon
	menu.x = WIDTH_CENTER - 15;
	menu.y = HEIGHT_CENTER;
	system("cls");
	Nocursortype();
	PrintString("BAN CO MUON CHOI LAI KHONG", 253, WIDTH_CENTER-10 , HEIGHT_CENTER-10);
	PrintString("Nhan phim YES de choi lai", 253, WIDTH_CENTER - 10, HEIGHT_CENTER - 8);
	PrintString("Nhan phim NO de quay lai MAINMENU", 253, WIDTH_CENTER - 10, HEIGHT_CENTER - 7);
	string s =  "     YES     ";
	string no = "      NO     ";
	demau(menu.x-5, menu.y - 3, 14, 2, 236, s);
	demau(menu.x + 30, menu.y - 3, 14, 2, 236, no);
	
	

	string str = "ERROR";//luu giu string cua toa do dang tro toi
	int choice = 0;//lua chon 
	int toado = menu.x - 4;//luu giu toa do
	int odau = 0;

	demau(menu.x-5, menu.y - 3, 14, 2, 75, s);//dang de con tro mau o o YES
	do
	{
		char a = _getch();
		if ( a == 'D' || a == 'd' || a == '6')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);
			choice = 1;//nhan phim qua ben phai
			if (odau == 0)
			{
				demau(menu.x - 5, menu.y - 3, 14, 2, 236, s);
			}
			else if (str != "ERROR" && toado < menu.x + 31)//de dua o tro ve trang thai binh thuong 
			{
				demau(toado-1, menu.y - 3, 14, 2, 236, str);
			}
			odau += 1;

		}
		else if ( a == 'a' || a == 'A' || a == '4')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);
			choice = 2;//nhan phim qua trai
			if (str != "ERROR" && toado > menu.x-4)
			{
				demau(toado-1, menu.y-3, 14, 2, 236, str);
			}
		}
		else if (a == 13 || a == 'e' || a == 'e' || a == '5')
		{
			PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);
			choice = 3;//nhan nut enter
		}
		else choice = 0;//trong truong hop khong phai nut du chuyen cach nhau 4 don vi moi o//tong 19 o
		if (choice == 1 && toado < menu.x + 31)
		{
			toado += 35;
		}
		if (choice == 2 && toado > menu.x-4)
		{
			toado -= 35;
		}
		if (toado == menu.x - 4)
		{

			demau(menu.x-5, menu.y - 3, 14, 2, 75, s);
			str = s;
		}
		if (toado == menu.x+31)
		{

			demau(menu.x+30, menu.y -3, 14, 2, 75, no);
			str = no;
		}
		

	} while (choice != 3);
	system("cls");
	if (toado == menu.x - 4)
	{
		//Choi lai game
		enum Stone game[15][15];
		for (int i = 0; i < MAX_SIZE; i++)
			for (int j = 0; j < MAX_SIZE; j++)
				game[i][j] = NA;

		GoToXY(0, 0);
		SetColor(253);
		ToaDo now;
		now.i = 0;
		now.j = 0;
		Player P1, P2;
		StartGame(game, 0, 0, 1, 0, now, P1, P2, 0);

	}
	if (toado == menu.x + 31)
	{
		MainMenu();
	}
	
}

