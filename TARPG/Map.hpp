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
#include <thread>

class Map {
    
public:
    Map();
    Map (TTF_Font *tf, SDL_Renderer *tr, int sw, int sh);
    
    double getTileVal (int x, int y);
    void render (SDL_Renderer *ren);
    void render_chunk (SDL_Renderer *ren, int i, int j, int chunk_size);
    void render_all_chunks (SDL_Renderer *ren);
    
    void move (int tx, int ty);
    
private:
    int size = 500;
    Tile **tiles[500];
    Noise *noise;
    
    TTF_Font *ttf;
    
    int pos_x = 200;
    int screen_width;
    int pos_y = 200;
    int screen_height;
};

#endif /* Map_hpp */
