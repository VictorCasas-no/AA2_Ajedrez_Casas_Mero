<<<<<<< Updated upstream
#include "Const.h"
#include "Board.h"


int main() {

	char chessBoard[BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chessBoard);

	viewChessBoard(chessBoard);
	
=======
#include <iostream>
#include "const.h"
#include "tablero.h"
#include "utils.h"

int main() 
{

	char chesstBoard [BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chesstBoard);

	viewChessBoard(chesstBoard);
>>>>>>> Stashed changes
}