# Frame Buffer Slit Scan
In this exercise the goal is to create a slit scanner.  The final result should look like something in the _slitScan.ogv_ video.

## Step by step
Start with code from _frameBufferDelay_ as we are going to be building the same structure. Make the following changes:

1. Inside the _ofApp.h_ file create the `slitWidth` variable of type `int`. This is where we're going to store the size of our slit, as we'd like it to be variable.
2. In _main.cpp_ set the size of the window to 960x480.
3. In `setup()` function, set the background to black, initialize `imgWidth` 320 and the `imgHeight` το 240. Modify the `videoGraber.initGrabber(...)` line to use these sizes. This will define the size that we want the frame to be when it comes out of the camera. Set the `slitWidth` to 10 and the `maxBufferSize` to the width of the window divided by the `slitWidth`. What we're effectively doing is we're setting the maximum size of the buffer to the number of scan lines that we can fit on the window width.
4. Once again we don't have to modify the `update()` function, but make sure you understand it!
5. Inside the _draw()_ function write an if-statement checking if the buffer has at least one frame in it (ie size > 0). If it does have at least one frame in it then... make a call to draw at position 0,0 on the canvas the very first frame in the buffer. Remember `imgBuffer` is a deque, which we'll address the same way as we address a vector or an array. When you run the program now, you should see the latest (most recent) frame drawn on the top-left part of the screen.
6. Create a local variable of type `int`, call it `sclitLocX` where you're going to store the exact location of the slit. We're going to use that to draw a virtual red slit so that we know what we're scanning. Calculate the value of `slitLocX`. We want it to be in the center of the image. To calculate it use the `getWidth()` function on the image as well as the `slitWidth` variable because we want the rect of the slit scan line to be centered properly on the image. Set the color to red. Draw the appropriate rectangle so that it is located at `(slitLocX,0)` and covers the image as seen below. What will the width and height of the rect be?
<br>
<br>
![image1](images/slit.png)
<br>
<br>
7. Now for the meaty part: Underneath the above code make a call to set the color to white. This is to ensure that the slit scans are drawn properly and not just with their red component. Under that call, create a for loop that will loop over all images of the `imgBuffer`. Use the `size()` function to know when to stop. Inside the foor loop create a local variable of type `int` called `locX` where you'll use the index of the for loop along with the `slitWidth` to know where to draw the lines you will extract from the images. Finally, instead of using the `draw()` fuction on the image buffer, we'll use the `drawSubsection()` function. This function allows us to draw any part we want of the image and it's much faster than cropping parts of the image [see documentation](http://openframeworks.cc/documentation/graphics/ofImage.html#show_drawSubsection). This function takes 6 parameters:
```
img.drawSubsection(whereX, whereY, howMuchX, howMuchY, fromWhereX, fromWhereY);
```
  * `whereX`/`whereY` refers to where do we want to draw the subsection of the image we are asking for (hint: locX, also make sure it's under the live image we have drawn above).
  * `howMuchX`/`howMuchY` refers to how much from the image we want to extract (hint: you've already calculated this).
  * `fromWhereX`/`fromWhereY` refers to from where in the image do we want to start to extract (hint: you've already calculated this).
For more help you can also check the example inside the `examples/graphics/imageSubsectionExample/` folder of your openFrameworks directory.

Before you leave change the value of `slitWidth` in the `setup()` function to 1. If you notice your computer being very slow you can increase it, but let's give it a shot with highest resolution. Results will look smoother this way.

----
# Radial Slit Scan
Modify the program above to show the scan lines in a circle as shown in the _radialSlitScan.ogv_ video.

## Step-by-step
Start a new project and copy the code you worked on for the _frameBufferSlitScan_. The code is 99% there already. All we'll need to do is change how we display the scan lines. So:
1. In the `main.cpp` set the window to 640x480.
2. Inside the `setup()` function set the `slitWidth` equal to 5 and the `maxBufferSize` equal to 360 (one for each angle).
3. Inside the `draw()` loop, remove all the code from inside the for loop you had created earlier. Leave the for-loop structure itself intact. Inside the (now empty) for-loop use the `ofTranslate()` to move to the center of the screen and the the `ofRotate()` to rotate by the index of the for loop. Since the `imgBuffer.size()` is equal to 360, we're going to be getting values fro 0-360 in the for loop. Modify the `draqSubsection()` command to take into account that we have already moved to the center of the screen (ie we should be drawing at the origin). Make sure you call the `ofPushMatrix()`/`ofPopMatrix()` in the beginnign and end of your for loop.

----
# Assignment for home
* See [Golan Levin's](http://www.flong.com/texts/lists/slit_scan/) historical overview of slit scanning and explore other ways of extending the lab exercise.
* How about using ofNoise() and the modulus [see documentation](http://www.cprogramming.com/tutorial/modulus.html) to modify the speed of the slit-scan acquisition pseudorandomly. Right now we are grabbing slices at every frame. How about if we wanted to do it every 2nd frame? Every 3rd? That's where we'd use the modulus. And whether it's every 1, 2, 3, 4th frame we can do with the noise function so that we move smoothly between these values.
* How about using `ofRandom()` to pick random slits from each frame in the buffer to draw on the canvas.
