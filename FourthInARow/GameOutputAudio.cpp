#include "GameOutputAudio.h"

#if DEBUG
void GameOutputAudio::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug(F("Init dummy screen GameOutputAudio: "));
	doRealInit();
	_debug(F("OK\n"));
}
#else
void GameOutputAudio::doInit()
{
	realInit();
}
#endif

void GameOutputAudio::doRealInit()
{
	volume = AUDIO_STARTING_VOLUME;
}

void GameOutputAudio::setup() {}
void GameOutputAudio::loop() {}
void GameOutputAudio::volumeUp() {}
void GameOutputAudio::volumeDown() {}
void GameOutputAudio::muteOn() {}
void GameOutputAudio::muteOff() {}
