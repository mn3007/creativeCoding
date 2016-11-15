#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(200,0,200);
    ballSys.setup(300);
}

//--------------------------------------------------------------
void ofApp::update(){
    ballSys.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ballSys.draw();
    ofDrawBitmapString("Total Balls: " + ofToString(ballSys.balls.size()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    ballSys.infectBall(x,y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ballSys.addBall(mouseX, mouseY);
}
