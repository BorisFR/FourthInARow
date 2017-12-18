#ifndef MyConfig_h
#define MyConfig_h

// Il s'agit du seule fichier à modifier.
// Vous définissez le matériel que vous avez
// et la configuration que vous avez construite.


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
//#define ESP32 1

// 1 si carte TEENSY35, sinon mettre 0
//#define TEENSY35 0


////////////////////////////////////////////////////////////////////////////////
// Paramètres définissant votre installation
////////////////////////////////////////////////////////////////////////////////

// mettre 1 si vous avez le matériel correspondant

// une carte son est présente ?
// ****************************
#define AUDIO_CARD 0

// réglage du volume sonore
// niveau du volume audio au démarrage : de 0 (MUTE) à 10 (Max)
#define AUDIO_STARTING_VOLUME 10
// avec 2 boutons poussoir
#define AUDIO_BUTTONS_VOLUME 0
// ou par un bouton rotatif
#define AUDIO_ROTARY_VOLUME 0

// un écran est présent ?
// **********************
#define DISPLAY_SCREEN 0

// un écran pour afficher des animations graphique
#define DISPLAY_ANIMATION 0

#define DUMMY_SCREEN 0
#define FEATHER_OLED 1

////////////////////////////////////////////////////////////////////////////////
// Paramètres de fonctionnement du programme
////////////////////////////////////////////////////////////////////////////////

// mettre 1 pour être en mode debug, sinon mettre 0
// En mode debug, il y a énormément d'informations qui seront envoyées
// à votre PC/Mac/Linux sur la console série

#define DEBUG 1


#endif