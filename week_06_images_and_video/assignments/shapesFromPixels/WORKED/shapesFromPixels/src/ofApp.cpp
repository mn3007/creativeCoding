#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());

    spacing = 10;
    startPos = spacing/2;

    mode = 1;
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();

    if (vidGrabber.isFrameNew())
    {
        pixels = vidGrabber.getPixels();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int x=0; x<ofGetWidth(); x+=spacing)
    {
        for (int y=0; y<ofGetHeight(); y+=spacing)
        {
            if (mode==1)
            {
                ofColor c = pixels.getColor(x,y);
                int brightness = c.getBrightness();
                int locX = startPos + x;
                int locY = startPos + y;
                ofSetColor(c);
                float maxSize = ofMap(mouseX, 0, ofGetWidth(), 0, spacing*2, true);
                float radius = ofMap(brightness, 0, 255, maxSize, 0);

                ofPushMatrix();
                ofTranslate(locX, locY);
                ofCircle(0, 0, radius);
                ofPopMatrix();
            }
            else if (mode==2)
            {
                ofColor c = pixels.getColor(x,y);
                int brightness = c.getBrightness();
                int locX = startPos + x;
                int locY = startPos + y;
                ofSetColor(c);
                ofSetLineWidth(ofMap(brightness, 0, 255, 3, 1));
                float maxSize = ofMap(mouseX, 0, ofGetWidth(), 0, spacing*4,true);
                float length = ofMap(brightness, 0, 255, maxSize, 3);

                ofPushMatrix();
                ofTranslate(locX, locY);
                ofRotate(ofMap(brightness, 0, 255, 0, 180, true));
                ofLine(0,0,length,0);
                ofPopMatrix();
            }

        }
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == '1'){
        mode = 1;
    }
    else if (key =='2'){
        mode = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
