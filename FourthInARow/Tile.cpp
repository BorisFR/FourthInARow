#include "Tile.hpp"

uint8_t Tile::getColumn()
{
	return column;
}

uint8_t Tile::getRow()
{
	return row;
}

Player Tile::getToken()
{
	return token;
}

void Tile::setColumn(uint8_t index)
{
	column = index;
}

void Tile::setRow(uint8_t value)
{
	row = value;
}

void Tile::setToken(Player value)
{
	token = value;
}
