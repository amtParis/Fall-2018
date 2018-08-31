#include "ofApp.h"
#include "easing.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    // calculate positions of circles
    int total = 40;
    float cX = ofGetWidth()/2;
    float cY = ofGetHeight()/2;
    float r = 300;
    
    for(int i = 0; i < total; i++){
        float a = TWO_PI/(float)total * i;
        circs.push_back( easeCirc() );
        circs[i].setup( ofPoint(cX + r*cos(a), cY+r*sin(a) ), i*.15 );
    }
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for(int i = 0; i < circs.size(); i++){
        circs[i].draw();
    }
    
    // initial lines animation
    for(int i = 0; i < circs.size()/2; i++){
        int endIndex = circs.size()/2 + i;
        float pct = ofClamp( ofMap(ofGetElapsedTimef(),7,8,0,1),0,1 );
        pct = inOutQuint(pct);
        ofPoint dst = ofPoint((1-pct)*circs[i].currPos.x+pct*circs[endIndex].currPos.x,(1-pct)*circs[i].currPos.y+pct*circs[endIndex].currPos.y);
        ofDrawLine(circs[i].currPos.x,circs[i].currPos.y,dst.x,dst.y);
    }
    

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    float rand =ofRandom(-150,150);
    for(int i = 0; i < circs.size(); i++){
        float a = TWO_PI/(float)circs.size() * i;
        float r = 300 + rand;
        float cX = ofGetWidth()/2;
        float cY = ofGetHeight()/2;
        circs[i].setTargetPosition(ofPoint(cX + r*cos(a), cY+r*sin(a) ));
    }
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
    
    for(int i = 0; i < circs.size(); i++){
        float d = ofDist(x, y, circs[i].pos.x,circs[i].pos.y);
        if(d < circs[i].radius){
            float a = TWO_PI/(float)circs.size() * i;
            float r = 300 + ofRandom(-150,150);
            float cX = ofGetWidth()/2;
            float cY = ofGetHeight()/2;
            circs[i].setTargetPosition(ofPoint(cX + r*cos(a), cY+r*sin(a) ));
        }
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
