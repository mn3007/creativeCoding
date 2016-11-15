# Smile activator
Activate the camera with a smile

# Step-by-step instructions
* Start by compiling and running the _cameraFacetracker_ in this week's examples.
* To make the algorithm faster and more robust when detecting smaller features such as eyes/mouth/nose etc you may need to detect where the faces are first (using the appropriate XML file), get the area under which the face is located and then within that area try to find the smaller feature. To crop the sections where the faces are, once the face detector has returned them you could use this code:
```
img1.getPixelsRef().cropTo(img2.getPixelsRef(),x,y,w,h)  
img2.update();  
```
and then check img2 for the smaller feature. Find more cascades [here](https://github.com/Itseez/opencv/tree/master/data/haarcascades).
* When a smile is detected have the system save that frame on the disc.
