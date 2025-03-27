
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



		viewChessBoard(chessBoard);

		Position userGetPiece, userSetPiece;

		userGetPiece = getPieceByUser(chessBoard, isWhiteTurn);
		userSetPiece = setPieceByUser(chessBoard, isWhiteTurn); 


		//Imprimir lo que haya puesto el jugador
		if (turnoJugador == 1) { 

			if (chessBoard[userGetPiece.x][userGetPiece.y] == EMPTY && chessBoard[userSetPiece.x][userSetPiece.y] == EMPTY) {

				chessBoard[userSetPiece.x][userSetPiece.y] = userGetPiece;                                        
				std::cout << "You've moved to " << "X: " << userSetPiece.x << " Y: " << userSetPiece.y << std::endl;                           
			}
			else {  

				chessBoard[userSetPiece.x][userSetPiece.y] != EMPTY; 

				std::cout << "There's already a piece in that position. Try again." << std::endl;              
				if (turnoJugador == 1) {
					turnoJugador = 2;
				}
				else if (turnoJugador == 2) {
					turnoJugador = 1;
				}
			}
		}


		for (int i = 0; i < BOARD_SIZE; i++) {                              //Crea i, e incrementa hasta el tamaño del tablero
			for (int j = 0; j < BOARD_SIZE; j++) {                          //Crea j, e incrementa hasta el tamaño del tablero
				if (chessBoard[i][j] = '*') {   //Condicional que dice que si no hay agua ni impacto...
					std::cout << "Has movido a " << userSetPiece.x;                                  //Imprime ~ en vez de los números del principio (oculta los barcos)
				}
				else {
					std::cout << chessBoard[i][j] << " ";                 //Si no se cumple el condicional, imprime normal
				}
			}
			std::cout << std::endl;                                     //Finaliza la línea
		}


		bool isGettingAPiece = false;



	} while (!gameOver);

	system("cls");
}
	
