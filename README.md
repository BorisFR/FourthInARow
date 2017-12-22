# Fourth-In-A-Row

Le jeu des [R2-Builders](https://r2builders.fr) : Le jeu Puissance 4 avec la Force du Jedi !

- Idée originale : [@SuTaiBot](https://twitter.com/RUGeek2)

## ___I. Objectif___

L'objectif est de créer un jeu avec la thématique de Star Wars, par le travail des membres des R2-Builders.  
Le jeu choisi : un dérivé de Puissance 4. Le wikipedia du jeu en français : [Puissance 4](https://fr.wikipedia.org/wiki/Puissance_4). Et le wikipedia en anglais : [Connect 4 ou Four-in-a-row](https://en.wikipedia.org/wiki/Connect_Four). Le jeu sera décliné en deux versions.

<p style="text-align: center;"><img src="https://upload.wikimedia.org/wikipedia/commons/a/ad/Connect_Four.gif" /></p>

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

On affiche l'information et on passe à l'état ***i***.

#### g. Le joueur 2 a gagné

On affiche l'information et on passe à l'état ***i***.

#### h. C'est un match nul

On affiche l'information et on passe à l'état ***i***.

#### i. Animation de fin de jeu

On retourne à l'état ***a***.

### **2. Matériel**

#### 1. Composant principal

Le cerveau de cette version électronique. On pourra utiliser divers matériels, voici ce que les membres ont utilisés / testés. Le programme fonctionne sur :

- Arduino Mega
- Adafruit Huzzah 32 (ESP32)
- Teensy 3.5

Il fonctionne certainement sur d'autres composants, mais ça n'a pas été testé.

#### 2. Composants additionnels

L'idée est d'avoir un panel d'options pour que vous puissiez réaliser votre propre jeu. Voici l'ensemble des composants qui sont activables dans le programme.

C'est dans le fichier ***"MyConfig.hpp"*** que vous indiquez votre configuration.

##### a. INPUT : Boutons pour jouer

Besoin :

- choisir le nombres de joueurs
- choisir qui commence
- choisir la colonne pour déposer le jeton

##### b. INPUT : Boutons pour audio

Gérer le son : augmenter le volume, baisser le volume, mute.

##### c. OUTPUT - Audio

Avoir la possibilité de jouer du son à divers moments pendant le jeu.

##### d. OUTPUT - LED

L'idée est d'avoir une LED par case, schématisant une case vide ou un jeton de joueur. Le tout représente un jeu complet.

Possibilités :

- 42 LEDs RGB

##### e. OUTPUT - Écran

Avoir un écran graphique sur lequel afficher des animations amusantes pendant le jeu. Pour le moment, cette option ne sera pas développée.

### 3. **Le programme**

Vous pouvez configurer votre installation dans le fichier "MyConfig.hpp". Vous pouvez alors compiler et télécharger votre programme sur votre arduino.

Le programme est développé en C++ "arduino".

#### "FourthInARow.ino"

Le point d'entrée est le fichier "FourthInARow.ino". Il s'agit du chef d'orchestre du jeu, celui qui va gérer les différents états du jeu et orchestrer l'ensemble des composants en fonction de cet état.

#### "Game.hpp"

Les fichiers Game.h et Game.cpp contiennent toute la logique d'exécution du jeu Puissance 4 en lui-même.

#### "GameInput.hpp"

Les fichiers "GameInput.h" et "GameInput.cpp" contiennent toute la logique pour que les joueurs puissent agir sur le jeu. A ce titre, c'est ici que l'on définit toutes les entrées possibles comme la gestion des boutons.
C'est fichiers contiennent une implémentation à vide de ces fonctions ! L'implémentation réelle est effectuée dans d'autres fichiers. Il suffit d'indiquer dans le fichier "MyConfig.h" l'implémentation réelle que vous voulez utiliser.

Voici les implémentations disponibles :

- GIserial.hpp/cpp : interface Serial (utilisable uniquement en mode debug).
- GI9buttons.hpp/.cpp : 7 boutons pour le choix de la colonne et 2 boutons pour le choix du nombre de joueurs.

#### "GameInputAudio.hpp"

Les fichiers "GameInputAudio.h" et "GameInputAudio.cpp" contiennent toute la logique pour agir sur l'audio : gérer le volume, couper le son, ...

Voici les implémentations disponibles concernant le son :

- GIAec11.hpp/cpp : encodeur rotatif EC11, pour la gestion du son (volume +/- et mute).

#### "GameOutputAudio.hpp"

Les fichiers "GameOutputAudio.h" et "GameOutputAudio.cpp" contiennent toute la logique pour que le jeu puissent faire du bruit.

Voici les implémentations disponibles concernant le son :

- aucune pour le moment

#### "GameOutput.hpp"

Les fichiers "GameOutput.h" et "GameOutput.cpp" contiennent toute la logique pour que le jeu puissent communiquer avec les joueurs. C'est donc ici que l'on gérera l'affichage du plateau de jeu (les LEDs), l'audio et l'affichage d'animations.
Ces fichiers contiennent une implémentation à vide de ces fonctions ! L'implémentation réelle est effectuée dans d'autres fichiers (par héritage de class). Mais pour vous, il suffit d'indiquer dans le fichier "MyConfig.h" l'implémentation réelle que vous voulez utiliser.

Voici les implémentations disponibles concernant l'affichage du plateau :

- GOserial.hpp/.cpp : rendu dans l'interface Série du PC/Mac/Linux
- GOFeatherOled.hpp/.cpp : un rendu basique du plateau de jeu sur écran [Featherwing OLED 128x32](https://www.adafruit.com/product/2900). Utilise les bibliothèques Adafruit_SSD1306 et Adafruit_GFX.

#### Autres fichiers

Global.hpp, CaseLocation.hpp, Column.hpp/.cpp, Tile.hpp/.cpp : utile pour le fonctionnement du moteur de jeu.

OneSwitch.hpp/.cpp : bibliothèque que vous pouvez utilisez pour implémenter un bouton avec gestion du debounce.

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

**********************************************************

## Liste de composants par Boris

C'est un premier jet, il serait étonnant que j'ai tout bon du premier coup ;)

**Alimentation :** 5V 10A - [https://fr.aliexpress.com/item/AC-DC-Power-Supply-5V-5A-6A-8A-10A-Adapter-Charger-Transformer-25W-60W-40W-50W/32756921792.html](https://fr.aliexpress.com/item/AC-DC-Power-Supply-5V-5A-6A-8A-10A-Adapter-Charger-Transformer-25W-60W-40W-50W/32756921792.html)  
**Connecteur d'alimentation :** Jack 5,5mm / 2,1mm - réf 48147 - [https://www.gotronic.fr/art-embase-alim-sc215-123.htm](https://www.gotronic.fr/art-embase-alim-sc215-123.htm)  
**Haut-parleur :** 2x 3W 8 Ohms - réf 05527 - [https://www.gotronic.fr/art-haut-parleur-hp8r3w-25596.htm](https://www.gotronic.fr/art-haut-parleur-hp8r3w-25596.htm)  (https://www.gotronic.fr/art-connecteur-jst-2-pts-coude-jst2m-22580.htm)  
**Ampli audio :** 2,8 W - réf 32946 - [https://www.gotronic.fr/art-module-ampli-audio-2-8w-ada1552-21902.htm](https://www.gotronic.fr/art-module-ampli-audio-2-8w-ada1552-21902.htm)  
**Bouton de commande audio :** encodeur rotatif - ref 35409 - [https://www.gotronic.fr/art-module-encodeur-rotatif-sen0235-26820.htm](https://www.gotronic.fr/art-module-encodeur-rotatif-sen0235-26820.htm)  
**Boutons pour jouer :** boutons d'arcade lumineux 30mm - [https://fr.aliexpress.com/item/10pcs-lot-30mm-Push-Button-Arcade-Button-5V-LED-Illuminated-Push-Button-LED-1P-2P-Start/32807197485.html](https://fr.aliexpress.com/item/10pcs-lot-30mm-Push-Button-Arcade-Button-5V-LED-Illuminated-Push-Button-LED-1P-2P-Start/32807197485.html)  
**Affichage du plateau par LEDs :** 2x Ruban 50 LEDs RGB - [https://fr.aliexpress.com/item/50pcs-WS2813-IC-pixel-LED-Module-lighting-F9-for-sign-DC5V-IP68-Waterproof-super-bright-WS2818/32803390301.html](https://fr.aliexpress.com/item/50pcs-WS2813-IC-pixel-LED-Module-lighting-F9-for-sign-DC5V-IP68-Waterproof-super-bright-WS2818/32803390301.html)  
**Coeur :** non décidé - Teensy 3.5 ou Huzzah32  
**Régulateur :** 3,3V 1,5A - réf 42632 - [https://www.gotronic.fr/art-lm1086it3-3-14313.htm](https://www.gotronic.fr/art-lm1086it3-3-14313.htm)  
