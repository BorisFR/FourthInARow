#include "GIA_ec11.hpp"

volatile bool ec11Fired;
volatile bool ec11State;

void ec11Interrupt()
{
	if (digitalRead(EC11_ENCODER_PIN_A))
		ec11State = digitalRead(EC11_ENCODER_PIN_B);
	else
		ec11State = !digitalRead(EC11_ENCODER_PIN_B);
	ec11Fired = true;
}

void GIAec11::setup()
{
	pinMode(EC11_ENCODER_PIN_A, INPUT_PULLUP);
	pinMode(EC11_ENCODER_PIN_B, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(EC11_ENCODER_PIN_A), ec11Interrupt, CHANGE);
	pinMode(EC11_BUTTON_PIN, INPUT);
	button.setup(EC11_BUTTON_PIN);
}

void GIAec11::loop()
{
	button.loop();
	if (button.isChange)
	{
		if (button.isPressed)
			input = actionVolumeMuteOnOff;
	}
	else
	{
		if (ec11Fired)
		{
			if (ec11State)
			{
				input = actionVolumeDown;
				if(value > 0) value--;
			}
			else
			{
				input = actionVolumeUp;
				if(value < 100) value++;
			}
			ec11Fired = false;
		}
	}
}