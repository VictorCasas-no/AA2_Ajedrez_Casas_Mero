
#pragma region Includes;

#include "Const.h"
#include "Board.h"
#include "Utils.h"

#pragma endregion;


int main() {

	bool gameOver = false;

	short turnoJugador = 1;

	int x;
	int y;

	char chessBoard[BOARD_SIZE][BOARD_SIZE];

	initChessBoard(chessBoard);

	viewChessBoard(chessBoard);



	do {

		viewChessBoard(chessBoard);

		Position userGetPiece, userSetPiece;

		userGetPiece = getPieceByUser();

		userGetPiece.x--;
		userGetPiece.y--;

		userGetPiece.y = BOARD_SIZE - userGetPiece.y;

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

		do {

			//Pedir al jugador ficha
			std::cout << std::endl;								//Añade una línea vacía entre el tablero y lo siguiente
			std::cout << "Elige una pieza: ";                   //Pide una altura a la que atacar
			std::cout << "X: ";									//Posición X que el usuario indica
			std::cin >> getPieceByUser.x;                       //Registra la altura dicha por el usuario
			std::cout << "Y: ";									//Pide una Y que el usuario indica
			std::cin >> getPieceByUser.y;


			//Pedir al jugador dónde mover
			std::cout << "Altura a la cual mover: ";            //Pide una altura a la que mover
			std::cin >> x;										//Registra el ancho dicho por el usuario
			std::cout << "Posición a lo ancho donde mover: ";   //Pide el ancho al cual mover
			std::cin >> y;										//Registra la altura dicha por el usuario


			if (userGetPiece.x < 0 && userGetPiece.x > BOARD_SIZE || userGetPiece.y < 1 && userGetPiece.y > BOARD_SIZE) {

				std::cout << "Invalid input" << std::endl;

			}
			else {

				isGettingAPiece = true;

			}

		} while (!isGettingAPiece);


	} while (!gameOver);

	system("cls");
}
	
