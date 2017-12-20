#ifndef GOserial_h
#define GOserial_h

#include "Global.h"
#include "GameOutput.h"

class GOserial : public GameOutput
{

	private:
		void traceLine();

	public:
		void showTouchSomething();
		void showChoosePlayersNumber();
		void showDecideWhoStart();
		void showPlayer1Turn();
		void showPlayer2Turn();
		void showMatchDraw();
		void showWinPlayer1();
		void showWinPlayer2();

		void drawBoard(Column board[BOARD_COLUMNS]);

};

#endif