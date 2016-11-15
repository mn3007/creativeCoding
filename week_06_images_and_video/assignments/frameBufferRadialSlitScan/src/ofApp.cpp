#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);

    imgWidth = 320;
    imgHeight = 240;
    vidGrabber.initGrabber(imgWidth, imgHeight);

    slitWidth = 5;
    maxBufferSize = 360;
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();

    if (vidGrabber.isFrameNew())
    {
        ofImage img;
        img.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
        img.setFromPixels(vidGrabber.getPixels());
        img.mirror(false, true);
        imgBuffer.push_front(img);
    }

    if (imgBuffer.size()>maxBufferSize) imgBuffer.pop_back();

}

//--------------------------------------------------------------
void ofApp::draw(){

    if (imgBuffer.size()>0)
    {
        int slitLocX = imgBuffer[0].getWidth()/2 - slitWidth/2;

        for (int x=0; x<imgBuffer.size(); x++)
        {
            ofPushMatrix();
            ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
            ofRotate(x);
            imgBuffer[x].drawSubsection(0,0, slitWidth, imgBuffer[0].getHeight(), slitLocX, 0);
            ofPopMatrix();
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
