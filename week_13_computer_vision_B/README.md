# Computer Vision part 2

## Topics
* Optical Flow
* Simple object tracking: fiducials, QR, AR
* Haar cascades:
  - Face tracking
  - Facial Expression Analysis
* Kinect

## Lab assignment
* __mouseCamera:__ turning the camera into a mouse with optical flow.
* __smartSlitScanner:__ using optical flow to make an intelligent slit scanner.
* __Kinect fiery comet:__ use the kinect to detect where your hand is and control a fiery comet with it.
* __Kinect piano:__ using the kinect improve the webcam piano from last week.
* __Haar-cascades:__ activate your installation with a smile.

## Homework assignment
* Finish and extend the lab assignments for the weekly show-and-tell session.
* Optionally:
  * Can you use a combination of techniques? Combining the image generated from optical flow along with thresholding and even contour tracking to find the center of objects moving on screen? You may need to use the `multiplyByScalar()` function of the _opticalFlow_morphing_ to amplify the optical flow values before using thresholding on them.
  * Download and run the example from [ofxFlowTools](https://github.com/moostrik/ofxFlowTools) combining optical flow with fluid simulation.
  * Study the links below and see if you can come up with something on your own using the algorithms we studied in class.

## Futher reading and links of interest
* Simple object tracking:
  * Great [Augemented reality with Processing](http://www.creativeapplications.net/processing/augmented-reality-with-processing-tutorial-processing/) turorial!
  * Fiducials: [Reactable](https://www.youtube.com/watch?v=Mgy1S8qymx0), [Music with paper](https://www.youtube.com/watch?v=5fVWg_rfq0w) and [real-time marker tracking](https://www.youtube.com/watch?v=m5zr8vO1Hso)
* Haar cascades:
  * Haar cascades trained on different [parts of the face](https://github.com/Itseez/opencv/tree/master/data/haarcascades).
  * [Haar cascades](http://opencv-python-tutroals.readthedocs.org/en/latest/py_tutorials/py_objdetect/py_face_detection/py_face_detection.html) explained simply.
  * Adam Harvey developed the [CV Dazzle](https://cvdazzle.com/) about tricking face detection algorithms. He also provides a helpful [video demo](https://vimeo.com/12774628) of the cascading nature of face detection. A more in depth explanation by the same author can be found [here](http://www.makematics.com/research/viola-jones/)
* [Face Tracker](https://github.com/kylemcdonald/ofxFaceTracker/): Kyle McDonald's addon for tracking elements of the face.
* Optical flow:
  * Optical flow: Look at the [documentation](http://docs.opencv.org/3.0-beta/modules/video/doc/motion_analysis_and_object_tracking.html#calcopticalflowfarneback) for more information on the Farneback algorithm and its parameters.
  * [Wikipedia](http://en.wikipedia.org/wiki/Optical_flow) article
  * [Flow Synth](https://www.youtube.com/watch?v=GX-HvOIFj-E): a synthesizer using optical flow
  * [Lighting choreographer](https://www.youtube.com/watch?v=Wtq6c6PuOYU): using optical flow to represent a dancer's movements
  * Optical flow used in [Data moshing](http://knowyourmeme.com/memes/datamoshing)
  * A [video lecture](https://www.youtube.com/watch?v=KoMTYnlNNnc) on optical flow.
* Kinect:
  * check out the [ofxKinect](https://github.com/ofTheo/ofxKinect) addon's source code for more functionality.
  * [Orbbec](https://orbbec3d.com/products/) makes embedded 3D cameras.
* [ofxFaceTracker](https://github.com/kylemcdonald/ofxFaceTracker) tracks the face as well as its features and can do a simple analysis of some facial expressions.
