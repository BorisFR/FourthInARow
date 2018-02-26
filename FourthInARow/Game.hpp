#ifndef Game_h
#define Game_h

#include "Global.hpp"
#include "Column.hpp"
#include "CaseLocation.hpp"
#include "Solver.hpp"

#define WIN_VALUE 100000
#define MAX_POSSIBILITIES 69
#define COLUMN 0
#define ROW 1
#define COLUMN_CHANGE 2
#define ROW_CHANGE 3
#define TILE_VALUE 4

enum GameState : uint8_t
{
	waitingTouch,			// attente d'une nouvelle partie
	choosingPlayersNumber,  // choix du nombre de joueurs
	startingNewGame,		// démarrage d'une nouvelle partie
	choosingWhoStart,		// choix de qui commence
	playingPlayer1,			// choix de la colonne du joueur 1
	choosingColumn,			// attente du choix de la colonne
	puttingToken,			// essai de jouer une colonne
	badColumn,				// impossible de jouer cette colonne
	tokenAnimation,			// on joue la colonne
	playingPlayer2,			// choix de la colonne du joueur 2
	matchDraw,				// match nul,plus personne ne peut jouer
	animationWinnerPlayer1, // le joueur 1 a gagner
	animationWinnerPlayer2, // le joueur 2 a gagner
};

class Game {

	private:
		#if DEBUG
			void (*_debug)(String text);
			void traceLine();
			void tab(uint8_t space);
		#endif
		void doRealInit();
		uint8_t tileInterest[BOARD_COLUMNS][COLUMN_TILES];
		void clearWinningCases();
		void clearTurn();
		Column board[BOARD_COLUMNS];
		Player currentPlayer;
		void addWinningCase(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4, uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4);
		bool isVerticalWin(uint8_t index);
		bool isHorizontalWin(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4);
		Player theWinner;
		LocationAlert winAlert;
		LocationAlert looseAlert;
		uint8_t countWinningCases;
		WinningPositions winningCases;
		int8_t winPossibilities[MAX_POSSIBILITIES][5];
		bool inbounds(int8_t row, int8_t column);
		void calculateAllPossibilities();
		uint8_t numberMoves;
		//int32_t getStrength(Player player, uint8_t column, uint8_t row, int8_t columnChange, int8_t rowChange);
		int32_t computeValue(int32_t me, int32_t other);
		int32_t getTileValue(Player player, Player other, uint8_t column, uint8_t row);
		int32_t getBoardValue(Player player);
		int32_t getMinimalMove(Player player, uint8_t deepness, int32_t alpha);
		int32_t getMaximalMove(Player player, uint8_t deepness, int32_t beta);
		uint8_t bestColumnToPlay;
		uint8_t playPossibilities[BOARD_COLUMNS];
		HintStatus hintsState;

		GameSolver::Connect4::Solver solver;

	public :
		#if DEBUG
			void
			doInit(void (*)(String));
			void dumpGame();
		#else
			void
			doInit();
		#endif
		GameState gameState;
		Board getBoard();
		void startNewGame();
		void setCurrentPlayer(Player player);
		Player getCurrentPlayer();
		void nextPlayer();
		uint8_t getRowPlayingColumn(uint8_t index);
		bool isPlayingPossible();
		bool isSomeoneWinner();
		Player getWhoWin();
		uint8_t getIndexPlayingForPlayerIA(Player player);
		bool willWin[BOARD_COLUMNS];
		bool willLoose[BOARD_COLUMNS];
		void calculateHints();
		WinningPositions getWinningCases();
		HintStatus getHints();
		LocationAlert getWinHints();
		LocationAlert getLooseHints();
};

#endif