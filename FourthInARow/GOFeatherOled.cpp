#include "GOFeatherOled.hpp"

void GOFeatherOled::setup()
{
	// by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
	display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with the I2C addr 0x3C (for the 128x32)
	display.display();
	display.clearDisplay();
	display.display();
	pinMode(BUTTON_A, INPUT_PULLUP);
	pinMode(BUTTON_B, INPUT_PULLUP);
	pinMode(BUTTON_C, INPUT_PULLUP);
	display.setTextSize(1);
	display.setTextColor(WHITE);
	display.setCursor(0, 0);
}

void GOFeatherOled::startLoop()
{
}

void GOFeatherOled::endLoop()
{
	display.display();
}

void GOFeatherOled::clearTextArea()
{
	display.fillRect(BOARD_COLUMNS * (SQUARE_SIZE + 1) + 2, 0, 128 - (BOARD_COLUMNS * (SQUARE_SIZE + 1) + 2), 32, BLACK);
}

void GOFeatherOled::printText(String text)
{
	display.setCursor(BOARD_COLUMNS * (SQUARE_SIZE + 1) + 2 + 2, 10);
	display.print(text);
}

void GOFeatherOled::showTouchSomething()
{
	clearTextArea();
	printText("Touch to start");
}
void GOFeatherOled::showChoosePlayersNumber()
{
	clearTextArea();
	printText("How many");
	display.setCursor(BOARD_COLUMNS * (SQUARE_SIZE + 1) + 2 + 2, 20);
	display.print("players ?");
}
void GOFeatherOled::showDecideWhoStart()
{
	clearTextArea();
	printText("Choosing ...");
}
void GOFeatherOled::showPlayer1Turn()
{
	clearTextArea();
	printText("Player 1");
}
void GOFeatherOled::showPlayer2Turn()
{
	clearTextArea();
	printText("Player 2");
}
void GOFeatherOled::showMatchDraw()
{
	clearTextArea();
	printText("Match draw");
}
void GOFeatherOled::showWinPlayer1()
{
	clearTextArea();
	printText("Player 1 WIN!");
}
void GOFeatherOled::showWinPlayer2()
{
	clearTextArea();
	printText("Player 2 WIN!");
}

void GOFeatherOled::drawGrid()
{
	display.clearDisplay();
	for (uint8_t y = 5; y < COLUMN_TILES * (SQUARE_SIZE + 1); y += (SQUARE_SIZE + 1))
	{
		display.drawFastHLine(0, y, BOARD_COLUMNS * (SQUARE_SIZE + 1), WHITE);
	}
	for (uint8_t x = 5; x < BOARD_COLUMNS * (SQUARE_SIZE + 1); x += (SQUARE_SIZE + 1))
	{
		display.drawFastVLine(x, 0, COLUMN_TILES * (SQUARE_SIZE + 1), WHITE);
	}
}

void GOFeatherOled::clearTiles()
{
	drawGrid();
}

void GOFeatherOled::setTiles(CaseLocation location, Player token)
{
	uint8_t x = location.index * (SQUARE_SIZE + 1);
	uint8_t y = (COLUMN_TILES - location.row - 1) * (SQUARE_SIZE + 1);
	switch (token)
	{
	case noPlayer:
		for (uint8_t i = 0; i <= SQUARE_SIZE; i++)
		{
			for (uint8_t j = 0; j <= SQUARE_SIZE; j++)
			{
				display.drawPixel(x + i, y + j, BLACK);
			}
		}
		break;
	case player1:
		for (uint8_t i = 0; i <= SQUARE_SIZE; i++)
		{
			for (uint8_t j = 0; j <= SQUARE_SIZE; j++)
			{
				display.drawPixel(x + i, y + j, WHITE);
			}
		}
		break;
	case player2:
		display.drawPixel(x, y, WHITE);
		display.drawPixel(x + 1, y + 1, WHITE);
		display.drawPixel(x + 2, y + 2, WHITE);
		display.drawPixel(x + 3, y + 3, WHITE);
		display.drawPixel(x + 4, y + 4, WHITE);
		display.drawPixel(x + 4, y, WHITE);
		display.drawPixel(x + 3, y + 1, WHITE);
		display.drawPixel(x + 2, y + 2, WHITE);
		display.drawPixel(x + 1, y + 3, WHITE);
		display.drawPixel(x, y + 4, WHITE);
		break;
	}
}
