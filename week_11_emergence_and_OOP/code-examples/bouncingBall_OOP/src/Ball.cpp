#include "Ball.h"

//-------------------------------------------------------
Ball::Ball()
{
    location = ofPoint(ofRandomWidth(), ofRandomHeight());
    velocity = ofPoint(ofRandom(-3,3), ofRandom(-3,3));
    radius = ofRandom(5, 15);
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
}

//--------------------------------------------------------
void Ball::setup(ofVec2f _location, ofVec2f _velocity, float _radius, ofColor _color)
{
    location = _location;
    velocity = _velocity;
    radius = _radius;
    color = _color;
}

//--------------------------------------------------------------
void Ball::draw(){
        ofSetColor(color);
        ofCircle(location, radius);
}

//--------------------------------------------------------------
void Ball::move(){
        location = location + velocity;
}

//--------------------------------------------------------------
void Ball::bounce() {
        if (location.x>=ofGetWidth()-radius || location.x<=0+radius){
            velocity.x = velocity.x * -1;
        }
        if (location.y>=ofGetHeight()-radius || location.y<=0+radius){
            velocity.y = velocity.y * -1;
        }
}
