#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    angleStep = 0.1;
    resolution = 2;

}

//--------------------------------------------------------------
void ofApp::update(){

    rotAngle += angleStep;

    //use globSpeed to set the angleStep
    angleStep = ofMap(mouseY, 0, ofGetHeight(), -0.3, 0.3);
}

//--------------------------------------------------------------
void ofApp::draw(){
    resolution = ofMap(mouseX, 0, ofGetWidth(), 2, 20, true);
    int radius1 = 200;

    //use globVol to set radius2
    int radius2 = 400;

    int noOfStars = 20;

    for (float i=0; i<noOfStars; i++) {
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        ofRotate(rotAngle*(i+1));
        ofScale(1-i/noOfStars, 1-i/noOfStars);
        ofSetColor(ofMap(i, 0, noOfStars, 0, 255, true));
        star(0, 0, radius1, radius2, resolution);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::star(float x, float y, float radius1, float radius2, int numOfPoints) {
  float angle = 360.0 / numOfPoints;
  float halfAngle = angle/2.0;

  ofSetPolyMode(OF_POLY_WINDING_NONZERO);
  ofBeginShape();
  for (float a = 0; a < 360.0; a += angle)
  {
    float sx = x + cos(ofDegToRad(a)) * radius2;
    float sy = y + sin(ofDegToRad(a)) * radius2;
    ofVertex(sx, sy);
    sx = x + cos(ofDegToRad(a+halfAngle)) * radius1;
    sy = y + sin(ofDegToRad(a+halfAngle)) * radius1;
    ofVertex(sx, sy);
  }
  ofEndShape();
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

    for (int i = 0; i < bufferSize; i++){

        double wave = 0;

        output[i*nChannels    ]= wave;
        output[i*nChannels + 1]= wave;

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
