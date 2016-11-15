#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofNoFill();
    ofSetBackgroundAuto(false);
    ofBackground(255);
    ofSetColor(0,10);
    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update(){
    circleRes = ofMap(mouseX, 0, ofGetWidth(), 3, 10, true);
    circleRad = mouseY / 2;
    ofSetCircleResolution(circleRes);
}

//--------------------------------------------------------------
void ofApp::draw(){
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'r' || key == 'R'){
        ofBackground(255);
    }
    else if (key == 's' || key == 'S'){
        ofSaveScreen(ofToString(ofGetFrameNum())+".png");
    }
    else if (key == '1'){
        ofSetColor(0, 10);
        //ofSetColor(ofColor::black, 25); // alternative way of choosing color (ie. by name)
    }
    else if (key == '2'){
        ofSetColor(0,130,163,10);

    }
    else if (key == '3'){
        ofSetColor(181,156,0,10);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofCircle(ofGetWidth()/2, ofGetHeight()/2, circleRad);

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
