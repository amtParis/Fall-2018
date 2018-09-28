#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    string xmlSettingsPath = "Particles.xml";
    gui.setup( "Particles", xmlSettingsPath );
    
    gui.add( spaceFrequency.set("Space Frequency",   1.0f,  0.0001f,  1.0f) );
    gui.add( timeFrequency.set("Time Frequency",    1.0f,  0.0001f,  2.0f) );
    gui.add( noiseMagnitude.set("Noise Magnitude",    1.0f,  0.0001f,  1.0f) );

    gui.loadFromFile( xmlSettingsPath );

    ofVec3f spawnSize(30,30,30);
    for( unsigned int i = 0; i < 1000; i++ ){
        Particle p;
        p.setup( ofPoint(ofRandom( -spawnSize.x , spawnSize.x ),
                         ofRandom( -spawnSize.y , spawnSize.y ),
                         ofRandom( -spawnSize.z , spawnSize.z )), ofPoint(0,0,0) );

        particles.push_back(p);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef() * timeFrequency;

    for( unsigned int i = 0; i < particles.size(); i++ ){
        ofPoint noiseReadPos = (particles[i].pos + particles[i].noiseRandomOffset ) * spaceFrequency;

        ofPoint p(0,0,0);
        p.x += ofSignedNoise( noiseReadPos.x, noiseReadPos.y, time );
        p.y += ofSignedNoise( noiseReadPos.y, time,noiseReadPos.z );
        p.z += ofSignedNoise(time, noiseReadPos.z,noiseReadPos.x );
        
        particles[i].addAttraction(ofPoint(0,15,0),100,.0015);
        particles[i].acc += (p * noiseMagnitude);
        particles[i].update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR);
    
    ofEnableDepthTest();
    
    camera.begin();
    
    ofSetColor( ofColor(60) );
    ofPushMatrix();
    ofRotateYDeg(90);//, 0, 0, -1);
    ofTranslate(30, 0, 0);
    ofDrawGridPlane( 10, 12, false );
    ofPopMatrix();
    
    glPointSize(4);
    ofMesh mesh;
    mesh.setMode( OF_PRIMITIVE_POINTS );
    for( unsigned int i = 0; i < particles.size(); i++ ){
        mesh.addColor( ofFloatColor(255,255,255) );
        mesh.addVertex( particles[i].pos );
    }
    mesh.draw();

    camera.end();
    
    ofDisableDepthTest();
    
    gui.draw();
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
