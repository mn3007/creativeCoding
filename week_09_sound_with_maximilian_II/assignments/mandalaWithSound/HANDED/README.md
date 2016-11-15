# Mandala with sound
In this assignment you'll be using one of the old examples we used in class and use the audio output to encode the motion of the particles as demonstrated in video _XXXXXXXXXX_.

## Step by step
* Take the code provided and move it in _myApps_ folder inside the _apps_ folder of your openFrameworks directory. Run it to make sure it compiles and runs.
* It should show a mandala where mouseY affects the rotation speed and direction of the shapes.
* In the _ofApp.h_ file create a variable called `bufferSize` and `sampleRate` both of type int. Also create two variables of type `double` called `globSpeed` and `globVol`. These last two variables are the link between the visuals and the audio. The `audioOut()` function is going to store data in there and the `draw()` function is going to read them so that the audio can affect the visuals. Finally, create one `maxiOsc` variable called `myOsc1`, a `maxiSample` object called `mySample` and a `maxiFilter` object called `filter`.
* Open the _ofApp.cpp_ file and in the `setup()` function  initialize the `bufferSize` to 512, the `sampleRate` to 48000. Also, copy/paste the following two lines to properly initialize Maximilian as well as the sound setting for openFrameworks. The middle line will open the _sound.wav_ file provided. You can change that to whatever you like as long as it is in the data folder and that it's a 16bit mono wav file. Use [Audacity](http://audacityteam.org/) to convert to this format.
  ```
  ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
  mySample.load(ofToDataPath("sound.wav"));
  ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);
  ```
* Go to the `audioOut()` function in the line that says `double wave = 0;` replace the 0 with code that will play the audio file. See example _audioWithVisuals_ on how to play a file. Run the program an make sure you hear the audio file in a loop.
* Above that line create a `double` called `speed` and link it to a sinewave using `myOsc1` with frequency 0.1. Multiply that with 1.5. This means that `speed` will range from -1.5 to 1.5. Insert that inside the `play()` function in the line below so that the audio file plays back and forth at speeds ranging from -1.5x (backwards) to 1.5x (forwards). __IMPORTANT:__ Open up _audioWithVisuals_ and see how to calculate the square root of the average volume (remember to use `fabs()`) and store that in `globVol`. Also calculate the average speed and store that in `globSpeed`. Time to use `globSpeed` and `globVol` to drive the graphics.
* Inside the `update()` function, change the `angleStep = ...` line to map from `globSpeed` which ranges from -1.5 to 1.5. Leave the other parameters the same. If you run the code now, you should have a mandala that oscillates from left to right in sync with the sound file. Make sure you understand how `angleStep` is linked to the rotation of the shape.
* Inside the `draw()` function go to the line that says `int radius2 = ...` and use the `ofMap()` with `globVol` as input to convert from a range between 0 and 1 to a range betwee 300 and 500. Set the clamp parameter in the end to true ([see documentation](http://www.openframeworks.cc/documentation/math/ofMath.html#show_ofMap)).
* Add a low pass filter under the above line. Use the `filter` variable and pass to its lopass function the `radius2` with a scaling factor of 0.1 (the 2nd parameter). Put the value returned to the `radius2` value itself. Once again see example _audioWithVisuals_ on how to use the filter. The mandala should now move more smoothly. Experiment with different scaling values to see their effect.

__Further development:__
* How about inverting the control relationship and have the mouseY affect the rotation of the mandala (as it did in the beginning) as well as the playback speed of the audio file.
