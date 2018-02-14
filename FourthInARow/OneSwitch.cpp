#include "OneSwitch.hpp"

OneSwitch::OneSwitch()
{
}

void OneSwitch::setup(byte pin)
{
	thePin = pin;
	currentState = LOW;
	lastState = LOW;
	debounceTime = 0;
	pinMode(thePin, INPUT_PULLUP);
	isPressed = false;
	isChange = false;
}

void OneSwitch::loop()
{
	isChange = false;
	uint8_t reading = digitalRead(thePin);
	if (reading != lastState)
		debounceTime = millis();

	if ((millis() - debounceTime) > DELAY_DEBOUNCE)
	{
		if (reading != currentState)
		{
			currentState = reading;
			isChange = true;
			if (currentState == HIGH)
				isPressed = false;
			else
				isPressed = true;
		}
	}

	lastState = reading;
}
