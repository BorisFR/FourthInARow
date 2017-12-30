/* pour le rendu openscad */

// pour la finesse de rendu
// plus c'est élevé, mieux c'est... mais ça prend plus de temps et de ressource
resolution = 50;

// pour enlever de la matière des objets dans openscad et être certain qu'il ne reste pas un bout de face
difference_objet_marge = 20;





/* pour le design du jeu  */

// tout est en millimetre !!!!

// configuration globale
////////////////////////

// quand on perce et que l'on va insérer quelque chose dedans...
// il faut un peu de vide en plus ;)
padding_percage = 0.5;

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


// cadrillage autour des LEDs
/////////////////////////////
profondeur_separateur_led = 15; // TODO: à valider !


// la grille de LEDS
////////////////////
epaisseur_tole_grille_led = 3;
diametre_trou_led = 10; // TODO: à valider !
largeur_rainure_grille_led = epaisseur_tole_grille_led + padding_rainure;
profondeur_rainure_grille_led = profondeur_rainure; // moins que epaisseur_tole_grille_led !!!


// pour stocker les cables et l'électronique
////////////////////////////////////////////
espace_vide_milieu = 40; // TODO: à valider !


// le plexi blanc derrière le mur, pour faire les fenêtres
//////////////////////////////////////////////////////////
epaisseur_plexi_blanc = 2;
transparence_plexi = 1;


// le mur Star Wars fenetré
///////////////////////////
epaisseur_tole_mur = 2;
taille_fenetre = diametre_bouton_arcade; // valeur à fixer si bouton plus petit, ici je m'adapte à cette taille de bouton
ecart_entre_fenetre = 5; // au jugé ;)
marge_mur = 10; // pour aérer le tour

// on peut maintenant calculer la surface du jeu !
largeur_mur = marge_mur + (nombre_colonnes * taille_fenetre) + ((nombre_colonnes - 1) * ecart_entre_fenetre) + marge_mur;
echo("largeur_mur=", largeur_mur);
hauteur_mur = marge_mur + (nombre_lignes * taille_fenetre) + ((nombre_lignes - 1) * ecart_entre_fenetre) + marge_mur;
echo("hauteur_mur=", hauteur_mur);

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
echo("profondeur_dessus=", profondeur_dessus);


// la plaque de dessous
///////////////////////
epaisseur_tole_dessous = 4; // ce socle sera rainurée pour tenir les plaques !
dessous_debord_rainure = 50;
profondeur_dessous = epaisseur_jeu + 2 * dessous_debord_rainure;
echo("profondeur_dessous=", profondeur_dessous);


hauteur_cote = epaisseur_tole_dessous + hauteur_mur + epaisseur_tole_dessus - 2 * profondeur_rainure_grille_led;
largeur_cote = profondeur_dessus;


// côté gauche
//////////////
epaisseur_tole_gauche = 2;


// côté droit
/////////////
epaisseur_tole_droit = 2;
