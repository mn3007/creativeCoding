# Kinect Firesnake
Using the kinect find the closest point in the depth image and paint things on the screen.

## Step by step instructions
* __Warning to linux users:__ If you have problem running the example it's about permissions. Compile it the usual way and then go with the terminal in the directory where it is located and run teh executable like this: `sudo ./NAME_OF_EXECUTABLE`
* Start with the _kinectExample_ found in your _openFrameworks/examples/addons/_ and the _fieryComet_ from the _code-examples_ of week 4.
* Loop through the depth image and find the closest point on there and paint a red dot on it.
* Use the thresholds to exlude objects that might be too close, so that you can focus on a specific region of interest.
* Make the depth image take the whole canvas. Do the same with the RGB image and allow with a click of the mouse to switch between them (you'll need to use a `bool` somewhere for that).
* Use the code from _fieryComet_ to add that structure where the closest point is (replacing the red dot).


