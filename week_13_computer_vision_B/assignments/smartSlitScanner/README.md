# Smart Slit Scanner
<br>
<br>
![image1](stephHorak.png)
<br>
<br>
Use the optical flow as a way of calculating when to add images to the deque and thus making a more uniform slit scanner. If you remember from [Steph Horak's](https://stephhorak.wordpress.com/commutations-2013/) work, she used a slit scanner and she filmed from the inside of a train. She then had to arbitrarily drop frames if they were repeated too often (stopping at a station for example). Can you make the algorithm more intelligent and have it stop taking pictures when there is no forward motion? Look at the [documentation](http://docs.opencv.org/3.0-beta/modules/video/doc/motion_analysis_and_object_tracking.html#calcopticalflowfarneback) for more information on the Farneback algorithm and its parameters.

## Step by step instructions
* Use the _opticalFlow_ example shown in class as a starting point. Get the _opticalFlowTracking_ example working first. Inside the _ofApp.h_ file you'll see instructions about what to correct in the openCV library for it to run. There's a small bug which needs to be addressed.
* Create the variables `sumX`, `sumY`, `avgX`, `avgX` of type `float` and `numOfEntries` of type `int`. Use these to calculate the sum and divide it by the `numberOfEntries` to find the averages.
* Start by drawing an ellipse in the middle of the screen and moving it by adding to it the average optical flow. Instead of moving your hands in front of the camera, move the camera (or computer). You can use the camera now as a control device.
* Join your work with the _frameBufferSlitScan_ assignment from week 6. In this assignment you're adding frames whenever a new frame is ready. Add frames only when there is movement on the x-axis and only on one direction.
