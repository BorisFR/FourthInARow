#include "GO_ws2813.hpp"


#if ESP32
#define FASTLED_SHOW_CORE 1
// -- Task handles for use in the notifications
static TaskHandle_t FastLEDshowTaskHandle = 0;
static TaskHandle_t userTaskHandle = 0;

void FastLEDshowESP32()
{
    if (userTaskHandle == 0) {
        const TickType_t xMaxBlockTime = pdMS_TO_TICKS( 200 );
        // -- Store the handle of the current task, so that the show task can
        //    notify it when it's done
        userTaskHandle = xTaskGetCurrentTaskHandle();

        // -- Trigger the show task
        xTaskNotifyGive(FastLEDshowTaskHandle);

        // -- Wait to be notified that it's done
        ulTaskNotifyTake(pdTRUE, xMaxBlockTime);
        userTaskHandle = 0;
    }
}

void FastLEDshowTask(void *pvParameters)
{
    const TickType_t xMaxBlockTime = pdMS_TO_TICKS( 500 );
    // -- Run forever...
    for(;;) {
        // -- Wait for the trigger
        ulTaskNotifyTake(pdTRUE, xMaxBlockTime);

        // -- Do the show (synchronously)
        FastLED.show();

        // -- Notify the calling task
        xTaskNotifyGive(userTaskHandle);
    }
}
#endif

void GO_ws2813::setLed(uint8_t number, CRGB color)
{
	uint8_t led = leds_positions[number];
	leds[led] = color;
	led = leds_positions_Player_2[number + LED_PLAYER_2_OFFSET];
	leds[led] = color;
}

void GO_ws2813::setup()
{
#if DEBUG
	_debug(F("WS2813: "));
#endif
	FastLED.addLeds<WS2813, WS2813_DATA_PIN, WS2813_COLOR_ORDER>(leds, WS2813_NUMBER_LEDS).setCorrection(TypicalLEDStrip);
	FastLED.setBrightness(WS2813_BRIGHTNESS);
	myBlack = CRGB::Black;
	//myBlack = CRGB::White;
	myWhite = CRGB::White;
	myRed = CRGB::Red;
	myGreen = CRGB::Green; // CHSV( HUE_GREEN, 255, 255)
	myBlue = CRGB::Blue;

#if ESP32
    // -- Create the FastLED show task
    xTaskCreatePinnedToCore(FastLEDshowTask, "FastLEDshowTask", 2048, NULL, 2, &FastLEDshowTaskHandle, FASTLED_SHOW_CORE);
#endif

	for(uint8_t i = 0; i < WS2801_NUMBER_LEDS; i++)
	{
		leds[i] = myBlack;
	}
#if ESP32	
	FastLEDshowESP32();
#else
	FastLED.show();
	FastLED.delay(10);
#endif

#if DEBUG
	_debug(F("ready\n"));
#endif
}

void GO_ws2813::endLoop()
{
#if ESP32	
	FastLEDshowESP32();
#else
	FastLED.show();
	FastLED.delay(10);
#endif
}

void GO_ws2813::showHints(LocationAlert winAlert, LocationAlert looseAlert)
{
	for(uint8_t index = 0; index < BOARD_COLUMNS; index++)
	{
		if (winAlert.row[index] != NO_VALUE)
		{
			setLed(index * COLUMN_TILES + winAlert.row[index], myBlue);
#if DEBUG
			_debug("Hint: " + String(index) + "/" + String(winAlert.row[index]) + "\n");
#endif
		}
		if (looseAlert.row[index] != NO_VALUE)
		{
			setLed(index * COLUMN_TILES + looseAlert.row[index], myBlue);
#if DEBUG
			_debug("Hint: " + String(index) + "/" + String(winAlert.row[index]) + "\n");
#endif
		}
	}
}

void GO_ws2813::showWinningCases(WinningPositions winningCases)
{
	for(int win = 0; win < 4; win ++)
	{
		//if (winningCases.winning[win].possibilityIndex != NO_VALUE)
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
					setLed(winningCases.winning[win].location[index].index * COLUMN_TILES + winningCases.winning[win].location[index].row, myBlue);
				}
			}
#if DEBUG
			_debug("\n");
#endif
		}
	}
}

void GO_ws2813::drawBoard(Board board)
{
#if DEBUG
	_debug("Show board with led.\n");
#endif
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		for (int8_t row = 0; row < COLUMN_TILES; row++)
		{
			uint8_t index = column * COLUMN_TILES + row;
			switch (board.column[column].getToken(row))
			{
			case noPlayer:
				setLed(index, myWhite);
				break;
			case player1:
				setLed(index, myGreen);
				break;
			case player2:
				setLed(index, myRed);
				break;
			}
		}
	}
	endLoop();
}

void GO_ws2813::lightFullWall(bool on)
{
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		lightColumn(column, on);
}

void GO_ws2813::lightColumn(uint8_t index, bool on)
{
	for (int8_t row = 0; row < COLUMN_TILES; row++)
		if(on)
			setLed(index, myWhite);
		else
			setLed(index, myBlack);
}
