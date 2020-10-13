//
//  ascii_char.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "ASCII_Char.hpp"

ASCII_Char::ASCII_Char(char c, int tx, int ty, TTF_Font *tf, SDL_Renderer *tr) {
    ch = c;
    x = tx;
    y = ty;
    r = tr; //RENDERER
    f = tf; //FONT
    
    rect.w = 16; // controls the width of the rect
    rect.h = 16; // controls the height of the rect
}

void ASCII_Char::Set_Color (Uint8 r, Uint8 g, Uint8 b) {
    color = {r, g, b, 255};
}

void ASCII_Char::update_pos (int tx, int ty) {
    x = tx;
    y = ty;
}

void ASCII_Char::render() {
    
    surface = TTF_RenderText_Solid(f, &ch, color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first

    message = SDL_CreateTextureFromSurface(r, surface); //now you can convert it into a texture

    rect.x = 16;  //controls the rect's x coordinate
    rect.y = 16; // controls the rect's y coordinte
    
    SDL_RenderCopy(r, message, NULL, &rect);
}

void ASCII_Char::clean() {
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(message);
}
