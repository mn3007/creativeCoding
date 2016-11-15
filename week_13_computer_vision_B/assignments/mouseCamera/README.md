# Mouse Camera
Calculate the average optical flow of all pixels (both in the x and y-axis) and use that to move within a picture. Look at the [documentation](http://docs.opencv.org/3.0-beta/modules/video/doc/motion_analysis_and_object_tracking.html#calcopticalflowfarneback) for more information on the Farneback algorithm and its parameters.


## Step by step instructions
* Use the _opticalFlow_ example shown in class as a starting point. Get the _opticalFlowTracking_ example working first. Inside the _ofApp.h_ file you'll see instructions about what to correct in the openCV library for it to run. There's a small bug which needs to be addressed.
* Create the variables `sumX`, `sumY`, `avgX`, `avgX` of type `float` and `numOfEntries` of type `int`. Use these to calculate the sum and divide it by the `numberOfEntries` to find the averages.
* Start by drawing an ellipse in the middle of the screen and moving it by adding to it the average optical flow. Instead of moving your hands in front of the camera, move the camera (or computer). You can use the camera now as a control device.
* Load the image in the _image_ folder and use `drawSubsection()` function to travel within it. This function allows us to draw any part we want of the image and it's much faster than cropping parts of the image [see documentation](http://openframeworks.cc/documentation/graphics/ofImage.html#show_drawSubsection). This function takes 6 parameters:
```
img.drawSubsection(whereX, whereY, howMuchX, howMuchY, fromWhereX, fromWhereY);
```
  * `whereX`/`whereY` refers to where do we want to draw the subsection of the image we are asking for (hint: locX, also make sure it's under the live image we have drawn above).
  * `howMuchX`/`howMuchY` refers to how much from the image we want to extract (hint: you've already calculated this).
  * `fromWhereX`/`fromWhereY` refers to from where in the image do we want to start to extract (hint: you've already calculated this).
For more help you can also check the example inside the `examples/graphics/imageSubsectionExample/` folder of your openFrameworks directory.
* Try making the application full screen.
