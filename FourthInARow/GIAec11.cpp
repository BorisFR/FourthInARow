#include "GIAec11.hpp"

volatile int ec11LastEncoded = 0;
volatile long ec11EncoderValue = 0;
volatile bool ec11Plus = false;
volatile bool ec11Minus = false;

void updateEncoder()
{
	uint8_t msb = digitalRead(EC11_ENCODER_PIN_A); //MSB = most significant bit
	uint8_t lsb = digitalRead(EC11_ENCODER_PIN_B); //LSB = least significant bit
	int encoded = (msb << 1) | lsb; //converting the 2 pin value to single number
	int sum = (ec11LastEncoded << 2) | encoded; //adding it to the previous encoded value
	if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
	{
		ec11EncoderValue++;
		ec11Plus = true;
	}
	if (sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
	{
		ec11EncoderValue--;
		ec11Minus = true;
	}
	ec11LastEncoded = encoded; //store this value for next time
}

void GIAec11::setup()
{
	pinMode(EC11_ENCODER_PIN_A, INPUT);
	pinMode(EC11_ENCODER_PIN_B, INPUT);
	digitalWrite(EC11_ENCODER_PIN_A, HIGH);
	digitalWrite(EC11_ENCODER_PIN_B, HIGH);
	attachInterrupt(0, updateEncoder, CHANGE);
	attachInterrupt(1, updateEncoder, CHANGE);

	button.setup(EC11_BUTTON_PIN);
}

void GIAec11::loop()
{
	button.loop();
	if (button.isChange)
	{
		if (button.isPressed)
			input = 'M';
	}
	else
	{
		if (ec11Plus)
		{
			input = '+';
			ec11Plus = false;
		}
		else
		{
			input = '-';
			ec11Minus = false;
		}
	}
}

bool GIAec11::hasInput()
{
	if (input == '|')
	{
		return false;
	}
	return true;
}

char GIAec11::getKey()
{
	char temp = input;
	input = '|';
	return temp;
}