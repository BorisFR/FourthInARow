#pragma once
#ifndef CASE_LOCATION_HPP
#define CASE_LOCATION_HPP

#include "Global.hpp"

class CaseLocation
{
	public:
	  	CaseLocation();
	  	CaseLocation(uint8_t x, uint8_t y);
		uint8_t index;
		uint8_t row;
};

struct LocationAlert
{
		  uint8_t row[BOARD_COLUMNS];
};

struct OneWinningPosition
{
	uint8_t possibilityIndex;
	CaseLocation location[4]; // 4 tokens to win
};

struct WinningPositions
{
	OneWinningPosition winning[4]; // one token permit 4 winning positions
};

#endif