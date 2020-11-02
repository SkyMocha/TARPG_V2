//
//  Menu.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "Menu.hpp"

Menu::Menu (int w, int h, int tx, int ty, int o_key, const char * n, TTF_Font *f, SDL_Renderer *r) {
    width = w;
    height = h;
    x = tx;
    y = ty;
    open_key = o_key;
    name = n;
}

void Menu::update_all_w () {
    for (int i = 0; i < lnCount; i++) {
        lines[i]->update_w();
    }
}

// Gets the max height of all the lines in the menu
int Menu::get_max_h () {
//    int max_h = 0;
//    for (int i = 0; i < lnCount; i++) {
//        if (lines[i]->get_h() > max_h) {
//            max_h = lines[i]->get_h();
//        }
//    }
//    return max_h;
    return height*16;
}

// Gets the max width of all the lines in the menu
int Menu::get_max_w () {
//    int max_w = 0;
//    for (int i = 0; i < lnCount; i++) {
//        if (lines[i]->get_w() > max_w) {
//            max_w = lines[i]->get_w();
//        }
//    }
//    return max_w;
    return width*16;
}
