#ifndef GameInput_h
#define GameInput_h

#include "Global.h"
#include <HardwareSerial.h>

class GameInput {

	private:
		#if DEBUG
			void (*_debug)(String text);
			HardwareSerial *hwSerial;
		#endif
		void doRealInit();

		char input;

	public:
		#if DEBUG
			void doInit(void (*)(String), HardwareSerial *serial);
		#else
			void doInit();
		#endif
		void loop();
		bool hasInput();
		char getKey();
};

#endif