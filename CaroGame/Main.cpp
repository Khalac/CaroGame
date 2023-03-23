// CaroGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Ctrl.h"

int main()
{
    _POINT _A[BOARD_SIZE][BOARD_SIZE]; //Ma trận bàn cờ
    bool _TURN =1; //true là lượt người thứ nhất và false là lượt người thứ hai
    int _COMMAND=1; // Biến nhận giá trị phím người dùng nhập
    int _X, _Y; //Tọa độ hiện hành trên màn hình bàn cờ

    CreateConsoleWindow(WIDTH, HEIGHT);
    FixConsoleWindow();
   /* do {
        StartGame(_A, _TURN, _COMMAND);
    } while (true);
    */

    StartGame(_A, _TURN, _COMMAND);
    system("pause");
    return 0;
}

