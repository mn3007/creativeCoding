#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    noiseStep = 0;
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //CIRCLE movement
    ofSetColor(255);
    float locX = ofNoise(noiseStep) * ofGetWidth()/2;
    float locY = ofNoise(noiseStep+500) * ofGetHeight()/2;
    ofCircle(locX, locY, 10);

    //RECT rotation
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(ofGetWidth()*0.75, ofGetHeight()*0.25);
    ofRotate(ofNoise(noiseStep)*360);
    ofRect(0,0,50,50);
    ofPopMatrix();

    //RECT color
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofSetColor(ofNoise(noiseStep)*255, 0, 0);
    ofRect(0, ofGetHeight()/2, ofGetWidth()/2, ofGetHeight()/2);


    noiseStep += 0.01;
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
