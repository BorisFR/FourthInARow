include <parametre.scad>

plexi_blanc();

// plexi blanc
module plexi_blanc() {
    color([1, 1, 1]) cube(size=[largeur_mur, hauteur_mur, epaisseur_plexi_blanc]);
}
