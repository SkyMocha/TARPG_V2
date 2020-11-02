//
//  InfoMenu.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "InfoMenu.hpp"

void InfoMenu::update (TTF_Font *font, SDL_Renderer *ren) {
    set_ln_count(1);

// creates the line to be printed
    std::stringstream ln;
    ln << "POS : " << pos_x << ", " << pos_y;

    ASCII_Line tmp[] = {
        *new ASCII_Line ( 0, 0, ln.str().c_str()),
    };
    for (int i = 0; i < get_ln(); i++) // CHANGE WHENEVER THERE IS A NEW AMOUNT OF LINES
        lines[i] = &tmp[i];
    for (int i = 0; i < get_ln(); i++) {
        lines[i]->store(font, ren);
    }
}

void InfoMenu::render (SDL_Renderer *ren) {
    for (int i = 0; i < get_ln(); i++) {
        lines[i]->render(ren);
    }
}
