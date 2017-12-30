include <parametre.scad>
use <bouton_arcade.scad>
use <haut_parleur_HP8R.scad>
use <ec11.scad>

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
			translate([(largeur_cote - HP8R_largeur) / 2, position_haut_parleur_HP8R, 0])
				haut_parleur_HP8R_trous();
			
			// trou axe bouton EC11
			translate([largeur_cote / 2, position_ec11, epaisseur_tole_droit])
				trous_ec11(epaisseur_tole_droit);
			
		}
	}
	
	if(show_accessoires == 1) {
		
		// bouton player 1
		translate([largeur_cote / 2, 
				hauteur_cote - rayon_bouton_arcade - epaisseur_tole_dessus - marge_mur, 
				-hauteur_bague_bouton_arcade]) 
			color([1, 1, 1]) bouton_arcade();
		
		// bouton player 2
		translate([largeur_cote / 2, 
				hauteur_cote- rayon_bouton_arcade - epaisseur_tole_dessus - marge_mur - taille_fenetre - ecart_entre_fenetre, 
				-hauteur_bague_bouton_arcade]) 
			color([1, 1, 1]) bouton_arcade();
	
		// le haut-parleur
		translate([(largeur_cote - HP8R_largeur) / 2, position_haut_parleur_HP8R, epaisseur_tole_droit])
			haut_parleur_HP8R();
		
		// le bouton EC11
		translate([largeur_cote / 2, position_ec11, epaisseur_tole_droit])
			mirror([0, 0, 1])
				ec11();
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