#ifndef GAME_OUTPUT_AUDIO_HPP
#define GAME_OUTPUT_AUDIO_HPP

#include "Global.hpp"

enum StarWarsSide : uint8_t
{
	noSide,
	rebel,
	empire,
};

class GameOutputAudio
{
	private:
		void doRealInit();

	protected:
		#if DEBUG
			void (*_debug)(String text);
		#endif
		uint8_t volume;
		bool mute;

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void setup();
		void loop();
		void startLoop();
		void endLoop();

		void volumeUp();
		void volumeDown();
		void setVolume(uint8_t value);
		uint8_t getVolume();
		void muteOn();
		void muteOff();
		bool isMute();
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