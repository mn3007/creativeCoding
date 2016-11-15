# Dumb Agents

## Description
In this exercise you'll program an autonomous, random agent to move around the screen leaving a trail behind it. Play file _dumbAgentsDEMO.mp4_ for a demonstration of what it does.

During each update operation, one of eight possible direction is randomly selected for the next step. Steps are made by adding or subtracting a predetermined value (stepSize) to the current position's coordinates. The circle is then drawn at the new position. See _dumbAgentsDrawing.jpg_ for a visual representation of the logic involved.

The heart of the program is in the `update()` function, where you'll have to call the `ofRandom()` function to see in which of the eight directions you'll go. Then, depending on what the function returns you'll adjust the variables that store the next position of the ellipse. (ie. If you have to go north you'll update just the parameter

## Steps
1. Inside the _ofApp.h_ create nine variables of type `int` called `north`, `northEast`, `east`, `northWest`, etc. These are the possible outcomes of the `ofRandom()` function (the sides of our dice). Also create a variable called _direction_ to store out outcome of the `ofRandom()` function, a `locX` and `locY` to store the current location of the agent, a `stepSize` to store the size of the step we are to make at each update and `diam` which will store the width/height of our ellipse.
2. In the `setup()` set the required background color + turn auto update to false. Then give each of the eight directions a number. Set the `stepSize` and the `diam` to 10 and the starting position of the pixels to the center of the screen (using variables _not_ static values).
3. In the `update()` function call the `ofRandom()` function with the appropriate value and store its outcome inside `direction`. Write a series of `if` and `else if` statements for each outcome. For example if the direction is equal to north you'll only update the `locY` variable by reducing it by `stepSize`. If you want your agent to exit from one side of the screen and enter from the other then check when `locX` is greater then the width of the canvas (minus 1) and set it to 0. Do the opposite when it's less than 0. Apply the same logic to `locY`.
4. In the `draw()` function, set the color to the color you want with trasparency 40. draw an ellipse with the appropriate parameters.

__Bonus:__ Use the combination of the `getLerped()` function to interpolate between colors as the agent moves on the X axis. `getLerped()` is applied on an `ofColor` object and takes a color and a value between 0 and 1 in order to return an color between them. You'll need to use `getLerped()` in combination with `ofMap()` and then use the returned color inside the `ofSetColor()` function.

__Food for thought:__ what patterns emerge when you limit the range of values available inside the `ofRandom()` function?
