#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    numOfTiles = 10;
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);

    imgWidth = ofGetWidth()/numOfTiles;
    imgHeight = ofGetHeight()/numOfTiles;
    maxBufferSize = numOfTiles * numOfTiles;
    vidGrabber.initGrabber(imgWidth, imgHeight);

    for (int i=0; i<maxBufferSize; i++)
    {
        table.push_back(ofRandom(maxBufferSize));
    }
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

    int imgIndex = 0;

    for (int x=0; x<ofGetWidth(); x+=imgWidth)
    {
        for (int y=0; y<ofGetHeight(); y+=imgHeight)
        {
            if (imgBuffer.size()==maxBufferSize)
            {
                imgBuffer[table[imgIndex]].draw(x,y);
                imgIndex++;
            }
        }
    }
    //cout << ofGetWidth() << endl;
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
