#pragma once
#include "ofMain.h"

class Cell{

	public:
		Cell();
		void setup(float _x, float _y, float _w);

        float x, y;
        float w;
        int state;
        int previous;

        //member functions
        void savePrevious();
        void newState(int s);
        void display();
};
