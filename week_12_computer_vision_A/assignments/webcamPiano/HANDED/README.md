# Webcam Piano
In this assignment you'll take pieces of code and stitch them together, manipulating their parameters in order to make what is shown in the _frameDiffWebcamPiano.ogv_ video, a stripped down version of Memo Akten's [webcam piano 2.0](http://www.memo.tv/webcam-piano-2/). 
## Step by step instructions:
1. Generate a new project (don't forget to include the ofxOpenCV addon) and copy the code from the _frameDifferecing_ folder. Press the mouse button to turn on/off the debug mode (ON by default).
2. Study what each square does and play with the scalar variables affecting `diffFloat`, `bufferFloat` (in `update()`) as well as the `threshold` (in `draw()`).
3. Copy the files inside the _simpleParticleSystem_ folder and include them in your project. Don't forget to put the following line:
```
 #include "simpleParticleSystem.h"
```
at the top of your _ofApp.h_ file.
4. Open the _simpleParticleSystem.h_ file and study it. You'll see that you can setup a grid by calling the `setupAsGrid()` function and giving it the size of the circles (make sure it's a multiple of 640 & 480, such like 10, 20, 40 etc. to avoid problems). You'll also have to give it the rate that you want the circles to fade. An `agingRate` of 2 is good. And the `lifespan` of the circles, how long to they get to live. In effect this defines how transparent they will be when they are activated. A value of `150` is a good start. You'll have to do all these in the `setup()` function of your program.
5. Make sure you call the `update()` function of your particle system inside your program's update function too.
6. Go to the line inside your `draw()` that says `EDIT HERE`. That's where things are done when pixels in the bufferFloat image are above a certain value. The debub mode draws small points. You want to have an else under that if statement which will make a call to the `activateParticle(x,y)` of your particle system, passing it the coordinate that has been activated.
7. Remember to call the `draw()` function of your particle system at the end of your main program's `draw()`.

__Ideas for further development:__
* Consider adding a GUI (see examples/Gui/ in you oF folder) in order to manipulate the computer vision parameters that affect the `diffFloat`, `bufferFloat` and `threshold`. You don't want to compile code when you're setting up an installation on location.
* You could look into the `setupAsGrid()` function and give the particles colors based on their location.
* How about using ofMaxim to add sound. Consider using envolopes on the waves you generate so that the sound discreet and more like notes or bells.

