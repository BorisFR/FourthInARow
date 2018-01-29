#include "CaseLocation.hpp"

CaseLocation::CaseLocation()
{
	index = NO_VALUE;
	row = NO_VALUE;
}

CaseLocation::CaseLocation(uint8_t x, uint8_t y)
{
	index = x;
	row = y;
}