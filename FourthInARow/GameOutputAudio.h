#ifndef GameOutputAudio_h
#define GameOutputAudio_h

#include "Global.h"

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
		void volumeUp();
		void volumeDown();
		void muteOn();
		void muteOff();

};

#endif