#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(200);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(200,0,0);
    ofRect(100, 100, 400, 400);
    ofSetColor(0,200,0);
    ofCircle(300,300,200);
    ofSetColor(0,0,200);
    ofRect(200,200,200,200);

    //alternative solution
    //uncomment the code and remove the code above to run!
/*
    ofSetRectMode(OF_RECTMODE_CENTER); //set the way you define the rectangle
    ofSetColor(200,0,0);
    ofRect(ofGetWidth()/2, ofGetHeight()/2, 400, 400);
    ofSetColor(0,200,0);
    ofCircle(ofGetWidth()/2,ofGetHeight()/2,200);
    ofSetColor(0,0,200);
    ofRect(ofGetWidth()/2,ofGetHeight()/2,200,200);
*/
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
