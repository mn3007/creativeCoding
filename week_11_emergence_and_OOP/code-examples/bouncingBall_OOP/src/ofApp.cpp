#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
        b.move();
        b.bounce();
}

//--------------------------------------------------------------
void ofApp::draw(){
        b.draw();
}