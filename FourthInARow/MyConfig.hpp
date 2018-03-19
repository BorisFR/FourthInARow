#ifndef MYCONFIG_HPP
#define MYCONFIG_HPP

// Il s'agit du seul fichier à modifier.
// Vous définissez le matériel que vous avez
// et la configuration que vous avez construite.


////////////////////////////////////////////////////////////////////////////////
// Paramètres de fonctionnement du programme
////////////////////////////////////////////////////////////////////////////////

// mettre 1 pour être en mode debug, sinon mettre 0
// En mode debug, il y a énormément d'informations qui seront envoyées
// à votre PC/Mac/Linux sur la console série

#define DEBUG 1


////////////////////////////////////////////////////////////////////////////////
// Définir la carte électronique que vous utilisez
////////////////////////////////////////////////////////////////////////////////

// si vous utilisez le programme Arduino
// *************************************
// mettre 1 à votre carte électronique 
// et 0 pour les autres
// il ne doit y avoir qu'un seul 1 !

// si vous utilisez platformIO (avec Atom ou Visual Studio Code)
// *************************************************************
// mettre en commentaire car c'est géré automatiquement
// dans le fichier platformio.ini du projet

// 1 si carte ESP32, sinon mettre 0
// impossible à utiliser car ça manque de pinouilles !
//#define ESP32 0

// 1 si carte TEENSY35 / TEENSY36, sinon mettre 0
#define TEENSY3x 1

// 1 si carte ARDUINO MEGA 2560, sinon mettre 0
// impossible à utiliser avec l'IA
//#define MEGA2560 1

// 1 si carte ARDUINO UNO, sinon mettre 0
// impossible à compiler sur UNO : pas assez de mémoire !
//#define UNO 1

////////////////////////////////////////////////////////////////////////////////
// Paramètres définissant votre installation
////////////////////////////////////////////////////////////////////////////////

// mettre 1 si vous avez le matériel correspondant


// les actions des joueurs
// ***********************

// 1 - les actions de jeu
/////////////////////////

// si aucun dispositif d'actions installé
#define GAME_INPUT_DUMMY 0

// utilisation de la console Série du PC/Mac/Linux /!\ #define DEBUG doit être à 1
#define GAME_INPUT_SERIAL 1

// dispositif à base de 7 boutons (1 par colonne) + 2 boutons choix du nombre de joueurs
#define GAME_INPUT_9BUTTONS 0
#if !GAME_INPUT_9BUTTONS
	#define BUTTON_COLUMN_1 0
	#define BUTTON_COLUMN_2 0
	#define BUTTON_COLUMN_3 0
	#define BUTTON_COLUMN_4 0
	#define BUTTON_COLUMN_5 0
	#define BUTTON_COLUMN_6 0
	#define BUTTON_COLUMN_7 0
	#define BUTTON_COLUMN_PLAYER_1 0
	#define BUTTON_COLUMN_PLAYER_2 0
