include <parametre.scad>

bouton_arcade();

module bouton_arcade() {
	union() {
		cylinder(hauteur_bague_bouton_arcade, d=diametre_bouton_arcade, $fn=resolution);
		translate([0, 0, -hauteur_bouton_arcade])
			cylinder(hauteur_bouton_arcade, d=diametre_push_bouton_arcade, $fn=resolution);
	}
}

module trou_bouton_arcade(epaisseur) {
	translate([0, 0, -difference_objet_marge / 2])
		cylinder(epaisseur + difference_objet_marge, d=diametre_trou_bouton_arcade + padding_percage, $fn=resolution);
}