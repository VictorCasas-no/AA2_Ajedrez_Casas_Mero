#include "Const.h"
#include "Utils.h"

#pragma region initChessBoard;

void initChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]) {

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {

			//Set PAWNS
			if (j == BOARD_SIZE - 2) {
				chessBoard[j][i] = WHITE_PAWN;	
			}
			else if (j == 1) {
				chessBoard[j][i] = BLACK_PAWN;
			}


			//Set EMPTY
			else chessBoard[j][i] = EMPTY;

		}
	}

	//Rooks
	const short rookXPosL = 0;
	const short rookXPosR = BOARD_SIZE - 1;

	//Knights
	const short knightXPosL = 1;
	const short knightXPosR = BOARD_SIZE - 2;

	//Bishops
	const short bishopXPosL = 2;
	const short bishopXPosR = BOARD_SIZE - 3;

	//Kings
	const short whiteKingXPosL = 3;
	const short blackKingXPosL = BOARD_SIZE - 4;
	
	//Queens
	const short whiteQueenXPosR = BOARD_SIZE - 4;
	const short blackQueenXPosR = 3;

	//Set black chess pieces
	chessBoard[0][rookXPosL] = BLACK_ROOK;
	chessBoard[0][rookXPosR] = BLACK_ROOK;

	chessBoard[0][knightXPosL] = BLACK_KNIGHT;
	chessBoard[0][knightXPosR] = BLACK_KNIGHT;

	chessBoard[0][bishopXPosL] = BLACK_BISHOP;
	chessBoard[0][bishopXPosR] = BLACK_BISHOP;

	chessBoard[0][blackKingXPosL] = BLACK_KING;

	chessBoard[0][blackQueenXPosR] = BLACK_QUEEN;

	//Set white chess pieces
	chessBoard[7][rookXPosL] = WHITE_ROOK;
	chessBoard[7][rookXPosR] = WHITE_ROOK;

	chessBoard[7][knightXPosL] = WHITE_KNIGHT;
	chessBoard[7][knightXPosR] = WHITE_KNIGHT;

	chessBoard[7][bishopXPosL] = WHITE_BISHOP;
	chessBoard[7][bishopXPosR] = WHITE_BISHOP;

	chessBoard[7][whiteKingXPosL] = WHITE_KING;

	chessBoard[7][whiteQueenXPosR] = WHITE_QUEEN;

}

#pragma endregion;

#pragma region viewChessBoard;

void viewChessBoard(char chessBoard[BOARD_SIZE][BOARD_SIZE]) {

	std::cout << ' ' << ' ';

	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << i + 1 << ' ';
	}

	std::cout << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++) {
		std::cout << BOARD_SIZE - i << ' ';
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << chessBoard[i][j] << ' ';
		}
		std::cout << std::endl;
	}

}

#pragma endregion;

Position getPieceByUser(char chessBoard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn) {

	Position userGetPiece;

	bool isGettingAPiece = true;

	do {

		bool isGettingAPiece = true;


		//Pedir al jugador ficha
		std::cout << std::endl;								//Añade una línea vacía entre el tablero y lo siguiente
		std::cout << "Elige una pieza: ";                   //Pide una altura a la que atacar
		std::cout << "X: ";									//Posición X que el usuario indica
		std::cin >> userGetPiece.x;							//Registra la altura dicha por el usuario
		std::cout << "Y: ";									//Pide una Y que el usuario indica
		std::cin >> userGetPiece.y;


		//Pedir al jugador dónde mover
		std::cout << "Altura a la cual mover: ";            //Pide una altura a la que mover
		std::cin >> x;										//Registra el ancho dicho por el usuario
		std::cout << "Posición a lo ancho donde mover: ";   //Pide el ancho al cual mover
		std::cin >> y;										//Registra la altura dicha por el usuario


		userGetPiece.x--;
		userGetPiece.y--;

		userGetPiece.y = BOARD_SIZE - userGetPiece.y;


		if (userGetPiece.x < 0 && userGetPiece.x > BOARD_SIZE || userGetPiece.y < 1 && userGetPiece.y > BOARD_SIZE) {

			std::cout << "Invalid input. Out of bounds." << std::endl;
			isGettingAPiece = false;

		}
		else if ((isWhiteTurn && chessBoard[userGetPiece.x][userGetPiece.y] >= 'a' && chessBoard[userGetPiece.x][userGetPiece.y] <= 'z') ||
			(isBlackTurn && chessBoard[userGetPiece.x][userGetPiece.y] >= 'A' && chessBoard[userGetPiece.x][userGetPiece.y] <= 'Z')) {

			std::cout << "Invalid input. You're trying to get an opp's piece." << std::endl;
			isGettingAPiece = false;

		}

	} while (!isGettingAPiece);



}