include <parametre.scad>

ec11();

module ec11() {
		union() {
			// le bouton
			translate([0, 0, espace_platine_bouton])
				color([0, 0, 0]) cylinder(hauteur_bouton_ec11, d=diametre_bouton_ec11, $fn=10);
			// son trait blanc
			rotate([0, 0, 90])
				translate([diametre_bouton_ec11 / 3, - epaisseur_trait_ec11 / 2, espace_platine_bouton + hauteur_bouton_ec11 / 5 + 0.01])
					color([1, 1, 1]) cube(size=[diametre_bouton_ec11 / 6 + 0.01, epaisseur_trait_ec11, hauteur_bouton_ec11 * 4 / 5]);
			// l'axe
			color([0.8, 0.8, 0.8]) cylinder(espace_platine_bouton, d=trou_axe_ec11, $fn=resolution);
			// la platine
			difference() {
				color([1, 1, 1]) cube(size=[largeur_platine_ec11, hauteur_platine_ec11, epaisseur_platine_ec11], center = true);

				hauteur = trou_fixation_ec11 + 2 * trou_marge_ec11;
				largeur = largeur_platine_ec11 / 2 - trou_marge_ec11 - trou_fixation_ec11 / 2;
				
				// les 4 coins de la platine
				translate([largeur + difference_objet_marge / 2, hauteur_platine_ec11 / 2 - hauteur / 2 + difference_objet_marge / 2, 0])
					cube(size=[largeur + difference_objet_marge, hauteur + difference_objet_marge, epaisseur_platine_ec11 + difference_objet_marge], center = true);

				translate([-(largeur + difference_objet_marge / 2), hauteur_platine_ec11 / 2 - hauteur / 2 + difference_objet_marge / 2, 0])
					cube(size=[largeur + difference_objet_marge, hauteur + difference_objet_marge, epaisseur_platine_ec11 + difference_objet_marge], center = true);

				translate([largeur + difference_objet_marge / 2, -(hauteur_platine_ec11 / 2 - hauteur / 2 + difference_objet_marge / 2), 0])
					cube(size=[largeur + difference_objet_marge, hauteur + difference_objet_marge, epaisseur_platine_ec11 + difference_objet_marge], center = true);

				translate([-(largeur + difference_objet_marge / 2), -(hauteur_platine_ec11 / 2 - hauteur / 2 + difference_objet_marge / 2), 0])
					cube(size=[largeur + difference_objet_marge, hauteur + difference_objet_marge, epaisseur_platine_ec11 + difference_objet_marge], center = true);
				
				trous_ec11(epaisseur_platine_ec11);
			}
		}
}

module trous_ec11(epaisseur) {
	translate([0, 0, -difference_objet_marge / 2]) {
		// trou pour l'axe
		cylinder(epaisseur + difference_objet_marge, d=trou_axe_ec11 + padding_percage, $fn=resolution);
		// trou de fixation
		translate([0, hauteur_platine_ec11 / 2 - trou_fixation_ec11 / 2 - trou_marge_ec11, 0])
			cylinder(epaisseur + difference_objet_marge, d=trou_fixation_ec11 + padding_percage, $fn=resolution);
		translate([0, -(hauteur_platine_ec11 / 2 - trou_fixation_ec11 / 2 - trou_marge_ec11), 0])
			cylinder(epaisseur + difference_objet_marge, d=trou_fixation_ec11 + padding_percage, $fn=resolution);
	}
}