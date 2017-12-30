include <parametre.scad>
use <bouton_arcade.scad>
use <haut_parleur_HP8R.scad>

// pour exporter en .dxf
//projection(cut = false) cote_droit();
translate([-largeur_cote / 2, 0, 0])
	cote_droit();

// plaque mur déco
module cote_droit() {
    color([0, 0, 0]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_cote, hauteur_cote, epaisseur_tole_droit]);
			
			// les trous player 1 et player 2
			pose_trous_bouton();
			
			// trou haut-parleur
			translate([(largeur_cote - HP8R_largeur) / 2, (hauteur_cote - HP8R_hauteur) / 2, 0])
				haut_parleur_HP8R_trous();
		}
	}
}

module pose_trous_bouton() {
	translate([largeur_cote / 2, 
			hauteur_cote - rayon_bouton_arcade - epaisseur_tole_dessus - marge_mur, 
			- difference_objet_marge / 2]) 
		trou_bouton_arcade(epaisseur_tole_droit + difference_objet_marge);

	translate([largeur_cote / 2, 
			hauteur_cote- rayon_bouton_arcade - epaisseur_tole_dessus - marge_mur - taille_fenetre - ecart_entre_fenetre, 
			- difference_objet_marge / 2]) 
		trou_bouton_arcade(epaisseur_tole_droit + difference_objet_marge);
}