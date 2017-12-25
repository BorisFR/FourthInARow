#include "GO_ws2801.hpp"

uint32_t GO_ws2801::Color(byte r, byte g, byte b)
{
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}

void GO_ws2801::setup()
{
#if DEBUG
	_debug(F("WS2801: "));
#endif
	strip.begin();
	strip.show();
	myBlack = Color(0, 0, 0);
	myWhite = Color(255, 255, 255);
	myRed = Color(255, 0, 0);
	myGreen = Color(0, 255, 0);
	myBlue = Color(0, 0, 255);
#if DEBUG
	_debug(F("ready\n"));
#endif
}

void GO_ws2801::endLoop()
{
	strip.show();
}

void GO_ws2801::showHints(LocationAlert winAlert, LocationAlert looseAlert)
{
	for(uint8_t index = 0; index < BOARD_COLUMNS; index++)
	{
		if (winAlert.row[index] != NO_VALUE)
		{
			uint8_t led = leds_positions[index * COLUMN_TILES + winAlert.row[index]];
			strip.setPixelColor(led, myBlue);
#if DEBUG
			_debug("Hint: " + String(index) + "/" + String(winAlert.row[index]) + "\n");
#endif
		}
		if (looseAlert.row[index] != NO_VALUE)
		{
			uint8_t led = leds_positions[index * COLUMN_TILES + looseAlert.row[index]];
			strip.setPixelColor(led, myBlue);
#if DEBUG
			_debug("Hint: " + String(index) + "/" + String(winAlert.row[index]) + "\n");
#endif
		}
	}
}

void GO_ws2801::showWinningCases(WinningPositions winningCases)
{
	for(int win = 0; win < 4; win ++)
	{
		if (winningCases.winning[win].location[0].index < BOARD_COLUMNS)
		{
#if DEBUG
			_debug("ShowWinningCases: ");
#endif
			for (uint8_t index = 0; index < 4; index++)
			{
				{
#if DEBUG
					_debug(String(winningCases.winning[win].location[index].index) + "/" + String(winningCases.winning[win].location[index].row) + " - ");
#endif
					uint8_t led = leds_positions[winningCases.winning[win].location[index].index * COLUMN_TILES + winningCases.winning[win].location[index].row];
					strip.setPixelColor(led, myBlue);
				}
			}
#if DEBUG
			_debug("\n");
#endif
		}
	}
}

void GO_ws2801::drawBoard(Board board)
{
#if DEBUG
	_debug("Show board with led.\n");
#endif
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		for (int8_t row = 0; row < COLUMN_TILES; row++)
		{
			uint8_t index = column * COLUMN_TILES + row;
			uint8_t led = leds_positions[index];
			switch (board.column[column].getToken(row))
			{
			case noPlayer:
				strip.setPixelColor(led, myWhite);
				break;
			case player1:
				strip.setPixelColor(led, myGreen);
				break;
			case player2:
				strip.setPixelColor(led, myRed);
				break;
			}
		}
	}
	endLoop();
}
