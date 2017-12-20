#ifndef GameInput_h
#define GameInput_h

#include "Global.hpp"
#include <HardwareSerial.h>

class GameInput {

	private:
		#if DEBUG
			void (*_debug)(String text);
		#endif
		void doRealInit();

	protected:
		char input;

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void loop();
		bool hasInput();
		char getKey();
};

#endif