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
}

void GameInputAudio::setup() {}
void GameInputAudio::loop() {}
