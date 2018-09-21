#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundColor(0);
    
    //we need to call this for textures to work on models
    ofDisableArbTex();
    
    //this makes sure that the back of the model doesn't show through the front
    ofEnableDepthTest();
    
    //now we load our model
    model.loadModel("dodeca.obj");
    model.setPosition(ofGetWidth()*.5, ofGetHeight() * 0.75, 0);
    
    light.enable();
    light.setPosition(model.getPosition() + ofPoint(500, -1000, 1000));
    
    baseVal.set(0,0,0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    baseVal += ofPoint(.01,.01,.01);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofMesh mesh = model.getMesh(0);
    auto &verts = mesh.getVertices();
    ofPoint center = mesh.getCentroid();
    
    for(unsigned int i = 0; i < verts.size(); i++){
        
        ofPoint fromCenter = verts[i]-center;
        fromCenter = fromCenter.normalize();
        
        verts[i].x += fromCenter.x * 2*(ofSignedNoise(verts[i].x/15+baseVal.x,verts[i].y/15+baseVal.y));
        verts[i].y += fromCenter.y * 2*(ofSignedNoise(verts[i].y/15+baseVal.y,verts[i].z/15+baseVal.z));
        verts[i].z += fromCenter.z * 2*(ofSignedNoise(verts[i].z/15+baseVal.z,verts[i].x/15+baseVal.x));
        
    }
    
    ofVec3f scale = model.getScale();
    float normalizedScale = model.getNormalizedScale();

    ofPushMatrix();
    
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2,0);
        ofRotateDeg(-ofGetMouseX(), 0, 1, 0);
        ofScale(normalizedScale, normalizedScale, normalizedScale);
        ofScale(scale.x,scale.y,scale.z);
        ofTranslate(0,-14,0); // model has a y offset adjust it

        mesh.drawFaces();
    
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
