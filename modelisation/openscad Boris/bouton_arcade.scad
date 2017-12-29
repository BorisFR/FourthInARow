include <parametre.scad>

module trou_bouton_arcade(epaisseur) {
    translate([0, 0, -1]) {
        translate([diametre_trou_bouton_arcade / 2, diametre_trou_bouton_arcade / 2, 0]) {
            cylinder(epaisseur + padding_percage, d=diametre_trou_bouton_arcade, $fn=resolution);
        }
    }
}