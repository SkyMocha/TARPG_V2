//
//  Perlin.hpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//

#ifndef Perlin_hpp
#define Perlin_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class Noise {
    
public:
    Noise(int s);
    ~Noise();
    
    float get (int x, int y) { return fPerlinNoise2D[y * size + x]; }
    
private:
    int size;
    float *fNoiseSeed2D;
    float *fPerlinNoise2D;
    
};

#endif /* Perlin_hpp */
