#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofVideoPlayer         vidPlayer;
    
        ofxCvColorImage         colorImg;
        ofxCvGrayscaleImage     grayImage;
        ofxCvGrayscaleImage     grayBg;
        ofxCvGrayscaleImage     grayDiff;
        ofxCvContourFinder     contourFinder;
    
        int                 threshold;
        bool                bLearnBakground;
    
    
        ofxBox2d                              box2d;
        vector <shared_ptr<ofxBox2dCircle>>   circles;
    ofxBox2dEdge shape;
    bool bHasShape;
		
};
