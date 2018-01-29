#pragma once
#ifndef GAME_OUPUT_WS2801_HPP
#define GAME_OUPUT_WS2801_HPP

#include "Global.hpp"
#include "GameOutput.hpp"
#include "Adafruit_WS2801.h"

class GO_ws2801 : public GameOutput
{
	private:
		Adafruit_WS2801 strip = Adafruit_WS2801(WS2801_NUMBER_LEDS, WS2801_DATA_PIN, WS2801_CLOCK_PIN);
		uint32_t Color(byte r, byte g, byte b);
		uint32_t myBlack;
		uint32_t myWhite;
		uint32_t myRed;
		uint32_t myGreen;
		uint32_t myBlue;

	public:
	  void setup();
	  void endLoop();

	  void showHints(LocationAlert winAlert, LocationAlert looseAlert);
	  void showWinningCases(WinningPositions winningCases);

	  void drawBoard(Board board);
};

#endif