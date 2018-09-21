#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    counter  = 0;
    fbo.allocate(ofGetWidth(), ofGetHeight());
    ofSetBackgroundColor(0 );
    
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    counter += .01;
    
    fbo.begin();
    
    ofSetColor(0,0,0,5);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPoint last;
    for(int i = 0; i < 100; i++){
        
        float x = ofNoise( counter, i*.005 )*ofGetWidth();
        float y = ofNoise( i*.005,counter ) *ofGetHeight();
        
        ofSetColor(255,255,255);
        ofDrawCircle( x,y,2);
        
        if(i > 0){
            ofDrawLine(ofPoint(x,y),last);
        }
        last.set(x,y);
        
    }
    
    fbo.end();
    
    fbo.draw(0,0);
    
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