#else
	// les boutons d'arcade sont-ils lumineux ? (avec une led)
	#define BUTTONS_LED 0
	// n° de la led 
	#define LED_PLAYER_1 7
	#define LED_PLAYER_2 8
	#if ESP32
		// SDA/SCL/A6/A7/A8/A9/A10/A12/21
		#define BUTTON_COLUMN_1 23
		#define BUTTON_COLUMN_2 22
		#define BUTTON_COLUMN_3 14
		#define BUTTON_COLUMN_4 32
		#define BUTTON_COLUMN_5 15
		#define BUTTON_COLUMN_6 33
		#define BUTTON_COLUMN_7 27
		#define BUTTON_COLUMN_PLAYER_1 13
		#define BUTTON_COLUMN_PLAYER_2 21
		#if BUTTONS_LED
			// 
			#define BUTTON_LED_1 0
			#define BUTTON_LED_2 0
			#define BUTTON_LED_3 0
			#define BUTTON_LED_4 0
			#define BUTTON_LED_5 0
			#define BUTTON_LED_6 0
			#define BUTTON_LED_7 0
			#define BUTTON_LED_PLAYER_1 0
			#define BUTTON_LED_PLAYER_2 0
		#endif
	#endif
	#if TEENSY3x
		#define BUTTON_COLUMN_1 24
		#define BUTTON_COLUMN_2 25
		#define BUTTON_COLUMN_3 26
		#define BUTTON_COLUMN_4 27
		#define BUTTON_COLUMN_5 28
		#define BUTTON_COLUMN_6 29
		#define BUTTON_COLUMN_7 30
		#define BUTTON_COLUMN_PLAYER_1 31
		#define BUTTON_COLUMN_PLAYER_2 32
		#if BUTTONS_LED
			#define BUTTON_LED_1 0
			#define BUTTON_LED_2 1
			#define BUTTON_LED_3 2
			#define BUTTON_LED_4 3
			#define BUTTON_LED_5 4
			#define BUTTON_LED_6 5
			#define BUTTON_LED_7 6
			#define BUTTON_LED_PLAYER_1 7
			#define BUTTON_LED_PLAYER_2 8
		#endif
	#endif
	#if MEGA2560
		#define BUTTON_COLUMN_1 0
		#define BUTTON_COLUMN_2 0
		#define BUTTON_COLUMN_3 0
		#define BUTTON_COLUMN_4 0
		#define BUTTON_COLUMN_5 0
		#define BUTTON_COLUMN_6 0
		#define BUTTON_COLUMN_7 0
		#define BUTTON_COLUMN_PLAYER_1 0
		#define BUTTON_COLUMN_PLAYER_2 0
		#if BUTTONS_LED
			#define BUTTON_LED_1 0
			#define BUTTON_LED_2 0
			#define BUTTON_LED_3 0
			#define BUTTON_LED_4 0
			#define BUTTON_LED_5 0
			#define BUTTON_LED_6 0
			#define BUTTON_LED_7 0
			#define BUTTON_LED_PLAYER_1 0
			#define BUTTON_LED_PLAYER_2 0
		#endif
	#endif
	#if UNO
		#define BUTTON_COLUMN_1 0
		#define BUTTON_COLUMN_2 0
		#define BUTTON_COLUMN_3 0
		#define BUTTON_COLUMN_4 0
		#define BUTTON_COLUMN_5 0
		#define BUTTON_COLUMN_6 0
		#define BUTTON_COLUMN_7 0
		#define BUTTON_COLUMN_PLAYER_1 0
		#define BUTTON_COLUMN_PLAYER_2 0
		#if BUTTONS_LED
			#define BUTTON_LED_1 0
			#define BUTTON_LED_2 0
			#define BUTTON_LED_3 0
			#define BUTTON_LED_4 0
			#define BUTTON_LED_5 0
			#define BUTTON_LED_6 0
			#define BUTTON_LED_7 0
			#define BUTTON_LED_PLAYER_1 0
			#define BUTTON_LED_PLAYER_2 0
		#endif
	#endif
#endif


// 2 - la gestion audio
///////////////////////

// pas de gestion audio
#define GAME_INPUT_AUDIO_DUMMY 1

// gestion du volume par un encodeur type ec11
#define GAME_INPUT_AUDIO_EC11 0
// comment est connecté cet encodeur
// PIN_A doit être sur une pin avec interruption
#if !GAME_INPUT_AUDIO_EC11
	#define EC11_ENCODER_PIN_A 0
	#define EC11_ENCODER_PIN_B 0
	#define EC11_BUTTON_PIN 0
#else
	#if ESP32
		// A2 / A3 / A4
		#define EC11_ENCODER_PIN_A 34
		#define EC11_ENCODER_PIN_B 39
		#define EC11_BUTTON_PIN 36
	#endif
	#if TEENSY3x
		#define EC11_ENCODER_PIN_A 23
		#define EC11_ENCODER_PIN_B 22
		#define EC11_BUTTON_PIN 21
	#endif
	#if MEGA2560
		#define EC11_ENCODER_PIN_A 0
		#define EC11_ENCODER_PIN_B 0
		#define EC11_BUTTON_PIN 0
	#endif
	#if UNO
		#define EC11_ENCODER_PIN_A 0
		#define EC11_ENCODER_PIN_B 0
		#define EC11_BUTTON_PIN 0
	#endif
