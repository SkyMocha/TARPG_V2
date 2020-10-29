//
//  Tile.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Tile_hpp
#define Tile_hpp

#include "ASCII_Char.hpp"

class Tile : public ASCII_Char{
    
public:
    Tile() : ASCII_Char () { };
    Tile(char const *c, int tx, int ty, TTF_Font *tf, SDL_Renderer *ren) : ASCII_Char(c, tx, ty, tf, ren) { };
    ~Tile();
    
    void setVal (double v) { val = v; };
    void setVariant (int v) { variant = v; };
    void setChar ();
    
private:
    double val;
    int variant;
    
};

#endif /* Tile_hpp */
