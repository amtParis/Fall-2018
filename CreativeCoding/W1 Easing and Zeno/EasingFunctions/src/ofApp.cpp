#include "ofApp.h"
#include "easing.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(pct < 1) pct+= .15 * ofGetLastFrameTime();
    pct = ofClamp(pct,0,1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float myPct = pct;
    float y = 0;
    
    ofSetColor(ofColor::hotPink);
    drawMovingRect(inOutBack(myPct),y+=100);
    drawMovingRect(outBounce(myPct),y+=100);
    drawMovingRect(linear(myPct),y+=100);
    drawMovingRect(inOutQuint(myPct),y+=100);
    drawMovingRect(inOutSine(myPct),y+=100);
    
    
}

void ofApp::drawMovingRect(float t, int y){
    
    float start = 200;
    float end = 800;
    ofDrawRectangle( (1-t)*start + t*end, y, 30,30);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    pct = 0;
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
