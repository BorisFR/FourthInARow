include <parametre.scad>
use <haut_parleur_HP8R.scad>

// pour exporter en .dxf
//projection(cut = false)
cote_gauche();

// plaque mur déco
module cote_gauche() {
    color([0, 0, 0]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_cote, hauteur_cote, epaisseur_tole_gauche]);
			
			// trou haut-parleur
			translate([(largeur_cote - HP8R_largeur) / 2, (hauteur_cote - HP8R_hauteur) / 2, 0])
				haut_parleur_HP8R_trous();
		}
	}
}