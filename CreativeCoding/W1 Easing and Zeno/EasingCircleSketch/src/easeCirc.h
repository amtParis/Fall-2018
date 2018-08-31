//
//  easeCirc.hpp
//  EasingCircleSketch
//
//  Created by csugrue on 8/30/18.
//

#pragma once

#include "ofMain.h"

class easeCirc{
    
public:
    void setup(ofPoint pos, float delay=0);
    void update();
    void draw();
    
    void setTargetPosition(ofPoint pos);
    
    float targetRadius;
    float radius;
    ofPoint pos;
    ofPoint currPos;
    ofPoint targetPos;
    float startTime;
    float endTime;
    
};
