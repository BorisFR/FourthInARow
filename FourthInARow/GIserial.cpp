#include "GIserial.hpp"

void GIserial::loop()
{
	if (Serial.available())
	{
		input = Serial.read();
	}
}