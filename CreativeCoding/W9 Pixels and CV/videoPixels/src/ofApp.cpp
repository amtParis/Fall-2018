#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(size_t i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            //log the device
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            //log the device and note it as unavailable
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(320, 240);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    // only do if we have new data
    if(vidGrabber.isFrameNew()){
        
        
        
        ofPixels mypix = vidGrabber.getPixels();
        
        float theBrightest = 0;
        
        int w = vidGrabber.getWidth();
        for(int x = 0; x < vidGrabber.getWidth(); x++){
            for(int y = 0; y < vidGrabber.getHeight(); y++){
                int index = y * w + x;
                ofColor c = mypix.getColor(x,y);

                float brightness = c.getBrightness();
                if( brightness > theBrightest){
                    theBrightest = brightness;
                    brightPos.set(x,y);
                }
                
            }
            
        }
        
        
        vidGrabber.getTexture().loadData(mypix);
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    vidGrabber.draw(0,0, 640,360);
    ofSetColor(255,0,0);
    ofNoFill();
    ofDrawCircle(brightPos.x/2,brightPos.y/2,6);
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
