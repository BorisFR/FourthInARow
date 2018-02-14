#ifndef GameInput_h
#define GameInput_h

#include "Global.hpp"
#include <HardwareSerial.h>

class GameInput {

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