#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);

    numOfXTiles = 20;
    numOfYTiles = 20;

    spacingX = ofGetWidth() / numOfXTiles;
    spacingY = ofGetHeight() / numOfYTiles;

    startingX = spacingX / 2;
    startingY = spacingY / 2;

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetCircleResolution(50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    for (int x=0; x<numOfXTiles; x++){
        for (int y=0; y<numOfYTiles; y++){
            int locX = startingX + spacingX * x;
            int locY = startingY + spacingY * y;

            ofPushMatrix();

            //calculate the color based on distance from mouse
            ofColor c1 = ofColor(200,0,0);
            ofColor c2 = ofColor(0,0,200);
            ofSetColor(c1.getLerped(c2, ofMap(ofDist(mouseX,mouseY,locX,locY),0,ofGetWidth()/2, 0, 1,true)));

            //apply transformations
            ofTranslate(locX, locY);
            int angle = ofRadToDeg(atan2(mouseY-locY, mouseX-locX));
            ofRotate(angle+180);
            ofTranslate(100,0);
            float scale = ofMap(ofDist(mouseX,mouseY,locX,locY),0,ofGetWidth()/2, 2, 0.5,true);
            ofScale(scale, scale);

            ofCircle(0,0,10);

            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='s') {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
    }
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
