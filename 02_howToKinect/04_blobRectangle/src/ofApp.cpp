#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetFrameRate(60);
    
    //init kinect
    kinect.init();
    kinect.open();
    
    //init cv images
    grayImage.allocate(kinect.width, kinect.height);
    grayThreshNear.allocate(kinect.width, kinect.height);
    grayThreshFar.allocate(kinect.width, kinect.height);
    
    //initial thresh values
    nearThreshold = 255;
    farThreshold = 155;
    
    // zero the tilt on startup
    angle = 0;
    kinect.setCameraTiltAngle(angle);
    
    //
    bDrawDebug = true;
    
}

//--------------------------------------------------------------
void ofApp::update() {
    
    ofBackground(100, 100, 100);
    
    kinect.update();
    
    if(kinect.isFrameNew()) {
        
        grayImage.setFromPixels(kinect.getDepthPixels(), kinect.width, kinect.height);
        
        grayThreshNear = grayImage;
        grayThreshFar = grayImage;
        grayThreshNear.threshold(nearThreshold, true);
        grayThreshFar.threshold(farThreshold);
        cvAnd(grayThreshNear.getCvImage(), grayThreshFar.getCvImage(), grayImage.getCvImage(), NULL);
        
        // update the cv images
        grayImage.flagImageChanged();
        
        // find contours which are between the size of 100 pixels and all kinect pixels.
        // find holes is set to false, so we won't get the interior contours as well....
        contourFinder.findContours(grayImage, 100, kinect.width*kinect.height/2, 1, false);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofBackground(255, 0, 0);
    
    if (contourFinder.blobs.size() > 0) {
        float x = contourFinder.blobs[0].boundingRect.getX();
        float y = contourFinder.blobs[0].boundingRect.getY();
        float w = contourFinder.blobs[0].boundingRect.getWidth();
        float h = contourFinder.blobs[0].boundingRect.getHeight();
        
        x = ofMap(x, 0, 640, 0, ofGetWidth());
        y = ofMap(y, 0, 480, 0, ofGetHeight());
        w = ofMap(w, 0, 640, 0, ofGetWidth());
        h = ofMap(h, 0, 480, 0, ofGetHeight());
        
        ofSetColor(0, 255, 0);
        ofRect(x, y, w, h);
    }
    
    
    if (bDrawDebug) drawDebug();
    
}

void ofApp::drawDebug() {
    
    ofSetColor(255, 255, 255);
    
    kinect.drawDepth(10, 10, 400, 300);
    kinect.draw(420, 10, 400, 300);
    
    grayImage.draw(10, 320, 400, 300);
    contourFinder.draw(10, 320, 400, 300);
    
    //All of this is just writing useful info to the screen
    
    stringstream reportStream;
    
    reportStream << "set near threshold " << nearThreshold << " (press: + -)" << endl
    << "set far threshold " << farThreshold << " (press: < >) num blobs found " << contourFinder.nBlobs << endl
    << "fps: " << ofGetFrameRate() << endl
    <<"press UP and DOWN to change the tilt angle: " << angle << " degrees" << endl
    <<"press space to hide debug" << endl;
    
    ofDrawBitmapString(reportStream.str(), 20, 652);
    
}

//--------------------------------------------------------------
void ofApp::exit() {
    kinect.setCameraTiltAngle(0); // zero the tilt on exit
    kinect.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
    switch (key) {
        case '>':
        case '.':
            farThreshold ++;
            if (farThreshold > 255) farThreshold = 255;
            break;
            
        case '<':
        case ',':
            farThreshold --;
            if (farThreshold < 0) farThreshold = 0;
            break;
            
        case '+':
        case '=':
            nearThreshold ++;
            if (nearThreshold > 255) nearThreshold = 255;
            break;
            
        case '-':
            nearThreshold --;
            if (nearThreshold < 0) nearThreshold = 0;
            break;
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
            
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
        case ' ':
            bDrawDebug = !bDrawDebug;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{}