#endif

// les actions du jeu
// ******************

// 1 - Dispositif d'affichage
/////////////////////////////

// si aucun dispositif n'est installé
#define GAME_OUTPUT_DUMMY 0

// utilisation de la console Série du PC/Mac/Linux /!\ #define DEBUG doit être à 1
#define GAME_OUTPUT_SERIAL 0

// la localisation des 42 leds
// pour le programme, ça va de bas en haut et de gauche à droite
//				      colonne 1				colonne 2			 colonne 3			     colonne 4				colonne 5			   colonne 6			  colonne 7
//					  bas ...		   haut/bas ...	        haut/bas ...		    haut/bas ...		   haut/bas ...	    	  haut/bas ...		     haut/bas ...
#define LED_POSITIONS 6, 7, 20, 21, 34, 35, 5, 8, 19, 22, 33, 36, 4, 9, 18, 23, 32, 37, 3, 10, 17, 24, 31, 38, 2, 11, 16, 25, 30, 39, 1, 12, 15, 26, 29, 40, 0, 13, 14, 27, 28, 41
#define LED_POSITIONS_PLAYER_2 6, 7, 20, 21, 34, 35, 5, 8, 19, 22, 33, 36, 4, 9, 18, 23, 32, 37, 3, 10, 17, 24, 31, 38, 2, 11, 16, 25, 30, 39, 1, 12, 15, 26, 29, 40, 0, 13, 14, 27, 28, 41
//#define LED_POSITIONS_PLAYER_2 36, 37, 38, 39, 40, 41, 35, 34, 33, 32, 31, 30, 24, 25, 26, 27, 28, 29, 23, 22, 21, 20, 19, 18, 12, 13, 14, 15, 16, 17, 11, 10, 9, 8, 7, 6, 0, 1, 2, 3, 4, 5
// LEDs for player 1 and 2 are on the same physical line, it is only one strip!
// LEDs for player 1 and 2 are the same, but player 2 start at index :
#define LED_PLAYER_2_OFFSET 50

// le plateau de jeu est visualisé par 42 LEDs RGB type WS2801
#define GAME_OUPUT_WS2801 0
#define WS2801_DATA_PIN 18
#define WS2801_CLOCK_PIN 5
#define WS2801_NUMBER_LEDS 56

// le plateau de jeu est visualisé par 42 LEDs RGB type WS2813
#define GAME_OUPUT_WS2813 1
#define WS2813_DATA_PIN 14
#define WS2813_NUMBER_LEDS 100
#define WS2813_COLOR_ORDER GRB
#define WS2813_BRIGHTNESS 255

// un rendu sur écran OLED Featherwing
#define GAME_OUTPUT_FEATHER_OLED 0

// 2 - audio
////////////

// une carte son n'est pas présente
#define GAME_OUTPUT_AUDIO_DUMMY 1

#define GAME_OUTPUT_AUDIO_DFPLAYER_MINI 0
#if !GAME_OUTPUT_AUDIO_DFPLAYER_MINI
	#define DFPLAYER_MINI_BUSY 0
	#define DFPLAYER_MINI_SERIAL Serial
#else
	#if ESP32
		// A5 + Serial1
		#define DFPLAYER_MINI_BUSY 4
		#define DFPLAYER_MINI_SERIAL Serial1
	#endif
	#if TEENSY3x
		#define DFPLAYER_MINI_BUSY 35
		#define DFPLAYER_MINI_SERIAL Serial5 // TX = 33, RX = 34
	#endif
	#if MEGA2560
		#define DFPLAYER_MINI_BUSY 0
		#define DFPLAYER_MINI_SERIAL Serial
	#endif
	#if UNO
		#define DFPLAYER_MINI_BUSY 0
		#define DFPLAYER_MINI_SERIAL Serial
	#endif
#endif

// Paramètres de démarrage
// ***********************

// réglage du volume sonore
// niveau du volume audio : de 0 (MUTE) à 100 (Max)
#define AUDIO_STARTING_VOLUME 50

#endif