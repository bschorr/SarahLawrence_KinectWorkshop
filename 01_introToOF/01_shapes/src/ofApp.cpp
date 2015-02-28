#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0, 120, 80);
    //ofBackgroundHex(0x00ff00);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //circle + set color
    ofFill();
    ofSetColor(255, 150, 150);
    ofCircle(400, 400, 200);
    
    // circle + RGBA color
    ofSetColor(200, 0, 255, 50);
    ofCircle(200, 200, 100);
    
    //  a rectangle
    ofRect(500, 450, 300, 100);
    
    // alpha color + a line
    ofSetColor(255);
    ofLine(50, 50, 500, 500);
    
    // Drawing a polygon with no fill
    ofSetColor(0, 230, 180);

    ofNoFill();

    ofBeginShape();
        ofVertex(500, 300);
        ofVertex(250, 400);
        ofVertex(500, 500);
        ofVertex(250, 600);
        ofVertex(500, 700);
    ofEndShape(true);
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
