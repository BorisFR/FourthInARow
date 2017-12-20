#include "GameInputAudio.h"


#if DEBUG
void GameInputAudio::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug(F("Init dummy screen GameOutputAudio: "));
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
