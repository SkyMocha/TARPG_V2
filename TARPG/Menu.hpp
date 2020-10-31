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

class Menu
{
    public:
        ASCII_Line *lines[2]; // CHANGE THE NUMBER DEPENDING ON HOW MANY MENUES EXIST
        Menu() {};
        Menu (int width, int height, int x, int y, int o_key, const char *name, TTF_Font *f, SDL_Renderer *ren);
        ~Menu();
    
        virtual void render (SDL_Renderer *ren) = 0; // Abstract render method
        virtual void update (TTF_Font *font, SDL_Renderer *ren) = 0; // Abstract update/store method
    
    private:
        int width;
        int height;
        int x;
        int y;
        int open_key;
        const char * name;
};

#endif /* Menu_hpp */
