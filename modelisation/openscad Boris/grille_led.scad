include <parametre.scad>

// pour exporter en .dxf
//projection(cut = false)
grille_led();

// plaque mur déco
module grille_led() {
    color([0, 1, 1]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_mur, hauteur_mur, epaisseur_tole_grille_led]);
			// que l'on perce
            pose_trous_led();
        }
    }
}

module pose_trous_led() {
    for(colonne = [1 : nombre_colonnes]) {
        for(ligne = [1 : nombre_lignes]) {
			// pour chaque led, on se positionne au coin de la fenetre
            translate([marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre) + (taille_fenetre - diametre_trou_led) / 2, 
					marge_mur + (ligne - 1) * (taille_fenetre + ecart_entre_fenetre) + (taille_fenetre - diametre_trou_led) / 2, 0]) {
                // et on fait le trou pour la led
				trou_led();
			}

        }
    }
}

module trou_led() {
	// on descend pour que le percage dépasse
    translate([0, 0, -difference_objet_marge / 2]) {
		// on se met au milieu pour percer
        translate([diametre_trou_led/2, diametre_trou_led/2, 0]) {
			// on fait le trou  qui dépasse donc de chaque côté pour bien percer la dalle
            cylinder(epaisseur_tole_grille_led + difference_objet_marge, d=diametre_trou_led + padding_percage, $fn=resolution);
        }
    }
}

