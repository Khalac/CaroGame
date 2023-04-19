#include "Ctrl.h"
#include "Data.h";
#include"View.h"

void StartGame(enum Stone game[15][15], int stepPlayer1, int stepPlayer2, int playerTurn, int updateStep, ToaDo now, Player P1,Player P2,bool checkLoad ) {
	
	Nocursortype();
	int step1 = stepPlayer1;
	int step2 = stepPlayer2;
	int k = updateStep;
	int luot = playerTurn;
	char lenh;
	if (checkLoad == 0) {
		inputNameScreen(P1, P2);
		system("cls");
	}
	while (true)
	{
		GoToXY(0, 0);
		displayBoard(game, MAX_SIZE, now, P1,P2);
		GoToXY(88, 5);
		cout << step1;
		GoToXY(88, 9);
		cout << step2;

		lenh = _getch();
		if (lenh == 'W' || lenh == 'w')
		{
			now.i--;
			if (now.i < 0)
				now.i = 0;
		}
		if (lenh == 'A' || lenh == 'a')
		{
			now.j--;
			if (now.j < 0)
				now.j = 0;
		}
		if (lenh == 'S' || lenh == 's')
		{
			now.i++;
			if (now.i > MAX_SIZE - 1)
				now.i = MAX_SIZE - 1;
		}
		if (lenh == 'D' || lenh == 'd')
		{
			now.j++;
			if (now.j > MAX_SIZE - 1)
				now.j = MAX_SIZE - 1;
		}
		if (lenh == 'p' || lenh == 'P') {
			SaveGame(game,step1,step2,luot,k,now,P1,P2);
		}
		if (lenh == ESC) {
			MainMenu();
		}
		if (lenh == 13 || lenh == 'e' || lenh == 'E' || lenh == '5')
		{
			k++; //CAP NHAT STEP
			if (k % 2 != 0)
			{
				if (checkMakeMove(game, MAX_SIZE, now) != true)
				{
					k--;
					continue;
				}
				else
				{
					PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);
					step1++;
					GoToXY(88, 5);
					cout << step1;
					GoToXY(88, 9);
					cout << step2;
					PrintFile("OTURN.txt", 250, 95, 20);
				}
			}
			if (k % 2 == 0)
			{
				if (checkMakeMove(game, MAX_SIZE, now) != true)
				{
					k--;
					continue;
				}
				else
				{
					PlaySound(TEXT("move_pointer.wav"), NULL, SND_FILENAME);
					step2++;
					GoToXY(88, 5);
					cout << step1;
					GoToXY(88, 9);
					cout << step2;
					PrintFile("XTURN.txt", 240, 95, 20);
				}
			}
			if (checkMakeMove(game, MAX_SIZE, now) != true)
				continue;

			makeMove(game, MAX_SIZE, now, luot);

			if (hasWon(game, MAX_SIZE, luot) == true)
			{
				if (luot == 1) {
					xWin();
					
					
				}
				else {
					oWin();
					
				}
			}

			if (checkdraw(game) == true) {
				drawnmatch();
				break;
			}

			luot = luot % 2 + 1;
		}

	}

}

void ExitGame() {
	exit(0);
}


