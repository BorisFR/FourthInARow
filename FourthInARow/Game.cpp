#include "Game.hpp"

#if DEBUG
void Game::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug("Init Game: ");
	doRealInit();
	_debug("OK\n");
};
void Game::tab(uint8_t space)
{
	for(uint8_t index = 6; index > space; index--)
		_debug(".");
}
#else
‡void Game::doInit()
{
	doRealInit();
};
#endif

void Game::doRealInit()
{
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		board[column].setNumber(column);
	}
	calculateAllPossibilities();
}

#if DEBUG
void Game::traceLine()
{
	_debug("+");
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		_debug("--------+");
	}
	_debug("\n");
}

void Game::dumpGame()
{
	Player other = player1;
	if(currentPlayer == player1)
		other = player2;
	traceLine();
	for (int8_t row = (COLUMN_TILES - 1); row >= 0; row--)
	{
		_debug("|");
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			switch (board[column].getToken(row))
			{
			case noPlayer:
				if ((board[column].getFreeRow() == row) && (willWin[column] || willLoose[column]))
				{
					if (willWin[column] && willLoose[column])
					{
						_debug("* WWLL *");
					} 
					else 
					{
						if (willWin[column])
							_debug("*  WW  *");
						if (willLoose[column])
							_debug("*  LL  *");
					}
				}
				else
				{
					int32_t value = getTileValue(currentPlayer, other, column, row);
					if (value >= 0)
						_debug(" ");
					if (value < 10)
						_debug(" ");
					if (value < 100)
						_debug(" ");
					if (value < 1000)
						_debug(" ");
					if (value < 10000)
						_debug(" ");
					if (value < 100000)
						_debug(" ");
					if (value < 1000000)
						_debug(" ");
					_debug(String(value));
				}
				break;
			case player1:
				_debug("  XXXX  ");
				break;
			case player2:
				_debug("  OOOO  ");
				break;
			}
			_debug("|");
		}
		_debug("\n");
		traceLine();
	}
}
#endif

bool Game::inbounds(int8_t row, int8_t column)
{
	return ((row >= 0) && (column >= 0) && (row < COLUMN_TILES) && (column < BOARD_COLUMNS));
}

void Game::calculateAllPossibilities()
{
	#if DEBUG
	/*_debug(F("\nTile's number\n"));
	for (int8_t row = COLUMN_TILES - 1; row >= 0; row--)
	{
		_debug("|");
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			uint8_t v = column * 10 + row;
			if (v < 10)
				_debug(" ");
			_debug(String(v));
			_debug("|");
		}
		_debug("\n");
	}*/
	#endif

	uint8_t index = 0;
	for (uint8_t row = 0; row < COLUMN_TILES; row++)
	{
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			for (int8_t rowChange = -1; rowChange <= 1; rowChange++)
			{
				for (int8_t columnChange = -1; columnChange <= 1; columnChange++)
				{
					//_debug(".");
					if (
						(
							((rowChange == 1) && (columnChange == 0)) || ((rowChange == 1) && (columnChange == 1)) || ((rowChange == 0) && (columnChange == 1)) || ((rowChange == -1) && (columnChange == 1))) &&
						(inbounds(row + rowChange, column + columnChange) && inbounds(row + (2 * rowChange), column + (2 * columnChange)) && inbounds(row + (3 * rowChange), column + (3 * columnChange))))
					{
						winPossibilities[index][COLUMN] = column;
						winPossibilities[index][ROW] = row;
						winPossibilities[index][COLUMN_CHANGE] = columnChange;
						winPossibilities[index][ROW_CHANGE] = rowChange;
						/*if (row == (COLUMN_TILES-1) && rowChange == 0 && columnChange == 1)
						{
							// on privilégie les diagonales
							winPossibilities[index][TILE_VALUE] = 2;
						}
						else
						{
							winPossibilities[index][TILE_VALUE] = 1;
						}*/
						winPossibilities[index][TILE_VALUE] = 1;
						index += 1;
					}
				}
			}
		}
	}
	#if DEBUG
	//_debug("Win Possibilities: " + String(index) + "\n");
	#endif

	#if DEBUG
	for (int8_t row = COLUMN_TILES - 1; row >= 0; row--)
	{
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			tileInterest[column][row] = 0;
		}
	}
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			tileInterest[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]][winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]] += winPossibilities[index][TILE_VALUE];
		}
	}
	_debug(F("\nBest places\n"));
	for (uint8_t row = 0; row < COLUMN_TILES; row++)
	{
		_debug("|");
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			uint8_t v = tileInterest[column][row];
			if (v < 10)
				_debug(" ");
			if (v < 100)
				_debug(" ");
			_debug(String(v));
			_debug("|");
		}
		_debug("\n");
	}
	#endif
}

