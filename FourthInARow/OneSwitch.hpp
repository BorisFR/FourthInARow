#ifndef ONESWITCH_h
#define ONESWITCH_h

#include <Arduino.h>

#define DELAY_DEBOUNCE 50

class OneSwitch
{

	private:
		byte thePin;
		uint8_t currentState;
		uint8_t lastState;
		unsigned long debounceTime;

	public:
		OneSwitch();
		void setup(byte pin);
		void loop();
		bool isPressed;
		bool isChange;
};

#endif