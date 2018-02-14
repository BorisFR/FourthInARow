include <parametre.scad>
use <haut_parleur_HP8R.scad>

use <logo_ia.scad>

// pour exporter en .dxf
//projection(cut = false)
cote_gauche();

// plaque mur déco
module cote_gauche() {
    color("Silver") {
        difference() {
			
			// une belle dalle
			cube(size=[largeur_cote, hauteur_cote, epaisseur_tole_gauche]);
					
			
			// trou haut-parleur
			translate([(largeur_cote - HP8R_largeur) / 2, position_haut_parleur_HP8R, 0])
				haut_parleur_HP8R_trous();
			
			
			// Dessin gravé
			
			translate([0, 0, 0]) {
			
				translate([largeur_cote / 2, hauteur_cote - 30, epaisseur_tole_gauche - 1 + padding_percage])
					scale([0.2, 0.2, 1])
						logo_ia(2);

				width = 27;
				translate([width / 2, hauteur_cote - 61, epaisseur_tole_gauche - 2 + padding_percage]) {
					difference() {
						cube(size=[largeur_cote - width, 10, 2]);
						
						translate([0.5, 3, 0])
							linear_extrude(height = 2 + padding_percage)
								text("Industrial Automaton", halign = "left", size = 3.1, font = "Aurabesh");
					}
				}
				
				// Fourth
				translate([largeur_cote / 2, 37, epaisseur_tole_gauche - 2 + padding_percage])
					linear_extrude(height = 2 + padding_percage)
						text("Fourth", halign = "center", size = 9, font = "Aurabesh");
				// in-a-row
				translate([largeur_cote / 2, 22, epaisseur_tole_gauche - 2 + padding_percage])
					linear_extrude(height = 2 + padding_percage)
						text("in-a-row", halign = "center", size = 9, font = "Aurabesh");

			}
			
		}
	
		if(show_accessoires == 1) {
		
		translate([(largeur_cote - HP8R_largeur) / 2, position_haut_parleur_HP8R, 0])
				mirror([0, 0, 1])
					haut_parleur_HP8R();
		}

	}
}