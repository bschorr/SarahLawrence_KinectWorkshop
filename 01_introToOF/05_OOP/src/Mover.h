//
//  Mover.h
//  05_OOP
//
//  Created by Bernardo Schorr on 2/27/15.
//
//

#pragma once
#include "ofMain.h"

class Mover {
public:
    
    void setup();
    void update();
    void draw();
    
    ofVec2f pos, vel;
    
};
