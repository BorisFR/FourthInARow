/* pour le rendu openscad */

// pour la finesse de rendu
// plus c'est élevé, mieux c'est... mais ça prend plus de temps et de ressource
resolution = 10;

// pour enlever de la matière des objets dans openscad et être certain qu'il ne reste pas un bout de face
difference_objet_marge = 20;

// pour afficher (1) ou pas (0) les accessoires installés
show_accessoires = 1;

show_logo_r2builders = 0;



/* pour le design du jeu  */

// tout est en millimetre !!!!

// configuration globale
////////////////////////

// quand on perce et que l'on va insérer quelque chose dedans...
// il faut un peu de vide en plus ;)
padding_percage = 0.2;

// espace supplémentaire pour la largeur de rainure
padding_rainure = 1;

// profondeur standard pour une rainure
profondeur_rainure = 2; // moins que epaisseur_tole_grille_led et que epaisseur_tole_grille_led ! Il faut qu'il reste de la matière !

// définition de base du jeu
nombre_colonnes = 7;
nombre_lignes = 6;


// les boutons de sélection de colonne et du nombre de joueurs
//////////////////////////////////////////////////////////////
diametre_bouton_arcade = 30;
rayon_bouton_arcade = diametre_bouton_arcade / 2;
diametre_trou_bouton_arcade = 20; // TODO: à valider !
rayon_trou_bouton_arcade = diametre_trou_bouton_arcade / 2;
hauteur_bague_bouton_arcade = 3;
hauteur_bouton_arcade = 1;
diametre_push_bouton_arcade = diametre_bouton_arcade - 4;
profondeur_interne_bouton_arcade = 20; // TODO: à valider !


// bouton EC11
//////////////
diametre_bouton_ec11 = 14.4;
hauteur_bouton_ec11 = 13.1;
epaisseur_trait_ec11 = 1;
trou_axe_ec11 = 7;
espace_platine_bouton = 10.7;
hauteur_platine_ec11 = 33.4;
largeur_platine_ec11 = 27.5;
epaisseur_platine_ec11 = 1.3;
trou_fixation_ec11 = 3;
trou_marge_ec11 = 2.40;


// haut-parleur HP8R
////////////////////
HP8R_epaisseur_totale = 16.25;
HP8R_largeur = 36.24;
HP8R_hauteur = 75;
HP8R_epaisseur_tole = 1.63;
HP8R_hauteur_caisson = 71;
//HP8R_epaisseur_caisson = 16.25 - HP8R_epaisseur_tole;
HP8R_decalage_hauteur_trou = 12.3;
HP8R_largeur_trou = 27.1;
HP8R_hauteur_trou = 38.3;
HP8R_epaisseur_trou = HP8R_epaisseur_totale - 2;
HP8R_diametre_creuse_coins = 10;
HP8R_diametre_creuse_fixation = 3;
HP8R_marge_creuse_fixation = 1.6 + padding_percage;


// Embase alimentation
//////////////////////
embase_decallage = 3.3;
embase_externe_largeur = 8.95;
embase_externe_hauteur = 10.7;
embase_externe_profondeur = 3.5;
embase_externe_marge_trou = 3.3;
embase_externe_diametre_trou = 6.4;
embase_externe_diametre_pin = 1.6;
embase_interne_profondeur = 10.6;
embase_platine_profondeur = 25.5;
embase_platine_decallage = 5.6;
embase_platine_largeur = 25.9;
embase_platine_epaisseur = 1.6;
embase_marge_fixation = 1.5;
embase_diametre_fixation = 3;


// led type1 : LED étanche avec électronique carré
////////////
profondeur_chapeau_led = 7.5;
diametre_trou_led = 7.9; // TODO: à valider !
diametre_interne_led = 13;
profondeur_interne_led = 7;
boitier_largeur_led = 22.5;
boitier_hauteur_led = 18.5;
boitier_epaisseur_led = 8;


// cadrillage autour des LEDs
/////////////////////////////
profondeur_separateur_led = 15; // TODO: à valider !


// pour stocker les cables et l'électronique
////////////////////////////////////////////
espace_vide_milieu = 50; // TODO: à valider !   40 => conflit entre bouton et led en haut !!!


