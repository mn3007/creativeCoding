#pragma once
/*
For this to work, make sure you compile the opticalFlow_morphing
example which tell you how to fix a bug in ofxCV
*/
#include "ofMain.h"
#include "ofxOpenCv.h"
using namespace cv;

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

    ofVideoGrabber video;
	bool calculatedFlow;

	ofxCvColorImage currentColor;		//First and second original images
	ofxCvGrayscaleImage gray1, gray2;	//Decimated grayscaled images
	ofxCvFloatImage flowX, flowY;		//Resulted optical flow in x and y axes
};
