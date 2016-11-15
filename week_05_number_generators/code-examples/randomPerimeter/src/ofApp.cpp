#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    numOfPoints = 150;
    radius = 200;
    angleStep = 360.0 / numOfPoints;

    for (int i=0; i<numOfPoints; i++)
    {
        randomMargin.push_back(ofPoint(ofRandom(-200,200),ofRandom(-200,200)));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    for (int i=0; i<numOfPoints; i++)
    {
        ofPoint pointLocation;
        pointLocation.x = sin(ofDegToRad(angleStep*i)) * radius;
        pointLocation.y = cos(ofDegToRad(angleStep*i)) * radius;

        pointLocation += randomMargin[i] * ofMap(mouseX, 0, ofGetWidth(), 0, 1);
        ofCircle(pointLocation,2);
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