// le mur Star Wars fenetré
///////////////////////////
epaisseur_tole_mur = 4;
taille_fenetre = diametre_bouton_arcade; // valeur à fixer si bouton plus petit, ici je m'adapte à cette taille de bouton
ecart_entre_fenetre = 5; // au jugé ;)
marge_mur = 15; // pour aérer le tour   10 => haut parleur touche led et conflit bouton dans le coin !

// on peut maintenant calculer la surface du jeu !
largeur_mur = marge_mur + (nombre_colonnes * taille_fenetre) + ((nombre_colonnes - 1) * ecart_entre_fenetre) + marge_mur;
hauteur_mur = marge_mur + (nombre_lignes * taille_fenetre) + ((nombre_lignes - 1) * ecart_entre_fenetre) + marge_mur;
echo(str("** PLAQUE MUR (x2) : ", largeur_mur , " x ", hauteur_mur, " x ", epaisseur_tole_mur));


// la grille de LEDS
////////////////////
epaisseur_tole_grille_led = 4;
largeur_rainure_grille_led = epaisseur_tole_grille_led + padding_rainure;
profondeur_rainure_grille_led = profondeur_rainure; // moins que epaisseur_tole_grille_led !!!
echo(str("** PLAQUE GRILLE LED (x2) : ", largeur_mur , " x ", hauteur_mur, " x ", epaisseur_tole_grille_led));


// le plexi blanc derrière le mur, pour faire les fenêtres
//////////////////////////////////////////////////////////
epaisseur_plexi_blanc = 2;
transparence_plexi = 1;
echo(str("** PLAQUE PLEXI BLANC (x2) : ", largeur_mur , " x ", hauteur_mur, " x ", epaisseur_plexi_blanc));


// calcul de l'épaisseur complète du jeu
epaisseur_jeu = espace_vide_milieu + 2 * epaisseur_tole_mur + 2 * epaisseur_plexi_blanc + 2 * epaisseur_tole_grille_led + 2 * profondeur_separateur_led;


// la plaque du dessus avec les boutons de choix de colonne
///////////////////////////////////////////////////////////
epaisseur_tole_dessus = 4; // ce "chapeau" sera rainurée pour tenir les plaques !
debord_rainure = 5; // qui dépasse de devant et derrière 
profondeur_dessus = epaisseur_jeu + 2 * debord_rainure;
marge_largeur_dessus = (largeur_mur - (nombre_colonnes * diametre_bouton_arcade) - ((nombre_colonnes - 1) * ecart_entre_fenetre)) / 2;
largeur_rainure_mur_plexi = epaisseur_tole_mur + epaisseur_plexi_blanc + padding_rainure;
profondeur_rainure_mur_plexi = profondeur_rainure; // moins que epaisseur_tole_dessus !!!
echo(str("** PLAQUE DESSUS : ", largeur_mur , " x ", profondeur_dessus, " x ", epaisseur_tole_dessus));


// la plaque de dessous
///////////////////////
epaisseur_tole_dessous = 4; // ce socle sera rainurée pour tenir les plaques !
dessous_debord_rainure = 50;
profondeur_dessous = epaisseur_jeu + 2 * dessous_debord_rainure;
echo(str("** PLAQUE SOCLE : ", largeur_mur , " x ", profondeur_dessous, " x ", epaisseur_tole_dessous));


hauteur_cote = epaisseur_tole_dessous + hauteur_mur + epaisseur_tole_dessus - 2 * profondeur_rainure_grille_led;
largeur_cote = profondeur_dessus;


// côté gauche
//////////////
epaisseur_tole_gauche = 4;
echo(str("** PLAQUE COTE GAUCHE : ", largeur_cote , " x ", hauteur_cote, " x ", epaisseur_tole_gauche));


// côté droit
/////////////
epaisseur_tole_droit = 4;
position_ec11 = epaisseur_tole_dessous + embase_platine_epaisseur + embase_externe_hauteur + 15 + hauteur_platine_ec11 / 2; // 15 = taille d'une pinouille arduino connectée sur l'embase
echo(str("** PLAQUE COTE DROIT : ", largeur_cote , " x ", hauteur_cote, " x ", epaisseur_tole_droit));

position_haut_parleur_HP8R = position_ec11 + hauteur_platine_ec11 / 2 + 5;
