//
//  ASCII_Line.cpp
//  TARPG
//
//  Created by Nicolas Kychenthal on 10/31/20.
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "ASCII_Line.hpp"

ASCII_Line::ASCII_Line (int tx, int ty, const char * ln) {
    x = tx;
    y = ty;
    line = ln;
    
    rect.w = ((int)strlen (line)) * 16 / 2;
    width = ((int)strlen (line)) * 16 / 2;
    rect.h = 16;
}

ASCII_Line::ASCII_Line (int tx, int ty, const char * ln, int w) {
    x = tx;
    y = ty;
    line = ln;
    
    rect.w = w*16;
    width = w*16;
    rect.h = 16;
}

void ASCII_Line::store (TTF_Font *font, SDL_Renderer *ren) {
        
    surface = TTF_RenderText_Solid(font, line, {255, 255, 255, 255}); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    
    message = SDL_CreateTextureFromSurface(ren, surface); //now you can convert it into a texture
    
    SDL_FreeSurface(surface);
};

void ASCII_Line::render(SDL_Renderer *ren) {
        
    rect.x = x*16;
    rect.y = y*16;
    rect.w = width;
    
    SDL_RenderCopy(ren, message, NULL, &rect);

}
