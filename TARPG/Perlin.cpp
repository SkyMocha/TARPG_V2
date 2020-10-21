//
//  Perlin.cpp
//  TARPG
//
//  Copyright © 2020 SkyMocha. All rights reserved.
//
//  https://youtu.be/6-0UaeJBumA
//

#include "Perlin.hpp"

Noise::Noise (int s) {
    size = s;
    fNoiseSeed2D = new float[s * s];
    fPerlinNoise2D = new float [s * s];
    
//  Fills the fNoiseSeed2D with completely random noise
    for(int i = 0; i < size * size; ++i) fNoiseSeed2D[i] = (float)rand() / (float)RAND_MAX;

    float fBias = 2.0f;
    
    int nOctaves = 6;
//  2D Perlin-like noise generation
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            
            float fNoise = 0.0f;
            float fScale = 1.0f;
            float fScaleAcc = 0.0f;
            for (int o = 0; o < nOctaves; o++) {
                int nPitch = size >> o;
                int nSampleX1 = (x / nPitch) * nPitch;
                int nSampleY1 = (y / nPitch) * nPitch;
                
                int nSampleX2 = (nSampleX1 + nPitch) % size;
                int nSampleY2 = (nSampleY1 + nPitch) % size;
                
                float fBlendX = (float)(x - nSampleX1) / (float)nPitch;
                float fBlendY = (float)(y - nSampleY1) / (float)nPitch;
                                
//              Linear Interpretation
                float fSampleT = (1.0f - fBlendX) * fNoiseSeed2D[nSampleY1 * size + nSampleX1] + fBlendX * fNoiseSeed2D[nSampleY1 * size + nSampleX2];
                float fSampleB = (1.0f - fBlendX) * fNoiseSeed2D[nSampleY2 * size + nSampleX1] + fBlendX * fNoiseSeed2D[nSampleY2 * size + nSampleX2];
                
                fNoise += (fBlendY * (fSampleB - fSampleT) + fSampleT) * fScale;
                fScaleAcc += fScale;
                fScale = fScale / fBias;
            }
            fPerlinNoise2D[y * size + x] = fNoise / fScaleAcc;
            
        }
    }
    
}

Noise::~Noise () {
    
}

