// pour la finesse de rendu
// plus c'est élevé, mieux c'est... mais ça prend plus de temps et de ressource
resolution = 50;

// pour enlever de la matière des objets et être certain qu'il ne reste pas un bout de face
difference_objet_marge = 20;

// quand on perce et que l'on va insérer quelque chose dedans...
// il faut un peu de vide en plus ;)
padding_percage = 1;

// espace supplémentaire pour la largeur de rainure
padding_rainure = 1;

// profondeur standard pour une rainure
profondeur_rainure = 2;

// définition de base du jeu
nombre_colonnes = 7;
nombre_lignes = 6;

// les boutons de sélection de colonne et du nombre de joueurs
//////////////////////////////////////////////////////////////
diametre_bouton_arcade = 30;
rayon_bouton_arcade = diametre_bouton_arcade / 2;
diametre_trou_bouton_arcade = 20;
rayon_trou_bouton_arcade = diametre_trou_bouton_arcade / 2;


// cadrillage autour des LEDs
/////////////////////////////
profondeur_separateur_led = 15;


// la grille de LEDS
////////////////////
epaisseur_tole_grille_led = 3;
diametre_trou_led = 10;
largeur_rainure_grille_led = epaisseur_tole_grille_led + padding_rainure;
profondeur_rainure_grille_led = profondeur_rainure; // moins que epaisseur_tole_dessus !!!


// pour stocker les cables et l'électronique
////////////////////////////////////////////
espace_vide_milieu = 40; 


// le plexi blanc derrière le mur, pour faire les fenêtres
//////////////////////////////////////////////////////////
epaisseur_plexi_blanc = 2;


// le mur Star Wars fenetré
///////////////////////////
epaisseur_tole_mur = 2;
taille_fenetre = diametre_bouton_arcade; // valeur à fixer si bouton plus petit;
ecart_entre_fenetre = 5; // au jugé ;)
marge_mur = 10; // pour aérer le tout

// on peut maintenant calculer la surface du jeu !
largeur_mur = marge_mur + (nombre_colonnes * taille_fenetre) + ((nombre_colonnes - 1) * ecart_entre_fenetre) + marge_mur;
echo("largeur_mur=", largeur_mur);
hauteur_mur = marge_mur + (nombre_lignes * taille_fenetre) + ((nombre_lignes - 1) * ecart_entre_fenetre) + marge_mur;
echo("hauteur_mur=", hauteur_mur);

// calcul de l'épaisseur complete du jeu
epaisseur_jeu = espace_vide_milieu + 2 * epaisseur_tole_mur + 2 * epaisseur_plexi_blanc + 2 * epaisseur_tole_grille_led + 2 * profondeur_separateur_led;

// la plaque du dessus avec les boutons de choix de colonne
///////////////////////////////////////////////////////////
epaisseur_tole_dessus = 4;
debord_rainure = 5; // qui dépasse de devant et derrière 
profondeur_dessus = epaisseur_jeu + 2 * debord_rainure;
marge_largeur_dessus = (largeur_mur - (nombre_colonnes * diametre_bouton_arcade) - ((nombre_colonnes - 1) * ecart_entre_fenetre)) / 2;
largeur_rainure_mur_plexi = epaisseur_tole_mur + epaisseur_plexi_blanc + padding_rainure;
profondeur_rainure_mur_plexi = profondeur_rainure;

// la plaque de dessous
///////////////////////
epaisseur_tole_dessous = 4;
dessous_debord_rainure = 100;
profondeur_dessous = epaisseur_jeu + 2 * dessous_debord_rainure;

