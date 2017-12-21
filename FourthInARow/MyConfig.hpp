#ifndef MyConfig_h
#define MyConfig_h

// Il s'agit du seule fichier à modifier.
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
//#define MEGA2560 1

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
#define BUTTON_COLUMN_1 5
#define BUTTON_COLUMN_2 6
#define BUTTON_COLUMN_3 7
#define BUTTON_COLUMN_4 8
#define BUTTON_COLUMN_5 9
#define BUTTON_COLUMN_6 10
#define BUTTON_COLUMN_7 11
#define BUTTON_COLUMN_PLAYER_1 12
#define BUTTON_COLUMN_PLAYER_2 13

// 2 - la gestion audio
///////////////////////

// pas de gestion audio
#define GAME_INPUT_AUDIO_DUMMY 1

// gestion du volume par un encodeur type ec11
#define GAME_INPUT_AUDIO_EC11 0
// comment est connecté cet encodeur
// PIN_A et PIN_B doivent être sur une pin avec interruption
#define EC11_ENCODER_PIN_A 2
#define EC11_ENCODER_PIN_B 3
#define EC11_BUTTON_PIN 4

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
#define GAME_OUTPUT_AUDIO_DUMMY 1


// Paramètres de démarrage
// ***********************

// réglage du volume sonore
// niveau du volume audio : de 0 (MUTE) à 10 (Max)
#define AUDIO_STARTING_VOLUME 10
// avec 2 boutons poussoir
#define AUDIO_BUTTONS_VOLUME 0
// ou par un bouton rotatif
#define AUDIO_ROTARY_VOLUME 0


#endif