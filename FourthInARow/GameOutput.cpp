#include "GameOutput.h"

#if DEBUG
void GameOutput::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug(F("Init dummy screen GameOutput: "));
	doRealInit();
	_debug(F("OK\n"));
};
#else
void GameOutput::doInit()
{
	realInit();
};
#endif

void GameOutput::doRealInit()
{
}

void GameOutput::showTouchSomething() {}
void GameOutput::showChoosePlayersNumber() {}
void GameOutput::showPlayerVsPlayer() {}
void GameOutput::showPlayerVsIa() {}
void GameOutput::showIaVsIa() {}
void GameOutput::showDecideWhoStart() {}
void GameOutput::showPlayer1Turn() {}
void GameOutput::showPlayer2Turn() {}
void GameOutput::showMatchDraw() {}
void GameOutput::showWinPlayer1() {}
void GameOutput::showWinPlayer2() {}

void GameOutput::setup(){}
void GameOutput::startLoop(){}
void GameOutput::endLoop(){}

void GameOutput::drawGrid() {}
void GameOutput::drawBoard(Column board[BOARD_COLUMNS]) {}
void GameOutput::clearTiles() {}
void GameOutput::setTiles(CaseLocation location, Player token) {}
