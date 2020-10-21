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
#include "Perlin.hpp"

class Map {
    
public:
    Map();
    Map (TTF_Font *tf, SDL_Renderer *tr, int sw, int sh);
    
    double getTileVal (int x, int y);
    void render (SDL_Renderer *ren);
    
private:
    int size = 500;
    Tile **tiles[500];
    Noise *noise;
    
    TTF_Font *ttf;
    
    int display_x = 175;
    int screen_width;
    int display_y = 175;
    int screen_height;
};

#endif /* Map_hpp */
