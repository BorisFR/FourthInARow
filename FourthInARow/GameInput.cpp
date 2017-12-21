#include "GameInput.hpp"

#if DEBUG
void GameInput::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug("Init dummy GameInput: ");
	doRealInit();
	_debug("OK\n");
};
#else
void GameInput::doInit()
{
	doRealInit();
};
#endif

void GameInput::doRealInit()
{
	input = actionNone;
}

void GameInput::setup(){}
void GameInput::loop(){}
void GameInput::startLoop(){}
void GameInput::endLoop(){}

bool GameInput::hasInput()
{
	if (input == actionNone)
	{
		return false;
	}
	return true;
}

InputAction GameInput::getAction()
{
	InputAction temp = input;
	input = actionNone;
	return temp;
}
