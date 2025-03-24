<<<<<<< Updated upstream
#include "Const.h"

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

=======
#include "const.h"




void initChessBoard(char chesstBoard[BOARD_SIZE][BOARD_SIZE]) {
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			// Set chess pieces
			if (j == BOARD_SIZE - 2) chesstBoard[j][i] = BLACK_PAWN;
			else if (j == 1) chesstBoard[j][i] = WHITE_PAWN;
			else chesstBoard[j][i] = EMPTY;		//Set empty cell
	
		}
	}

	const short YPosL = 0;
	const short YPosR = BOARD_SIZE - 1;

	const short rookXPosL = 0;
	const short rookXPosR = BOARD_SIZE -1;
	const short KnightXPosL = 1;
	const short KnightXPosR = BOARD_SIZE - 2;
	const short bishopXPosL = 2;
	const short bishopXPosR = BOARD_SIZE - 3;

	const short whiteKingXPosL = 3;
	const short whiteQueenXPosR = BOARD_SIZE - 4;
	const short blackKingXPosL = BOARD_SIZE - 4;
	const short blackQueenXPosR = 3;
	


	// Set white chess pieces
			// Set chess pieces
	chesstBoard[7][rookXPosL] = WHITE_ROOK; 
	chesstBoard[7][rookXPosR] = WHITE_ROOK; 
	chesstBoard[7][KnightXPosL] = WHITE_KNIGHT; 
	chesstBoard[7][KnightXPosR] = WHITE_KNIGHT; 
	chesstBoard[7][bishopXPosL] = WHITE_BISHOP; 
	chesstBoard[7][bishopXPosR] = WHITE_BISHOP; 
	chesstBoard[7][blackKingXPosL] = WHITE_KING;  
	chesstBoard[7][blackQueenXPosR] = WHITE_QUEEN; 

	// Set black chess pieces

	chesstBoard[0][rookXPosL] = BLACK_ROOK;  
	chesstBoard[0][rookXPosR] = BLACK_ROOK;  
	chesstBoard[0][KnightXPosL] = BLACK_KNIGHT;  
	chesstBoard[0][KnightXPosR] = BLACK_KNIGHT;  
	chesstBoard[0][bishopXPosL] = BLACK_BISHOP;  
	chesstBoard[0][bishopXPosR] = BLACK_BISHOP;   
	chesstBoard[0][blackKingXPosL] = BLACK_KING; 
	chesstBoard[0][blackQueenXPosR] = BLACK_QUEEN;  

}

void viewChessBoard(char chesstBoard[BOARD_SIZE][BOARD_SIZE]) {

	std::cout << ' ' << ' ';

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << i + 1 << ' ';
	}
	std::cout << std::endl;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << BOARD_SIZE - i << ' ';
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << chesstBoard[i][j] << ' ';
		}
		std::cout << std::endl;
	}
>>>>>>> Stashed changes
}