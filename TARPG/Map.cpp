//
//  Map.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "Map.hpp"

/*
    def noise(gen, nx, ny):
        return gen.noise2d(nx, ny) / 2.0 + 0.5
 
    values = []
    for y in range(height):
        values.append([0] * width)
        for x in range(width):
            nx = x/(width*0.1125) - 0.5
            ny = y/(height*0.1125) - 0.5
            values[y][x] = noise(generators[0], nx, ny)
        print (f"{y * 100 / height}% DONE!")
*/

Map::Map(TTF_Font *tf, SDL_Renderer *tr) {
//    font = tf;
//    renderer = tr;
    
    for (int w = 0; w < size; w++) {
        for (int h = 0; h < size; h++) {
            
            tiles[w][h]->setFont(tf);
            tiles[w][h]->setRenderer(tr);
            
            tiles[w][h]->setVal( getTileVal(w, h) );
            tiles[w][h]->update_pos ( w, h );
            tiles[w][h]->setChar ();
            
        }
    }
    
}

double Map::getTileVal (int x, int y) {
    int nx = x/(size * 0.1125) - 0.5;
    int ny = y/(size * 0.1125) - 0.5;
    return gen->Evaluate(nx, ny);
}

void Map::render () {
    for (int w = 0; w < size; w++) {
        for (int h = 0; h < size; h++) {
            tiles[w][h]->render();
        }
    }
}
