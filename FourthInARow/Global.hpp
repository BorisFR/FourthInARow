#ifndef Global_h
#define Global_h

#include <Arduino.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyConfig.hpp"

#define COLUMN_TILES 6
#define BOARD_COLUMNS 7
#define NO_VALUE 255

#define VOLUME_MAX 100
#define VOLUME_MIN 0

enum Player : uint8_t
{
	noPlayer,
	player1,
	player2
};

enum InputAction : uint8_t
{
	actionNone,
	actionReset,
	actionColumn1,
	actionColumn2,
	actionColumn3,
	actionColumn4,
	actionColumn5,
	actionColumn6,
	actionColumn7,
	actionPlayer0,
	actionPlayer1,
	actionPlayer2,
	actionVolumeUp,
	actionVolumeDown,
	actionVolumeMuteOnOff,
};

enum HintStatus : uint8_t
{
	hintNothing,
	hintCanWin,
	hintCanLoose,
	hintSureToLoose,
};

#endif