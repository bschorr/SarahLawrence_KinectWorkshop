#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    kinect.init();
    kinect.open();
    
    kinect.setCameraTiltAngle(15);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    kinect.update();
    distanceTrack = 10000;
    
    if(kinect.isFrameNew()) {
        
        for(int y = 0; y < 480; y++) {
            for(int x = 0; x < 640; x++) {
                
                float currDistance = kinect.getDistanceAt(x, y);
                if(currDistance < distanceTrack && currDistance != 0) {
                    distanceTrack = currDistance;
                    posX = x;
                    posY = y;
                }
            }
        }
        
        posX = ofMap(posX, 640, 0, 0, ofGetWidth());
        posY = ofMap(posY, 0, 480, 0, ofGetHeight());
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255);
    //kinect.drawDepth(0, 0, ofGetWidth(), ofGetHeight());
    
    ofSetColor(255, 0, 0);
    ofCircle(posX, posY, 10);

}

void ofApp::exit() {
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
