#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	finder.setup("haarcascade_frontalface_default.xml");

    videoGrabber.setDeviceID(0);
    videoGrabber.setDesiredFrameRate(60);
    videoGrabber.initGrabber(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    videoGrabber.update();
    img.setFromPixels(videoGrabber.getPixels());
	finder.findHaarObjects(img);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofNoFill();
    img.draw(0, 0);

    if(videoGrabber.isFrameNew()){
        for(unsigned int i = 0; i < finder.blobs.size(); i++) {
            ofRectangle cur = finder.blobs[i].boundingRect;
            ofDrawRectangle(cur);
        }
    }

}
