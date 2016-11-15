#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofBackground(0);
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){
    angleSec = ofMap(ofGetSeconds(), 0, 60, 0, 360);

    float minsPlusSecs = ofGetMinutes() + ofMap(ofGetSeconds(), 0, 60, 0, 1);  // we're doing this because the hour indicator is moving between hours as the minutes pass.
    angleMin = ofMap(minsPlusSecs, 0, 60, 0, 360);

    float hourPlusMins = ofGetHours()%12 + ofMap(ofGetMinutes(), 0, 60, 0, 1);  // we're doing this because the hour indicator is moving between hours as the minutes pass.
    angleHour = ofMap(hourPlusMins, 0, 12, 0, 360);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(3);
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, 200);

    //seconds
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angleSec);
    ofSetLineWidth(1);
    ofSetColor(220,0,0);
    ofLine(0,0,0,-180);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angleMin);
    ofSetLineWidth(3);
    ofSetColor(255);
    ofLine(0,0,0,-150);
    ofPopMatrix();

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotate(angleHour);
    ofSetLineWidth(5);
    ofLine(0,0,0,-110);
    ofPopMatrix();
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
