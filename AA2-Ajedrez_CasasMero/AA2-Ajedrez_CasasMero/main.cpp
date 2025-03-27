
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



#pragma region Turnos;

		//Indicar turnos
		std::cout << std::endl;                                                 //Finaliza línea previamente
		std::cout << "---------------------------------" << std::endl;
		std::cout << "Turno de Jugador " << turnoJugador << std::endl;          //Texto para mostrar el turno correspondiente
		std::cout << "---------------------------------" << std::endl;


		//Cambios de turno
		if (turnoJugador == 1) {        //Condicional que cambia el turno del 1 al 2 cada vez que finaliza una ronda
			turnoJugador = 2;
		}
		else {
			turnoJugador = 1;           //Y si tenía turno el 2, cambia al 1
		}

#pragma endregion;

		bool isGettingAPiece = false;



	} while (!gameOver);

	system("cls");
}
	
