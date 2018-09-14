#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofEnableAlphaBlending();
    
    for (int i = 0; i < 150; i++) {
        Particle p;
        p.setup(ofPoint( ofRandom(30,ofGetWidth()-30),ofRandom(30,ofGetHeight()-30)),
                ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)));
        particles.push_back(p);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // particle to particle repulsion
    float particleDist = 35;
    for( int i = 0; i < particles.size(); i++){
        
        for( int j = 0; j < i; j++){
            particles[i].addRepulsion(particles[j].pos, particleDist, 0.25);
            particles[j].addRepulsion(particles[i].pos, particleDist, 0.25);
        }
    }
    
    // attraction to the mouse and update
    ofPoint mouse = ofPoint(mouseX,mouseY);

    for (int i = 0; i < particles.size(); i++) {
        particles[i].addAttraction(mouse, 100, 0.015);
        particles[i].update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // draw lines between
    ofNoFill();
    for( int i = 0; i < particles.size(); i++){
        
        for( int j = 0; j < i; j++){
            ofPoint diffVec =particles[i].pos-particles[j].pos;
            float d = diffVec.length();

            if(d < 100 ){
                float alpha = ofMap(d,100,0,0,255);
                ofSetColor(255,alpha);
                ofDrawLine(particles[i].pos,particles[j].pos);
            }
            
        }
    }
    
    
   ofFill();
    for( int i = 0; i < particles.size(); i++){
//        particles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Particle p;
    p.setup( ofPoint(x,y),ofPoint(ofRandom(-1, 1), ofRandom(-1, 1)) );
    particles.push_back(p);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
