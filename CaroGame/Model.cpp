#include "Model.h"

void ResetData(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND) {
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

void GabageCollect()
{
	
		// Dọn dẹp tài nguyên nếu có khai báo con trỏ
		
}