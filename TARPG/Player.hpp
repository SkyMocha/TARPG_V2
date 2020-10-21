//
//  Player.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#include "ASCII_Char.hpp"

#ifndef Player_hpp
#define Player_hpp

class Player : public ASCII_Char {
public:
    Player() : ASCII_Char () { };
    Player(int x, int y, TTF_Font *f) : ASCII_Char("@", x, y, f) { };
    ~Player();


private:

};

#endif /* Player_hpp */
