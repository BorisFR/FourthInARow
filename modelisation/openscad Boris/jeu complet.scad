include <parametre.scad>
use <mur.scad>
use <plexi blanc mur.scad>
use <dessus.scad>

translate([0, 0, deport_glissiere])
    mur();
translate([0, 0, profondeur_dessus - deport_glissiere - epaisseur_tole_mur])
    mur();
translate([0, 0, deport_glissiere + epaisseur_tole_mur])
    plexi_blanc();
translate([0, 0, profondeur_dessus - deport_glissiere - epaisseur_tole_mur - epaisseur_plexi_blanc])
    plexi_blanc();

rotate([90, 0, 0])
    translate([0, 0, -(hauteur_mur + epaisseur_tole_dessus)])
        dessus();