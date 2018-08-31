//
//  easeCirc.cpp
//  EasingCircleSketch
//
//  Created by csugrue on 8/30/18.
//
#include "easeCirc.h"
#include "easing.h"

void easeCirc::setup(ofPoint _pos, float delay){
    targetRadius = 10;
    radius = 0;
    pos = _pos;
    targetPos = _pos;
    startTime = ofGetElapsedTimef()+delay;
    endTime = startTime+1;
}

void easeCirc::update(){
}

void easeCirc::draw(){
    
    
    float pct = ofClamp( ofMap(ofGetElapsedTimef(),startTime,endTime,0,1),0,1 );
    pct = outBack(pct);
    if(pct >= 1) radius = targetRadius;
    
    float posPct = ofClamp( ofMap(ofGetElapsedTimef(),startTime,endTime,0,1),0,1 );
    posPct =outBounce(posPct);
    if(posPct >= 1) pos = targetPos;
    
    ofPoint dstPos = ofPoint((1-posPct)*pos.x+posPct*targetPos.x,(1-posPct)*pos.y+posPct*targetPos.y);
    currPos = dstPos;
    float newRadius = (1-pct)*radius + pct*targetRadius;
    ofDrawCircle(dstPos.x,dstPos.y, newRadius);
}



void easeCirc::setTargetPosition(ofPoint _pos){
    startTime = ofGetElapsedTimef();
    endTime = startTime+1;
    targetPos = _pos;
}


