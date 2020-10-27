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

Map::Map(TTF_Font *tf, SDL_Renderer *tr, int sh, int sw) {
    screen_width = sw;
    screen_height = sh;
    
    ttf = tf;
    
    noise = new Noise(size);
    
    for(int i = 0; i < size; ++i) {
        tiles[i] = new Tile*[size];
    }
    
    for (int w = 0; w < size; w++) {
        for (int h = 0; h < size; h++) {
            
            tiles[w][h] = new Tile(" ", w, h, tf);
            
            tiles[w][h]->setVal( noise->get(w, h));
            
            tiles[w][h]->setChar ();
            
        }
    }
    
}

// RENDERS ALL CHARACTERS ON THE MAP
// x, y are the positions on the screen
// w, h are the place on the world map
void Map::render (SDL_Renderer *ren) {
    
    int x = 0;
    int y = 0;
    // Loops through the part of the map that starts at display_x and ends at the screen width
    for (int w = (display_x - screen_width/2/16); w <= (display_x + screen_width/2/16); w++) {
        for (int h = (display_y - screen_height/2/16); h < (display_y + screen_height/2/16); h++) {
            
//          CHECKS TO SEE TiLE IS IN BORDERS
            if (tiles[w][h]) { // Checks to see that the tile exists
                if ((int)y/16 != (int)screen_width/2/16 || (int)x/16 != (int)screen_height/2/16) { // Does not render the tile below the player
                    tiles[w][h]->render(ren, x, y);
                }
            }
            x+=16;
        }
        x = 0;
        y+=16;
    }
}
