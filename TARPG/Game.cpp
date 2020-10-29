//
//  Game.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "Game.hpp"

Game::Game()
{}
Game::~Game()
{}

void Game::init(const char *title, int width, int height, bool fullscreen)
{
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { // Checks to see if SDL Subsystems have been initialized
        std::cout << "Subystems initialized!" << std::endl;
        
        window = SDL_CreateWindow("SkyMocha TRPG", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            std::cout << "Renderer created!" << std::endl;
        }
        
        player = new Player(width/2/16, height/2/16, font, renderer);
        
        map = new Map (font, renderer, width, height);
    
        isRunning = true;
        
    }
    else {
        isRunning = false;
    }
    
}

// LOADS THE FONT FROM THE MAIN FILE
void Game::set_font(TTF_Font *tf)
{
    font = tf;
}

void Game::handle_keys (int key) {
    std::cout << key << std::endl;
    switch (key) {
        case SDLK_w:
            map->move(0, 1);
            break;
        case SDLK_s:
            map->move(0, -1);
            break;
        case SDLK_d:
            map->move(1, 0);
            break;
        case SDLK_a:
            map->move(-1, 0);
            break;
    }
}

void Game::handle_events()
{
    
    SDL_Event event;
    SDL_PollEvent(&event); // Dereferences the event variable
    switch (event.type) {
        case SDL_QUIT:
            std::cout << "QUIT" << std::endl;
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            handle_keys(event.key.keysym.sym);
            
        default:
            break;
    }
    
}

void Game::update()
{
}

void Game::render()
{
    if (isRunning) {
        SDL_RenderClear(renderer);
        
        // Render stuff below:
        player->render(renderer);
        map->render_all_chunks(renderer);
        
        SDL_RenderPresent(renderer);
    }
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned!" << std::endl;
}