bool hasWon(enum Stone board[][15], int size, int luot) //Kiểm tra điều kiện thắng thua//
{
	int h = 0, i, j, m, n, e, bd, kt;
	enum Stone b, d;
	if (luot == 1)
	{
		b = X;
		d = O;
	}
	else
	{
		b = O;
		d = X;
	}
	while (h < size)
	{
		int c = 0;
		while (c < size)
		{
			if (board[h][c] != b)
			{
				c++;
				continue;
			}
			if (h + 4 < size)
			{
				int dem = 0;
				for (i = h; i < h + 5; i++)
					if (board[i][c] == b)
						dem++;
				if (dem == 5)
				{
					bool tren5 = false;
					int chan2Dau = 0;
					if (h > 0 && board[h - 1][c] == b)
						tren5 = true;
					if (h + 5 < size && board[h + 5][c] == b)
						tren5 = true;
					if (h > 0 && board[h - 1][c] == d)
						chan2Dau++;
					if (h + 5 < size && board[h + 5][c] == d)
						chan2Dau++;
					if (tren5 == false && chan2Dau < 2)
						return true;
				}
			}
			if (c > 3)
			{
				int dem = 0;
				for (i = c - 4; i <= c; i++)
					if (board[h][i] == b)
						dem++;
				if (dem == 5)
				{
					bool tren5 = false;
					int chan2Dau = 0;
					if (c > 4 && board[h][c - 5] == b)
						tren5 = true;
					if (c < size - 1 && board[h][c + 1] == b)
						tren5 = true;
					if (c > 4 && board[h][c - 5] == d)
						chan2Dau++;
					if (c < size - 1 && board[h][c + 1] == d)
						chan2Dau++;
					if (tren5 == false && chan2Dau < 2)
						return true;
				}
			}
			if (c + 4 < size)
			{
				int dem = 0;
				for (i = c; i < c + 5; i++)
					if (board[h][i] == b)
						dem++;
				if (dem == 5)
				{
					bool tren5 = false;
					int chan2Dau = 0;
					if (c > 0 && board[h][c - 1] == b)
						tren5 = true;
					if (c + 5 < size && board[h][c + 5] == b)
						tren5 = true;
					if (c > 0 && board[h][c - 1] == d)
						chan2Dau++;
					if (c + 5 < size && board[h][c + 5] == d)
						chan2Dau++;
					if (tren5 == false && chan2Dau < 2)
						return true;
				}
			}
			if (c > 3 && h + 4 < size)
			{
				int dem = 0;
				for (i = 0; i < 5; i++)
					if (board[h + i][c - i] == b)
						dem++;
				if (dem == 5)
				{
					bool tren5 = false;
					int chan2Dau = 0;
					if (c > 4 && h + 5 < size && board[h + 5][c - 5] == b)
						tren5 = true;
					if (c < size - 1 && h>0 && board[h - 1][c + 1] == b)
						tren5 = true;
					if (c > 4 && h + 5 < size && board[h + 5][c - 5] == d)
						chan2Dau++;
					if (c < size - 1 && h>0 && board[h - 1][c + 1] == d)
						chan2Dau++;
					if (tren5 == false && chan2Dau < 2)
						return true;
				}
			}
			if (c + 4 < size && h + 4 < size)
			{
				int dem = 0;
				for (i = 0; i < 5; i++)
					if (board[h + i][c + i] == b)
						dem++;
				if (dem == 5)
				{
					bool tren5 = false;
					int chan2Dau = 0;
					if (c > 0 && h > 0 && board[h - 1][c - 1] == b)
						tren5 = true;
					if (c + 5 < size && h + 5 < size && board[h + 5][c + 5] == b)
						tren5 = true;
					if (c > 0 && h > 0 && board[h - 1][c - 1] == b)
						chan2Dau++;
					if (c + 5 < size && h + 5 < size && board[h + 5][c + 5] == b)
						chan2Dau++;
					if (tren5 == false && chan2Dau < 2)
						return true;
				}
			}
			c++;
		}
		h++;
	}
	return false;
}

void makeMove(enum Stone board[][15], int size, ToaDo playerMove, int luot) //Hàm đổi lượt chơi//
{
	if (luot == 1)
		board[playerMove.i][playerMove.j] = X;
	else board[playerMove.i][playerMove.j] = O;
}

bool checkMakeMove(enum Stone board[][15], int size, ToaDo now) //Kiểm tra ô có hợp lệ để đánh không//
{
	if (board[now.i][now.j] != NA)
		return false;
	return true;
}

bool CheckMark(Mark* z, int x, int y)
{
	for (int i = 0; i < 15 * 15; i++)
	{
		if (z[i].x == x && z[i].y == y)
		{
			return true;
		}
	}
	return false;
}

bool checkdraw(enum Stone game[15][15]) {
	int count = 0;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (game[i][j] == NA) {
				count += 1;
			}
		}
	}
	if (count == 0) {
		return true;
	}
	return false;
}

