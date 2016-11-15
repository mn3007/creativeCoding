#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //CIRCLE movement
    ofSetColor(255);
    float margin = sin(ofDegToRad(ofGetFrameNum())) * 100;
    float locY = ofGetHeight()*0.25;
    ofCircle(150+margin, locY, 10);

    //RECT rotation
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.75, ofGetHeight()*0.25);
    float angle = sin(ofDegToRad(ofGetFrameNum())) * 180;
    ofRotate(angle);
    ofRect(0,0,50,50);
    ofPopMatrix();

    //RECT color
    ofSetRectMode(OF_RECTMODE_CORNER);
    float c = ofMap(sin(ofDegToRad(ofGetFrameNum())), -1, 1, 0, 255);
    ofSetColor(c);
    ofRect(0, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);
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
