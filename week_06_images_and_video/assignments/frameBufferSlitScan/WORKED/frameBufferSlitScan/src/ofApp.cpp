#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);

    imgWidth = 320;
    imgHeight = 240;
    vidGrabber.initGrabber(imgWidth, imgHeight);

    slitWidth = 1;
    maxBufferSize = ofGetWidth()/slitWidth;
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
        imgBuffer[0].draw(0, 0);
        int slitLocX = imgBuffer[0].getWidth()/2 - slitWidth/2;
        ofSetColor(255,0,0);
        ofRect(slitLocX, 0, slitWidth, imgBuffer[0].getHeight());

        ofSetColor(255);

        for (int x=0; x<imgBuffer.size(); x++)
        {
            int locX = x*slitWidth;
            imgBuffer[x].drawSubsection(locX, ofGetHeight()/2, slitWidth, imgBuffer[0].getHeight(), slitLocX, 0);
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
