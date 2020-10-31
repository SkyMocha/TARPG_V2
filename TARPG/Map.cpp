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
            
            tiles[w][h] = new Tile(" ", w, h, tf, tr);
            
            tiles[w][h]->setVal( noise->get(w, h));
            tiles[w][h]->setVariant ( rand() % 100 );
            
            tiles[w][h]->setChar ();
            
        }
    }
    
    noise->~Noise();
    
}

// RENDERS ALL CHARACTERS ON THE MAP
// x, y are the positions on the screen
// w, h are the place on the world map
void Map::render (SDL_Renderer *ren) {
    
    int x = 0;
    int y = 0;
    // Loops through the part of the map that starts at display_x and ends at the screen width
    for (int w = (pos_x - screen_width/2/16); w <= (pos_x + screen_width/2/16); w++) {
        for (int h = (pos_y - screen_height/2/16); h < (pos_y + screen_height/2/16); h++) {
            
//          CHECKS TO SEE TiLE IS IN BORDERS
            if (tiles[w][h]) { // Checks to see that the tile exists
                if ((int)y/16 != (int)screen_width/2/16 || (int)x/16 != (int)screen_height/2/16) { // Does not render the tile below the player
                    tiles[w][h]->render(ren, x, y);
                    tiles[w][h]->clean();
                }
            }
            x+=16;
        }
        x = 0;
        y+=16;
    }
}

// Loops through all chunks and creates a thread to render it
void Map::render_all_chunks (SDL_Renderer *ren) {
    int chunk_size = 16;
    for (int w = 0; w <= screen_width/16/chunk_size; w++) {
        for (int h = 0; h <= screen_height/16/chunk_size; h++) {
            std::thread t( &Map::render_chunk, this, ren, w, h, chunk_size );
            t.join();
        }
    }
}

void Map::render_chunk (SDL_Renderer *ren, int i, int j, int chunk_size) {
    int x = j*chunk_size*16;
    int y = i*chunk_size*16;
//    std::cout << "LOADING CHUNK: ";
//    std::cout << i;
//    std::cout << " | ";
//    std::cout << j << std::endl;
    // Loops through the part of the map that starts at display_x and ends at the screen width
    for (int w = pos_x + i*chunk_size; w <= pos_x + i*chunk_size + chunk_size; w++) {
        for (int h = pos_y + j*chunk_size; h < pos_y + j*chunk_size + chunk_size; h++) {
            
//          CHECKS TO SEE TiLE IS IN BORDERS
            if (tiles[w][h] && w >= 0 && h >= 0 && w < size && h < size) { // Checks to see that the tile exists
                if ((int)y/16 != (int)screen_width/2/16 || (int)x/16 != (int)screen_height/2/16) { // Does not render the tile below the player
                    tiles[w][h]->render(ren, x, y);
                }
            }
            x+=16;
        }
        x = j*chunk_size*16;
        y+=16;
    }
}

// Derenders the outer-most line in a certain direction
void Map::derender (int dx, int dy) {
//   Derender upwards or downwards
    if (dx == 0) {
        int pos = pos_y - screen_height/2/16*dy;
        for (int i = 0; i < screen_width/16; i++) {
            std::cout << i;
            std::cout << " | ";
            std::cout << pos << std::endl;
            tiles[i][pos]->clean();
        }
    }
//   Derender left or right
    else {
        int pos = pos_x - screen_width/2/16*dx;
        for (int i = 0; i < screen_height/16; i++) {
            std::cout << i;
            std::cout << " | ";
            std::cout << pos << std::endl;
            tiles[pos][i]->clean();
        }
    }
}

void Map::move (int x, int y) {
//    Weird voodo magic to make things work !
    pos_x += y * -1;
    pos_y += x;
//    std::cout << x;
//    std::cout << " | ";
//    std::cout << y << std::endl;
//    derender(y, x);
}

Map::~Map() {
    for(int i = 0; i < size; ++i) {
        delete[] tiles[i];
    }
}
