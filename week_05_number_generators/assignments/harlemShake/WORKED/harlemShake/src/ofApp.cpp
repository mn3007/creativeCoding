#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetBackgroundAuto(false);
    goCrazy = false;

    spacingX = ofGetWidth() / numX;
    spacingY = ofGetHeight() / numY;

    startingX = spacingX / 2;
    startingY = spacingY / 2;

    stepSize = 20;

    for (int x=0; x<numX; x++)
    {
        for (int y=0; y<numY; y++)
        {
            noiseSeeds[x][y]=ofRandom(1000);
        }
    }

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

            if (goCrazy)
            {
                locX += ofSignedNoise(noiseSeeds[x][y]) * stepSize;
                locY += ofSignedNoise(noiseSeeds[x][y] + 500) * stepSize;
            }
            else if (x==20 && y==20)
            {
                locX += ofSignedNoise(noiseSeeds[x][y]) * stepSize;
                locY += ofSignedNoise(noiseSeeds[x][y] + 500) * stepSize;
            }

            ofEllipse(locX, locY, 3, 3);
            noiseSeeds[x][y] += 0.02;
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
    goCrazy = !goCrazy;
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
