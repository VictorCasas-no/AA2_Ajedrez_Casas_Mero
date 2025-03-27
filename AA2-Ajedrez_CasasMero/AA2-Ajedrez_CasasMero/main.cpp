
#pragma region 

// Includes

#include "Const.h"
#include "Board.h"
#include "Utils.h"

#pragma endregion;


int main() {

	bool gameOver = false;

	bool isWhiteTurn = true;

	short turnoJugador = 1;

	char chessBoard[BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chessBoard);

	do {

		viewChessBoard(chessBoard);

		Position userGetPiece, userSetPiece;

		userGetPiece = getPieceByUser(chessBoard, isWhiteTurn);
		userSetPiece = setPieceByUser(chessBoard, isWhiteTurn); 




		bool isGettingAPiece = false;



	} while (!gameOver);

	system("cls");
}
	
