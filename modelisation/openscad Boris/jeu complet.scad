include <parametre.scad>
use <mur.scad>
use <plexi blanc mur.scad>
use <dessus.scad>
use <dessous.scad>

// mur du bas
translate([0, 0, deport_glissiere])
    mur();
// mur du haut
translate([0, 0, profondeur_dessus - deport_glissiere - epaisseur_tole_mur])
    mur();

// plexi du bas
translate([0, 0, deport_glissiere + epaisseur_tole_mur])
    plexi_blanc();
// plexi du haut
translate([0, 0, profondeur_dessus - deport_glissiere - epaisseur_tole_mur - epaisseur_plexi_blanc])
    plexi_blanc();


// pour fermer le dessus
rotate([90, 0, 0])
    translate([0, 0, -(hauteur_mur + epaisseur_tole_dessus - profondeur_glissiere)])
        dessus();

// on ferme le dessous
rotate([90, 0, 0])
    translate([0, 0, - profondeur_glissiere])
        dessous();
