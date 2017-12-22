#ifndef GAME_OUTPUT_AUDIO_DFPLAYER_MINI_HPP
#define GAME_OUTPUT_AUDIO_DFPLAYER_MINI_HPP

#include "Global.hpp"
#include "GameOutputAudio.hpp"

class GOA_DFPlayerMini : public GameOutputAudio
{
	private:
	  void sendCommand(uint8_t command, uint8_t part1, uint8_t part2);
	  void doReceiveData();

	public:
	  void setup();
	  void loop();
	  void volumeUp();
	  void volumeDown();
	  void setVolume(uint8_t value);
};

#endif