#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    scale = 3;
    noiseScale = 0.02;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int x=0; x<ofGetWidth()/scale; x++)
    {
        for (int y=0; y < ofGetHeight()/scale; y++)
        {
            float noiseValue = ofNoise(x*noiseScale, y*noiseScale, float(ofGetFrameNum())*noiseScale);
            ofSetColor(noiseValue * 255);
            ofRect(x*scale,y*scale,scale,scale);
        }
    }
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
