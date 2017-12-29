include <parametre.scad>
use <bouton_arcade.scad>

dessus();

module dessus() {
    color([0, 0, 0]) {
        difference() {
            cube(size=[largeur_mur, profondeur_dessus, epaisseur_tole_dessus]);
            pose_trous_bouton();
            translate([-1, deport_glissiere, profondeur_glissiere])
                cube(size=[largeur_mur + 2, glissiere_mur_plexi, profondeur_glissiere + 2]);
            translate([-1, profondeur_dessus - deport_glissiere - glissiere_mur_plexi, profondeur_glissiere])
                cube(size=[largeur_mur + 2, glissiere_mur_plexi, profondeur_glissiere + 2]);
        }
    }
}

module pose_trous_bouton() {
    for(colonne = [1 : nombre_colonnes]) {
        translate([marge_largeur_dessus + (diametre_bouton_arcade - rayon_bouton_arcade) / 2 + (colonne - 1) * (diametre_bouton_arcade + ecart_entre_fenetre), marge_profondeur_dessus + (diametre_bouton_arcade - rayon_bouton_arcade) / 2, 0]) 
            trou_bouton_arcade(epaisseur_tole_dessus);
    }
}
