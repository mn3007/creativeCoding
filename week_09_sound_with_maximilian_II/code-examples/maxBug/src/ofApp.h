#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void star(float x, float y, float radius1, float radius2, int numOfPoints);
		float rotAngle;
		float angleStep;


		// Audio output and input methods
        void audioOut(float * output, int bufferSize, int nChannels);

 		int bufferSize; /* buffer size */
        int sampleRate;

		maxiOsc myOsc1, myOsc2, myOsc3;
		double vizLink;
};
