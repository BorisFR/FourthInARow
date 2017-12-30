include <parametre.scad>

led_rgb_type1();
//#led_rgb_type1_trou(10);

module led_rgb_type1() {
	
	translate([-boitier_largeur_led / 2, - boitier_hauteur_led / 2, -boitier_epaisseur_led - profondeur_interne_led])
		union() {
			// boitier électronique
			color([1, 1, 1])
				cube(size=[boitier_largeur_led, boitier_hauteur_led, boitier_epaisseur_led]);
			
			// le support interne
			color([1, 1, 1])
				translate([boitier_largeur_led / 2, boitier_hauteur_led / 2, boitier_epaisseur_led])
					cylinder(profondeur_interne_led, d=diametre_interne_led, $fn=resolution);
			
			// la led
			color([rands(0,1,1)[0], rands(0,1,1)[0], rands(0,1,1)[0]])
				translate([boitier_largeur_led / 2, boitier_hauteur_led / 2, boitier_epaisseur_led + profondeur_interne_led])
					union() {
						// la grosse partie
						cylinder(profondeur_chapeau_led - diametre_trou_led / 2, d=diametre_trou_led, $fn=resolution);
						// le bout rond
						translate([0, 0, diametre_trou_led / 2])
						sphere(d=diametre_trou_led, $fn=resolution);
					}
		}
	
}

module led_rgb_type1_trou(epaisseur) {
	// on descend pour que le percage dépasse
    translate([0, 0, -difference_objet_marge / 2]) {
		// on fait le trou  qui dépasse donc de chaque côté pour bien percer la dalle
		cylinder(epaisseur + difference_objet_marge, d=diametre_trou_led + padding_percage, $fn=resolution);
    }
}