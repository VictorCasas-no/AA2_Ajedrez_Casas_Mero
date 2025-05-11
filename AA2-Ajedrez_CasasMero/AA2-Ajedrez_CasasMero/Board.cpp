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

#pragma region isValidMove;

bool isValidMove(char board[BOARD_SIZE][BOARD_SIZE], Position from, Position to, bool isWhiteTurn) {

	char piece = board[from.y][from.x];
	int movementX = to.x - from.x;
	int movementY = to.y - from.y;

	// Movimiento inválido fuera del tablero
	if (to.x < 0 || to.x >= BOARD_SIZE || to.y < 0 || to.y >= BOARD_SIZE) {
		return false;
		std::cout << "Error, you can't move outside of the board." << std::endl;
	}


	// No puedes mover una pieza a tu misma posición
	if (from.x == to.x && from.y == to.y) {
		return false;
		std::cout << "Error, you can't move to the same place you are." << std::endl;
	}


	// Validación por pieza
	switch (piece) {
	case WHITE_PAWN:
	case BLACK_PAWN: {
		int dir = isWhiteTurn ? -1 : 1;
		int startRow = isWhiteTurn ? 6 : 1;

		if (movementX == 0 && movementY == dir && board[to.y][to.x] == EMPTY)
			return true;

		if (movementX == 0 && movementY == 2 * dir && from.y == startRow &&
			board[from.y + dir][from.x] == EMPTY && board[to.y][to.x] == EMPTY)
			return true;

		if ((movementX == 1 || movementX == -1) && movementY == dir &&
			board[to.y][to.x] != EMPTY &&
			((isWhiteTurn && islower(board[to.y][to.x])) || (!isWhiteTurn && isupper(board[to.y][to.x]))))
			return true;

		return false;
	}

	case WHITE_ROOK:
	case BLACK_ROOK: {
		if (movementX != 0 && movementY != 0) return false;

		int stepX = (movementX == 0) ? 0 : (movementX > 0 ? 1 : -1);
		int stepY = (movementY == 0) ? 0 : (movementY > 0 ? 1 : -1);

		int x = from.x + stepX;
		int y = from.y + stepY;

		while (x != to.x || y != to.y) {
			if (board[y][x] != EMPTY) return false;
			x += stepX;
			y += stepY;
		}

		return true;
	}

	case WHITE_KNIGHT:
	case BLACK_KNIGHT: {
		if ((abs(movementX) == 2 && abs(movementY) == 1) || (abs(movementX) == 1 && abs(movementY) == 2))
			return true;
		return false;
	}

	case WHITE_BISHOP:
	case BLACK_BISHOP: {
		if (abs(movementX) != abs(movementY)) return false;

		int stepX = (movementX > 0) ? 1 : -1;
		int stepY = (movementY > 0) ? 1 : -1;

		int x = from.x + stepX;
		int y = from.y + stepY;

		while (x != to.x && y != to.y) {
			if (board[y][x] != EMPTY) return false;
			x += stepX;
			y += stepY;
		}

		return true;
	}

	case WHITE_QUEEN:
	case BLACK_QUEEN: {
		if (movementX == 0 || movementY == 0 || abs(movementX) == abs(movementY)) {
			int stepX = (movementX == 0) ? 0 : (movementX > 0 ? 1 : -1);
			int stepY = (movementY == 0) ? 0 : (movementY > 0 ? 1 : -1);

			int x = from.x + stepX;
			int y = from.y + stepY;

			while (x != to.x || y != to.y) {
				if (board[y][x] != EMPTY) return false;
				x += stepX;
				y += stepY;
			}

			return true;
		}

		return false;
	}

	case WHITE_KING:
	case BLACK_KING: {
		if ((abs(movementX) <= 1) && (abs(movementY) <= 1)) {
			return true;
		}
		return false;
	}

	default:
		return false;
	}

}

#pragma endregion;

Position getPieceByUser(char chessBoard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn) 
{

	Position userGetPiece;

	bool isGettingAPiece = true;

	do {

		bool isGettingAPiece = false;

		//Pedir al jugador ficha
		std::cout << std::endl;								//Añade una línea vacía entre el tablero y lo siguiente
		std::cout << "Elige una pieza: ";                   //Pide una altura a la que atacar
		std::cout << "X: ";									//Posición X que el usuario indica
		std::cin >> userGetPiece.x;							//Registra la altura dicha por el usuario
		std::cout << "Y: ";									//Pide una Y que el usuario indica
		std::cin >> userGetPiece.y;

		userGetPiece.x--;
		userGetPiece.y--;

		userGetPiece.y = BOARD_SIZE - userGetPiece.y;


		if (userGetPiece.x < 0 && userGetPiece.x > BOARD_SIZE || userGetPiece.y < 1 && userGetPiece.y > BOARD_SIZE) {

			std::cout << "Invalid input. Out of bounds." << std::endl;
			isGettingAPiece = false;

		}
		else if ((isWhiteTurn && chessBoard[userGetPiece.x][userGetPiece.y] >= 'a' && chessBoard[userGetPiece.x][userGetPiece.y] <= 'z') ||
			(!isWhiteTurn && chessBoard[userGetPiece.x][userGetPiece.y] >= 'A' && chessBoard[userGetPiece.x][userGetPiece.y] <= 'Z')) {

			std::cout << "Invalid input. You're trying to get an opp's piece." << std::endl;
			isGettingAPiece = false;
		}

	} while (!isGettingAPiece);
	
	return userGetPiece;

}

Position setPieceByUser(char chessBoard[BOARD_SIZE][BOARD_SIZE], bool isWhiteTurn) 
{

	Position userSetPiece;

	bool isSettingAPiece = true;

	do {

		

				////Pedir al jugador dónde mover
		std::cout << "Altura a la cual mover: ";            //Pide una altura a la que mover
		std::cout << "X: ";
		std::cin >> userSetPiece.x;							//Registra el ancho dicho por el usuario
		std::cout << "Posición a lo ancho donde mover: ";   //Pide el ancho al cual mover
		std::cout << "Y: ";
		std::cin >> userSetPiece.y;										//Registra la altura dicha por el usuario


		userSetPiece.x--;
		userSetPiece.y--;

		userSetPiece.y = BOARD_SIZE - userSetPiece.y;


		if (userSetPiece.x < 0 && userSetPiece.x > BOARD_SIZE || userSetPiece.y < 1 && userSetPiece.y > BOARD_SIZE) {

			std::cout << "Invalid input. Out of bounds." << std::endl;
			isSettingAPiece = false;

		}
		else if (isWhiteTurn && chessBoard[userSetPiece.x][userSetPiece.y] >= 'a' && chessBoard[userSetPiece.x][userSetPiece.y] <= 'z' ||
			!isWhiteTurn && chessBoard[userSetPiece.x][userSetPiece.y] >= 'A' && chessBoard[userSetPiece.x][userSetPiece.y] <= 'Z') 
			 {
			 	std::cout << "Invalid input. You're trying to get an opp's piece." << std::endl;
			 	isSettingAPiece = false;
			 }


	} while (!isSettingAPiece); 

	return userSetPiece;
}