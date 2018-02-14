#include "GI_serial.hpp"

void GIserial::loop()
{
	if (Serial.available())
	{
		switch(Serial.read())
		{
			case '1': 
				input = actionColumn1;
				break;
			case '2':
				input = actionColumn2;
				break;
			case '3':
				input = actionColumn3;
				break;
			case '4':
				input = actionColumn4;
				break;
			case '5':
				input = actionColumn5;
				break;
			case '6':
				input = actionColumn6;
				break;
			case '7':
				input = actionColumn7;
				break;
			case 'R':
				input = actionReset;
				break;
			}
	}
}