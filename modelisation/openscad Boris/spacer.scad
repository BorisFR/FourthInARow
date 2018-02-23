include <parametre.scad>

// pour exporter en .dxf
if(show_mode_projection == 1)
	projection(cut = false) spacerVertical();

if(show_mode_projection == 0)
	spacerHorizontal();

module spacerHorizontal() {
    color([1, 1, 1]) {
        difference() {
            cube(size=[largeur_mur, profondeur_separateur_led, epaisseur_separateur_led]);

            for(colonne = [1 : nombre_colonnes + 1]) {
                translate([marge_mur + (colonne - 1) * (taille_fenetre + ecart_entre_fenetre) - (ecart_entre_fenetre / 2) - 2 * padding_percage, 
                        -difference_objet_marge + padding_percage, 
                        -padding_percage])
                    cube(size=[epaisseur_separateur_led + 2 * padding_percage, 
                    profondeur_separateur_led / 2 + padding_percage + difference_objet_marge, 
                    epaisseur_separateur_led + 2 * padding_percage]);
            }
        }
    }
}

module spacerVertical() {
    color([1, 1, 1]) {
        translate([-profondeur_separateur_led, 0, padding_percage - decallage_separateur_led])
        difference() {
            cube(size=[profondeur_separateur_led, hauteur_mur, epaisseur_separateur_led]);

            for(ligne = [1 : nombre_lignes + 1]) {
                translate([-difference_objet_marge, 
                marge_mur + (ligne - 1) * (taille_fenetre + ecart_entre_fenetre) - ecart_entre_fenetre / 2 - 3 * padding_percage, 
                -padding_percage])
                    cube(size=[profondeur_separateur_led / 2 - padding_percage + difference_objet_marge, 
                    epaisseur_separateur_led + 2 * padding_percage, 
                    epaisseur_separateur_led + 2 * padding_percage]);
            }
        }
    }
}