Board Game::getBoard()
{
	Board result;
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		result.column[column] = board[column];
	}
	return result;
}

void Game::clearWinningCases()
{
	countWinningCases = 0;
	for (uint8_t index = 0; index < 4; index++)
	{
		winningCases.winning[index].possibilityIndex = NO_VALUE;
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			winningCases.winning[index].location[pos] = CaseLocation();
		}
	}
}

void Game::clearTurn()
{
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		willWin[column] = false;
		willLoose[column] = false;
		winAlert.row[column] = NO_VALUE;
		looseAlert.row[column] = NO_VALUE;
	}
	clearWinningCases();
}

void Game::startNewGame()
{
	currentPlayer = noPlayer;
	theWinner = noPlayer;
	numberMoves = 0;
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		board[column].clear();
	}
	clearTurn();
}

void Game::setCurrentPlayer(Player player)
{
	currentPlayer = player;
}

Player Game::getCurrentPlayer()
{
	return currentPlayer;
}

void Game::nextPlayer()
{
	if (currentPlayer == player1)
	{
		currentPlayer = player2;
		return;
	}
	currentPlayer = player1;
}

uint8_t Game::getRowPlayingColumn(uint8_t index)
{
	uint8_t row = board[index].addToken(currentPlayer);
	if (row != NO_VALUE)
		numberMoves++;
	return row;
}

bool Game::isPlayingPossible()
{
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		if (!board[column].isFull())
		{
			return true;
		}
	}
	return false;
}

void Game::addWinningCase(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4, uint8_t r1, uint8_t r2, uint8_t r3, uint8_t r4)
{
	winningCases.winning[countWinningCases].possibilityIndex = 0;
	winningCases.winning[countWinningCases].location[0] = CaseLocation(c1, r1);
	winningCases.winning[countWinningCases].location[1] = CaseLocation(c2, r2);
	winningCases.winning[countWinningCases].location[2] = CaseLocation(c3, r3);
	winningCases.winning[countWinningCases].location[3] = CaseLocation(c4, r4);
	countWinningCases++;
}

bool Game::isVerticalWin(uint8_t index)
{
	Column column = board[index];
	for (uint8_t line = 0; line <= (COLUMN_TILES - 4); line++)
	{
		Player token = column.getToken(line);
		if ((token != noPlayer) && (token == column.getToken(line + 1)) && (token == column.getToken(line + 2)) && (token == column.getToken(line + 3)))
		{
			addWinningCase(index, index, index, index, line, line + 1, line + 2, line + 3);
			theWinner = token;
			return true;
		}
	}
	return false;
}

bool Game::isHorizontalWin(uint8_t column1, uint8_t column2, uint8_t column3, uint8_t column4)
{
	for (uint8_t line = 0; line < COLUMN_TILES; line++)
	{
		Player token = board[column1].getToken(line);
		if ((token != noPlayer) && (token == board[column2].getToken(line)) && (token == board[column3].getToken(line)) && (token == board[column4].getToken(line)))
		{
			addWinningCase(column1, column2, column3, column4, line, line, line, line);
			theWinner = token;
			return true;
		}
	}
	for (uint8_t line = 0; line <= (COLUMN_TILES - 4); line++)
	{
		Player token = board[column1].getToken(line);
		if ((token != noPlayer) && (token == board[column2].getToken(line + 1)) && (token == board[column3].getToken(line + 2)) && (token == board[column4].getToken(line + 3)))
		{
			addWinningCase(column1, column2, column3, column4, line, line + 1, line + 2, line + 3);
			theWinner = token;
			return true;
		}
	}
	for (uint8_t line = 3; line < COLUMN_TILES; line++)
	{
		Player token = board[column1].getToken(line);
		if ((token != noPlayer) && (token == board[column2].getToken(line - 1)) && (token == board[column3].getToken(line - 2)) && (token == board[column4].getToken(line - 3)))
		{
			addWinningCase(column1, column2, column3, column4, line, line - 1, line - 2, line - 3);
			theWinner = token;
			return true;
		}
	}
	return false;
}

