include <parametre.scad>

embase();

module embase() {
	
	// embase en elle-même
	translate([embase_decallage, embase_platine_epaisseur, 0]) union() {
		difference() {
			color([0, 0, 0]) union() {
				// connecteur externe
				cube(size=[embase_externe_largeur, embase_externe_hauteur, embase_externe_profondeur]);
				// partie basse intérieure
				translate([0, 0, embase_externe_profondeur])
					cube(size=[embase_externe_largeur, embase_externe_hauteur / 2, embase_interne_profondeur]);
				// partie supérieure intérieure
				translate([embase_externe_largeur / 2, embase_externe_hauteur / 2, embase_externe_profondeur])
					cylinder(embase_interne_profondeur, d=embase_externe_largeur, $fn=resolution);
			}
			
			// trou du connecteur
			translate([embase_externe_largeur / 2, embase_externe_marge_trou + embase_externe_diametre_trou / 2, - difference_objet_marge])
				cylinder(embase_interne_profondeur + difference_objet_marge, d=embase_externe_diametre_trou, $fn=resolution);
		}
		// pinouille de masse
		color([1, 1, 1]) translate([embase_externe_largeur / 2, embase_externe_marge_trou + embase_externe_diametre_trou / 2, 1])
			cylinder(embase_interne_profondeur, d=embase_externe_diametre_pin, $fn=resolution);

	}
	
	difference() {
		// platine
		translate([0, 0, embase_platine_decallage])
			cube(size=[embase_platine_largeur, embase_platine_epaisseur, embase_platine_profondeur]);

		// trou de la platine
		embase_fixation();
	}
}

module embase_trou() {
	translate([embase_decallage - padding_percage, embase_platine_epaisseur - padding_percage, -difference_objet_marge])
		// connecteur externe
		cube(size=[embase_externe_largeur + 2 * padding_percage, embase_externe_hauteur + 2 * padding_percage, embase_externe_profondeur + difference_objet_marge]);
	embase_fixation();
}

module embase_fixation() {
	rotate([90, 0, 0])
		translate([embase_platine_largeur / 2 - padding_percage, 
				embase_platine_decallage + embase_platine_profondeur - embase_diametre_fixation / 2 - embase_marge_fixation, 
				-embase_platine_epaisseur - difference_objet_marge / 2])
			// fixation platine
			cylinder(embase_platine_epaisseur + difference_objet_marge, d=embase_diametre_fixation + padding_percage, $fn=resolution);
}