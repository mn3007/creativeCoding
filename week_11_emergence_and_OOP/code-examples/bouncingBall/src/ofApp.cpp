#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        ofBackground(0);
        location = ofPoint(ofRandomWidth(), ofRandomHeight());
        velocity = ofPoint(ofRandom(-3,3), ofRandom(-3,3));
        radius = ofRandom(5, 15);
        color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------------
void ofApp::update(){
        moveBall();
        bounceBall();
}

//--------------------------------------------------------------
void ofApp::draw(){
        drawBall();
}

//--------------------------------------------------------------
void ofApp::drawBall(){
        ofSetColor(color);
        ofCircle(location, radius);
}

//--------------------------------------------------------------
void ofApp::moveBall(){
        location = location + velocity;
}

//--------------------------------------------------------------
void ofApp::bounceBall() {
        if (location.x>=ofGetWidth()-radius || location.x<=0+radius){
            velocity.x = velocity.x * -1;
        }
        if (location.y>=ofGetHeight()-radius || location.y<=0+radius){
            velocity.y = velocity.y * -1;
        }
}
