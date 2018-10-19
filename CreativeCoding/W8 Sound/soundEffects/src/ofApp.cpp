#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sound1.load("1.mp3");
    sound1.setMultiPlay(true);
    sound1.play();
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for( auto & p : particles){
        p.addForce(ofPoint(0,.25));
        p.update();
        
        if(p.bPlayContact){
            p.bPlayContact = false;
            sound1.setVolume(p.vel.length());
            sound1.play();
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for( auto & p : particles){
        p.draw();
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
    ofPoint centerPt = ofPoint(x,y);
    
    for(int i = 0; i < 20; i++){
        Particle p;
        p.setup( centerPt );
        p.vel = ofPoint( ofRandom(-25,25), ofRandom(-10,-30) );
        particles.push_back(p);
    }
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
