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
	input = actionNone;
	value = AUDIO_STARTING_VOLUME;
}

void GameInputAudio::setup() {}
void GameInputAudio::loop() {}
void GameInputAudio::startLoop(){}
void GameInputAudio::endLoop(){}

bool GameInputAudio::hasInput()
{
	if (input == actionNone)
	{
		return false;
	}
	return true;
}

InputAction GameInputAudio::getAction()
{
	InputAction temp = input;
	input = actionNone;
	return temp;
}

uint8_t GameInputAudio::getValue() { return value; }