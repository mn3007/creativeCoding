#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    gol.setup(ofGetWidth(), 100);
}

//--------------------------------------------------------------
void ofApp::update(){
    gol.generate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    gol.display();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    gol.setup(ofGetWidth(), 100);
}
