#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    location = ofPoint(20, 0);
    velocity = ofPoint(5, 0);
    gravity = ofPoint(0,0.1);

    ofBackground(0);
    ballRad = 20;
}

//--------------------------------------------------------------
void ofApp::update(){
    friction = velocity.getNormalized() * -1 * 0.01;
    velocity = velocity + friction;
    velocity = velocity + gravity;
    location = location + velocity;

    if (location.x > ofGetWidth() - ballRad || location.x < ballRad) {
        velocity.x = velocity.x * -1;
    }

    if (location.y > ofGetHeight() - ballRad) {  //only checks the bottom boundary
        velocity.y = velocity.y * -1;
        location.y = ofGetHeight() - ballRad;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("Press mouse to reset ball", 390, 20);
    ofCircle(location, ballRad);
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
    location = ofPoint(mouseX, mouseY);
    velocity = ofPoint(5, 0);
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
