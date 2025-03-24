#include "Const.h"
#include "Board.h"


int main() {

	char chessBoard[BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chessBoard);

	viewChessBoard(chessBoard);
	
}