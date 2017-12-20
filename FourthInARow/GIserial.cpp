#include "GIserial.h"

void GIserial::loop()
{
	if (Serial.available())
	{
		input = Serial.read();
	}
}