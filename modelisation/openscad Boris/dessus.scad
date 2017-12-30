include <parametre.scad>
use <bouton_arcade.scad>

// pour exporter en .dxf
//projection(cut = false) dessus();

translate([0, -profondeur_dessus / 2, 0])
dessus();

module dessus() {
    color([0, 0, 0]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_mur, profondeur_dessus, epaisseur_tole_dessus]);
			// on fait les trous pour les 7 colonnes
            pose_trous_bouton();
			
			
			// rainure pour grille de LEDs
            translate([- difference_objet_marge / 2, 
					profondeur_dessus / 2 - largeur_rainure_grille_led - espace_vide_milieu / 2, 
					epaisseur_tole_dessus - profondeur_rainure_grille_led])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_grille_led, profondeur_rainure_grille_led + difference_objet_marge]);

			// rainure pour grille de LEDs
            translate([- difference_objet_marge / 2, 
					profondeur_dessus / 2 + espace_vide_milieu / 2, 
					epaisseur_tole_dessus - profondeur_rainure_grille_led])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_grille_led, profondeur_rainure_grille_led + difference_objet_marge]);

			
			// rainure pour plexi blanc et mur star wars
            translate([- difference_objet_marge / 2, 
					profondeur_dessus / 2 - largeur_rainure_mur_plexi - espace_vide_milieu / 2 - epaisseur_tole_grille_led - profondeur_separateur_led,
					epaisseur_tole_dessus - profondeur_rainure_mur_plexi])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_mur_plexi, profondeur_rainure_mur_plexi + difference_objet_marge]);
				
			// rainure pour plexi blanc et mur star wars
            translate([- difference_objet_marge / 2, 
					profondeur_dessus / 2 + espace_vide_milieu / 2 + epaisseur_tole_grille_led + profondeur_separateur_led, 
					epaisseur_tole_dessus - profondeur_rainure_mur_plexi])
                cube(size=[largeur_mur + difference_objet_marge, largeur_rainure_mur_plexi, profondeur_rainure_mur_plexi + difference_objet_marge]);
		
        }
	}
		
	if(show_accessoires == 1) {
		
		for(colonne = [1 : nombre_colonnes]) {
			translate([marge_mur + diametre_bouton_arcade / 2 + (colonne - 1) * (diametre_bouton_arcade + ecart_entre_fenetre), 
					profondeur_dessus / 2 , -hauteur_bague_bouton_arcade]) 
				color([1, 1, 1]) bouton_arcade();
		}
		
	}
}

module pose_trous_bouton() {
    for(colonne = [1 : nombre_colonnes]) {
        translate([marge_mur + diametre_bouton_arcade / 2 + (colonne - 1) * (diametre_bouton_arcade + ecart_entre_fenetre), 
				profondeur_dessus / 2 , - difference_objet_marge / 2]) 
            trou_bouton_arcade(epaisseur_tole_dessus + difference_objet_marge);
    }
}
