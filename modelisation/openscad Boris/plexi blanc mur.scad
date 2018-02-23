include <parametre.scad>

if(show_mode_projection == 1)
	projection(cut = false)
plexi_blanc();

// plexi blanc
module plexi_blanc() {
    color([1, 1, 1], transparence_plexi) cube(size=[largeur_mur, hauteur_mur, epaisseur_plexi_blanc]);
}