void Ctrl(int& x, int& y)
{
	Mark* z = new Mark[15 * 15];
	int i = 0;
	int luot = 0;
	GoToXY(x, y);
	//cout << "_";
	char lenh;
	while (1)
	{
		lenh = _getch();
		if (lenh == 's' || lenh == 'S')
		{
			y += 2;
			if (CheckMark(z, x, y) == true)
			{
				GoToXY(x, y);
				if (lenh == 13 || lenh == 'e' || lenh == '5')
				{
					continue;
				}
			}
			else
			{
				GoToXY(x, y);
			}

		}
		if (lenh == 'w' || lenh == 'W')
		{

			y -= 2;
			if (y < 2)
			{
				y = 2;
			}
			if (CheckMark(z, x, y) == true)
			{
				GoToXY(x, y);
				if (lenh == 13 || lenh == 'e' || lenh == '5')
				{
					continue;
				}

			}
			else
			{
				GoToXY(x, y);
			}


		}
		if (lenh == 'A' || lenh == 'a')
		{
			x -= 4;
			if (x < 3)
			{
				x = 3;
			}
			if (CheckMark(z, x, y) == true)
			{
				GoToXY(x, y);
				if (lenh == 13 || lenh == 'e' || lenh == '5')
				{
					continue;
				}
			}
			else
			{
				GoToXY(x, y);
			}


		}
		if (lenh == 'd' || lenh == 'D')
		{
			x += 4;
			if (CheckMark(z, x, y) == true)
			{
				GoToXY(x, y);
				if (lenh == 13 || lenh == 'e' || lenh == '5')
				{
					continue;
				}
			}
			else
			{
				GoToXY(x, y);
			}

		}
		if (lenh == 13 || lenh == 'e' || lenh == '5')
		{
			luot++;
			if (luot % 2 == 1)
			{
				if (CheckMark(z, x, y) == true)
				{
					luot--;
					continue;
				}
				else
				{
					z[i].x = x;
					z[i].y = y;
					i++;
					GoToXY(x, y);
					TextColor(4);
					cout << "X";
					//x += 4;
					/*if (x > 59)
					{
						x = 59;
						y += 2;
						if (y > 30)
						{
							y = 30;
						}
					}*/
					GoToXY(x, y);

				}
			}
			else
			{
				if (CheckMark(z, x, y) == true)
				{
					luot--;
					continue;
				}
				else
				{
					z[i].x = x;
					z[i].y = y;
					i++;
					GoToXY(x, y);
					TextColor(3);
					cout << "O";
					//x += 4;
					/*if (x > 59)
					{
						x = 59;
						y += 2;
						if (y > 30)
						{
							y = 30;
						}
					}*/
					GoToXY(x, y);
				}
			}
		}
	}
}

void SaveData(enum Stone game[15][15], int stepPlayer1, int stepPlayer2, int playerTurn, int updateStep,ToaDo now,Player P1, Player P2,string filename)
{
	fstream saveFile;
	saveFile.open(filename, ios::out);

	saveFile << stepPlayer1 << "\n";
	saveFile << stepPlayer2 << "\n";
	saveFile << playerTurn << "\n";
	saveFile << updateStep << "\n";
	saveFile << now.i << "\n";
	saveFile << now.j << "\n";
	saveFile << P1.name << "\n";
	saveFile << P2.name << "\n";


	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			saveFile << game[i][j] << " ";
		}
		saveFile << "\n";
	}

	saveFile.close();
}

bool CheckFileExists(string filename)
{
	string nameSave; 
	fstream savedFile;
	savedFile.open("SavedFile.txt", ios::in);

	while (savedFile >> nameSave)
	{
		if (nameSave == filename)
		{
			savedFile.close();
			return true;
		}
	}
	savedFile.close();
	return false;
}

void SaveGame(enum Stone game[15][15], int stepPlayer1, int stepPlayer2, int playerTurn, int updateStep, ToaDo now,Player P1,Player P2) {
	string filename;
	system("cls");
	PrintString("Nhap ten muon luu game: ", 245, WIDTH_CENTER - 20, HEIGHT_CENTER);
	getline(cin, filename);
	filename += ".txt";
	do
	{
		if (CheckFileExists(filename))
		{
			system("cls");
			PrintString("Ten da ton tai", 245, WIDTH_CENTER - 20, HEIGHT_CENTER );
			PrintString("Ban hay nhap ten khac: ", 245, WIDTH_CENTER - 20, HEIGHT_CENTER + 2);
			getline(cin, filename);
			filename += ".txt";
		}
		else break;
	} while (true);

	fstream saveFile;
	saveFile.open("SavedFile.txt", ios::app);
	saveFile << filename << "\n";
	saveFile.close();
	SaveData(game, stepPlayer1, stepPlayer2, playerTurn, updateStep,now,P1,P2,filename);
	MainMenu();
}


