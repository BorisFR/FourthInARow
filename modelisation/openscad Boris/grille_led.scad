include <parametre.scad>
use <led_rgb_type1.scad>

// pour exporter en .dxf
projection(cut = false)
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
	if(show_accessoires == 1) {
		for(colonne = [1 : nombre_colonnes]) {
			for(ligne = [1 : nombre_lignes]) {
				translate([marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre) + (taille_fenetre - 0) / 2, 
						marge_mur + (ligne - 1) * (taille_fenetre + ecart_entre_fenetre) + (taille_fenetre - 0) / 2, 0])
					led_rgb_type1();
			}
		}
	}
}

module pose_trous_led() {
    for(colonne = [1 : nombre_colonnes]) {
        for(ligne = [1 : nombre_lignes]) {
			// pour chaque led, on se positionne au coin de la fenetre
            translate([marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre) + taille_fenetre / 2, 
					marge_mur + (ligne - 1) * (taille_fenetre + ecart_entre_fenetre) + taille_fenetre / 2, 0])
                // et on fait le trou pour la led
				led_rgb_type1_trou(epaisseur_tole_grille_led);
        }
    }
}
