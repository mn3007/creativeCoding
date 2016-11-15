#include "Ball.h"

//-------------------------------------------------------
Ball::Ball()
{
    xoff = ofRandom(1000);
    yoff = ofRandom(1000);
    location = ofPoint(ofRandomWidth(), ofRandomHeight());

    float gene = ofRandom(1);           // setting the type
    radius = ofMap(gene, 0, 1, 3, 15);  // 0 small balls - 1 large balls
    maxSpeed = 5;
    cureRate = 2;

    health = 255;
    isAlive = true;
}

//--------------------------------------------------------------
void Ball::draw(){
    ofSetColor(ofColor(health));
    ofCircle(location, radius);
}

//--------------------------------------------------------------
void Ball::move(){
    velocity.x = ofMap(ofNoise(xoff),0,1,-maxSpeed,maxSpeed);
    velocity.y = ofMap(ofNoise(yoff),0,1,-maxSpeed,maxSpeed);
    xoff += 0.01;
    yoff += 0.01;

    location = location + velocity;
}

//--------------------------------------------------------------
void Ball::borders() {
    if (location.x < -radius) location.x = ofGetWidth()+radius;
    if (location.y < -radius) location.y = ofGetHeight()+radius;
    if (location.x > ofGetWidth()+radius) location.x = -radius;
    if (location.y > ofGetHeight()+radius) location.y = -radius;
}

//--------------------------------------------------------------
bool Ball::isInside(int x, int y)
{
    if (ofDist(x, y, location.x, location.y) < radius) return true;
    else return false;
}

//--------------------------------------------------------------
void Ball::cure()
{
  if (isAlive)
  {
    health = health + cureRate;
    health = ofClamp(health, 0, 255);
    if (health<255 && ofRandom(1)<0.001) isAlive=false;
  }
}
