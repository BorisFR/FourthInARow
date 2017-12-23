#ifndef GAME_INPUT_AUDIO_EC11_HPP
#define GAME_INPUT_AUDIO_EC11_HPP

#include "Global.hpp"
#include "GameInputAudio.hpp"
#include "OneSwitch.hpp"

class GIAec11 : public GameInputAudio
{

	private:
		long lastEncoderValue = 0;
		OneSwitch button;

	public :
		void setup();
		void loop();
};

#endif