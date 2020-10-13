#include "Game.hpp"

Game *game = nullptr;

int WINDOW_WIDTH = 1280;
int WINDOW_HEIGHT = 720;

TTF_Font* font = nullptr;

bool load_res ()
{
    if (TTF_Init()!=-1) {
        font = TTF_OpenFont("./assets/open-sans.ttf", 16);
        std::cout << TTF_GetError() << std::endl;
        if (font) {
            return true;
        }
    }
    return false;
}

int main( )
{
    
    if (load_res()) {
        std::cout << "Resources loaded!" << std::endl;
    }
    else {
        std::cout << "Resources unable to be loaded!" << std::endl;
        return 0;
    }
    
    game = new Game();
    
    game->set_font (font);
    game->init("SKYMOCHA T-ARPG", WINDOW_WIDTH, WINDOW_HEIGHT, false);
    
    while (game->is_running()) {
        game->handle_events();
        game->update();
        game->render();
    }
    
    game->clean();

	return 0;
}
