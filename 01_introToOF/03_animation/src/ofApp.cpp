#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    bkg.r = ofRandom(0, 255);
    bkg.g = ofRandom(0, 255);
    bkg.b = ofRandom(0, 255);
    
    ofBackground(bkg);
    
    x = 0;
    y = 0;
    
    xSpeed = 1;
    ySpeed = 3;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    x = x + xSpeed;
    y = y + ySpeed;
    
    if (x < 0) {
        xSpeed = xSpeed * -1;
    }
    
    if (x > ofGetWidth()) {
        xSpeed = xSpeed * -1;
    }
    
    if (y < 0) {
        ySpeed = ySpeed * -1;
    }
    
    if (y > ofGetHeight()) {
        ySpeed = ySpeed * -1;
        bkg.r = ofRandom(0, 255);
        bkg.g = ofRandom(0, 255);
        bkg.b = ofRandom(0, 255);
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(bkg);
    ofCircle(x, y, 10);

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
