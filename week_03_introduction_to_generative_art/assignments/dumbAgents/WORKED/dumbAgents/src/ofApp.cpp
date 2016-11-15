#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);

    north = 0;
    northEast = 1;
    east = 2;
    southEast = 3;
    south = 4;
    southWest = 5;
    west = 6;
    northWest = 7;

    colorOne = ofColor(0,0,255,40);
    colorTwo = ofColor(255,0,0,40);

    //if you don't want overlapping ellipses make sure
    //stepSize and diam divide the window size (900x600) exactly.
    stepSize = 10;
    diam = 10;

    locX = ofGetWidth() / 2;
    locY = ofGetHeight() / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
    direction = int(ofRandom(8));

    if (direction == north){
        locY = locY - stepSize;
    } else if (direction == northEast){
        locX = locX + stepSize;
        locY = locY - stepSize;
    } else if (direction == east){
        locX = locX + stepSize;
    } else if (direction == southEast){
        locY = locY + stepSize;
        locX = locX + stepSize;
    } else if (direction == south){
        locY = locY + stepSize;
    } else if (direction == southWest){
        locY = locY + stepSize;
        locX = locX - stepSize;
    } else if (direction == west){
        locX = locX - stepSize;
    } else if (direction == northWest){
        locY = locY - stepSize;
        locX = locX - stepSize;
    }

    if (locX > ofGetWidth()-1) locX = 0;
    else if (locX < 0) locX = ofGetWidth()-1;
    else if (locY > ofGetHeight()-1) locY = 0;
    else if (locY < 0) locY = ofGetHeight()-1;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(colorOne.getLerped(colorTwo, ofMap(locX, 0, ofGetWidth(), 0, 1)));
    ofEllipse(locX, locY, diam, diam);
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
