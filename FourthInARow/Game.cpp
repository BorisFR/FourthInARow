#include "Game.hpp"

#if DEBUG
void Game::doInit(void (*debug)(String))
{
	_debug = debug;
	_debug("Init Game: ");
	doRealInit();
	_debug("OK\n");
};
#else
void Game::doInit()
{
	doRealInit();
};
#endif

void Game::doRealInit()
{
	calculateAllPossibilities();
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		board[column].setNumber(column);
	}
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

	int32_t val[BOARD_COLUMNS][COLUMN_TILES];
	for (int8_t row = COLUMN_TILES - 1; row >= 0; row--)
	{
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			val[column][row] = 0;
		}
	}
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			val[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]][winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]] += winPossibilities[index][TILE_VALUE];
		}
	}

	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		//_debug(String(index) + "= ");
		int32_t strength = getStrength(currentPlayer, winPossibilities[index][COLUMN], winPossibilities[index][ROW], winPossibilities[index][COLUMN_CHANGE], winPossibilities[index][ROW_CHANGE]) * winPossibilities[index][TILE_VALUE];
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			//_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]) + " ");
			val[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]][winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]] += strength;
		}
		//_debug("\n");
	}

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
					if (val[column][row] >= 0)
						_debug(" ");
					if (val[column][row] < 10)
						_debug(" ");
					if (val[column][row] < 100)
						_debug(" ");
					if (val[column][row] < 1000)
						_debug(" ");
					if (val[column][row] < 10000)
						_debug(" ");
					if (val[column][row] < 100000)
						_debug(" ");
					if (val[column][row] < 1000000)
						_debug(" ");
					_debug(String(val[column][row]));
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
	//_debug("Possibilities: " + String(index) + "\n");
	#endif

	#if DEBUG
	/*uint8_t val[BOARD_COLUMNS][COLUMN_TILES];
	for (int8_t row = COLUMN_TILES - 1; row >= 0; row--)
	{
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			val[column][row] = 0;
		}
	}
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		for (uint8_t pos = 0; pos < 4; pos++)
		{
			val[winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]][winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]] += winPossibilities[index][TILE_VALUE];
		}
	}
	_debug(F("\nBest places\n"));
	for (uint8_t row = 0; row < COLUMN_TILES; row++)
	{
		_debug("|");
		for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
		{
			uint8_t v = val[column][row];
			if (v < 10)
				_debug(" ");
			if (v < 100)
				_debug(" ");
			_debug(String(v));
			_debug("|");
		}
		_debug("\n");
	}*/
	#endif
}

void Game::startNewGame()
{
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		board[column].clear();
	}
	currentPlayer = noPlayer;
	theWinner = noPlayer;
	numberMoves = 0;
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
	if(row < COLUMN_TILES)
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

bool Game::isVerticalWin(uint8_t index)
{
	Column column = board[index];
	for (uint8_t line = 0; line <= (COLUMN_TILES - 4); line++)
	{
		Player token = column.getToken(line);
		if ((token != noPlayer) && (token == column.getToken(line + 1)) && (token == column.getToken(line + 2)) && (token == column.getToken(line + 3)))
		{
			winPosition[0].row = line;
			winPosition[1].row = line + 1;
			winPosition[2].row = line + 2;
			winPosition[3].row = line + 3;
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
			winPosition[0].row = line;
			winPosition[1].row = line;
			winPosition[2].row = line;
			winPosition[3].row = line;
			theWinner = token;
			return true;
		}
	}
	for (uint8_t line = 0; line <= (COLUMN_TILES - 4); line++)
	{
		Player token = board[column1].getToken(line);
		if ((token != noPlayer) && (token == board[column2].getToken(line + 1)) && (token == board[column3].getToken(line + 2)) && (token == board[column4].getToken(line + 3)))
		{
			winPosition[0].row = line;
			winPosition[1].row = line + 1;
			winPosition[2].row = line + 2;
			winPosition[3].row = line + 3;
			theWinner = token;
			return true;
		}
	}
	for (uint8_t line = 3; line < COLUMN_TILES; line++)
	{
		Player token = board[column1].getToken(line);
		if ((token != noPlayer) && (token == board[column2].getToken(line - 1)) && (token == board[column3].getToken(line - 2)) && (token == board[column4].getToken(line - 3)))
		{
			winPosition[0].row = line;
			winPosition[1].row = line - 1;
			winPosition[2].row = line - 2;
			winPosition[3].row = line - 3;
			theWinner = token;
			return true;
		}
	}
	return false;
}

