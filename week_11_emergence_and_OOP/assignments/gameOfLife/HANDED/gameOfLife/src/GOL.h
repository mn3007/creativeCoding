#pragma once
#include "ofMain.h"
#include "Cell.h"

class GOL{

	public:
	    GOL();
	    void setup(int boardSize, int numOfCells);
        int w;
        int rows;
        int columns;

        // Game of life board
        vector< vector<Cell> > board;

        void display();
        void generate();
};
