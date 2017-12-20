#include "Global.h"

#if ESP32
//#include <HardwareSerial.h>
//HardwareSerial Serial1(2);
#endif

#if TEENSY35
#endif

uint8_t playLine;
uint8_t playColumn;
bool winner;
bool player1IsIA;
bool player2IsIA;

////////////////////////////////////////////////////////////////////////////////
// HELPER
////////////////////////////////////////////////////////////////////////////////

#if DEBUG

void debug(String text)
{
	Serial.print(text);
	//Serial.print(text);
}

// only call one time, starting the program
void doInitHelper()
{
	Serial.begin(115200);
	debug(F("Init helper\n"));
}

#endif

////////////////////////////////////////////////////////////////////////////////
// GAME
////////////////////////////////////////////////////////////////////////////////

// INPUT
// *****

#if GAME_INPUT_DUMMY
#include "GameInput.h"
GameInput gameInput;
#endif
#if GAME_INPUT_SERIAL
#include "GIserial.h"
GIserial gameInput;
#endif

// OUTPUT
// ******

#if GAME_OUTPUT_DUMMY
#include "GameOutput.h"
GameOutput gameOutput;
#endif
#if GAME_OUTPUT_SERIAL
#include "GOserial.h"
GOserial gameOutput;
#endif
#if GAME_OUTPUT_FEATHER_OLED
#include "GOFeatherOled.h"
GOFeatherOled gameOutput;
#endif

// AUDIO
// *****
#if GAME_INPUT_AUDIO_DUMMY
#include "GameInputAudio.h"
GameInputAudio gameInputAudio;
#endif
#if GAME_OUTPUT_AUDIO_DUMMY
#include "GameOutputAudio.h"
GameOutputAudio gameOutputAudio;
#endif

#include "Game.h"
Game game;

// only call one time, starting the program
void doInitGame()
{
	game.gameState = waitingTouch;
#if DEBUG
	gameInput.doInit(debug);
	gameOutput.doInit(debug);
	gameInputAudio.doInit(debug);
	gameOutputAudio.doInit(debug);
	game.doInit(debug);
#else
	gameInput.doInit();
	gameOutput.doInit();
	gameInputAudio.doInit();
	gameOutputAudio.doInit();
	game.doInit();
#endif
	gameOutput.setup();
	gameOutput.drawGrid();
	gameInputAudio.setup();
	gameOutputAudio.setup();
}

// set gamestate at who is playing now
void gameTurn()
{
	if(!game.isPlayingPossible()) {
		game.gameState = matchDraw;
		return;
	}
	switch (game.getCurrentPlayer())
	{
	case player1:
		game.gameState = playingPlayer1;
		gameOutput.showPlayer1Turn();
		break;
	case player2:
		game.gameState = playingPlayer2;
		gameOutput.showPlayer2Turn();
		break;
	}
}


////////////////////////////////////////////////////////////////////////////////
// Program starting...
////////////////////////////////////////////////////////////////////////////////

void setup()
{
#if DEBUG
	doInitHelper();
#endif
	doInitGame();
	gameOutput.showTouchSomething();
}

////////////////////////////////////////////////////////////////////////////////
// BOUCLE SANS FIN
////////////////////////////////////////////////////////////////////////////////

