#pragma once
#ifndef BUTTONS_LED_HPP
#define BUTTONS_LED_HPP

#include "Global.hpp"
#include "GameInput.hpp"
#include "ElapsedMillis.hpp"

class ButtonsLed
{

	private:
		#if DEBUG
			void (*_debug)(String text);
		#endif
		void doRealInit();

		#if BUTTONS_LED
		uint8_t pinButtonsLed[9] = {BUTTON_LED_1, BUTTON_LED_2, BUTTON_LED_3, BUTTON_LED_4, BUTTON_LED_5, BUTTON_LED_6, BUTTON_LED_7,
									BUTTON_LED_PLAYER_1, BUTTON_LED_PLAYER_2};
		#endif
		bool ledOn[9];
		bool blinkPlayers;
		ElapsedMillis delayBlinkPlayers;
		bool blinkInputs;
		ElapsedMillis delayBlinkInputs;
		bool chaseInputs;
		ElapsedMillis delayChaseInputs;
		int8_t blinkOneLed;
		ElapsedMillis delayBlinkOneLed;

	public:
		#if DEBUG
			void doInit(void (*)(String));
		#else
			void doInit();
		#endif
		void loop();
		void invertLight(uint8_t index);
		void lightOn(uint8_t index);
		void lightOff(uint8_t index);
		bool isLightOn(uint8_t index);
		void allLightsOn();
		void allLightsOff();
		void doBlinkPlayers(bool value);
		void doBlinkInputs(bool value);
		void doChaseInputs(bool value);
		void doBlinkOneLed(uint8_t led, bool value);
	
};

#endif