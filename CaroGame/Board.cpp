﻿#include <iostream>
#include "Board.h"
#include<Windows.h>
using namespace std;
void gotoxy(int x, int y)//x,y là tọa điểm x,y trên màn hình
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD a = { x, y };
    SetConsoleCursorPosition(h, a);
}
void draw()
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
                gotoxy(1, 1);
                printf("%c", 218);
                gotoxy(53, 1);//57
                printf("%c", 191);
                for (int k = 2; k < 53; k++)
                {
                    gotoxy(k, 1);
                    printf("%c", 196);

                }
                for (int k = 5; k < 53; )
                {
                    gotoxy(k, 1);
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
            gotoxy(1, i);
            printf("%c", 195);
        }
    }
    gotoxy(53, 27);// ve vien ben phai
    printf("%c", 217);
    for (int m = 3; m < 27; m++)
    {
        if (m % 2 == 1)
        {
            gotoxy(53, m);
            printf("%c", 180);
        }
    }
    gotoxy(1, 27);//ve vien ben duoi
    printf("%c", 192);
    for (int k = 2; k < 53; k++)
    {
        gotoxy(k, 27);
        printf("%c", 196);

    }
    for (int m = 5; m < 53; )
    {
        gotoxy(m, 27);
        printf("%c", 193);
        m += 4;
    }
    gotoxy(51, 27);
    printf("%c", 196);
    gotoxy(52, 27);
    printf("%c", 196);
    gotoxy(53, 27);
    printf("%c", 217);
}