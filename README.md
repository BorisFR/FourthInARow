# Fourth-In-A-Row

Le jeu des [R2-Builders](https://r2builders.fr)

- Idée originale : [@SuTaiBot](https://twitter.com/RUGeek2)

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

### 3. Règles du jeu

Pendant un match, chaque joueur, à tour de rôle, dépose un jeton dans une des sept colonnes. Le jeton tombe au plus bas de la colonne. Une colonne peut contenir 6 jetons au maximum. Un match est gagné quand un des joueurs a aligné 4 jetons à l'horizontale, à la verticale ou en diagonale. S'il n'y a plus de place pour jouer un jeton et qu'il n'y a pas de gagnant, la partie est déclarée match nul.

## ___II. Version classique___

### 1. Le plateau de jeu

Voici un rendu de ce que ça pourrait donner :  
![plateau](https://raw.githubusercontent.com/BorisFR/FourthInARow/master/imagesgithub/Fourth-in-a-row-03.jpg)

#### a. Le plateau

![plateau](https://raw.githubusercontent.com/BorisFR/FourthInARow/master/imagesgithub/4thInARow-Frame.png)

#### b. Les supports

![plateau](https://raw.githubusercontent.com/BorisFR/FourthInARow/master/imagesgithub/4thInARow-Side.png)

### 2. Les jetons

![plateau](https://raw.githubusercontent.com/BorisFR/FourthInARow/master/imagesgithub/4thInARow-Token.png)

## ___III. Version électronique___

### **1. Fonctionnement**

Le jeu a plusieurs états. Les inter-actions avec les joueurs seront variables en fonction de cet état. Voici le détail pour chaque état.

#### a. Attente

Dans cet phase, il n'y a pas de jeu en cours. Le programme est juste en attente d'une action des joueurs. Il passe alors à l'état suivant ***b***.

#### b. Choix du nombre de joueurs

Ici, il faut déterminer combien de joueurs participe au jeu. Ce nombre peut être de 1 ou 2. Si 2 joueurs est choisit, il s'agit d'un match opposant deux joueurs. Si il n'y a qu'un seul joueur, il jouera alors contre une  "Intelligence Artificielle" (IA). Afin de tester cette IA, il est possible de choisir zéro joueur : le programme joue alors contre lui-même.

#### c. Choix du joueur qui commence

Il faut maintenant décider qui commence parmi les deux opposants. Une fois ce choix effectué, le programme passe alors à l'état ***d***.

#### d. Placer un jeton

Le joueur en cours doit sélectionner une colonne pour déposer son jeton. Le programme passe alors à l'état ***e***.

#### e. Analyser le jeton

Si la colonne est pleine, retour à l'état ***d***.
Si quelqu'un a gagné, à l'état correspondant ***f*** ou ***g***.
S'il n'est plus possible de jouer, aller à l'état ***h***.
C'est au joueur suivant de jouer, aller à l'état ***d***.

#### f. Le joueur 1 a gagné

On affiche l'infrmation et on passe à l'état ***i***.

#### g. Le joueur 2 a gagné

On affiche l'infrmation et on passe à l'état ***i***.

#### h. C'est un match nul

On affiche l'infrmation et on passe à l'état ***i***.

#### i. Animation de fin de jeu

On retourne à l'état ***a***.

### **2. Matériel**

#### 1. Composant principal

Le cerveau de cette version électronique. On pourra utiliser divers matériels, voici ce que les membres ont utilisés / testés. Le programme fonctionne sur :

- Arduino Mega
- Adafruit Huzzah 32 (ESP32)
- Teensy 3.5

Il fonctionne surement sur d'autres composants, mais ça n'a pas été testé.

#### 2. Composants additionnels

L'idée est d'avoir un panel d'options pour que vous puissiez réaliser votre propre jeu. Voici l'ensemble des composants qui sont activables dans le programme.

##### a. INPUT : Boutons

Besoin :

- choisir le nombres de joueurs
- choisir qui commence
- choisir la colonne pour déposer le jeton

##### b. OUTPUT - Audio

Avoir la possibilité de jouer du son à divers moments pendant le jeu.

##### c. OUTPUT - LED

L'idée est d'avoir une LED par case, schématisant une case vide ou un jeton de joueur. Le tout représente un jeu complet.

Possibilités :

- 42 LEDs RGB

##### d. OUTPUT - Ecran

Avoir un écran graphique sur lequel afficher des animations amusantes pendant le jeu.

Note : pour debug, en plus de la console Serial, Boris utilise un écran OLED Featherwing pour Huzzah 32.

### 3. **Le programme**

Vous pouvez configurer votre installation dans le fichier "MyConfig.h". Vous pouvez alors comiler et télécharger votre programme sur votre arduino.

Le programme est développé en C++ "arduino".

#### "FourthInARow.ino"

Le point d'entrée est le fichier "FourthInARow.ino". Il s'git du chef d'orchestre du jeu, celui qui va gérer les différents états du jeu et orchestrer l'ensemble des composants en fonction de cet état.

#### "Game.h"

Les fichiers Game.h et Game.cpp contiennent toute la logique d'exécution du jeu Puissance 4 en lui-même.

#### "GameInput.h"

Les fichiers "GameInput.h" et "GameInput.cpp" contiennent toute la logique pour que les joueurs puissent agir sur le jeu. A ce titre, c'est ici que l'on définiera toutes les entrées possibles comme la gestion des boutons.
C'est fichiers contiennent une implémentation à vide de ces fonctions ! L'implémentation réelle est effectuée dans d'autres fichiers. Il suffit d'indiquer dans le fichier "MyConfig.h" l'implémentation réelle que vous voulez utiliser.

Voici les implémentations disponibles :

- interface Serial en mode debug.

#### "GameOutput.h"

Les fichiers "GameOutput.h" et "GameOuput.cpp" contiennent toute la logique pour que le jeu puissent communiquer avec les joueurs. C'est donc ici que l'on gérera l'affichage du plateau de jeu (les LEDs), l'audio et l'affichage d'animations.
Ces fichiers contiennent une implémentation à vide de ces fonctions ! L'implémentation réelle est effectuée dans d'autres fichiers (par héritage de class). Mais pour vous, il suffit d'indiquer dans le fichier "MyConfig.h" l'implémentation réelle que vous voulez utiliser.

Voici les implémentations disponibles concernant l'audio :

- aucune pour le moment

Voici les implémentations disponibles concernant l'affichage du plateau :

- FeatherOled.h/.cpp : un rendu basique du plateau de jeu sur l'écran [Featherwing OLED 128x32](https://www.adafruit.com/product/2900).

Voici les implémentations disponibles concernant l'écran d'animations :

- aucune pour le moment

#### Autres fichiers

Global.h, CaseLocation.h, Column.h/.cpp, Tile.h/.cpp : utile pour le fonctionnement du jeu.

### 4. **Environnement de développement**

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