bool Game::isSomeoneWinner()
{
	clearWinningCases();
	bool oneWin = false;
	// check vertically
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		bool win = isVerticalWin(column);
		if (win)
			oneWin = true;
	}
	// check horizontally
	for (uint8_t column = 0; column <= (BOARD_COLUMNS - 4); column++)
	{
		bool win = isHorizontalWin(column, column + 1, column + 2, column + 3);
		if (win)
			oneWin = true;
	}
	return oneWin;
}

Player Game::getWhoWin()
{
	return theWinner;
}


////////////////////////////////////////////////////////////////////////////////
// to help the player
////////////////////////////////////////////////////////////////////////////////

void Game::calculateHints()
{
	clearTurn();
	uint8_t canWinNextTime = 0;
	uint8_t canLooseNextTime = 0;
	// check who is playing
	Player otherPlayer;
	if(currentPlayer == player1)
		otherPlayer = player2;
	else
		otherPlayer = player1;
	
	// for each column, check the state
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		uint8_t row = board[column].getFreeRow();
		// if we can play on this column
		if (row != NO_VALUE)
		{
			// check all possibilities
			for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
			{
				uint8_t meInLine = 0;
				uint8_t otherInLine = 0;
				// for each possibility, we have 4 tokens
				for (uint8_t pos = 0; pos < 4; pos++)
				{
					Player possible = board[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]].getToken(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]);
					if (possible == currentPlayer) {
						meInLine++;
						otherInLine = 100;
					}
					if (possible == otherPlayer)
					{
						otherInLine++;
						meInLine = 100;
					}
					if(possible == noPlayer) {
						if ((row != (winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE])) || (column != (winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE])))
						{
							otherInLine = 100;
							meInLine = 100;
						}
					}
				}
				// already have 4 tokens, we win :)
				if (meInLine == 4)
				{
					bool found = false;
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						if (winningCases.winning[pos].possibilityIndex == index)
							found = true;
					}
					if(!found) {
						winningCases.winning[countWinningCases].possibilityIndex = index;
						_debug(String(index) + " => " + String(column) + "/" + String(row) + " ******* END, we have a winner! => ");
						for (uint8_t pos = 0; pos < 4; pos++)
						{
							winningCases.winning[countWinningCases].location[pos] = CaseLocation(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE], winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]);
							_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]) + " ");
						}
						_debug("\n");
						countWinningCases++;
					}
				}
				// other player have already 4 tokens, we loose :()
				if (otherInLine == 4)
				{
					bool found = false;
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						if (winningCases.winning[pos].possibilityIndex == index)
							found = true;
					}
					if (!found)
					{
						winningCases.winning[countWinningCases].possibilityIndex = index;
						_debug(String(index) + " => " + String(column) + "/" + String(row) + " ******* END, we have a looser! => ");
						for (uint8_t pos = 0; pos < 4; pos++)
						{
							winningCases.winning[countWinningCases].location[pos] = CaseLocation(column, row);
							_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]) + " ");
						}
						_debug("\n");
						countWinningCases++;
					}
				}
				// we have 3 tokens!
				if (meInLine == 3)
				{
					_debug(String(index) + " => " + String(column) + "/" + String(row) + " = WIN: ");
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						uint8_t rowTotest = winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE];
						_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(rowTotest) + " ");
						Player possible = board[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]].getToken(rowTotest);
						if (possible == player1)
							_debug("=>P1 ");
						if (possible == player2)
							_debug("=>P2 ");
						if (possible == noPlayer)
							_debug("=>?? ");
						// we can win by playing here!
						if (possible == noPlayer)
						{
							willWin[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]] = true;
							if (rowTotest == row)
							{
								winAlert.row[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]] = row;
								canWinNextTime++;
							}
						}
					}
					_debug("\n");
				}
				// other player have already 3 tokens!
				if (otherInLine == 3)
				{
					_debug(String(index) + " = LOOSE: ");
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						uint8_t rowTotest = winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE];
						_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(rowTotest) + " ");
						Player possible = board[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]].getToken(rowTotest);
						if (possible == player1)
							_debug("=>P1 ");
						if (possible == player2)
							_debug("=>P2 ");
						if (possible == noPlayer)
							_debug("=>?? ");
						// he can win by playing here!
						if (possible == noPlayer)
						{
							willLoose[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]] = true;
							looseAlert.row[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]] = row;
							canLooseNextTime++;
						}
					}
					_debug("\n");
				}
			}
		}
	}
	hintsState = hintNothing;
	if (canWinNextTime > 0)
		hintsState = hintCanWin;
	if(canLooseNextTime == 1)
		hintsState = hintCanLoose;
	if (canLooseNextTime > 1)
		hintsState = hintSureToLoose;
}

