//
//  InfoMenu.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "InfoMenu.hpp"

void InfoMenu::update (TTF_Font *font, SDL_Renderer *ren) {
    ASCII_Line tmp[] = {
        { 0, 0, "HELLO!" },
        { 0, 1, "UwU!" },
    };
    for (int i = 0; i < 2; ++i) // CHANGE WHENEVER THERE IS A NEW AMOUNT OF LINES
        lines[i] = &tmp[i];
    for (int i = 0; i < sizeof(lines)/sizeof(int)-1; i++) {
        lines[i]->store(font, ren);
    }
}

void InfoMenu::render (SDL_Renderer *ren) {
   for (int i = 0; i < sizeof(lines)/sizeof(int)-1; i++) {
        lines[i]->render(ren);
   }
}
