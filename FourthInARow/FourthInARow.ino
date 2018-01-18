#include "Global.hpp"

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
	debug(F("Init Debug: OK\n"));
}

#endif


////////////////////////////////////////////////////////////////////////////////
// GAME
////////////////////////////////////////////////////////////////////////////////

// INPUT
// *****

#if GAME_INPUT_DUMMY
	#include "GameInput.hpp"
	GameInput gameInput;
#endif
#if GAME_INPUT_SERIAL
	#include "GI_serial.hpp"
	GIserial gameInput;
#endif
#if GAME_INPUT_9BUTTONS
	#include "GI_9buttons.hpp"
	GI9buttons gameInput;
#endif

// OUTPUT
// ******

#if GAME_OUTPUT_DUMMY
	#include "GameOutput.hpp"
	GameOutput gameOutput;
#endif
#if GAME_OUTPUT_SERIAL
	#include "GO_serial.hpp"
	GOserial gameOutput;
#endif
#if GAME_OUPUT_WS2801
	#include "GO_ws2801.hpp"
	GO_ws2801 gameOutput;
#endif
#if GAME_OUPUT_WS2813
	#include "GO_ws2813.hpp"
	GO_ws2813 gameOutput;
#endif
#if GAME_OUTPUT_FEATHER_OLED
	#include "GO_FeatherOled.hpp"
	GOFeatherOled gameOutput;
#endif

// AUDIO
// *****
#if GAME_INPUT_AUDIO_DUMMY
	#include "GameInputAudio.hpp"
	GameInputAudio gameInputAudio;
#endif
#if GAME_INPUT_AUDIO_EC11
	#include "GIA_ec11.hpp"
	GIAec11 gameInputAudio;
#endif
#if GAME_OUTPUT_AUDIO_DUMMY
	#include "GameOutputAudio.hpp"
	GameOutputAudio gameOutputAudio;
#endif
#if GAME_OUTPUT_AUDIO_DFPLAYER_MINI
	#include "GOA_DFPlayerMini.hpp"
	GOA_DFPlayerMini gameOutputAudio;
#endif

#include "Game.hpp"
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
	default: break;
	}
}


////////////////////////////////////////////////////////////////////////////////
// Program starting...
////////////////////////////////////////////////////////////////////////////////

void setup()
{
	randomSeed(analogRead(0));
#if DEBUG
	doInitHelper();
#endif
	doInitGame();
	gameOutputAudio.playPowerOn();
	gameOutput.showTouchSomething();
}

////////////////////////////////////////////////////////////////////////////////
// Endless loop
////////////////////////////////////////////////////////////////////////////////

void loop()
{
	// get the player's input
	// **********************
	gameInput.loop();
	gameInputAudio.loop();
	gameOutput.loop();
	gameOutputAudio.loop();

	// start the loop
	// *********************
	gameInput.startLoop();
	gameInputAudio.startLoop();
	gameOutput.startLoop();
	gameOutputAudio.startLoop();

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
			switch (gameInput.getAction())
			{
			case actionReset:
				gameOutputAudio.playGoodChoice();
				player1IsIA = true;
				player2IsIA = true;
				game.gameState = startingNewGame;
				gameOutput.showIaVsIa();
				break;
			case actionPlayer1:
			case actionColumn1:
				gameOutputAudio.playGoodChoice();
				player1IsIA = false;
				player2IsIA = true;
				game.gameState = startingNewGame;
				gameOutput.showPlayerVsIa();
				break;
			case actionPlayer2:
			case actionColumn2:
				gameOutputAudio.playGoodChoice();
				player1IsIA = false;
				player2IsIA = false;
				game.gameState = startingNewGame;
				gameOutput.showPlayerVsPlayer();
				break;
			default: 
				gameOutputAudio.playBadChoice();
				break;
			}
		}
		break;

		// we are starting a new game session
		// **********************************
	case startingNewGame:
		game.startNewGame();
		gameOutput.drawBoard(game.getBoard());
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
		gameOutputAudio.playStartGame();
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
			gameOutputAudio.playIAThinking();
			playColumn = game.getIndexPlayingForPlayerIA(player1);