bool Game::isSomeoneWinner()
{
	// check vertically
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		bool win = isVerticalWin(column);
		if (win)
		{
			winPosition[0].index = column;
			winPosition[1].index = column;
			winPosition[2].index = column;
			winPosition[3].index = column;
			return true;
		}
	}
	// check horizontally
	for (uint8_t column = 0; column <= (BOARD_COLUMNS - 4); column++)
	{
		bool win = isHorizontalWin(column, column + 1, column + 2, column + 3);
		if (win)
		{
			winPosition[0].index = column;
			winPosition[1].index = column + 1;
			winPosition[2].index = column + 2;
			winPosition[3].index = column + 3;
			return true;
		}
	}
	return false;
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
	// clean all
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		willWin[column] = false;
		willLoose[column] = false;
	}
	uint8_t canWinNexttime = 0;
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
		if(row < BOARD_COLUMNS)
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
					_debug(String(index) + " => " + String(column) + "/" + String(row) + " ******* END, we have a winner! => ");
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]) + " ");
					}
					_debug("\n");
				}
				// other player have already 4 tokens, we loose :()
				if (otherInLine == 4)
				{
					_debug(String(index) + " => " + String(column) + "/" + String(row) + " ******* END, we have a looser! => ");
					for (uint8_t pos = 0; pos < 4; pos++)
					{
						_debug(String(winPossibilities[index][COLUMN] + pos * winPossibilities[index][COLUMN_CHANGE]) + "/" + String(winPossibilities[index][ROW] + pos * winPossibilities[index][ROW_CHANGE]) + " ");
					}
					_debug("\n");
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
								canWinNexttime++;
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
							canLooseNextTime++;
						}
					}
					_debug("\n");
				}
			}
		}
	}
	hintsState = hintNothing;
	if (canWinNexttime > 0)
		hintsState = hintCanWin;
	if(canLooseNextTime == 1)
		hintsState = hintCanLoose;
	if (canLooseNextTime > 1)
		hintsState = hintSureToLoose;
}

HintStatus Game::getHints()
{
	return hintsState;
}

////////////////////////////////////////////////////////////////////////////////
// IA: simple Min/Max
////////////////////////////////////////////////////////////////////////////////

int32_t Game::getStrength(Player player, uint8_t column, uint8_t row, int8_t columnChange, int8_t rowChange)
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
	uint8_t meMaxLine = 0;
	uint8_t otherInLine = 0;
	uint8_t otherMaxLine = 0;
	for (uint8_t pos = 0; pos < 4; pos++)
	{
		Player possible = board[column + pos * columnChange].getToken(row + pos * rowChange);

		if (possible == player)
		{
			meInLine += 1;
			if (meInLine > meMaxLine)
				meMaxLine = meInLine;
		}
		else
		{
			meInLine = 0;
		}

		if (possible == otherPlayer)
		{
			otherInLine += 1;
			if (otherInLine > otherMaxLine)
				otherMaxLine = otherInLine;
		}
		else
		{
			otherInLine = 0;
		}
	}
	int32_t strength = 0;
	if (meMaxLine == 1)
		strength += 1;
	if (meMaxLine == 2)
		strength += 4;
	if (meMaxLine == 3)
		strength += (64 - (otherMaxLine * 16));
	if (meMaxLine == 4)
		strength = WIN_VALUE;

	if (otherMaxLine == 1)
		strength -= 1;
	if (otherMaxLine == 2)
		strength -= 4;
	if (otherMaxLine == 3)
		strength -= (64 - (meMaxLine * 16));
	if (otherMaxLine == 4)
		strength = -WIN_VALUE;

	//_debug("Strength: " + String(strength) + "\n");
	//dumpGame();
	return strength;
}

int32_t Game::getBoardValue(Player player)
{
	int32_t sum = 0;
	for (uint8_t index = 0; index < MAX_POSSIBILITIES; index++)
	{
		sum += getStrength(player, winPossibilities[index][COLUMN], winPossibilities[index][ROW], winPossibilities[index][COLUMN_CHANGE], winPossibilities[index][ROW_CHANGE]) * winPossibilities[index][TILE_VALUE];
	}
	//_debug("xx VALUE: " + String(sum) + "\n");
	return sum;
}

int32_t Game::getMinimalMove(Player player, uint8_t deepness, int32_t actualMaximal)
{
	if (deepness <= 0)
	{
		//_debug("-- MIN " + String(deepness) + " DEEPNESS END\n");
		return getBoardValue(player);
	}
	//_debug("-- MIN " + String(deepness) + " DEEPNESS: " + String(deepness) + "\n");
	//int32_t MinCol = 0;
	int32_t minimalValue = WIN_VALUE * 10;
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		//_debug("-- MIN " + String(deepness) + " TESTING COLUMN: " + String(column) + "\n");
		uint8_t row = board[column].getFreeRow();
		if (row < COLUMN_TILES)
		{
			//_debug("-- MIN " + String(deepness) + " TESTING ROW: " + String(row) + "\n");
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
			int32_t guessValue = getMaximalMove(player, deepness - 1, minimalValue);
			// undo move
			board[column].setToken(noPlayer, row);
			if (guessValue == -WIN_VALUE) {
				//_debug(F("-- MIN " + String(deepness) + " WE LOOSE IF PLAY HERE!\n"));
				return -WIN_VALUE;
			}
			if (guessValue < actualMaximal)
			{ // no need to go further, because the min will be less than the max already found
				//_debug("-- MIN " + String(deepness) + " NO NEED TO SEARCH DEEPER\n");
				//_debug(" q:" + String(column) + "/" + String(row) + " " + String(guessValue) + "<" + String(actualMaximal));
				//dumpGame();
				return guessValue;
			}
			if (guessValue < minimalValue)
			{ // less than
				//_debug("-- MIN " + String(deepness) + " FOUND BETTER VALUES\n");
				minimalValue = guessValue;
				//MinCol = column;
			}
		}
	}
	//debug( "Min -> minimalValue=" + minimalValue + ", MinCol=" + MinCol + "\n" );
	//_debug("---------------- MIN " + String(deepness) + " -> minimalValue=" + String(minimalValue) + ", MinCol=" + String(MinCol) + "\n");
	return minimalValue;
}

