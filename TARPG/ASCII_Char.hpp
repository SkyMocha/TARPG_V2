//
//  ascii_char.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include <SDL2/SDL.h>
 #include <SDL2_Image/SDL_image.h>
 #include <SDL2_ttf/SDL_ttf.h>
//#include <SDL_image.h>
//#include <SDL_ttf.h>

#ifndef ASCII_Char_hpp
#define ASCII_Char_hpp
//#include <string>
//#include <cmath>
#include <iostream>

class ASCII_Char
{
    public:
        //Initializes variables
    
        ASCII_Char () {};
        
        ASCII_Char(char const *c, int tx, int ty, TTF_Font *f);

        //Deallocates memory
        ~ASCII_Char();
    
        void Set_Color (Uint8 r, Uint8 g, Uint8 b);
    
        void sdl_surface();
    
//        void sdl_texture();
    
//        void sdl_rect(); //
    
        void render(SDL_Renderer *ren, int x, int y); // Renders the indiviudal character
        void render(SDL_Renderer *ren); // Renders the indiviudal character
    
        void clean(); // CLEANS UP RESOURCES
    
        void update_pos(int x, int y);
    
        void setCh (char const *c) { ch = c; };
            
        void log ();

    private:
        char const *ch;
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
