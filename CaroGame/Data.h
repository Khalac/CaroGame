#pragma once
// Kính thước màn hình console
#define WIDTH 1320 //1320
#define HEIGHT 700
#define X_CENTER WIDTH / 16 + 2
#define Y_CENTER HEIGHT / 32

#define BOARD_SIZE 12 // Kích thức ma trận bàn cờ
#define LEFT 3 // Tọa độ trái màn hình bàn cờ
#define TOP 1 // Tọa độ trên màn hình bàn cờ
#define _CRT_SECURE_NO_WARNINGS

#define MAX_SIZE 15
const char HORZ = 196;
const char VERT = 179;
const char TL = 218;
const char TM = 194;
const char TR = 191;
const char BL = 192;
const char BM = 193;
const char BR = 217;
const int numW = 3;
const int charW = 1;
const int numPerLine = 15;
const char VERT_START = 195;
const char VERT_END = 180;
const char VERT_MID = 197;
enum Stone { NA, X, O };
struct ToaDo
{
	int i;
	int j;
};
struct Move {
	int row;
	int col;
	enum Stone stone;
};

#include<iostream>
#include<Windows.h>

using namespace std;
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

