#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetBackgroundAuto(false);

    spacingX = ofGetWidth() / numX;
    spacingY = ofGetHeight() / numY;

    startingX = spacingX / 2;
    startingY = spacingY / 2;

    for (int x=0; x<numX; x++)
    {
        for (int y=0; y<numY; y++)
        {
            noiseSeeds[x][y]=ofRandom(1000);
        }
    }

    //insert audio stuff here

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,20);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());

    ofSetColor(255);

    for (int x=0; x<numX; x++)
    {
      for (int y=0; y<numY; y++)
      {
            int locX = startingX + spacingX * x;
            int locY = startingY + spacingY * y;

            //set step size based on globVol
            float stepSize = ofMap(mouseX, 0, ofGetWidth(), 1, 90);

            locX += ofSignedNoise(noiseSeeds[x][y]) * stepSize;
            locY += ofSignedNoise(noiseSeeds[x][y] + 500) * stepSize;

            ofEllipse(locX, locY, 3, 3);

            //walk down the noise graph using globalFreq
            float speed = ofMap(mouseY, 0, ofGetHeight(), 0, 0.04);
            noiseSeeds[x][y] += speed;
      }
    }
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {


    for (int i = 0; i < bufferSize; i++)
    {
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
