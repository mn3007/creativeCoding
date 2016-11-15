#include "BallSystem.h"

//-------------------------------------------------------
BallSystem::BallSystem()
{

}

//--------------------------------------------------------------
void BallSystem::setup(int _numOfBalls){

    numOfBalls = _numOfBalls;

    for (int x=0; x<numOfBalls; x++)
    {
        Ball b;
        balls.push_back(b);
    }
}

//--------------------------------------------------------------
void BallSystem::update(){

    for (int x=0; x<balls.size(); x++)
    {
        balls[x].move();
        balls[x].bounce();
    }
}

//--------------------------------------------------------------
void BallSystem::draw(){

    for (int x=0; x<balls.size(); x++)
    {
        balls[x].draw();
    }
}

//--------------------------------------------------------------
void BallSystem::addBall(int x, int y){
    ofVec2f loc(x,y);
    ofVec2f vel(ofRandom(-3,3), ofRandom(-3,3));
    float rad = ofRandom(5,15);
    ofColor c = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));

    Ball b;
    b.setup(loc, vel, rad, c);
    balls.push_back(b);
}
