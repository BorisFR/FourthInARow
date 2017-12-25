#include "GI_9buttons.hpp"

void GI9buttons::setup()
{
#if DEBUG
	_debug(F("9 Buttons: "));
#endif
	button[0].setup(BUTTON_COLUMN_1);
	button[1].setup(BUTTON_COLUMN_2);
	button[2].setup(BUTTON_COLUMN_3);
	button[3].setup(BUTTON_COLUMN_4);
	button[4].setup(BUTTON_COLUMN_5);
	button[5].setup(BUTTON_COLUMN_6);
	button[6].setup(BUTTON_COLUMN_7);
	button[7].setup(BUTTON_COLUMN_PLAYER_1);
	button[8].setup(BUTTON_COLUMN_PLAYER_2);
#if DEBUG
	_debug(F("ready\n"));
#endif
}

void GI9buttons::loop()
{
	for(uint8_t i = 0; i < 7; i++)
	{
		button[i].loop();
		if (button[i].isChange)
		{
			if (button[i].isPressed)
			switch(i)
			{
				case 0: 
					input = actionColumn1;
					break;
				case 1:
					input = actionColumn2;
					break;
				case 2:
					input = actionColumn3;
					break;
				case 3:
					input = actionColumn4;
					break;
				case 4:
					input = actionColumn5;
					break;
				case 5:
					input = actionColumn6;
					break;
				case 6:
					input = actionColumn7;
					break;
				}
		}
	}
	button[7].loop();
	if (button[7].isChange)
	{
		if (button[7].isPressed)
			input = actionPlayer1;
	}
	button[8].loop();
	if (button[8].isChange)
	{
		if (button[9].isPressed)
			input = actionPlayer2;
	}
	// button 0 + button 6 = reset
	if (button[0].isPressed && button[6].isPressed)
	{
		input = actionReset;
	}
	// player 1 + player 2 = reset
	if (button[7].isPressed && button[8].isPressed)
	{
		input = actionReset;
	}
}