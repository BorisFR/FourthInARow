#ifndef GameInputAudio_h
#define GameInputAudio_h

#include "Global.h"

class GameInputAudio
{
	private:
		void doRealInit();

	protected:
		#if DEBUG
			void (*_debug)(String text);
		#endif

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void setup();

};

#endif