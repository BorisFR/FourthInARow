#ifndef GAME_OUTPUT_AUDIO_DFPLAYER_MINI_HPP
#define GAME_OUTPUT_AUDIO_DFPLAYER_MINI_HPP

#include "Global.hpp"
#include "GameOutputAudio.hpp"

class GOA_DFPlayerMini : public GameOutputAudio
{
	private:
	  void sendCommand(uint8_t command, uint8_t part1, uint8_t part2);
	  void doReceiveData();
	  bool playing;
	  void playSongInFolder(uint8_t song, uint8_t folder);
	  void playRandomSongInFolder(uint8_t folder);

	public:
	  void setup();
	  void loop();
	  void volumeUp();
	  void volumeDown();
	  void setVolume(uint8_t value);
	  void muteOnOff();

	  void playPowerOn();
	  void playReset();

	  void playQuestion();
	  void playBadChoice();
	  void playGoodChoice();
	  void playStartGame();
	  void playToken();
	  void playIAThinking();
	  void playLoosingAlert();
	  void playWinningTeasing();
	  void playLoose();
	  void playWin();
	  void playDraw();
};

#endif