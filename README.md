# Fourth-In-A-Row

Le jeu des [R2-Builders](https://r2builders.fr)

- Idée originale : [@SuTaiBot](https://twitter.com/RUGeek2)

**********************************************************

## ___I. Objectif___

L'objectif est de créer un jeu avec la thématique de Star Wars, par le travail des membres des R2-Builders.  
Le jeu choisi : un dérivé de Puissance 4. Le wikipedia du jeu en français : [Puissance4](https://fr.wikipedia.org/wiki/Puissance_4). Et le wikipedia en anglais : [Connect 4 ou Four-in-a-row](https://en.wikipedia.org/wiki/Connect_Four). Le jeu sera décliné en deux versions.

<p style="text-align: center;">
<img src="https://upload.wikimedia.org/wikipedia/commons/a/ad/Connect_Four.gif" />
</p>

### 1. Version dite "classique"

La version classique sera réalisée avec des jetons que l'on dépose dans les colonnes pour jouer, dans le pure style connu de tous, mais au look de Star Wars !

### 2. Version électronique

La version électronique viendra en complément de la version "classique" en supprimant ces jetons et en représentant les jetons par des LEDs et l'on choisira la colonne par des boutons.

### 3. Regles du jeu

Pendant un match, chaque joueur, à tour de rôle, dépose un jeton dans une des sept colonnes. Le jeton tombe au plus bas de la colonne. Une colonne peut contenir 6 jetons au maximum. Un match est gagné quand un des joueurs a aligné 4 jetons à l'horizontale, à la verticale ou en diagonale. S'il n'y a plus de place pour jouer un jeton et qu'il n'y a pas de gagnant, la partie est déclarée match nul.

**********************************************************

## ___II. Version classique___

**********************************************************

## ___III. Version électronique___

### 1. Fonctionnement

Le jeu a plusieurs états. Les inter-actions seront variables en fonction de cet état.

#### a. Attente

Dans cet phase, il n'y a pas de jeu en cours.

#### b. Choix du nombre de joueurs

Ici, il faut déterminer combien de joueurs participe au jeu. Ce nombre peut être de 1 ou 2. Si 2 joueurs est choisit, il s'agit d'un match oppasant deux joueurs. Si il n'y a qu'un seul joueur, il jouera alors contre une  "Intelligence Artificielle" (IA).

#### c. Choix du joueur qui commence

Il faut maintenant décider qui commence parmi les deux opposants.

#### d. Placer un jeton

#### e. Analyser le jeton

Si la colonne est pleine, retour à l'état d.
Si quelqu'un a gagné, à l'état correspondant.
S'il n'est plus possible de jouer, aller à l'état .
C'est au joueur suivant de jouer, aller à l'état d.

### f. Le joueur 1 a gagné

### g. Le joueur 2 a gagné

### h. C'est un match nul

### i. Animation de fin de jeu

On retourne à l'état a.

### 2. Matériel

#### 1. Composant principal

Le programme fonctionne sur : (testé)

- Arduino Mega
- Adafruit Huzzah 32 (ESP32)
- Teensy 3.5

#### 2. Composants additionnels

##### a. Audio

Rien pour le moment

##### b. Boutons

Rien pour le moment

##### c. LED

Rien pour le moment

##### d. Ecran

- Featherwing Oled (pour Huzzah 32) : uniquement pour debug

### 3. Environnement de développement

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

**********************************************************

## Des liens

Aide pour la [mise en forme de ce readme](https://openclassrooms.com/courses/redigez-en-markdown).