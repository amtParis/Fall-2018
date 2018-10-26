#include "ofApp.h"

static bool shouldRemove(shared_ptr<ofxBox2dBaseShape>shape) {
    return !ofRectangle(0, -400, ofGetWidth(), ofGetHeight()+400).inside(shape->getPosition());
}

static bool shouldRemovePoly(shared_ptr<ofxBox2dPolygon>shape) {
    return true;
}
//--------------------------------------------------------------
void ofApp::setup(){
    vidPlayer.load("fingers.mov");
    vidPlayer.play();
    vidPlayer.setLoopState(OF_LOOP_NORMAL);
    
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
    
    bLearnBakground = true;
    threshold = 80;
    ofBackground(100,100,100);
    
    
    // Box2d
    box2d.init();
    box2d.setGravity(0, 10);
    box2d.createGround();
    box2d.setFPS(30.0);
    
    bHasShape = false;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    bool bNewFrame = false;
    vidPlayer.update();
    bNewFrame = vidPlayer.isFrameNew();
    
    if (bNewFrame){
        colorImg.setFromPixels(vidPlayer.getPixels());
        grayImage = colorImg;
        if (bLearnBakground == true){
            grayBg = grayImage;        // the = sign copys the pixels from grayImage into grayBg (operator overloading)
            bLearnBakground = false;
        }
        
        // take the abs value of the difference between background and incoming and then threshold:
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(threshold);
        
        // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
        // also, find holes is set to true so we will get interior contours as well....
        contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);    // find holes
        
        if(contourFinder.nBlobs > 0){
            if(bHasShape) shape.clear();
            for(int i=contourFinder.blobs[0].pts.size()-1; i>=0; i--) {
                shape.addVertex(contourFinder.blobs[0].pts[i].x*4, contourFinder.blobs[0].pts[i].y*4);
            }
            shape.create(box2d.getWorld());
            bHasShape = true;
        }

    }
    
    
    // add some circles every so often
    if((int)ofRandom(0, 10) == 0) {
        auto circle = std::make_shared<ofxBox2dCircle>();
        circle->setPhysics(0.3, 0.5, 0.1);
        circle->setup(box2d.getWorld(), (ofGetWidth()/2)+ofRandom(-20, 20), -20, ofRandom(10, 20));
        circles.push_back(circle);
    }
    
    // remove shapes offscreen
    ofRemove(circles, shouldRemove);
    // ofRemove(polyShapes, shouldRemove);
    
    box2d.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(contourFinder.nBlobs > 0){
        contourFinder.blobs[0].draw(0,0);
    }
    
    
    // some circles :)
    for(int i=0; i<circles.size(); i++) {
        ofFill();
        ofSetHexColor(0xc0dd3b);
        circles[i]->draw();
    }
    
    ofNoFill();
    shape.draw();
//    for(int i=0; i<polyShapes.size(); i++) {
//        polyShapes[i].draw();
//        
////        ofDrawCircle(polyShapes[i]->getPosition(), 3);
//    }
    
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
