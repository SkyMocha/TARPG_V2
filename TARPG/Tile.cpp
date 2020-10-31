//
//  Tile.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "Tile.hpp"

void Tile::setChar(){
    
//   NONE
    if (val == 0) {
        setCh(" ");
    }
//   WATER
    else if (val < 0.325) {
        setCh("~");
        if (val < 0.1) {
            Set_Color(20, 20, 80);
        }
        else if (val < 0.2) {
            Set_Color(20, 20, 100);
        }
        else if (val < 0.2545) {
            Set_Color(20, 20, 175);
        }
        else if (val < 0.275) {
            Set_Color(20, 20, 220);
        }
        else if (val < 0.325) {
            Set_Color(20, 20, 255);
        }
        
        if (variant > 97) {
            setCh("=");
        }
        else if (variant > 90) {
            setCh("^");
        }
        else if (variant > 75) {
            setCh("-");
        }
    }
//    BEACH
    else if (val < 0.345) {
        if (val < 0.330) {
            Set_Color(178, 162, 100);
        }
        else if (val < 0.336) {
            Set_Color(184, 170, 112);
        }
        else if (val < 0.345) {
            Set_Color(194, 178, 128);
        }
        
        if (variant > 80) {
            setCh("^");
        }
        else {
            setCh("#");
        }
    }
//   GRASS
    else if (val < 0.75) {
        setCh("#");
        Set_Color (20, 200, 30);
        if (variant > 95) {
            setCh("!");
            Set_Color(30, 80, 50);
        }
        else if (variant > 80) {
            setCh("%");
            Set_Color(16, 59, 29);
        }
        else if (variant > 65) {
            Set_Color (20, 180, 40);
        }
        else if (variant > 40) {
            Set_Color (25, 165, 50);
        }
    }
//   MOUNTAINS
    else if (val < 1) {
        setCh("^");
        Set_Color (166, 172, 166);
    }
    
}
