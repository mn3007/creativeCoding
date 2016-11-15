#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

	mouseX = 0;
	mouseY = 0;
	mouseButtonState = "";

	ofBackground(30, 30, 130);

}

//--------------------------------------------------------------
void ofApp::update(){

    if (messageBuffer.size()>maxBufferSize) messageBuffer.pop_back();

	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(m);

		// check for mouse moved message
		if(m.getAddress() == "/mouse/position"){
			// both the arguments are ints
			mouseX = m.getArgAsInt(0);
			mouseY = m.getArgAsInt(1);
		}
		// check for mouse button message
		else if(m.getAddress() == "/mouse/button"){
			// the single argument is a string
			mouseButtonState = m.getArgAsString(1);
		}
		else{
			// unrecognized message: display on the bottom of the screen
			string msg_string;
			msg_string = m.getAddress() + ": UNRECOGNIZED MESSAGE";
			messageBuffer.push_front(msg_string);
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){

	string buf;
	buf = "listening for osc messages on port" + ofToString(PORT);
	ofDrawBitmapString(buf, 10, 20);

	// draw mouse state
	buf = "mouse: " + ofToString(mouseX, 4) +  " " + ofToString(mouseY, 4);
	ofDrawBitmapString(buf, 430, 20);
	ofDrawBitmapString(mouseButtonState, 580, 20);

    // read the buffer
	for(int i = 0; i < messageBuffer.size(); i++){
		ofDrawBitmapString(messageBuffer[i], 10, 40 + 15 * i);
	}
}
