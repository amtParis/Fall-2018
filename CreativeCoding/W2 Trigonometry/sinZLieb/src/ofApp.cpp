#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i < 800; i++){
//        ofDrawCircle(ofGetWidth()/2,i,40,40);
        
//        ofDrawCircle(ofGetWidth()/2 + 200 * sin(ofGetElapsedTimef()+i*.01) ,i,40,40);
        
//        ofSetColor( 127 + 127 * sin(i*.01 + ofGetElapsedTimef()));
        ofDrawCircle(
                     ofGetWidth()/2 + 200 * sin(ofGetElapsedTimef()+i*.01), i,
                     40+ 30* cos(ofGetElapsedTimef()+i*.021),
                     40+ 30* cos(ofGetElapsedTimef()+i*.01) );
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
