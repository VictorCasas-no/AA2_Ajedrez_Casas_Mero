
#pragma region Includes;

#include "Const.h"
#include "Board.h"
#include "Utils.h"

#pragma endregion;


int main() {

	bool gameOver = false;

	bool isWhiteTurn = true;

	short turnoJugador = 1;

	int x;
	int y;

	char chessBoard[BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chessBoard);

	viewChessBoard(chessBoard);



	do {

		viewChessBoard(chessBoard);

		Position userGetPiece, userSetPiece;

		userGetPiece = getPieceByUser(chessBoard, isWhiteTurn);




		bool isGettingAPiece = false;



	} while (!gameOver);

	system("cls");
}
	
