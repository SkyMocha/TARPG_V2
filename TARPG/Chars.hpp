//
//  Chars.hpp
//  TARPG
//
//  Created by Nicolas Kychenthal on 10/29/20.
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Chars_hpp
#define Chars_hpp

#include <stdio.h>

class Chars {
    public:
        ~Chars();
        Chars();
    
        char const * get(char c);

    private:
        char const *chs [];
};
    

class ASCII {
    public:
        ASCII (char const *ch) {
                
        };
        ~ASCII();
    
    private:
};

#endif /* Chars_hpp */
