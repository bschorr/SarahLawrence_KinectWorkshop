#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    
    device.setup();
    
    if (tracker.setup(device))
    {
        cout << "tracker inited" << endl;
    }
    
    bDrawDebug = true;
    
}

void ofApp::exit()
{
    tracker.exit();
    device.exit();
}

//--------------------------------------------------------------
void ofApp::update()
{
    device.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    if (bDrawDebug) drawDebug();
    
    //MAGIC
    for (int i = 0; i < tracker.getNumUser(); i++){
        
        ofxNiTE2::User::Ref user = tracker.getUser(i);
        const ofxNiTE2::Joint &joint = user->getJoint(nite::JOINT_RIGHT_HAND);
        jointPos = joint.getGlobalPosition();
        pos = tracker.getOverlayCamera().worldToScreen(jointPos);
        
    }
    
    //all drawing takes place here
    ofSetColor(255, 0, 0);
    ofCircle(pos.x, pos.y, 50);
    //ofCircle(pos.x, pos.y, abs(jointPos.z)*0.05);
    
}

void ofApp::drawDebug() {
    // draw depth
    depth_image.setFromPixels(tracker.getPixelsRef(1000, 4000));
    
    ofSetColor(255);
    depth_image.draw(0, 0, ofGetWidth(), ofGetHeight());
    
    // draw in 2D
    ofPushView();
    tracker.getOverlayCamera().begin(ofRectangle(0, 0, ofGetWidth(), ofGetHeight()));
    ofDrawAxis(100);
    tracker.draw();
    tracker.getOverlayCamera().end();
    ofPopView();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    switch (key) {
        case ' ':
            bDrawDebug = !bDrawDebug;
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    
}