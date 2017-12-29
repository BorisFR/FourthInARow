include <parametre.scad>
use <bouton_arcade.scad>

// pour exporter en .dxf
//projection(cut = false) dessous();

translate([0, -profondeur_dessous / 2, 0])
	dessous();

module dessous() {
    color([0, 0, 0]) {
        difference() {
            cube(size=[largeur_mur, profondeur_dessous, epaisseur_tole_dessous]);
			
						
			// rainure pour grille de LEDs
            translate([- difference_objet_marge / 2, 
					profondeur_dessous / 2 - largeur_rainure_grille_led - espace_vide_milieu / 2, 
					- difference_objet_marge])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_grille_led, profondeur_rainure_grille_led + difference_objet_marge]);

			// rainure pour grille de LEDs
            translate([- difference_objet_marge / 2, 
					profondeur_dessous / 2 + espace_vide_milieu / 2, 
					- difference_objet_marge])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_grille_led, profondeur_rainure_grille_led + difference_objet_marge]);

			
			// rainure pour plexi blanc et mur star wars
            translate([- difference_objet_marge / 2, 
					profondeur_dessous / 2 - largeur_rainure_mur_plexi - espace_vide_milieu / 2 - epaisseur_tole_grille_led - profondeur_separateur_led,
					-difference_objet_marge])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_mur_plexi, profondeur_rainure_mur_plexi + difference_objet_marge]);
				
			// rainure pour plexi blanc et mur star wars
            translate([- difference_objet_marge / 2, 
					profondeur_dessous / 2 + espace_vide_milieu / 2 + epaisseur_tole_grille_led + profondeur_separateur_led, 
					-difference_objet_marge])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_mur_plexi, profondeur_rainure_mur_plexi + difference_objet_marge]);
        }
    }
}
