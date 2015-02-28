#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    for (int i = 0; i < 100; i++) {
        Mover myMover;
        myMover.setup();
        moverList.push_back(myMover);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < moverList.size(); i++) {
        moverList[i].draw();
    }

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
