include <parametre.scad>

module bouton_arcade() {
	cylinder(3, d=diametre_bouton_arcade, $fn=resolution);
}

module trou_bouton_arcade(epaisseur) {
	cylinder(epaisseur + padding_percage, d=diametre_trou_bouton_arcade, $fn=resolution);
}