int32_t Game::getMaximalMove(Player player, uint8_t deepness, int32_t actualMinimal)
{

	if (deepness <= 0)
	{
		//_debug("** MAX " + String(deepness) + " DEEPNESS END\n");
		//dumpGame();
		int32_t res = getBoardValue(player);
		//_debug(String(res) + "\n");
		return res;
	}
	//_debug("** MAX " + String(deepness) + " DEEPNESS: " + String(deepness) + "\n");
	int32_t maximalValue = -WIN_VALUE * 10;
	for (uint8_t column = 0; column < BOARD_COLUMNS; column++)
	{
		//_debug("** MAX " + String(deepness) + " TESTING COLUMN: " + String(column) + "\n");
		uint8_t row = board[column].getFreeRow();
		if (row < COLUMN_TILES)
		{
			//_debug("** MAX " + String(deepness) + " TESTING ROW: " + String(row) + "\n");
			// play the tile
			board[column].setToken(player, row);
			int32_t guessValue = getMinimalMove(player, deepness - 1, maximalValue);
			// undo move
			board[column].setToken(noPlayer, row);
			if (guessValue == WIN_VALUE) {
				//_debug("** MAX " + String(deepness) + " WE WIN PLAYING HERE!\n");
				return WIN_VALUE; // game won
			}
			if (guessValue > actualMinimal)
			{
				//_debug("** MAX " + String(deepness) + " NO NEED TO SEARCH DEEPER\n");
				//_debug(" q:" + String(guessValue) + ">" + String(actualMinimal));
				return guessValue;
			}
			if (guessValue > maximalValue)
			{
				//_debug("** MAX " + String(deepness) + " FOUND BETTER VALUES\n");
				maximalValue = guessValue;
				bestColumnToPlay = column;
				for (uint8_t index = 0; index < BOARD_COLUMNS; index++)
				{
					playPossibilities[index] = 255;
				}
				playPossibilities[0] = column;
				//_debug(" *" + String(column) + "/" + String(row) + " " + String(column) + "=" + String(guessValue));
				//dumpGame();
			} else {
				if(guessValue == maximalValue) {
					//_debug(" =" + String(column) + "=" + String(guessValue));
					uint8_t index = 0;
					while (playPossibilities[index] == 255)
						index++;
					playPossibilities[index] = column;
				} else {
					//_debug(" <" + String(column) + "=" + String(guessValue));
				}
			}
		}
	}
	//debug( "Max -> maximalValue=" + maximalValue + ", MaxCol=" + MaxCol + "\n" );
	//_debug(">>>>>>>>>>>>>>>> MAX " + String(deepness) + " -> maximalValue=" + String(maximalValue) + ", MaxCol=" + String(MaxCol) + "\n");
	return maximalValue;
}

uint8_t Game::getIndexPlayingForPlayerIA(Player player)
{
	if (numberMoves == 0)
	{
		bestColumnToPlay = 3;
		return bestColumnToPlay;
	}
	bestColumnToPlay = 255;
	/*
	Difficulty = document.formo.difficulty.value;
	switch (Difficulty)
	{
	case "Too Easy":
		Levels = 2;
		StartStupid = 2;
		StupidProb = 0.9;
		break;

	case "Easy":
		Levels = 2;
		StartStupid = 4;
		StupidProb = 0.7;
		break;

	case "Medium":
		Levels = 2;
		StartStupid = 10;
		StupidProb = 0.2;
		break;

	case "Hard":
		Levels = 2;
		StartStupid = 1000;
		StupidProb = 0.0;
		break;

	case "Impossible":
		Levels = 4;
		StartStupid = 1000;
		StupidProb = 0.0;
		break;

	default:
		Levels = 2;
		StartStupid = 6;
		StupidProb = 0.7;
	}
	//debug("Levels=" + Levels + "," + StupidProb + "," + Difficulty );
*/
	// MaxMove(player, Levels, Number.MAX_VALUE, "Col");
	int8_t dummy = getMaximalMove(player, 2, WIN_VALUE * 10);

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
	while (playPossibilities[index] == 255)
	{
		_debug("Possible to play: " + String(playPossibilities[index]) + "\n");
		index++;
	}
	/*if((rand() % 10) > 5) 
					{
						maximalValue = guessValue;
						MaxCol = column;
					}*/

	return bestColumnToPlay;
}