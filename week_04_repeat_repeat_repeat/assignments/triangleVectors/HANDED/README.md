# Triangle vectors
This assignment is similar to the _bouncingBallVector_ example. Only instead of having two vectors to store the x and y coordinates of each ball we use 4 vectors. Two for one corner, two for the other corner of the triangle and the 3rd corner is where the mouse is. Watch _triangleVectorsDEMO.mkv_ for a demo.

## Step by step:
1. Create 6 global vectors of type `float` with the following names: `speed1X`, `speed1Y`, `loc1X`, `loc1Y` (these describe one corner of the triangle) and `speed2X`, `speed2Y`, `loc2X`, `loc2Y` (which describe the other corner). Also create a global vector of type `float` called `green`.
2. Set the background to black.
3. Inside the `mousePressed()` function check which button is pressed. If it is the left button (`button==0`) then add a new triangle on the sketch by pushing a new value all of the aforementioned vectors. The location vectors should take a random value __anywhere__ on the canvas using the `ofRandom()` function (alternatively you can use the `ofRandomWidth()` & `ofRandomHeight()` functions). For the speed use the `ofRandomf()` function which returns a value between -1 and 1. For `green` use a random value between 0 and 255. If the right button is clicked then remove a triangle from the end of the vector. You'll need to use the `pop_back()` command ([see documentation](http://www.cplusplus.com/reference/vector/vector/)). Make sure before you remove a triangle you have another _if_ statement checking the size of the vector with the `size()` command. If you try to pop a triangle from an empty vector you program is going to crash.
4. Inside the `draw()` loop add a _for_ loop which loops over the vectors and draws each triangle (use one of them along with `size()` to dynamically adjust the conditional). For example the first triangle is:
```
ofTriangle(loc1X[0], loc1Y[0], loc2X[0], loc2Y[0], mouseX, mouseY);
```
Naturally, inside the loop you'll need to use the index. Above this line make a call to the `ofSetColor()` command passing it a 255 value for red, the green value for the specific triangle, a 0 for blue and 100 for alpha. What you should now see is that every time you press the left mouse button a new static triangle is drawn in random location one tip of which is always following the mouse. Let's add a bit of movement.
5. Inside the `update()` function loop over all of the triangles and add to each location the corresponding speed. For example the first corner of the first triangle is:
```
loc1X[0] = loc1X[0] + speed1X[0];
```
Within the loop add four _if_ statements that check if each of the corners have touched the walls of the sketch and change the direction of movement when that's the case (see _bouncingBallVector_).
6. For a bit more excitement move the code inside the `mouseClicked()` function inside the `mouseDragged()` function. This way many more triangles are added as you press + drag the mouse.
