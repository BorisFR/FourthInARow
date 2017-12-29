include <parametre.scad>

// pour exporter en .dxf
//projection(cut = false)
cote_gauche();

// plaque mur déco
module cote_gauche() {
    color([0, 0, 0]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_cote, hauteur_cote, epaisseur_tole_gauche]);
		}
	}
}