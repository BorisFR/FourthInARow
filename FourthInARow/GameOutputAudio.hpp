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

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void setup();
		void loop();
		void volumeUp();
		void volumeDown();
		void muteOn();
		void muteOff();

		void playPowerOn();
		void playReset();

		void playQuestion(StarWarsSide side);
		void playClick(StarWarsSide side);
		void playStartGame();
		void playToken(StarWarsSide side);
		void playLooseingAlert(StarWarsSide side);
		void playWinningTeasing(StarWarsSide side);
		void playLoose(StarWarsSide side);
		void playWin(StarWarsSide side);
		void playDraw();
};

#endif