//
//  Mover.cpp
//  05_OOP
//
//  Created by Bernardo Schorr on 2/27/15.
//
//

#include "Mover.h"

void Mover::setup() {
    
    pos.x = ofGetWidth() / 2;
    pos.y = ofGetHeight() / 2;
    
    vel.x = ofRandom(-3, 3);
    vel.y = ofRandom(-3, 3);
    
}

void Mover::update(){
    
    pos += vel;
    
}

void Mover::draw(){
    
    ofCircle(pos, 5);
    
}