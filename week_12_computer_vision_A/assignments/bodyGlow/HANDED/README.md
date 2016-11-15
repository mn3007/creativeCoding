# Body glow
In this assignment you'll take pieces of code and stitch them together, manipulating their parameters of the frame differencing algorithm in order to make what is shown in the _frameDifferencing_particleSystem.ogv_ video. 

### Step by step instructions:
1. Generate a new project (don't forget to include the ofxOpenCV addon) and copy the code from the _frameDifferecing_ folder demonstrated in class.
2. Study what each square does and play with the scalar variables affecting `diffFloat`, `bufferFloat` (in `update()`) as well as the `threshold` (in `draw()`).
3. Copy the files inside the _simpleParticleSystem_ folder and include them in your project. Don't forget to put the following line:
```
 #include "simpleParticleSystem.h"
```
at the top of your _ofApp.h_ file.
4. Create a `simpleParticleSystem` object (let's call it `partSys`) in your _ofApp.h_ file.
5. Inside your `update()` function call this line:
```
  partSys.applyForce(ofVec2f(0,-0.1));
```
if you want your particles to move upwards. Modify it if you want them to move downwards. Keep in mind it takes small values.
6. Make sure you call the `update()` function of your particle system inside your program's update function too.
7. Go to the line inside your `draw()` that says `EDIT HERE`. That's where things are done when pixels in the bufferFloat image are above a certain value. The debub mode draws small points. You want to have an else under that if statement which will make a call to the `addParticle(x,y)` of your particle system, passing it the coordinate where you want a particle generated. __Important:__ If you run it like that it will generate a particle for every pixel active (above the threshold of course). This is very cumbersome and usually doesn't look nice. You could go around that by turning the `else` statement into an `else if` like that: `else if (ofRandom(1)<0.003) {  }`. This adds a particle 3 times every 1000 calls. You can play with that number to affect the frequency of activation.
8. Remember to call the `draw()` function of your particle system at the end of your main program's `draw()`.
9. Adjust the parameters mentioned in step 2 in order to get the optimum result.

__Ideas for further development:__
* You can add text instead of ellipses (look into the `/examples/graphics/fontsExample/` in your oF directory)
* If the system is overwhelmed you can check every 5 pixels rather than every pixel in the nested loop that checks for thresholded pixels.
