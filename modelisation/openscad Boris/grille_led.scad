include <parametre.scad>
use <led_rgb_type1.scad>
use <spacer.scad>

// pour exporter en .dxf
if(show_mode_projection == 1)
	projection(cut = false) grille_led();

if(show_mode_projection == 0)
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

        for(ligne = [1 : nombre_lignes + 1]) {
            rotate([90, 0, 0])
                translate([0, epaisseur_tole_grille_led, 
                        -marge_mur - (ligne - 1) * (taille_fenetre + ecart_entre_fenetre) + decallage_separateur_led])
                    spacerHorizontal();
        }

        for(colonne = [1 : nombre_colonnes + 1]) {
            rotate([0, 90, 0])
                translate([-epaisseur_tole_grille_led, 0,
            marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre) - epaisseur_separateur_led])
                    spacerVertical();
        }

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
