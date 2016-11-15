#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofBackground(0);
        numOfBalls = 30;

        for (int x=0; x<numOfBalls; x++)
        {
            Ball b;
            balls.push_back(b);
        }
}

//--------------------------------------------------------------
void ofApp::update(){

        for (int x=0; x<balls.size(); x++)
        {
            balls[x].move();
            balls[x].bounce();
        }
}

//--------------------------------------------------------------
void ofApp::draw(){

        for (int x=0; x<balls.size(); x++)
        {
            balls[x].draw();
        }
}
