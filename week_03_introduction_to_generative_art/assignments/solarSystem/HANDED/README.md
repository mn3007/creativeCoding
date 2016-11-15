# Solar system

Code what is shown in the video file _solarSystemDEMO.ogv_.

# Step-by-step:
0. In the _main.cpp_ set your canvas to 500 by 500.
1. In the _ofApp.h_ file create a variable called `angle` of type `float`. This will be the variable that we update in order to make our world move.
2. In the _ofApp.cpp_ file's `setup()` function set the background to black and set the shape to have no fill. Set the circle resolution to 50, initialize the `angle` variable to 50 and set the width of the line to 2.
3. In the update add 0.2 to `angle` so that it increases by that amount at every frame.
4. In the `draw()` function:
  * move the entire coordinate system at the center of the screen using the `ofTranslate()` command. Make sure not to use static values but variables inside the call.
  * __Sun:__ Create a push/pop matrix pair and within it draw an circle at 0,0 of radius 40 and a line from its center to its perimeter (so that we can detect the rotation). If you run the program now you should see a non-rotating sun at the center of the window. Now make a call to `ofRotate(angle*5)` before the `ofCircle()` call. This should get the sun rotating.
  * __Earth/Moon:__ Create another push/pop matrix pair and within it call `ofTranslate(150,0);`. Now draw a circle at 0,0 of size 12 also with a line through it. This should now draw an earth at a static location next to the sun. Above the `ofTranslate(150,0)` line add a call to `ofRotate(angle)`. This should now get the earth moving around the sun at a rate of `angle`. Notice that to achieve this we did the rotation before the translation. Now it's time to sort out the rotation of the earth on its axis. Above the `ofCircle()` of the earth to another `ofPushMatrix()` and under the `ofLine()` do another `ofPopMatrix()`. Now right under the `ofPushMatrix()` write `ofRotate(angle*20)`. This should get the earth rotating around its axis too. Write code to rotate the moon around the earth at a rate of `angle*4`. Notice in the video that the moon itself does not rotate around its axis (that's why we never see the dark side of it). Make sure that's simulated too, as in the video.
  * __Mars__: Add another planet at another orbit.
