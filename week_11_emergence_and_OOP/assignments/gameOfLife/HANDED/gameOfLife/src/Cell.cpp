#include "Cell.h"

//-------------------------------------------------------
Cell::Cell()
{

}

//-------------------------------------------------------
void Cell::setup(float _x, float _y, float _w)
{
    x = _x;
    y = _y;
    w = _w;

    state = int(ofRandom(2));
    previous = state;
}

//--------------------------------------------------------------
void Cell::savePrevious(){
    previous = state;
}

//--------------------------------------------------------------
void Cell::newState(int s) {
    state = s;
}

//--------------------------------------------------------------
void Cell::display() {
    ofFill();
    if (state == 1) ofSetColor(0);
    else ofSetColor(255);
    ofRect(x, y, w, w);
    ofNoFill();
    ofSetColor(0);
    ofRect(x, y, w, w);
}
