//
//  Player.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

class Player : public ASCII_Char {
public:
    Player() : ASCII_Char () { };
    Player(int x, int y, TTF_Font *f, SDL_Renderer *r) : ASCII_Char('@', x, y, f, r) { };
    ~Player();


private:

};

#endif /* Player_hpp */
