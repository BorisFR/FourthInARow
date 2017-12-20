#include "GOserial.h"

void GOserial::showTouchSomething()
{
	Serial.println(F("Touchez pour démarrer"));

}
		
void GOserial::showChoosePlayersNumber()
{
	Serial.println(F("Combien de joueurs ? (0/1/2)"));
}

void GOserial::showDecideWhoStart()
{
	Serial.println(F("Décide qui commence..."));
}

void GOserial::showPlayer1Turn()
{
	Serial.println(F("Joueur 1, colonne de 1 à 7 : "));
}

void GOserial::showPlayer2Turn()
{
	Serial.println(F("Joueur 2, colonne de 1 à 7 : "));
}

void GOserial::showMatchDraw()
{
	Serial.println(F("Match null"));
}

void GOserial::showWinPlayer1()
{
	Serial.println(F("Le joueur 1 gagne !"));
}

void GOserial::showWinPlayer2()
{
	Serial.println(F("Le joueur 2 gagne !"));
}

void GOserial::traceLine()
{
	Serial.print("+");
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		Serial.print("-+");
	}
	Serial.print("\n");
}

void GOserial::drawBoard(Column board[BOARD_COLUMNS])
{
	traceLine();
	for (int8_t row = (COLUMN_TILES - 1); row >= 0; row--)
	{
		Serial.print("|");
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			switch (board[column].getToken(row))
			{
			case noPlayer:
				Serial.print(" ");
				break;
			case player1:
				Serial.print("X");
				break;
			case player2:
				Serial.print("O");
				break;
			}
			Serial.print("|");
		}
		Serial.print("\n");
		traceLine();
	}
}
