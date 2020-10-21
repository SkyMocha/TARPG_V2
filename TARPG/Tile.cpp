//
//  Tile.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "Tile.hpp"

void Tile::setChar(){
    
    if (val == 0) {
        setCh(" ");
    }
    else if (val < 0.3) {
        setCh("~");
    }
    else if (val < 0.75) {
        setCh("#");
    }
    else if (val < 1) {
        setCh("^");
    }
    
}
