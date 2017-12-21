#ifndef GAME_INPUT_9BUTTONS_HPP
#define GAME_INPUT_9BUTTONS_HPP

#include "Global.hpp"
#include "GameInput.hpp"
#include "OneSwitch.hpp"

class GI9buttons : public GameInput
{
	private:
		OneSwitch button[9];

	public:
	  void setup();
	  void loop();

};

#endif