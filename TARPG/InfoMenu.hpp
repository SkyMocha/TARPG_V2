//
//  InfoMenu.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

//#include <SDL2/SDL.h>

#ifndef InfoMenu_hpp
#define InfoMenu_hpp

#include "Menu.hpp"

class InfoMenu : public Menu {
    
    public:
        InfoMenu() : Menu () {};
        InfoMenu(TTF_Font *f, SDL_Renderer *ren) : Menu (15, 3, 0, 0, SDLK_e, "info", f, ren) {};
        ~InfoMenu();
    
        void update(TTF_Font *font, SDL_Renderer *ren);
        void update_pos (int tx, int ty) {
            pos_x = tx;
            pos_y = ty;
            update_all_w();
        };
        void render(SDL_Renderer *ren);
        
    private:
    
        int pos_x = 1;
        int pos_y = 1;
};

#endif /* InfoMenu_hpp */
