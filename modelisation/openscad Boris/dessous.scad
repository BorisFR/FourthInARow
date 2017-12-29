include <parametre.scad>
use <bouton_arcade.scad>

dessous();

module dessous() {
    color([0, 0, 0]) {
        difference() {
            cube(size=[largeur_mur, profondeur_dessous, epaisseur_tole_dessous]);
            translate([-1, deport_glissiere_dessous, -profondeur_glissiere_dessous])
                cube(size=[largeur_mur + 2, glissiere_mur_plexi, profondeur_glissiere_dessous + 2]);
            translate([-1, profondeur_dessous - deport_glissiere_dessous - glissiere_mur_plexi, -profondeur_glissiere_dessous])
                cube(size=[largeur_mur + 2, glissiere_mur_plexi, profondeur_glissiere_dessous + 2]);
        }
    }
}
