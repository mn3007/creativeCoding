#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ballSys.setup(10);
}

//--------------------------------------------------------------
void ofApp::update(){
    ballSys.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ballSys.draw();
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ballSys.addBall(x,y);
}
