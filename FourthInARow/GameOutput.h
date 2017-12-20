#ifndef GameOutput_h
#define GameOutput_h

#include "Global.h"
#include "Column.h"
#include "CaseLocation.h"

class GameOutput
{
	private:
		void doRealInit();

	protected:
		#if DEBUG
			void (*_debug)(String text);
		#endif

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void setup();
		void startLoop();
		void endLoop();

		void showTouchSomething();
		void showChoosePlayersNumber();
		void showPlayerVsPlayer();
		void showPlayerVsIa();
		void showIaVsIa();
		void showDecideWhoStart();
		void showPlayer1Turn();
		void showPlayer2Turn();
		void showMatchDraw();
		void showWinPlayer1();
		void showWinPlayer2();

		void drawGrid();
		void drawBoard(Column board[BOARD_COLUMNS]);
		void clearTiles();
		void setTiles(CaseLocation location, Player token);
};

#endif