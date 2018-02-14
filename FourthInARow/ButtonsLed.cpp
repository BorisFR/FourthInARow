#include "ButtonsLed.hpp"


#if DEBUG
void ButtonsLed::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug("Init ButtonsLed: ");
	doRealInit();
	_debug("OK\n");
};
#else
void ButtonsLed::doInit()
{
	doRealInit();
};
#endif

void ButtonsLed::doRealInit()
{
	blinkPlayers = false;
	blinkInputs = false;
	for(uint8_t index = 0; index < 9; index++)
		pinMode(pinButtonsLed[index], OUTPUT);
	allLightsOff();
}

void ButtonsLed::loop()
{
	if(blinkOneLed >= 0)
	{
		if(delayBlinkOneLed > BLINK_DELAY)
		{
			invertLight(blinkOneLed);
			delayBlinkOneLed = 0;
		}
	}
	if(blinkPlayers)
	{
		if(delayBlinkPlayers > BLINK_DELAY)
		{
			invertLight(LED_PLAYER_1);
			invertLight(LED_PLAYER_2);
			delayBlinkPlayers = 0;
		}
	}
	if(blinkInputs)
	{
		if(delayBlinkInputs > BLINK_DELAY)
		{
			for(uint8_t index = 0; index < 7; index++)
				invertLight(index);
			delayBlinkInputs = 0;
		}
	}
	if(chaseInputs)
	{
		if(delayChaseInputs > BLINK_DELAY)
		{
			bool isLight = isLightOn(6);
			for(uint8_t i = 6; i > 0; i--)
			{
				if(isLightOn(i-1))
					lightOn(i);
				else
					lightOff(i);
			}
			if(isLight)
				lightOn(0);
			else
				lightOff(0);
			delayChaseInputs = 0;
		}
	}
}

void ButtonsLed::invertLight(uint8_t index)
{
	if(isLightOn(index))
		lightOff(index);
	else
		lightOn(index);
}

void ButtonsLed::lightOn(uint8_t index)
{
	if(isLightOn(index))
		return;
	ledOn[index] = true;
	digitalWrite(index, LOW);
}

void ButtonsLed::lightOff(uint8_t index)
{
	if(!isLightOn(index))
		return;
	ledOn[index] = false;
	digitalWrite(index, HIGH);
}

bool ButtonsLed::isLightOn(uint8_t index)
{
	return ledOn[index];
}

void ButtonsLed::allLightsOn()
{
	for(uint8_t index = 0; index < 9; index++)
		lightOn(index);
}

void ButtonsLed::allLightsOff()
{
	for(uint8_t index = 0; index < 9; index++)
		lightOff(index);
}

void ButtonsLed::doBlinkPlayers(bool value)
{
	blinkPlayers = value;
	if(blinkPlayers)
	{
		lightOff(LED_PLAYER_1);
		lightOn(LED_PLAYER_2);
		delayBlinkPlayers = BLINK_DELAY / 2;
	}
}

void ButtonsLed::doBlinkInputs(bool value)
{
	blinkInputs = value;
	if(blinkInputs)
	{
		doChaseInputs(false);
		delayBlinkInputs = 0;
		for(uint8_t index = 0; index < 7; index++)
			lightOn(index);
	}
}

void ButtonsLed::doChaseInputs(bool value)
{
	chaseInputs = value;
	if(chaseInputs)
	{
		doBlinkInputs(false);
		delayChaseInputs = 0;
		lightOff(0);
		for(uint8_t index = 1; index < 7; index++)
			lightOff(index);
	}
}

void ButtonsLed::doBlinkOneLed(uint8_t led, bool value)
{
	if(value) {
		blinkOneLed = led;
		lightOn(led);
		delayBlinkOneLed = 0;
	} else {
		blinkOneLed = -1;
		lightOff(led);
	}
}
