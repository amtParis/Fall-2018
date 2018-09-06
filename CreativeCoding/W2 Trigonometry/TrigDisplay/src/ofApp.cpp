#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(40);
    ofSetBackgroundColor(0);
    ofEnableAntiAliasing();
    
    origin = ofPoint(100,ofGetHeight()/2);
    radius = 50;
    angle = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    angle += .025;
    ofPoint dst = ofPoint(origin.x + 2*radius,origin.y + radius * sin(angle));

    for(int i = 0; i < sinPts.size(); i++){
        sinPts[i].x += .75;
    }
    sinPts.insert(sinPts.begin(),dst);
    
    if( sinPts[ sinPts.size()-1 ].x > ofGetWidth() ){
        sinPts.pop_back();
    }
    
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    // draw circle
    ofNoFill();
    ofDrawCircle(origin.x,origin.y,radius);
    
    // draw moving point
    ofPoint dst = ofPoint(origin.x + radius * cos(angle),origin.y + radius * sin(angle));
    ofFill();
    ofDrawCircle(dst.x ,dst.y,2);
    ofDrawLine(origin,dst);
    
    // draw line at amplitude of sin wave
    ofDrawLine(dst,ofPoint(origin.x + 2*radius, dst.y));
    
    // draw sin wave
    ofNoFill();
    
    ofPushMatrix();
    
    ofBeginShape();
    for(int i = 0; i < sinPts.size(); i++){
        ofVertex(sinPts[i].x,sinPts[i].y);
    }
    ofEndShape();
    
    ofPopMatrix();
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
