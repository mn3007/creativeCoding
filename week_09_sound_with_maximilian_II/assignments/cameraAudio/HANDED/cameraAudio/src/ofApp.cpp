#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    imgWidth = 640;
    imgHeight = 480;

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(imgWidth, imgHeight);

    readingSpeed = 1;
    pixelLoc = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();

    if (vidGrabber.isFrameNew())
    {
        img.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
        img.setFromPixels(vidGrabber.getPixels());
        img.mirror(false, true);

        int brightness = img.getPixels().getColor(pixelLoc, imgHeight/2).getLightness();

    }

    pixelLoc+=readingSpeed;
    if (pixelLoc>=imgWidth) pixelLoc=0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    img.draw(0,0);
    ofSetLineWidth(3);
    ofLine(pixelLoc, ofGetHeight()/2-10, pixelLoc, ofGetHeight()/2+10);
    ofLine(0, ofGetHeight()/2, imgWidth, ofGetHeight()/2);
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
