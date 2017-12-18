#include "GameInput.h"

#if DEBUG
void GameInput::doInit(void (*debug)(String), HardwareSerial *serial)
{
	_debug = debug;
	hwSerial = serial;
	_debug("Init GameInput: ");
	doRealInit();
	_debug("OK\n");
};
#else
void GameInput::doInit()
{
	doRealInit();
};
#endif

void GameInput::doRealInit()
{
	input = ' ';
}

bool GameInput::hasInput()
{
	if (input == ' ')
	{
		return false;
	}
	return true;
}

char GameInput::getKey()
{
	char temp = input;
	input = ' ';
	return temp;
}

void GameInput::loop()
{
	#if DEBUG
	if (hwSerial->available())
	{
		input = hwSerial->read();
	}
	#endif	
}