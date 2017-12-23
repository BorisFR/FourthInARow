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
//#define ESP32 0

// 1 si carte TEENSY35, sinon mettre 0
//#define TEENSY35 0

// 1 si carte ARDUINO MEGA 2560, sinon mettre 0
//#define MEGA2560 0

// 1 si carte ARDUINO UNO, sinon mettre 0
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
	#if ESP32
		#define BUTTON_COLUMN_1 21
		#define BUTTON_COLUMN_2 25
		#define BUTTON_COLUMN_3 26
		#define BUTTON_COLUMN_4 14
		#define BUTTON_COLUMN_5 32
		#define BUTTON_COLUMN_6 15
		#define BUTTON_COLUMN_7 33
		#define BUTTON_COLUMN_PLAYER_1 27
		#define BUTTON_COLUMN_PLAYER_2 12
	#endif
	#if TEENSY35
		#define BUTTON_COLUMN_1 0
		#define BUTTON_COLUMN_2 0
		#define BUTTON_COLUMN_3 0
		#define BUTTON_COLUMN_4 0
		#define BUTTON_COLUMN_5 0
		#define BUTTON_COLUMN_6 0
		#define BUTTON_COLUMN_7 0
		#define BUTTON_COLUMN_PLAYER_1 0
		#define BUTTON_COLUMN_PLAYER_2 0
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
	#endif
#endif


// 2 - la gestion audio
///////////////////////

// pas de gestion audio
#define GAME_INPUT_AUDIO_DUMMY 0

// gestion du volume par un encodeur type ec11
#define GAME_INPUT_AUDIO_EC11 1
// comment est connecté cet encodeur
// PIN_A doit être sur une pin avec interruption
#if !GAME_INPUT_AUDIO_EC11
	#define EC11_ENCODER_PIN_A 0
	#define EC11_ENCODER_PIN_B 0
	#define EC11_BUTTON_PIN 0
#else
	#if ESP32
		#define EC11_ENCODER_PIN_A 34
		#define EC11_ENCODER_PIN_B 39
		#define EC11_BUTTON_PIN 36
	#endif
	#if TEENSY35
		#define EC11_ENCODER_PIN_A 0
		#define EC11_ENCODER_PIN_B 0
		#define EC11_BUTTON_PIN 0
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
#define GAME_OUTPUT_SERIAL 1

// le plateau de jeu est visualisé par 42 LEDs RGB
#define GAME_OUTPUT_BOARD_RGW_LED 0

// les buttons d'actions ont des leds blanches
#define GAME_OUTPUT_9BUTTONS_INPUT_WHITE_LED 0

// un rendu sur écran OLED Featherwing
#define GAME_OUTPUT_FEATHER_OLED 0

// 2 - audio
////////////

// une carte son n'est pas présente
#define GAME_OUTPUT_AUDIO_DUMMY 0

#define GAME_OUTPUT_AUDIO_DFPLAYER_MINI 1
#if !GAME_OUTPUT_AUDIO_DFPLAYER_MINI
	#define DFPLAYER_MINI_BUSY 0
	#define DFPLAYER_MINI_SERIAL Serial
#else
	#if ESP32
		#define DFPLAYER_MINI_BUSY 4
		#define DFPLAYER_MINI_SERIAL Serial1
	#endif
	#if TEENSY35
		#define DFPLAYER_MINI_BUSY 0
		#define DFPLAYER_MINI_SERIAL Serial
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