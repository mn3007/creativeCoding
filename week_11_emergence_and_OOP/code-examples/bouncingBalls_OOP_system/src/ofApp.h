#pragma once
#include "ofMain.h"
#include "BallSystem.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void mouseDragged(int x, int y, int button);
		BallSystem ballSys;
};
