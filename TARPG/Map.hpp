//
//  Map.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include "Tile.hpp"
#include "Player.hpp"
#include "3rd-Party/OpenSimplexNoise.hpp"

class Map {
    
public:
    Map();
    Map (TTF_Font *tf, SDL_Renderer *tr);
    
    double getTileVal (int x, int y);
    void render ();
    
private:
    int size = 1000;
    Tile *tiles[1000][1000];
    OpenSimplexNoise* gen = new OpenSimplexNoise ();
//    TTF_Font *font;
//    SDL_Renderer *renderer;
};

#endif /* Map_hpp */