WinningPositions Game::getWinningCases()
{
	return winningCases;
}

HintStatus Game::getHints()
{
	return hintsState;
}

LocationAlert Game::getWinHints()
{
	return winAlert;
}

LocationAlert Game::getLooseHints()
{
	return looseAlert;
}

////////////////////////////////////////////////////////////////////////////////
// IA: simple Min/Max
////////////////////////////////////////////////////////////////////////////////

/*int32_t Game::getStrength(Player player, uint8_t column, uint8_t row, int8_t columnChange, int8_t rowChange)
{
	Player otherPlayer;
	if (player == player1)
	{
		otherPlayer = player2;
	}
	else
	{
		otherPlayer = player1;
	}
	uint8_t meInLine = 0;
	uint8_t otherInLine = 0;
	for (uint8_t pos = 0; pos < 4; pos++)
	{
		Player possible = board[column + pos * columnChange].getToken(row + pos * rowChange);

		if (possible == player)
		{
			meInLine += 1;
		}
		if (possible == otherPlayer)
		{
			otherInLine += 1;
		}
	}
	int32_t strength = 0;
	if (meInLine == 1)
		strength += 1;
	if (meInLine == 2)
		strength += 2;
	if (meInLine == 3)
		strength += 8; //(64 - (otherMaxLine * 16));
	if (meInLine == 4)
		return WIN_VALUE;

	if (otherInLine == 1)
		strength -= 10;
	if (otherInLine == 2)
		strength -= 12;
	if (otherInLine == 3)
		strength -= 22; // (64 - (meMaxLine * 16));
	if (otherInLine == 4)
		return -WIN_VALUE;
	strength += (4 - meInLine - otherInLine) * 4;
	return strength;
}

int32_t Game::getBoardValue(Player player)
{
	int32_t sum = 0;
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		sum += getStrength(player, winPossibilities[index][COLUMN], winPossibilities[index][ROW], winPossibilities[index][COLUMN_CHANGE], winPossibilities[index][ROW_CHANGE]) * winPossibilities[index][TILE_VALUE];
	}
	return sum;
}*/

int32_t Game::computeValue(int32_t me, int32_t other)
{
	int32_t value = 0;
	if (me == 4)
		value += 1000;
	if (me == 3)
	{
		if (other == 0)
			value += 150;
	}
	if (me == 2)
	{
		if (other == 0)
			value += 70;
	}
	if (me == 1)
	{
		if (other == 0)
			value += 30;
	}
	if (other == 4)
		value += 1000;
	if (other == 3)
	{
		if (me == 0)
			value += 110;
	}
	if (other == 2)
	{
		if (me == 0)
			value += 60;
	}
	if (other == 1)
	{
		if (me == 0)
			value += 20;
	}
	return value;
}

