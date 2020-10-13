//
//  ascii_char.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef ASCII_Char_hpp
#define ASCII_Char_hpp

#include <SDL2/SDL.h>
#include <SDL2_Image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
//#include <string>
//#include <cmath>
#include <iostream>

class ASCII_Char
{
    public:
        //Initializes variables
    
        ASCII_Char () {};
        
        ASCII_Char(char c, int tx, int ty, TTF_Font *f, SDL_Renderer *r);

        //Deallocates memory
        ~ASCII_Char();
    
        void Set_Color (Uint8 r, Uint8 g, Uint8 b);
    
        void sdl_surface();
    
//        void sdl_texture();
    
//        void sdl_rect(); //
    
        void render(); // Renders the indiviudal character
    
        void clean(); // CLEANS UP RESOURCES
    
        void update_pos(int x, int y);
    
        void setCh (char c) { ch = c; };
    
        void setFont (TTF_Font *tf) { f = tf; }
    
        void setRenderer (SDL_Renderer *tr) { r = tr; }
    
        void log ();

    private:
        char ch;
        int x;
        int y;
        SDL_Color color;
        SDL_Surface* surface;
        SDL_Texture* message;
        SDL_Rect rect;
        TTF_Font* f;
        SDL_Renderer* r;
};


#endif /* ascii_char_hpp */
