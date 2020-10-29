//
//  Game.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "SDL2/SDL.h"

#include "Map.hpp"

class Game {
    
public:
    Game(); // CONSTRUCTOR
    ~Game(); // DECONSTRUCTOR
    
    void init(const char* title, int width, int height, bool fullscreen);
    void handle_events();
    void handle_keys(int key);
    void update();
    void render();
    void clean();
    
    void set_font(TTF_Font *tf);
    
    bool is_running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
    Player *player;
    
    Map *map;
};

#endif /* Game_hpp */
