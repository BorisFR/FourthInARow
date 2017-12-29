include <parametre.scad>
use <mur.scad>
use <plexi blanc mur.scad>
use <grille_led.scad>
use <dessus.scad>
use <dessous.scad>

// pour se mettre sur le plancher :)
translate([0, epaisseur_tole_dessous, 0]) {
	
	// on pose le dessous
	rotate([90, 0, 0])
		translate([0, 0, - 0])
			dessous();

	// et on vient y mettre tous les éléments
	translate([0, 0, (profondeur_dessous - profondeur_dessus) / 2]) {

		// chaque élément vient dans la rainure prévue pour
		
		// mur du bas
		translate([0, -profondeur_rainure, profondeur_dessus / 2 - epaisseur_tole_mur - espace_vide_milieu / 2 - epaisseur_tole_grille_led - profondeur_separateur_led - epaisseur_plexi_blanc - (largeur_rainure_mur_plexi - epaisseur_tole_mur - epaisseur_plexi_blanc) / 2])
			mur();
		
		// mur du haut
		translate([0, -profondeur_rainure, profondeur_dessus / 2 + espace_vide_milieu / 2 + epaisseur_tole_grille_led + profondeur_separateur_led + epaisseur_plexi_blanc + (largeur_rainure_mur_plexi - epaisseur_tole_mur - epaisseur_plexi_blanc) / 2])
			mur();

		// plexi du bas
		translate([0, -profondeur_rainure, profondeur_dessus / 2 - epaisseur_plexi_blanc - espace_vide_milieu / 2 - epaisseur_tole_grille_led - profondeur_separateur_led - (largeur_rainure_mur_plexi - epaisseur_tole_mur - epaisseur_plexi_blanc) / 2])
			plexi_blanc();
		
		// plexi du haut
		translate([0, -profondeur_rainure, profondeur_dessus / 2 + espace_vide_milieu / 2 + epaisseur_tole_grille_led + profondeur_separateur_led + (largeur_rainure_mur_plexi - epaisseur_tole_mur - epaisseur_plexi_blanc) / 2])
			plexi_blanc();


		// plaque de LEDs du bas
		translate([0, -profondeur_rainure, profondeur_dessus / 2 - epaisseur_tole_grille_led - espace_vide_milieu / 2 - (largeur_rainure_grille_led - epaisseur_tole_grille_led) / 2])
			grille_led(); 

		// plaque de LEDs du haut
		translate([0, -profondeur_rainure, profondeur_dessus / 2 + espace_vide_milieu / 2  + (largeur_rainure_grille_led - epaisseur_tole_grille_led) / 2])
			grille_led();


		// et on ferme avec la plaque du dessus
		rotate([90, 0, 0])
			translate([0, 0, -(hauteur_mur + epaisseur_tole_dessus) + 2 * profondeur_rainure ])
				dessus();
				
		/*
		// DEBUG : test pour visu centrage des trous pour les LEDs
		translate([0, 0, 1 +  profondeur_dessus / 2 - epaisseur_tole_mur - espace_vide_milieu / 2 - epaisseur_tole_grille_led - profondeur_separateur_led - epaisseur_plexi_blanc - (largeur_rainure_mur_plexi - epaisseur_tole_mur - epaisseur_plexi_blanc) / 2])
			grille_led();
		*/
	}

}