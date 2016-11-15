# Camera Audio
In this assignment you'll be using the camera input to encode changes in brightness to frequency as demonstrated in the video _XXXXXXXXXX_.

## SIMPLE VERSION: Step by step
* Take the code provided and move it in _myApps_ folder inside the _apps_ folder of your openFrameworks directory. Run it to make sure it compiles and runs. You should see a video input and a long line in the middle of the screen with a smaller line scanning the pixels from left to right.
* In the _ofApp.h_ file create a variable called `bufferSize` and `sampleRate` both of type int. Create four `maxiOsc` variables called `osc1`, `osc2` and a variable called `freq` of type int. The latter will be the connection between the visuals and the audio.
* Open the _ofApp.cpp_ file and in the `setup()` function initialize the `bufferSize` to 512, the `sampleRate` to 48000. Also, copy/paste the following two lines to properly initialize Maximilian as well as the sound setting for openFrameworks.
  ```
  ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
  ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
  ```
* In the `update()` function under the line that gets th pixel intensity and stores it in a variable called `brightness` use the `ofMap()` function to convert the `brightness` from 0-255 to 200-600. Save the result in the variable `freq`.
* Go to the `audioOut()` function in the line that says `double wave = 0;` replace the 0 with code that will generate a sinewave with frequency `freq` using the `osc1` object.
* If you run the program now you should get a variable frequency depending on the brightness of the pixels under the scanning line.


## ADVANCED VERSION: Step by step
In this version we won't encode the brightness of the pixel straight into frequency (it's too easy!). We'll measure how many times the pixels oscillate from dark to light and use these oscillations as modulating frequency in amplitude modulation. Remember, we can achieve amplitude modulation by multiplying two sinewaves together.
* To achieve the results you'll need a global variable called `state` of type `bool` which is initialized in the `setup()` function to `false`.
* Then under the `img.mirror(false, true);` line in the `update()` function you need the following: Set the `freq` to 0 and then loop over all pixels from position 0 to `imgWidth` in steps of `readingSpeed`. Get the brightness and store it in the `brightness` variable. If the brightness is greater than 127 and state == false OR brightness is less than 127 and state == true then increase the `freq` by 1 and flip the `state`. What this if-statement is basically saying is "if the pixel is white and my previous state is black (or vice-versa) then it means there's been an oscillation. Count that in freq."
* The freq should be a much smaller number than before because pixels don't change so radically in an image. Use that to do amplitude modulation (or frequency modulation) inside the `audioOut()` function.
