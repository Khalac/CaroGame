#include "Ctrl.h"
void StartGame(_POINT _A[BOARD_SIZE][BOARD_SIZE], bool _TURN, int _COMMAND) {
	system("cls");
	ResetData(_A, _TURN,_COMMAND); // Khởi tạo dữ liệu gốc
	DrawBoard(); // Vẽ màn hình game
	BangTinhDiem();
}

void ExitGame() {
	system("cls");
	GabageCollect();
	//Có thể lưu game trước khi exit
}
