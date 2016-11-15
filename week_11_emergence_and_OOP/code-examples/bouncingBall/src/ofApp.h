#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

        ofPoint location;
        ofPoint velocity;
        float radius;
        ofColor color;

        void drawBall();
        void moveBall();
        void bounceBall();
};
