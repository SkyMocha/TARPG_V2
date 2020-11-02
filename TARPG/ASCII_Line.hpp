//
//  ASCII_Line.hpp
//  TARPG
//
//  Created by Nicolas Kychenthal on 10/31/20.
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "ASCII_Char.hpp"

#ifndef ASCII_Line_hpp
#define ASCII_Line_hpp

class ASCII_Line {
    
public:
    
    ASCII_Line(int tx, int ty, const char * ln);
    ASCII_Line(int tx, int ty, const char * ln, int width);
    
    void store (TTF_Font *f, SDL_Renderer *r);
    
    void render (SDL_Renderer *ren);
    
    int get_w () { return ((int)strlen (line)-1) * 16 + 1; };
    
    int get_h () { return 16; };
    
    void update_w () {
//        rect.w = ((int)strlen (line)) * 16 / 2;
        width = ((int)strlen (line)) * 16 / 2;
    };
    
private:
    int width;
    int height = 16;
    int x;
    int y;
    const char * line;

    SDL_Rect rect;
    SDL_Surface* surface;
    SDL_Texture* message;
    
};

#endif /* ASCII_Line_hpp */
