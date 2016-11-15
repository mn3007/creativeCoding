#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.setDeviceID(0);
    video.setDesiredFrameRate(60);
    video.initGrabber(320,240);
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();	//Decode the new frame if needed

	//Do computing only if the new frame was obtained
	if ( video.isFrameNew() ) {
		//Getting a new frame
		image.setFromPixels( video.getPixelsRef() );

		//Convert to grayscale image
		grayImage = image;

		//Smoothing image
		blurred = grayImage;
		blurred.blurGaussian( 5 );

		//Thresholding for obtaining binary image
		mask = blurred;
		mask.threshold( ofMap(mouseX, 0, ofGetWidth(), 0, 200) );

        //Getting an inverted mask of image to use in contour finder
        inverted = mask;
        inverted.invert();

        //#### FIND INTERESTING POINTS #####
		Mat imageCV;
		imageCV = Mat( mask.getCvImage() );
		goodFeaturesToTrack(imageCV, corners, 100, 0.01, 4);

		//#### FIND CONTOURS (on inverted image) ####
		contourFinder.findContours( inverted, 10, 10000, 20, false );
        blobs = contourFinder.blobs;

        line.clear();

        //currently only looks at the first blob in the queue
        if (blobs.size()>0)
        {
            for (int i=0; i<blobs.at(0).pts.size(); i++)
            {
                line.addVertex(contourFinder.blobs.at(0).pts[i]);
            }
            line = line.getResampledByCount(50);
        }
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofBackground(255, 255, 255);	//Set the background color

		ofSetColor( 255, 255, 255 );	//Set color for images drawing

        int w = image.width;
        int h = image.height;
		//Original decimated image
		image.draw(0, 0, w/2, h/2);

        //blurred immage
		blurred.draw( w/2, 0, w/2, h/2);

		//Thresholded image
		mask.draw( w, 0, w/2, h/2);

		//Inverted image
		inverted.draw( w/2*3, 0, w/2, h/2);

        ofTranslate(ofGetWidth()/2-w/2, h/2+10);
        ofSetColor(0);
        ofNoFill();
        ofRect(0,0,w,h);

        //draw the interesting points in RED
        ofSetColor(255,0,0);
        ofFill();
		for (int i=0; i<corners.size(); i++) {
            ofEllipse(corners[i].x, corners[i].y, 3,3);
        }

        //draw the blob points in BLUE
        ofSetColor(0,0,255);
		for (int i=0; i<line.size(); i++)
        {
            ofEllipse(line[i].x, line[i].y, 3,3);
        }
}
