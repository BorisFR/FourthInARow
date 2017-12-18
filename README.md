# Fourth-In-A-Row

Le jeu des [R2-Builders](https://r2builders.fr)

- Idée originale : [@SuTaiBot](https://twitter.com/RUGeek2)

**********************************************************

## 1. Objectif

L'objectif est de créer un jeu avec la thématique de Star Wars, par le travail des membres des R2-Builders.  
Le jeu choisi : un dérivé de Puissance 4. Il sera décliné en deux versions :

### 1. Version dite "classique"

La version classique sera réalisée avec des jetons que l'on dépose dans les colonnes pour jouer.

### 2. Version électronique

La version électronique viendra en complément de la version "classique" en supprimant ces jetons et en représentant les jetons par des LEDs et l'on choisira la colonne par des boutons.

**********************************************************

## 2. Hardware

### 1. Composant principal

Le programme fonctionne sur : (testé)

- Arduino Mega
- Adafruit Huzzah 32 (ESP32)
- Teensy 3.5

### 2. Composants additionnels

#### 1. Audio

Rien pour le moment

#### 2. Boutons

Rien pour le moment

#### 3. LED

Rien pour le moment

#### 4. Ecran

- Featherwing Oled pour Huzzah 32

**********************************************************

## 3. Environnement de développement

Ce projet est réalisé avec [Visual Studio Code](https://code.visualstudio.com) avec l'extension [PlatformIO](http://platformio.org).  
Cependant, la structure du projet permet d'ouvrir ce projet avec l'environnement [Arduino IDE](https://www.arduino.cc/en/Main/Software) standard.  
Ce projet fonctionne également avec [Atom](https://atom.io) + [PlatformIO](http://platformio.org).  

### Sur Mac

Il faut un git avec une version au moins 2.0.0  
git --version  
git version 2.13.5 (Apple Git-94)  
  
git credential-osxkeychain  
usage: git credential-osxkeychain <get|store|erase>  
  
git config --global credential.helper osxkeychain  

[GitHub Desktop](https://desktop.github.com)
