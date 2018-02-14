#ifndef FeatherOled_h
#define FeatherOled_h

#include "Global.hpp"
#include "GameOutput.hpp"

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#if defined(ESP8266)
#define BUTTON_A 0
#define BUTTON_B 16
#define BUTTON_C 2
#define LED 0
#elif defined(ESP32)
#define BUTTON_A 15
#define BUTTON_B 32
#define BUTTON_C 14
#define LED 13
#elif defined(ARDUINO_STM32F2_FEATHER)
#define BUTTON_A PA15
#define BUTTON_B PC7
#define BUTTON_C PC5
#define LED PB5
#elif defined(TEENSYDUINO)
#define BUTTON_A 4
#define BUTTON_B 3
#define BUTTON_C 8
#define LED 13
#elif defined(ARDUINO_FEATHER52)
#define BUTTON_A 31
#define BUTTON_B 30
#define BUTTON_C 27
#define LED 17
#else // 32u4, M0, and 328p
#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5
#define LED 13
#endif

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#define SQUARE_SIZE 4

class GOFeatherOled : public GameOutput
{
	private:
		Adafruit_SSD1306 display = Adafruit_SSD1306();
		void clearTextArea();
		void printText(String text);

	public:
		void setup();
		void endLoop();

		void showTouchSomething();
		void showChoosePlayersNumber();
		void showDecideWhoStart();
		void showPlayer1Turn();
		void showPlayer2Turn();
		void showMatchDraw();
		void showWinPlayer1();
		void showWinPlayer2();

		void drawGrid();
		void clearTiles();
		void setTiles(CaseLocation location, Player token);
};

#endif