void loop()
{
	// get the player's input
	// **********************
	gameInput.loop();
	gameInputAudio.loop();
	gameOutputAudio.loop();

	// start the game output
	// *********************
	gameOutput.startLoop();

	// actions are possible against gamestate
	// **************************************
	switch (game.gameState)
	{
		// not playing, just waiting for someone touching something...
		// ***********************************************************
	case waitingTouch:
		if (gameInput.hasInput())
		{
			game.gameState = choosingPlayersNumber;
			gameOutput.clearTiles();
			gameOutput.showChoosePlayersNumber();
		}
		break;

		// waiting to know if here is 1 or 2 players
		// *****************************************
	case choosingPlayersNumber:
		if (gameInput.hasInput())
		{
			switch (gameInput.getKey())
			{
			case '0':
				player1IsIA = true;
				player2IsIA = true;
				game.gameState = startingNewGame;
				gameOutput.showIaVsIa();
				break;
			case '1':
				player1IsIA = false;
				player2IsIA = true;
				game.gameState = startingNewGame;
				gameOutput.showPlayerVsIa();
				break;
			case '2':
				player1IsIA = false;
				player2IsIA = false;
				game.gameState = startingNewGame;
				gameOutput.showPlayerVsPlayer();
				break;
			}
		}
		break;

		// we are starting a new game session
		// **********************************
	case startingNewGame:
		game.startNewGame();
		game.gameState = choosingWhoStart;
#if DEBUG
		debug(F("new game\n"));
		game.dumpGame();
#endif
		gameOutput.showDecideWhoStart();
		break;

		// determining which player is starting the game
		//**********************************************
	case choosingWhoStart:
	// TODO: randomize!
#if DEBUG
		debug(F("Player 1 is starting\n"));
#endif
		game.setCurrentPlayer(player1);
		gameTurn();
		break;

		// Player 1 must choose where he put his token
		// ******************************************
	case playingPlayer1:
		game.gameState = choosingColumn;
		break;

		// Player 2 must choose where he put his token
		// ******************************************
	case playingPlayer2:
		game.gameState = choosingColumn;
		break;

		// Waiting for the current player to choose a column for his token
		// ***************************************************************
	case choosingColumn:
		if (game.getCurrentPlayer() == player1 && player1IsIA)
		{
			playColumn = game.getIndexPlayingForPlayerIA(player1);
#if DEBUG
			debug(F("(IA)"));
#endif
			game.gameState = puttingToken;
		}
		if (game.getCurrentPlayer() == player2 && player2IsIA)
		{
			playColumn = game.getIndexPlayingForPlayerIA(player2);
#if DEBUG
			debug(F("(IA)"));
#endif
			game.gameState = puttingToken;
		}
		if (gameInput.hasInput())
		{
			switch (gameInput.getKey())
			{
			case '1':
				playColumn = 0;
				game.gameState = puttingToken;
				break;
			case '2':
				playColumn = 1;
				game.gameState = puttingToken;
				break;
			case '3':
				playColumn = 2;
				game.gameState = puttingToken;
				break;
			case '4':
				playColumn = 3;
				game.gameState = puttingToken;
				break;
			case '5':
				playColumn = 4;
				game.gameState = puttingToken;
				break;
			case '6':
				playColumn = 5;
				game.gameState = puttingToken;
				break;
			case '7':
				playColumn = 6;
				game.gameState = puttingToken;
				break;
			}
		}
		break;

		// A player has choosen a column for his token
		// *******************************************
	case puttingToken:
		playLine = game.getRowPlayingColumn(playColumn);
		if (playLine == 255)
		{
			game.gameState = badColumn;
#if DEBUG
			debug(String(playColumn).c_str());
			debug(F("=bad column\n"));
#endif
		}
		else
		{
#if DEBUG
			debug(String(playColumn).c_str());
			debug(F("\n"));
#endif
			game.gameState = tokenAnimation;
			CaseLocation location;
			location.index = playColumn;
			location.row = playLine;
			gameOutput.setTiles(location, game.getCurrentPlayer());
		}
		game.calculateHints();
#if DEBUG
		game.dumpGame();
#endif
		break;

		// It is not a valid column
		// ************************
	case badColumn:
		gameTurn();
		break;

		// It's a valid column, so play it!
		// ********************************
	case tokenAnimation:
		winner = game.isSomeoneWinner();
		if (!winner)
		{
			if (game.isPlayingPossible())
			{
				game.nextPlayer();
				gameTurn();
			}
			else
			{
				game.gameState = matchDraw;
				gameOutput.showMatchDraw();
			}
		}
		else
		{
			switch (game.getWhoWin())
			{
			case player1:
				game.gameState = animationWinnerPlayer1;
				gameOutput.showWinPlayer1();
				break;
			case player2:
				game.gameState = animationWinnerPlayer2;
				gameOutput.showWinPlayer2();
				break;
			}
		}
		break;

		// Nobody win
		// **********
	case matchDraw:
		game.gameState = waitingTouch;
		break;

		// Player 1 has won!
		// *****************
	case animationWinnerPlayer1:
		game.gameState = waitingTouch;
#if DEBUG
		debug(F("anim1\n"));
#endif
		break;

		// Player 2 has won!
		// *****************
	case animationWinnerPlayer2:
		game.gameState = waitingTouch;
#if DEBUG
		debug(F("anim2\n"));
#endif
		break;

	} // switch (game.gameState)

	// end the game output
	// *******************
	gameOutput.endLoop();

}