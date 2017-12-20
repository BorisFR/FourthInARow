#include "GameOutputAudio.hpp"

#if DEBUG
void GameOutputAudio::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug(F("Init dummy GameOutputAudio: "));
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

void GameOutputAudio::playPowerOn() {}
void GameOutputAudio::playReset() {}

void GameOutputAudio::playQuestion(StarWarsSide side) {}
void GameOutputAudio::playClick(StarWarsSide side) {}
void GameOutputAudio::playStartGame() {}
void GameOutputAudio::playToken(StarWarsSide side) {}
void GameOutputAudio::playLooseingAlert(StarWarsSide side) {}
void GameOutputAudio::playWinningTeasing(StarWarsSide side) {}
void GameOutputAudio::playLoose(StarWarsSide side) {}
void GameOutputAudio::playWin(StarWarsSide side) {}
void GameOutputAudio::playDraw() {}