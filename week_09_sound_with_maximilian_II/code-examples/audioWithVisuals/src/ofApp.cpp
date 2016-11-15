#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    sampleRate 	= 48000; /* Sampling Rate */
    bufferSize	= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */

    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    mySample.load(ofToDataPath("sound.wav"));
    ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4); /* this has to happen at the end of setup - it switches on the DAC */

    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float radius = ofMap(RMS,0,1,0,ofGetWidth()/2);

    //comment out to add a low-pass filter
    //radius = lpFilter.lopass(radius, 0.1);

    ofCircle(ofGetWidth()/2, ofGetHeight()/2, radius, radius);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {

    float sum=0;

    for (int i = 0; i < bufferSize; i++){

        double wave;

        //==== EXAMPLE 1 =====
        //playing an audio file at 1x
        wave = mySample.play();

        //==== EXAMPLE 2 =====
        //playing an audio file backwards at half speed
        //wave = mySample.play(-0.5);

        //==== EXAMPLE 3 =====
        //playing an audio file at a variable speed using a phasor. Speeds up slowly and after 5 seconds drops off.
        //wave = mySample.play(osc1.phasor(0.2, 0, 3));

        output[i*nChannels    ]= wave;
        output[i*nChannels + 1]= wave;

        sum += fabs(wave);
    }
    double average = sum/bufferSize;
    RMS = sqrt(average);
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
