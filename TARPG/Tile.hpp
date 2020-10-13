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
    Tile(char c, int tx, int ty, TTF_Font *tf, SDL_Renderer *tr) : ASCII_Char(c, tx, ty, tf, tr) { };
    ~Tile();
    
    void setVal (double v) { val = v; };
    void setChar ();
    
private:
    double val;
    
};

#endif /* Tile_hpp */
