#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	video.setDeviceID(0);
    video.setDesiredFrameRate(60);
    video.initGrabber(640, 480);

    debug = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	video.update();	//Decode the new frame if needed

	//Do computing only if the new frame was obtained
	if ( video.isFrameNew() ) {
		//Getting a new frame
		image.setFromPixels( video.getPixelsRef() );

		//Decimate image for speed-up processing
		if ( !imageDecimated.bAllocated ) {
			imageDecimated.allocate( image.width * 0.5,
				image.height * 0.5 );
		}
		imageDecimated.scaleIntoMe( image, CV_INTER_NN );

		//Convert to grayscale image
		grayImage = imageDecimated;

		//Smoothing image
		blurred = grayImage;
		blurred.blurGaussian( 9 );

		//Store first frame to background image
		if ( !background.bAllocated ) {
			background = blurred;
		}

		//Find difference of the frame and background
		diff = blurred;
		diff.absDiff(blurred, background); // general case
        //diff -= background;                // if background was dark and objects bright

		//Thresholding for obtaining binary image
		mask = diff;
		mask.threshold( ofMap(mouseX, 0, ofGetWidth(), 0, 200) ); //Threshold controlled by mouseX
                                                                  //It should be adjusted for good results when using another videos than in example.
		//Find contours
		contourFinder.findContours( mask, 10, 10000, 20, false );

		//Store objects' centers
        blobs = contourFinder.blobs;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
		ofSetColor( 255, 255, 255 );	//Set color for images drawing

        //DEBUG MODE: draws the color image (top left), the difference from background (top right)
        //the thresholded image (bottom left) and the original image with centroids (bottom right).
        if (debug){
            int w = imageDecimated.width;
            int h = imageDecimated.height;
            //Original decimated image
            imageDecimated.draw(0, 0, w, h);

            //Difference
            diff.draw( w, 0, w, h );

            //Thresholded
            mask.draw( 0, h, w, h );

            //Draw found contours
            contourFinder.draw( 0, h, w, h );

            //Draw centers over decimated image
            imageDecimated.draw(w, h, w, h);
            ofSetColor( 255, 255, 0 );
            ofSetLineWidth( 2 );
            for (int i=0; i<blobs.size(); i++) {
                ofPoint p = blobs[i].centroid + ofPoint( w, h );
                ofLine( p.x - 20, p.y, p.x + 20, p.y );
                ofLine( p.x, p.y - 20, p.x, p.y + 20 );
            }
            ofSetLineWidth(1);
        }
        else{
            //Draw centers over original image and the centroids
            image.draw(0, 0);//, h);
            ofSetColor( 255, 255, 0 );
            ofSetLineWidth( 2 );
            for (int i=0; i<blobs.size(); i++) {
                ofPoint p = ofPoint(blobs[i].centroid.x*2, blobs[i].centroid.y*2); //multiplies by 2 because we decimated the original image by 50%
                ofLine( p.x - 20, p.y, p.x + 20, p.y );
                ofLine( p.x, p.y - 20, p.x, p.y + 20 );
            }
            ofSetLineWidth(1);
        }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    debug = !debug;
}
//--------------------------------------------------------------
void ofApp::keyPressed(int button){
   background = blurred;
}
