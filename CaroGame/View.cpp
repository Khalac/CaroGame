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
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
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
void gotoxy(int x, int y)//x,y là tọa điểm x,y trên màn hình
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = { x, y };
    SetConsoleCursorPosition(h, a);
}
void draw()//Ve ban co
{

    for (int i = 0; i <= 27; i++)
    {
        for (int j = 0; j <= 17; j++)
        {
            if (i < 1)//tao khaong cach ben tren
            {
                printf(" ");
            }
            if (i == 1)//Ve vien tren cung
            {
                gotoxy(1, 1);
                printf("%c", 218);
                gotoxy(57, 1);
                printf("%c", 191);
                for (int k = 2; k < 57; k++)
                {
                    gotoxy(k, 1);
                    printf("%c", 196);

                }
                for (int k = 5; k < 57; )
                {
                    gotoxy(k, 1);
                    printf("%c", 194);
                    k += 4;

                }
            }//

            else if (j < 1)//Tao khoang cach ben trai
            {
                printf(" ");
            }
            else if (i % 2 == 1 && j > 1 && j < 16 && i>1) {
                printf("%c%c%c%c", 197, 196, 196, 196);

            }
            else if (i % 2 == 0 && j > 1 && j < 16 && i>1)
            {
                printf("%c   ", 179);

            }

            else if (i % 2 == 1 && j == 16 && i > 1 && j > 2 && i < 27)
                printf("%c", 197);
            else if (i % 2 == 0 && j == 16 && i > 1 && i < 27)
                printf("%c", 179);

        }

        printf("\n");
    }
    for (int i = 3; i < 27; i++)//ve vien ben trai
    {
        if (i % 2 == 1)
        {
            gotoxy(1, i);
            printf("%c", 195);
        }
    }
    gotoxy(57, 27);// ve vien ben phai
    printf("%c", 217);
    for (int m = 3; m < 27; m++)
    {
        if (m % 2 == 1)
        {
            gotoxy(57, m);
            printf("%c", 180);
        }
    }
    gotoxy(1, 27);//ve vien ben duoi
    printf("%c", 192);
    for (int k = 2; k < 57; k++)
    {
        gotoxy(k, 27);
        printf("%c", 196);

    }
    for (int m = 5; m < 57; )
    {
        gotoxy(m, 27);
        printf("%c", 193);
        m += 4;
    }
    gotoxy(54, 27);
    printf("%c", 196);
    gotoxy(55, 27);
    printf("%c", 196);
    gotoxy(56, 27);
    printf("%c", 196);
    gotoxy(57, 27);// ve vien ben phai
    printf("%c", 217);


}
void StartGame() {
		system("cls");
		ResetData(); // Khởi tạo dữ liệu gốc
        draw(); // Vẽ màn hình game
        bangtinhdiem();
}
void bangtinhdiem()
{
    gotoxy(10, 0);
    printf("a");
}