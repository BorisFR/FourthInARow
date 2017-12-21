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
	mute = false;
}

void GameOutputAudio::setup() {}
void GameOutputAudio::loop() {}
void GameOutputAudio::startLoop(){}
void GameOutputAudio::endLoop(){}

void GameOutputAudio::volumeUp() { if(volume < VOLUME_MAX) volume++; }
void GameOutputAudio::volumeDown() { if(volume > VOLUME_MIN) volume--; }
void GameOutputAudio::setVolume(uint8_t value) { if((volume >= VOLUME_MIN) && (volume = VOLUME_MAX)) volume = value; }
uint8_t GameOutputAudio::getVolume() { return volume; }
void GameOutputAudio::muteOn() { mute = true; }
void GameOutputAudio::muteOff() { mute = false; }
bool GameOutputAudio::isMute() { return mute; }
void GameOutputAudio::muteOnOff() { mute = !mute; }

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