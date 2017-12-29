include <parametre.scad>

// pour exporter en .dxf
//projection(cut = false)
mur();

// plaque mur déco
module mur() {
    color([0, 0, 0]) {
        difference() {
			// une belle dalle
            cube(size=[largeur_mur, hauteur_mur, epaisseur_tole_mur]);
			// que l'on perce de trous pour chaque token du jeu
            pose_trous_fenetre();
			// et on dessine un mur Star Wars avec ces trous
            translate([marge_mur, marge_mur, 0]) {
                trou_mur(1, 1, 2);
                trou_mur(1, 3, 4);
                trou_mur(3, 1, 2);
                trou_mur(3, 3, 4);
                trou_mur(5, 1, 2);
                trou_mur(5, 3, 4);
                trou_mur(7, 1, 2);
                trou_mur(7, 3, 4);

                trou_mur(2, 1, 4);
                trou_mur(2, 5, 2);
                trou_mur(4, 1, 4);
                trou_mur(4, 5, 2);
                trou_mur(6, 1, 4);
                trou_mur(6, 5, 2);
            }
        }
    }
}

module pose_trous_fenetre() {
    for(colonne = [1 : nombre_colonnes]) {
        for(ligne = [1 : nombre_lignes]) {
            translate([marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre), marge_mur + (ligne - 1) * (taille_fenetre + ecart_entre_fenetre), 
                        0]) 
                trou_fenetre();

        }
    }
}

module trou_fenetre() {
    translate([0, 0, -1]) {
        translate([taille_fenetre/2, taille_fenetre/2, - difference_objet_marge / 2]) {
            cylinder(epaisseur_tole_mur + difference_objet_marge, d=taille_fenetre, $fn=resolution);
        }
    }
}

module trou_mur(colonne, ligne, nombre) {
    translate([0, 0, -1]) {
        translate([(colonne - 1) * (taille_fenetre + ecart_entre_fenetre), 
            taille_fenetre/2 + ((ligne - 1) * (taille_fenetre + ecart_entre_fenetre)), 
			- difference_objet_marge / 2])
            cube(size=[taille_fenetre, 
				(nombre - 1) * (taille_fenetre) + ((nombre - 1) * ecart_entre_fenetre), 
				epaisseur_tole_mur + difference_objet_marge]);
    }
}
