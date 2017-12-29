include <parametre.scad>
use <bouton_arcade.scad>

dessus();

module dessus() {
    color([0, 0, 0]) {
        difference() {
            cube(size=[largeur_mur, profondeur_dessus, epaisseur_tole_dessus]);
            pose_trous_bouton();
        }
    }
}

module pose_trous_bouton() {
    for(colonne = [1 : nombre_colonnes]) {
        translate([marge_largeur_dessus + (diametre_bouton_arcade - rayon_bouton_arcade) / 2 + (colonne - 1) * (diametre_bouton_arcade + ecart_entre_fenetre), marge_profondeur_dessus + (diametre_bouton_arcade - rayon_bouton_arcade) / 2, 0]) 
            trou_bouton_arcade(epaisseur_tole_dessus);
    }
}
