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
        InfoMenu(TTF_Font *f, SDL_Renderer *ren) : Menu (40, 12, 0, 0, SDLK_e, "info", f, ren) {};
        ~InfoMenu();
    
        void update(TTF_Font *font, SDL_Renderer *ren);
        void render(SDL_Renderer *ren);
        
    private:
        
};

#endif /* InfoMenu_hpp */
