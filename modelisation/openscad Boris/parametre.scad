// pour la finesse de rendu
// plus c'est élevé, mieux c'est... mais ça prend plus de temps et de ressource
resolution = 50;


// définition de base du jeu
nombre_colonnes = 7;
nombre_lignes = 6;

// pour stocker les cables et l'électronique
espace_vide_milieu = 40; 

// cadrillage autour des LEDs
hauteur_separateur_led = 15;


// les boutons de sélection de colonne et du nombre de joueurs
diametre_bouton_arcade = 30;
rayon_bouton_arcade = diametre_bouton_arcade / 2;
diametre_trou_bouton_arcade = 20;
rayon_trou_bouton_arcade = diametre_trou_bouton_arcade / 2;

// le mur Star Wars fenetré
epaisseur_tole_mur = 2;
marge_mur = 10; // pour aérer le tout
taille_fenetre = diametre_bouton_arcade; // valeur à fixer si bouton plus petit;
ecart_entre_fenetre = 5; // au jugé ;)

largeur_mur = marge_mur + (nombre_colonnes * taille_fenetre) + ((nombre_colonnes - 1) * ecart_entre_fenetre) + marge_mur;
echo("largeur_mur=", largeur_mur);
hauteur_mur = marge_mur + (nombre_lignes * taille_fenetre) + ((nombre_lignes - 1) * ecart_entre_fenetre) + marge_mur;
echo("hauteur_mur=", hauteur_mur);

// le plexi blanc derrière le mur, pour faire les fenêtres
epaisseur_plexi_blanc = 2;

// calcul de l'épaisseur complete du jeu
epaisseur_jeu = espace_vide_milieu + 2 * epaisseur_tole_mur + 2 * epaisseur_plexi_blanc + 2 * hauteur_separateur_led;

// la plaque du dessus avec les boutons de choix de colonne
epaisseur_tole_dessus = 4;
glissiere_mur_plexi = epaisseur_tole_mur + epaisseur_plexi_blanc + 0.5;
deport_glissiere = 2;
profondeur_glissiere = 2;
debord_dessus = 2 * glissiere_mur_plexi + 2 * deport_glissiere;
profondeur_dessus = epaisseur_jeu + debord_dessus;
marge_profondeur_dessus = (profondeur_dessus - diametre_bouton_arcade) / 2;
echo("marge_profondeur_dessus=", marge_profondeur_dessus);
marge_largeur_dessus = (largeur_mur - (nombre_colonnes * diametre_bouton_arcade) - ((nombre_colonnes - 1) * ecart_entre_fenetre)) / 2;
echo("marge_largeur_dessus=", marge_largeur_dessus);

// la plaque de dessous
epaisseur_tole_dessous = 4;
debord_dessous = 2 * glissiere_mur_plexi + 2 * deport_glissiere;
deport_glissiere_dessous = 2;
profondeur_glissiere_dessous = 2;
profondeur_dessous = epaisseur_jeu + debord_dessous;


