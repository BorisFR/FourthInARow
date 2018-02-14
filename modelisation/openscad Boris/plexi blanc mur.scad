include <parametre.scad>

// aucun intérêt à exporter ça !
plexi_blanc();

// plexi blanc
module plexi_blanc() {
    color([1, 1, 1], transparence_plexi) cube(size=[largeur_mur, hauteur_mur, epaisseur_plexi_blanc]);
}
