//
//  ascii_char.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "ASCII_Char.hpp"

ASCII_Char::ASCII_Char(char const *c, int tx, int ty, TTF_Font *tf) {
    ch = c;
    x = tx * 16;
    y = ty * 16;
    f = tf; //FONT
        
    rect.w = 16; // controls the width of the rect
    rect.h = 16; // controls the height of the rect
}

void ASCII_Char::Set_Color (Uint8 r, Uint8 g, Uint8 b) {
    color = {r, g, b, 255};
}

void ASCII_Char::update_pos (int tx, int ty) {
    x = tx * 16;
    y = ty * 16;
}

// RENDERS AT SPECIFIC POS
void ASCII_Char::render(SDL_Renderer *ren, int tx, int ty) {
    
    rect.x = tx;  //controls the rect's x coordinate
    rect.y = ty; // controls the rect's y coordinte
    
    surface = TTF_RenderText_Solid(f, ch, color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    
    message = SDL_CreateTextureFromSurface(ren, surface); //now you can convert it into a texture
    
    SDL_RenderCopy(ren, message, NULL, &rect);
}

// RENDERS AT DEFAULT POS
void ASCII_Char::render(SDL_Renderer *ren) {
    
    surface = TTF_RenderText_Solid(f, ch, color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
    
    message = SDL_CreateTextureFromSurface(ren, surface); //now you can convert it into a texture

    rect.x = x;  //controls the rect's x coordinate
    rect.y = y; // controls the rect's y coordinte
    
    SDL_RenderCopy(ren, message, NULL, &rect);
}

void ASCII_Char::clean() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(message);
}
