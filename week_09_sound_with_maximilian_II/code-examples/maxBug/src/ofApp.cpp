#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    angleStep = 0.1;

    sampleRate 	= 48000; /* Sampling Rate */
    bufferSize	= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */

    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */
}

//--------------------------------------------------------------
void ofApp::update(){
    if (abs(vizLink)>110) cout << vizLink << "======================================================" << endl;
    //vizLink = ofMap(mouseX, 0, ofGetWidth(), 0, 200);
}

//--------------------------------------------------------------
void ofApp::draw(){
    float width = ofMap(vizLink, -100, 100, -ofGetWidth()/2, ofGetWidth()/2, true);
    ofRect(ofGetWidth()/2,ofGetHeight()/2, width,30);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

    float sum;
    vizLink = 0;

    for (int i = 0; i < bufferSize; i++){

        double modFreq = myOsc3.sinewave(0.1)*100; //how many times
        vizLink += modFreq;

        double wave = myOsc1.sinewave(220+myOsc2.sinewave(modFreq)*100); //should I +-100?

        output[i*nChannels    ]= wave;
        output[i*nChannels + 1]= wave;
    }
    vizLink /= bufferSize;
    cout << "internal: " << vizLink << "   " ;
    cout << "buffSize: " << bufferSize << "    ";
    cout << "nChannels: " << nChannels << "    " << endl;
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