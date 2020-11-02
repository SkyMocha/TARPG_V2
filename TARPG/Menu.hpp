//
//  Menu.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "ASCII_Char.hpp"
#include "ASCII_Line.hpp"
#include <string>
#include <sstream>
#include <iostream>

class Menu
{
    public:
        ASCII_Line *lines[2]; // CHANGE THE NUMBER DEPENDING ON HOW MANY MENUES EXIST
        Menu() {};
        Menu (int width, int height, int x, int y, int o_key, const char *name, TTF_Font *f, SDL_Renderer *ren);
        ~Menu();
    
        virtual void render (SDL_Renderer *ren) = 0; // Abstract render method
        virtual void update (TTF_Font *font, SDL_Renderer *ren) = 0; // Abstract update/store method
        virtual void update_pos (int tx, int ty) { printf("ATTEMPTING TO ACCESS IN-ACCESSIBLE FUNCTION"); };
    
        void update_all_w();
    
        int get_max_w();
        int get_max_h();
        int get_x() {return x;}
        int get_y () {return y;}
    
        void set_width (int w) { width = w; }
        void set_height (int h) { height = h; }
    
        void set_ln_count (int tln ) { lnCount = tln; }
        int get_ln () { return lnCount; }
    
    private:
        int width;
        int height;
        int x;
        int y;
        int open_key;
        const char * name;
        int lnCount;
};

#endif /* Menu_hpp */
