#ifndef Column_h
#define Column_h

#include "Global.hpp"
#include "Tile.hpp"

class Column {

	private:
		Tile tiles[COLUMN_TILES];
		uint8_t number;


	public:
		void setNumber(uint8_t index);
		uint8_t getNumber();
		void clear();
		bool isFull();
		uint8_t getFreeRow();
		uint8_t addToken(Player player);
		Player getToken(uint8_t row);
		void setToken(Player player, uint8_t row);
};

#endif