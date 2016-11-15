# Kinect Piano
Using the more effective camera of the kinect make a camera instrument.

## Step by step instructions:
__Warning to linux users:__ If you have problem running the example it's about permissions. Compile it the usual way and then go with the terminal in the directory where it is located and run teh executable like this: `sudo ./NAME_OF_EXECUTABLE`
1. Start with the _kinectExample_ found in your _openFrameworks/examples/addons/_.
2. Combine it with the code from the _webcamPiano_ from last week to create better interaction. Last week even areas such as the elbows and head of the organist were playing "notes". Eliminate this problem by specifying a smaller area in space within which the piano can be activated. If for example you threshold things so that only items between 0.5m and 0.75m from the camera are seen by your program then the instrument area becomes that and anything further than that (like your head) does not activate it.

__Ideas for further development:__
* Consider adding a GUI (see examples/Gui/ in you oF folder) in order to manipulate the thresholds before a "concert".
