#ifndef GameOutput_h
#define GameOutput_h

#include "Global.hpp"
#include "Column.hpp"
#include "CaseLocation.hpp"

class GameOutput
{
	private:
		void doRealInit();

	protected:
		#if DEBUG
			void (*_debug)(String text);
		#endif
			uint8_t leds_positions[42] = { LED_POSITIONS };
			uint8_t leds_positions_Player_2[42] = { LED_POSITIONS_PLAYER_2 };

  public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void setup();
		void loop();
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
		void showHints(LocationAlert winAlert, LocationAlert looseAlert);
		void showWinningCases(WinningPositions winningCases);

		void drawGrid();
		void drawBoard(Board board);
		void clearTiles();
		void setTiles(CaseLocation location, Player token);

		void lightFullWall(bool on);
		void lightColumn(uint8_t index, bool on);
};

#endif