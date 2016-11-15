#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false); //turns automatic updating false
    ofBackground(0); //move to draw() in order to update canvas with every frame
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofRect(100, 100, 200, 150);
    ofTriangle(600, 100, 500, 300, 700, 300);
    ofCircle(200, 400, 100);
    ofEllipse(600, 400, 300, 100);
    ofLine(100, 600, 800, 600);

    //custom shape
    ofBeginShape();
    ofVertex(220, 720);
    ofVertex(240, 720);
    ofVertex(240, 740);
    ofVertex(260, 740);
    ofVertex(260, 760);
    ofVertex(220, 760);
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
