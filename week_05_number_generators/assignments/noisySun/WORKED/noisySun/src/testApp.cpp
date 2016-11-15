#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    //sun stuff
    totalRays = 100;
    stepSize = 200;
    radius = 300;
    angleStep = 360.0 / totalRays;
    sunLoc = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    ofSetCircleResolution(60);

    for (int x=0; x<totalRays; x++)
    {
        noiseSeeds.push_back(ofRandom(10000));
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    ofTranslate(sunLoc);

    ofSetColor(253, 202, 19);

    ofBeginShape();
    for (int i=0; i<totalRays; i++)
    {
        float noisedRadius = radius + ofNoise(noiseSeeds[i]) * stepSize;
        float endX = sin(ofDegToRad(i*angleStep)) * noisedRadius;
        float endY = cos(ofDegToRad(i*angleStep)) * noisedRadius;
        noiseSeeds[i]+=0.01;

        ofVertex(endX, endY);
    }
    ofEndShape();

    ofSetColor(255,215, 13);
    ofCircle(0, 0, 300);
}

void testApp::keyPressed(int key)
{

}
