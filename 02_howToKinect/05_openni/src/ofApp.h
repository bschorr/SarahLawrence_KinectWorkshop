#pragma once

#include "ofMain.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void exit();
        
        void update();
        void draw();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
        void drawDebug();
        
        ofxNI2::Device device;
        ofxNiTE2::UserTracker tracker;
        
        ofImage depth_image;
        ofEasyCam cam;
        
        bool bDrawDebug;
        
        ofVec3f jointPos;
        ofVec3f pos;
		
};
