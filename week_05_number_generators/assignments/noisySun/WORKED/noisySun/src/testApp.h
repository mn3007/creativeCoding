#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);

        //sun related
        vector <float> noiseSeeds;
        int totalRays;
        float angleStep;
        float stepSize;
        float radius;
        ofPoint sunLoc;
};