#if DEBUG
			debug(F("(IA)"));
#endif
			game.gameState = puttingToken;
		}
		if (game.getCurrentPlayer() == player2 && player2IsIA)
		{
			gameOutputAudio.playIAThinking();
			playColumn = game.getIndexPlayingForPlayerIA(player2);
#if DEBUG
			debug(F("(IA)"));
#endif
			game.gameState = puttingToken;
		}
		if (gameInput.hasInput())
		{
			switch (gameInput.getAction())
			{
				case actionColumn1:
					playColumn = 0;
					game.gameState = puttingToken;
					break;
				case actionColumn2:
					playColumn = 1;
					game.gameState = puttingToken;
					break;
				case actionColumn3:
					playColumn = 2;
					game.gameState = puttingToken;
					break;
				case actionColumn4:
					playColumn = 3;
					game.gameState = puttingToken;
					break;
				case actionColumn5:
					playColumn = 4;
					game.gameState = puttingToken;
					break;
				case actionColumn6:
					playColumn = 5;
					game.gameState = puttingToken;
					break;
				case actionColumn7:
					playColumn = 6;
					game.gameState = puttingToken;
					break;
				default:
					gameOutputAudio.playBadChoice();
					break;
			}
		}
		break;

		// A player has choosen a column for his token
		// *******************************************
	case puttingToken:
		playLine = game.getRowPlayingColumn(playColumn);
		if (playLine == NO_VALUE)
		{
			gameOutputAudio.playBadChoice();
			game.gameState = badColumn;
#if DEBUG
			debug(String(playColumn).c_str());
			debug(F("=bad column\n"));
#endif
		}
		else
		{
			gameOutputAudio.playGoodChoice();
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
		switch(game.getHints())
		{
			case hintCanWin:
				if (game.getCurrentPlayer() == player2)
					gameOutputAudio.playWinningTeasing();
				else
					gameOutputAudio.playLoosingAlert();
				break;
			case hintCanLoose:
				if (game.getCurrentPlayer() == player2)
					gameOutputAudio.playLoosingAlert();
				else
					gameOutputAudio.playWinningTeasing();
				break;
			case hintSureToLoose:
				if (game.getCurrentPlayer() == player2)
					gameOutputAudio.playLoosingAlert();
				else
					gameOutputAudio.playWinningTeasing();
				break;
			default:
				break;
		}
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
		gameOutput.drawBoard(game.getBoard());
		winner = game.isSomeoneWinner();
		if (!winner)
		{
			if (game.isPlayingPossible())
			{
				gameOutput.showHints(game.getWinHints(), game.getLooseHints());
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
					gameOutputAudio.playWin();
					game.gameState = animationWinnerPlayer1;
					gameOutput.showWinPlayer1();
					break;
				case player2:
					gameOutputAudio.playLoose();
					game.gameState = animationWinnerPlayer2;
					gameOutput.showWinPlayer2();
					break;
				default:
				break;
			}
			gameOutput.showWinningCases(game.getWinningCases());
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

	// end the loop
	// ************
	gameOutput.endLoop();
	gameOutputAudio.endLoop();
	gameInput.endLoop();
	gameInputAudio.endLoop();

	if (gameInputAudio.hasInput()) {
		switch (gameInputAudio.getAction())
		{
			case actionVolumeMuteOnOff:
#if DEBUG
				debug(F("Push MUTE ON/OFF\n"));
#endif			
				gameOutputAudio.muteOnOff();
				break;
			case actionVolumeUp:
				gameOutputAudio.volumeUp();
				break;
			case actionVolumeDown:
				gameOutputAudio.volumeDown();
				break;
			default: break;
		}
	}
}