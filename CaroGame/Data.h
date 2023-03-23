#pragma once
// Kính thước màn hình console
#define WIDTH 1320 //1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32

#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ


#include<iostream>
#include<Windows.h>

using namespace std;


struct _POINT { 
	int x, y, c; // x: tọa độ dòng, y: tọa độ cột, c: đánh dấu
}; 

struct MENU
{
	int choices;	//So chuc nang menu
	int x;			 // Toa do cua diem bat 
	int y;			 //dau cua chuc nang dau tien
};

struct _PLAYER {
	char* name;
	int score;
};

struct _BOT {
	int score;
	char* level;
};

