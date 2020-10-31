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

//void Menu::render () {
//    std::cout << "Attempting to render empty line" << std::endl;
//}

