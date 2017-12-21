#ifndef GameInputAudio_h
#define GameInputAudio_h

#include "Global.hpp"

class GameInputAudio
{
	private:
		void doRealInit();

	protected:
		#if DEBUG
			void (*_debug)(String text);
		#endif
			InputAction input;

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

		bool hasInput();
		InputAction getAction();
};

#endif