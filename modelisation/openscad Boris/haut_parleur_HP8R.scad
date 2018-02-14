include <parametre.scad>

// pour exporter en .dxf
//projection(cut = false) 
haut_parleur_HP8R();

module haut_parleur_HP8R() {
	union() {
		difference() {
			color([0.7, 0.7, 0.7])
			union() {
				// la plaque de fixation
				cube(size=[HP8R_largeur, HP8R_hauteur, HP8R_epaisseur_tole]);
				// le caisson
				translate([0, (HP8R_hauteur - HP8R_hauteur_caisson) / 2, 0])
					cube(size=[HP8R_largeur, HP8R_hauteur_caisson, HP8R_epaisseur_totale]);
			}
			
			// on fait des trous :)

			// les 4 coins
			translate([HP8R_diametre_creuse_coins / 4, HP8R_diametre_creuse_coins / 4, HP8R_epaisseur_tole])
				cylinder(HP8R_epaisseur_totale + difference_objet_marge, d=HP8R_diametre_creuse_coins, $fn=resolution);
			translate([HP8R_largeur - HP8R_diametre_creuse_coins / 2 + HP8R_diametre_creuse_coins / 4, HP8R_diametre_creuse_coins / 4, HP8R_epaisseur_tole])
				cylinder(HP8R_epaisseur_totale + difference_objet_marge, d=HP8R_diametre_creuse_coins, $fn=resolution);
			translate([HP8R_diametre_creuse_coins / 4, HP8R_hauteur - HP8R_diametre_creuse_coins / 2 + HP8R_diametre_creuse_coins / 4, HP8R_epaisseur_tole])
				cylinder(HP8R_epaisseur_totale + difference_objet_marge, d=HP8R_diametre_creuse_coins, $fn=resolution);
			translate([HP8R_largeur - HP8R_diametre_creuse_coins / 2 + HP8R_diametre_creuse_coins / 4, HP8R_hauteur - HP8R_diametre_creuse_coins / 2 + HP8R_diametre_creuse_coins / 4, HP8R_epaisseur_tole])
				cylinder(HP8R_epaisseur_totale + difference_objet_marge, d=HP8R_diametre_creuse_coins, $fn=resolution);

			haut_parleur_HP8R_trous();
		}
		
		// on ajoute la membrane de l'enceinte
		haut_parleur_HP8R_membrane();
	}
}

module haut_parleur_HP8R_membrane() {
	color([0.5, 0.5, 0.5])
		translate([HP8R_largeur / 2 - HP8R_largeur_trou / 2, HP8R_decalage_hauteur_trou, 2]) 
			cube(size=[HP8R_largeur_trou, HP8R_largeur_trou * 2, 2]);
}

module haut_parleur_HP8R_trouHP() {
	union() {
		// arrondi HP
		translate([HP8R_largeur / 2, HP8R_decalage_hauteur_trou + HP8R_largeur_trou / 2, -difference_objet_marge])
			cylinder(HP8R_epaisseur_trou + difference_objet_marge, d=HP8R_largeur_trou, $fn=resolution);
		translate([HP8R_largeur / 2, HP8R_decalage_hauteur_trou + HP8R_hauteur_trou - HP8R_largeur_trou / 2, -difference_objet_marge])
			cylinder(HP8R_epaisseur_trou + difference_objet_marge, d=HP8R_largeur_trou, $fn=resolution);

		// le trou HP
		translate([(HP8R_largeur - HP8R_largeur_trou) / 2, HP8R_decalage_hauteur_trou + HP8R_largeur_trou / 2, -difference_objet_marge])
				cube(size=[HP8R_largeur_trou, HP8R_hauteur_trou - HP8R_largeur_trou, HP8R_epaisseur_trou + difference_objet_marge]);
	}
}

module haut_parleur_HP8R_trousFixation() {
	// les 4 trous pour fixation
	translate([HP8R_marge_creuse_fixation, HP8R_marge_creuse_fixation, -difference_objet_marge/2])
		cylinder(HP8R_epaisseur_tole + difference_objet_marge, d=HP8R_diametre_creuse_fixation, $fn=resolution);
	translate([HP8R_largeur - HP8R_marge_creuse_fixation, HP8R_marge_creuse_fixation, -difference_objet_marge/2])
		cylinder(HP8R_epaisseur_tole + difference_objet_marge, d=HP8R_diametre_creuse_fixation, $fn=resolution);
	translate([HP8R_marge_creuse_fixation, HP8R_hauteur - HP8R_marge_creuse_fixation, -difference_objet_marge/2])
		cylinder(HP8R_epaisseur_tole + difference_objet_marge, d=HP8R_diametre_creuse_fixation, $fn=resolution);
	translate([HP8R_largeur - HP8R_marge_creuse_fixation, HP8R_hauteur - HP8R_marge_creuse_fixation, -difference_objet_marge/2])
		cylinder(HP8R_epaisseur_tole + difference_objet_marge, d=HP8R_diametre_creuse_fixation, $fn=resolution);
}

module haut_parleur_HP8R_trous() {
	haut_parleur_HP8R_trouHP();
	haut_parleur_HP8R_trousFixation();
}