#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int total = 40;
    float cX = ofGetWidth()/2;
    float cY = ofGetHeight()/2;
    float r = 200;
    float t = ofGetElapsedTimef() * ofMap(mouseY,0,ofGetHeight(),0,2);
    float amp = ofMap(mouseX,0,ofGetWidth(),0,100);
    for(int i = 0; i < total; i++){
        float a = TWO_PI/(float)total * i;
        float ra = r + amp * ofSignedNoise( t , i);
        float x = ra*cos(a);
        float y = ra*sin(a);
        ofDrawCircle( ofPoint(cX + x, cY+y ), 10 );
        ofDrawLine(cX,cY,cX+x,cY+y);
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
