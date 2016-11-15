#pragma once
#include "ofMain.h"
#include "Ball.h"

class BallSystem{

	public:
	    BallSystem();
	    void setup(int _numOfBalls);
	    void update();
	    void draw();
        void addBall(int x, int y);
        vector<Ball> balls;
		int numOfBalls;
};
