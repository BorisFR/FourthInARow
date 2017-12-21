#include "GameInputAudio.hpp"


#if DEBUG
void GameInputAudio::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug(F("Init dummy GameInputAudio: "));
	doRealInit();
	_debug(F("OK\n"));
}
#else
void GameInputAudio::doInit()
{
	realInit();
}
#endif

void GameInputAudio::doRealInit()
{
	input = '|';
}

void GameInputAudio::setup() {}
void GameInputAudio::loop() {}
void GameInputAudio::startLoop(){}
void GameInputAudio::endLoop(){}

bool GameInputAudio::hasInput()
{
	if (input == '|')
	{
		return false;
	}
	return true;
}

char GameInputAudio::getKey()
{
	char temp = input;
	input = '|';
	return temp;
}