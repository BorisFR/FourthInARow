#include "Column.hpp"

void Column::setNumber(uint8_t index)
{
	number = index;
	for(uint8_t row = 0; row < COLUMN_TILES; row++) {
		tiles[row].setColumn(number);
		tiles[row].setRow(row);
		tiles[row].setToken(noPlayer);
	}
}

uint8_t Column::getNumber()
{
	return number;
}

void Column::clear()
{
	for(uint8_t row = 0; row < COLUMN_TILES; row++) {
		tiles[row].setToken(noPlayer);
	}

}

bool Column::isFull()
{
	if (tiles[COLUMN_TILES - 1].getToken() != noPlayer)
	{
		return true;
	}
	return false;
}

uint8_t Column::getFreeRow()
{
	if (isFull())
	{
		return 255;
	}
	for (uint8_t row = 0; row < COLUMN_TILES; row++)
	{
		if (tiles[row].getToken() == noPlayer)
		{
			return row;
		}
	}
	return 255;
}

uint8_t Column::addToken(Player player)
{
	if(isFull()) {
		return NO_VALUE;
	}
	for(uint8_t row = 0; row < COLUMN_TILES; row++) {
		if(tiles[row].getToken() == noPlayer) {
			tiles[row].setToken(player);
			return row;
		}
	}
	return NO_VALUE;
}

Player Column::getToken(uint8_t row)
{
	return tiles[row].getToken();
}

void Column::setToken(Player player, uint8_t row)
{
	tiles[row].setToken(player);
}