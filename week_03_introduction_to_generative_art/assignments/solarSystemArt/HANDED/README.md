# Solar System Art
Starting from the Solar System exercise we saw in class modify the code following the instruction below to generate interesting shapes, like the ones inside the samples directory.

1. Inside the _ofApp.h_ file create three floats called `randDist`, `randFactor1` and `randFactor2`.
2. Inside the `setup()` function write:
```
    randDist = ofRandom(30, 120);
    randFactor1 = ofRandom(5, 30);
    randFactor2 = ofRandom(5, 30);
```
and make sure the background is NOT updated (see `ofSetBackgroundAuto()`) and line width is set to 1.
3. In the `draw()` function, comment out the lines that draw the sun, but leave all the transformations (ie comment out just the sun's circle + line commands). Do the same for the earth and the mars. Comment out the moon's `ofLine()` and set the moon's circle to radius 1. Replace the `ofRotate()` above the earth with `ofRotate(angle * randFactor1);` and the `ofRotate()` above the moon with `ofRotate(angle * randFactor2);`. Also replace the `ofTranslate()` above the moon with `ofTranslate(randDist, 0)`. These commands will help provide variety in the movement of the moon. Inside the `setup()` function set the amount that you add to `angle` to 0.03. This will slow down the drawing (we'll fix that) but will make sure you have continuous lines.
4. Now, iside the `mousePressed()` function add this code:
```
    ofBackground(0);
    randDist = ofRandom(30, 120);
    randFactor1 = ofRandom(5, 30);
    randFactor2 = ofRandom(5, 30);
```
This will make sure that every time you click the button a new system is drawn with new values for the way the earth rotates around the sun, the moon around the earth and how far the moon is from the earth.
Finally, if you want, set the color inside the `setup()` function to 255 but with a transparency of 45. It will produce more interesting results.

__Note:__ if you can't wait to see your drawing, bring the attention to another window, hiding it behind, the bring it again forward. Not having to send commands to the graphics card (because it is not rendering anything when it is behind another app) speeds things up enormously. This way you can have your shapes ready much faster.

__Saving Images:__ If you want to save the occasional screegrab you can do so by adding this inside the `keyPressed()` function.
```
    if (key=='s') {
        ofSaveScreen(ofToString(ofGetFrameNum()) + ".png");
    }
```
This way whenever you press 's' it saves an image with the frame number in the hard drive.
