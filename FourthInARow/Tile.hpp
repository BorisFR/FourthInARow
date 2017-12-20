#ifndef Tile_h
#define Tile_h

#include "Global.hpp"

class Tile {

	private:
		uint8_t column;
		uint8_t row;
		Player token;

	  public:
		uint8_t getColumn();
		uint8_t getRow();
		Player getToken();
		void setColumn(uint8_t index);
		void setRow(uint8_t value);
		void setToken(Player value);
};

#endif