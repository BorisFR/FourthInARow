include <parametre.scad>
use <bouton_arcade.scad>
use <embase.scad>

use <logo_club_forme.scad>

// pour exporter en .dxf
//projection(cut = false) dessous();

translate([0, -profondeur_dessous / 2, 0])
	dessous();

module dessous() {
    color("Silver") {
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


			// fixation de la platine de l'embase
			rotate([90, 180, 270])
				translate([profondeur_dessous / 2 - embase_platine_largeur / 2, 0, -1*padding_percage -largeur_mur - embase_externe_profondeur + epaisseur_tole_droit])
				embase_fixation(); 
				
			// Dessins sur la plaque
			
			translate([0, 0, 0]) {
			
				translate([largeur_mur / 2, profondeur_dessous / 2 + 5, epaisseur_tole_dessous - 2 - 0])
					rotate([180, 0, 0])
						linear_extrude(height = 2 + padding_percage)
							text("Design by Boris, 2018", valign = "center", halign = "center", size = 6, font = "Aurabesh");
			
				translate([largeur_mur / 2, profondeur_dessous / 2 - 5, epaisseur_tole_dessous - 2 - 0])
					rotate([180, 0, 0])
						linear_extrude(height = 2 + padding_percage)
							text("Original idea by SuTaiBot", valign = "center", halign = "center", size = 6, font = "Aurabesh");

			
				translate([10, profondeur_dessous - 10, epaisseur_tole_dessous - 2 - 0])
					rotate([180, 0, 0])
						linear_extrude(height = 2 + padding_percage)
							text("Player 1", valign = "bottom", halign = "left", size = 10, font = "Aurabesh");

			
				translate([largeur_mur - 10, 10, epaisseur_tole_dessous - 2 - 0])
					rotate([0, 180, 0])
						linear_extrude(height = 2 + padding_percage)
							text("Player 2", valign = "bottom", halign = "left", size = 10, font = "Aurabesh");

				if(show_logo_r2builders == 1) {
					
					translate([20, 20, 2 - padding_percage])
						rotate([0, 180, 0])
							scale([0.2, 0.2, 1])
								logo_club_forme(2 + padding_percage);

					translate([largeur_mur - 20, profondeur_dessous - 20, 2 - padding_percage])
						rotate([180, 0, 0])
							scale([0.2, 0.2, 1])
								logo_club_forme(2 + padding_percage);
				}
			
			}

        }
    }

			// fixation de la platine de l'embase
			/*rotate([90, 180, 270])
				translate([profondeur_dessous / 2 - embase_platine_largeur / 2, 0, -1*padding_percage -largeur_mur - embase_externe_profondeur + epaisseur_tole_droit])
				embase(); */
}
