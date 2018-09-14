//
//  Particle.cpp
//  simpleParticles
//
//  Created by csugrue on 9/11/18.
//

#include "Particle.hpp"


Particle::Particle() {
    pos.x = ofGetWindowWidth()*0.5;
    pos.y = ofGetWindowHeight()*0.5;
    pos.z = 0.0;
    
    vel.set(0,0,0);
    acc.set(0,0,0);
    
    damp = 0.9; // de resistance!!!
    radius = 10;
}

void Particle::setup(ofPoint _pos){
    pos = _pos;
    vel.set(0,0,0);
    acc.set(0,0,0);
}

void Particle::addForce(ofPoint _force){
    acc += _force;
}

void Particle::update() {
    
    vel += acc;
    vel *= damp;
    pos += vel;
    acc *= 0.0;
    
    if( pos.x < 0.0+radius || pos.x > ofGetWidth()-radius ){
        pos.x -= vel.x; // Bounced back! think of this as an undo;
        vel.x *= -1.0;
    }
    
    if( pos.y < 0.0+radius || pos.y > ofGetHeight()-radius ){
        pos.y -= vel.y; // Bounced back! think of this as an undo;
        vel.y *= -1.0;
    }
}

void Particle::draw() {
    ofDrawCircle(pos, radius);
}
