#include "Ctrl.h"
void StartGame(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND) {
	enum Stone game[15][15];
	for (int i = 0; i < MAX_SIZE; i++)
		for (int j = 0; j < MAX_SIZE; j++)
			game[i][j] = NA;
	ToaDo now = ToaDo{ 0,0 };
	int luot = 1;
	char lenh;
	while (true)
	{
		system("cls");
		displayBoard(game, MAX_SIZE, now, luot);
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
		if (lenh == 13)
		{
			if (checkMakeMove(game, MAX_SIZE, now) != true)
				continue;
			makeMove(game, MAX_SIZE, now, luot);
			if (hasWon(game, MAX_SIZE, luot))
			{
				system("cls");
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
	system("cls");
	GabageCollect();
	//Có thể lưu game trước khi exit
}

static char* lineString(char left, char mid, char right, char horz, int wcell, int ncell) {
    static char result[100];
    strcpy(result, "");
    char cell[10];
    for (int i = 0; i < wcell; i++) {
        cell[i] = horz;
    }
    cell[wcell] = '\0';
    strncat(result, &left, 1);
    char cellMid[20];
    strcpy(cellMid, cell);
    strncat(cellMid, &mid, 1);
    for (int i = 0; i < ncell - 1; i++)
        strcat(result, cellMid);
    char cellRight[20];
    strcpy(cellRight, cell);
    strncat(cellRight, &right, 1);
    strcat(result, cellRight);
    return result;
}

bool hasWon(enum Stone board[][15], int size, int luot)
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

void makeMove(enum Stone board[][15], int size, ToaDo playerMove, int luot)
{
	if (luot == 1)
		board[playerMove.i][playerMove.j] = X;
	else board[playerMove.i][playerMove.j] = O;
}

bool checkMakeMove(enum Stone board[][15], int size, ToaDo now)
{
	if (board[now.i][now.j] != NA)
		return false;
	return true;
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
				if (arr[i][j] == NA) printf("* *%c", VERT);
				if (arr[i][j] == X) printf("*X*%c", VERT);
				if (arr[i][j] == O) printf("*O*%c", VERT);
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
}