int32_t Game::getTileValue(Player player, Player other, uint8_t column, uint8_t row)
{
	int32_t strength = tileInterest[column][row];
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		bool found = false;
		uint8_t meInLine = 0;
		uint8_t otherInLine = 0;
		// for each possibility, we have 4 tokens
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			uint8_t c = winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE];
			uint8_t r = winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE];
			if(column == c && row == r)
				found = true;
			Player possible = board[c].getToken(r);
			if (possible == player)
				meInLine++;
			if (possible == other)
				otherInLine++;
			if (possible == noPlayer)
				strength += winPossibilities[index][TILE_VALUE];
		}
		if(found)
			strength += 2 * computeValue(meInLine, otherInLine);
		else
			strength += computeValue(meInLine, otherInLine);
	}
	return strength;
}

int32_t Game::getBoardValue(Player player)
{
	uint8_t canWinNextTime = 0;
	uint8_t canLooseNextTime = 0;
	int32_t strength = 0;
	Player other = player1;
	if (player == player1)
		other= player2;
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		uint8_t meInLine = 0;
		uint8_t otherInLine = 0;
		// for each possibility, we have 4 tokens
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			Player possible = board[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]].getToken(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]);
			if (possible == player)
				meInLine++;
			if (possible == other)
				otherInLine++;
			if (possible == noPlayer)
				strength += winPossibilities[index][TILE_VALUE];
		}
		strength += computeValue(meInLine, otherInLine);
	}
	return strength;
}

int32_t Game::getMinimalMove(Player player, uint8_t deepness, int32_t alpha)
{
	if (deepness <= 0)
	{
		int32_t res = getBoardValue(player);
		//_debug("=" + String(res) + "\n");
		return res;
	}
	int32_t beta = WIN_VALUE * 10; //maxi;
	_debug("\n");
	//tab(deepness);
	//_debug("-- MIN " + String(deepness) + " DEEPNESS: " + String(deepness) + " ALPHA: " + String(alpha) + "\n");
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		uint8_t row = board[column].getFreeRow();
		if (row != NO_VALUE)
		{
			tab(deepness);
			_debug(String(column) + "/" + String(row));
			// play the tile with OPPOSITE currentPlayer
			if (player == player1)
			{
				board[column].setToken(player2, row);
			}
			else
			{
				board[column].setToken(player1, row);
			}
			// calculate the resulting board value
			int32_t guessValue = getMaximalMove(player, deepness - 1, beta);
			_debug("=" + String(guessValue));
			// undo move
			board[column].setToken(noPlayer, row);
			if (guessValue == -WIN_VALUE) {
				_debug(" WE LOOSE IF PLAY HERE!\n");
				return -WIN_VALUE;
			}
			if (guessValue < beta)
			{ // less than
				_debug("***");
				beta = guessValue;
				//MinCol = column;
			}
			if (beta < alpha)
			{
				_debug("exit\n");
				return guessValue;
			}
			_debug("\n");
		}
	}
	return beta;
}

int32_t Game::getMaximalMove(Player player, uint8_t deepness, int32_t beta)
{
	if (deepness <= 0)
	{
		int32_t res = getBoardValue(player);
		//_debug("=" + String(res) + "\n");
		return -res;
	}
	int32_t alpha = -WIN_VALUE * 10;
	_debug("\n");
	//tab(deepness);
	//_debug("** MAX " + String(deepness) + " DEEPNESS: " + String(deepness) + " BETA: " + String(beta) + "\n");
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		uint8_t row = board[column].getFreeRow();
		if (row != NO_VALUE)
		{
			if (bestColumnToPlay == NO_VALUE)
				bestColumnToPlay = column;
			tab(deepness);
			_debug(String(column) + "/" + String(row));
			// play the tile
			board[column].setToken(player, row);
			int32_t guessValue = getMinimalMove(player, deepness - 1, alpha);
			_debug("=" + String(guessValue));
			// undo move
			board[column].setToken(noPlayer, row);
			if (guessValue == WIN_VALUE) {
				_debug(" WE WIN PLAYING HERE!\n");
				return WIN_VALUE; // game won
			}
			if (guessValue > alpha)
			{
				_debug("****");
				alpha = guessValue;
				bestColumnToPlay = column;
				for (uint8_t index = 1; index < BOARD_COLUMNS; index++)
				{
					playPossibilities[index] = NO_VALUE;
				}
				playPossibilities[0] = column;
				//_debug(" ***" + String(column) + "/" + String(row) + " " + String(column) + "=" + String(guessValue) + "\n");
				//dumpGame();
			} else {
				if(guessValue == alpha) {
					//_debug(" ===" + String(column) + "=" + String(guessValue) + "\n");
					uint8_t index = 0;
					while (playPossibilities[index] == NO_VALUE)
						index++;
					playPossibilities[index] = column;
				} else {
					//_debug(" <" + String(column) + "=" + String(guessValue));
				}
			}
			if(beta < alpha)
			{
				_debug("exit\n");
				return guessValue;
			}
			_debug("\n");
		}
	}
	return alpha;
}

