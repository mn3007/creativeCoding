# Remote Picasso
Write a program that paints on the canvas of another program over the network. You'll need to save the positions that the mouse moves in and then, when you're ready send them over the network to be painted on the canvas of the other machine.

## Step-by-step instructions
* __painting surface (client):__
  * Take the _oscScend_ example as a starting point.
  * Create a `vector` inside the `ofApp.h` that will store integers. Call it `positions`.
  * Every time the mouse is moved add the current `mouseX` and `mouseY` position to the `positions` vector. Also a line is drawn between where the mouse was in the previous frame and where it is now. Hint: You'll need to create a `pMouseX/pMouseY` variable to store those locations of the previous frame.
  * If the user presses the _c_ button, the vector is cleared as well as the painting on the client screen.
  * When the user presses the _s_ button on the keyboard have the vector `positions` packaged up in an `oscMessage` and sent to the server. Set the address of the oscMessage to `/coords/`
* __display surface (server):__
  * Take the _oscReceive_ example as a starting point.
  * When a message is received check that it has the correct address (`/coords/`) and if it does start unpacking the packet. Given that it can be of arbitrary size, you might want to use the `getNumArgs()` function to get the total number of arguments. Your number of points will be half of that (because you have x+y for each point). As you unpack the points add them to another vector structure on the server side. Your draw function should be looping over this vector and joining them with lines on the screen.

__Possible extensions:__
* Osc has a maximum packet size. Move the mouse a lot and try to exceed that packet size. Most likely your program will fail when trying to receive and unpackage it. What can you do to stop that from happening?
* How about adding a GUI so that you also send how thick you want the line drawn and what color?
