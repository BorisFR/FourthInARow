#ifndef Global_h
#define Global_h

#include <Arduino.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MyConfig.hpp"

#define COLUMN_TILES 6
#define BOARD_COLUMNS 7

#define VOLUME_MAX 10
#define VOLUME_MIN 0

enum Player : uint8_t
{
	noPlayer,
	player1,
	player2
};

#endif