uint8_t Game::getIndexPlayingForPlayerIA(Player player)
{
	if (numberMoves == 0)
	{
		bestColumnToPlay = 3;
		return bestColumnToPlay;
	}
	bestColumnToPlay = NO_VALUE;
	uint8_t deepThinking = 2; //6;
	// on devient idiot à partir du tour n°#
	uint8_t turnToStartBeingStupid = 50;// 10; max 42 tours
	// avec une probability d'être mauvais de #%
	uint8_t probabilityToBeStupid = 70;
	/*
	case "Too Easy":
		deepThinking = 2;
		turnToStartBeingStupid = 2;
		probabilityToBeStupid = 90;
	case "Easy":
		deepThinking = 2;
		turnToStartBeingStupid = 4;
		probabilityToBeStupid = 70;
	default:
		deepThinking = 2;
		turnToStartBeingStupid = 6;
		probabilityToBeStupid = 70;
	case "Medium":
		deepThinking = 2;
		turnToStartBeingStupid = 10;
		probabilityToBeStupid = 20;
	case "Hard":
		deepThinking = 2;
		turnToStartBeingStupid = 43;
		probabilityToBeStupid = 0;
	case "Impossible":
		deepThinking = 4;
		turnToStartBeingStupid = 43;
		probabilityToBeStupid = 0;
*/
	// MaxMove(player, Levels, Number.MAX_VALUE, "Col");
	// on calcule le meilleur coup
	int8_t dummy = getMaximalMove(player, deepThinking, WIN_VALUE * 10);

	// est-on stupide ?
	if (numberMoves >= turnToStartBeingStupid)
	{
		// bingo ?
		if (random(100) < probabilityToBeStupid)
		{
			// on regarde ce qu'il est possible de jouer en dehors du meilleur coup
			uint8_t which[BOARD_COLUMNS];
			uint8_t countWhich = 0;
			for(uint8_t column = 0; column < BOARD_COLUMNS; column++)
			{
				if (!board[column].isFull() && bestColumnToPlay != column)
				{
					which[countWhich] = column;
					countWhich++;
				}
			}
			// et on le joue
			if (countWhich > 0)
			{
#if DEBUG
				_debug(">>>>> Must play: " + String(bestColumnToPlay) + ", but play: ");
#endif
				bestColumnToPlay = which[random(countWhich)];
#if DEBUG
				_debug(String(bestColumnToPlay) + "\n");
#endif
			}
		}
	}
	// make it easier by randomly being stupid
	/*	moves += 1;
	if (moves > StartStupid)
	{
		if (Math.random() < StupidProb)
		{
			TryCol = Math.floor(Math.random() * COLS);
			//debug("TryCol=" + TryCol + ",");
			if (colcount[TryCol] < ROWS)
			{
				BestCol = TryCol;
			}
		}
	}
*/
	uint8_t index = 0;
	while (playPossibilities[index] == NO_VALUE)
	{
		_debug("Possible to play: " + String(playPossibilities[index]) + "\n");
		index++;
	}
	return bestColumnToPlay;
}