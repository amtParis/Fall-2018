#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
    if(pct < 1) pct += .25 * ofGetLastFrameTime();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawCircle(pct*ofGetWidth(), ofGetHeight()*.25, 30);
    
    float myPct = powf(pct,1.5f);
    ofDrawCircle(myPct*ofGetWidth(), ofGetHeight()/2, 30);
    
    myPct = powf(pct,.5f);
    ofDrawCircle(myPct*ofGetWidth(), ofGetHeight()*.75, 30);
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
