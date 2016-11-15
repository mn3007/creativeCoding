#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofNoFill();
    ofSetCircleResolution(50);
    angle = 0;
    ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update(){
    angle = angle + 0.2;
}

//--------------------------------------------------------------
void ofApp::draw(){
    //move to center of solar system
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    //### SUN ###
    ofPushMatrix();
        ofRotate(angle*5);
        ofCircle(0, 0, 40);
        ofLine(0,0,40,0);
    ofPopMatrix();

    // EARTH + MOON
    ofPushMatrix();
        ofRotate(angle); //rotation around the sun
        ofTranslate(150, 0);
        ofPushMatrix();
            ofRotate(angle*20); //rotation around its axis
            ofCircle(0,0, 12); // EARTH
            ofLine(0,0,12,0);
        ofPopMatrix();
        ofPushMatrix();
            ofRotate(angle*4); // rotation of the moon around earth
            ofTranslate(35, 0); //no rotation for the moon on its axis
            ofCircle(0,0, 6); // MOON
            ofLine(0,0,6,0);
        ofPopMatrix();
    ofPopMatrix();

    // MARS
    ofPushMatrix();
        ofRotate(-angle*2); //rotation around the sun
        ofTranslate(220, 0);
        ofPushMatrix();
            ofRotate(angle*15); //rotation around its axis
            ofCircle(0,0, 15); // MOON
            ofLine(0,0,15,0);
        ofPopMatrix();
    ofPopMatrix();
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
