#include "Ctrl.h"
#include "Data.h";
#include"View.h"
void StartGame(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND) {
	Nocursortype();
	enum Stone game[15][15];
	int step1 = 0;
	int step2 = 0;
	int k = 0;
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			game[i][j] = NA;
	ToaDo now = ToaDo{ 0,0 };
	int luot = 1;
	char lenh;
	PrintFile("XTURN.txt", 253, 95, 20);
	while (true)
	{
		GoToXY(0, 0);
		displayBoard(game, MAX_SIZE, now, luot);
		GoToXY(88, 5);
		cout << step1;
		GoToXY(130, 5);
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
		if (lenh == 'G' || lenh == 'g')
		{
			cout << endl;
			cout << "Nguoi choi " << luot << " da dau hang !" << endl;
			luot = luot % 2 + 1;
			cout << "Nguoi choi " << luot << " da thang !" << endl;
			cout << "Nhan phim bat ky de tiep tuc....";
			lenh = _getch();
			return;
		}
		if (lenh == 13 || lenh == 'e' || lenh == 'e' || lenh == '5')
		{
			k++; //CAP NHAT SCORE VA STEP

			//TU DAY TRO XUONG LA HAM CUA UYEN!!!!!
			if (k % 2 != 0)
			{
				if (checkMakeMove(game, MAX_SIZE, now) != true)
				{
					k--;
					continue;
				}
				else
				{
					step1++;
					GoToXY(88, 5);
					cout << step1;
					GoToXY(130, 5);
					cout << step2;
					PrintFile("OTURN.txt", 253, 95, 20);
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
					step2++;
					GoToXY(88, 5);
					cout << step1;
					GoToXY(130, 5);
					cout << step2;
					PrintFile("XTURN.txt", 253, 95, 20);
				}
				//TOI DAY LA HET HAM CUA UYEN R NHENNN!!!
			}
			if (checkMakeMove(game, MAX_SIZE, now) != true)
				continue;
			makeMove(game, MAX_SIZE, now, luot);
			if (hasWon(game, MAX_SIZE, luot))
			{
				GoToXY(0, 0);
				//system("cls");
				displayBoard(game, MAX_SIZE, now, 0);
				cout << "Nguoi choi " << luot << " da thang !" << endl;
				cout << "Nhan phim bat ky de tiep tuc....";
				lenh = _getch();
				return;
			}
			luot = luot % 2 + 1;
		}

	}

}

void ExitGame() {
	//system("cls");
	GabageCollect();
	//Có thể lưu game trước khi exit
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
		if (lenh == 'a' || lenh == 'a')
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

