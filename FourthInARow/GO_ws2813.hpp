#pragma once
#ifndef GAME_OUPUT_WS2813_HPP
#define GAME_OUPUT_WS2813_HPP

#include "Global.hpp"
#include "GameOutput.hpp"
#include "FastLED.h"

class GO_ws2813 : public GameOutput
{
	private:
		CRGB leds[WS2813_NUMBER_LEDS];
		CRGB myBlack;
		CRGB myWhite;
		CRGB myRed;
		CRGB myGreen;
		CRGB myBlue;

		void setLed(uint8_t number, CRGB color);

	public:
		void setup();
		void endLoop();

		void showHints(LocationAlert winAlert, LocationAlert looseAlert);
		void showWinningCases(WinningPositions winningCases);

		void drawBoard(Board board);

		void lightFullWall(bool on);
		void lightColumn(uint8_t index, bool on);

};

#endif