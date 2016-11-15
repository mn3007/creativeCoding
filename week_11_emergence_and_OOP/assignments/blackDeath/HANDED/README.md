# Black Death
In this assignment you'll take the code already provided in this directory, study it and make the modifications below.

## Step by step instructions:
1. __Run the program:__ and make sure it compiles.
2. __Some more realism:__ 
  * Set the speed of the balls to variable. Inside the Ball class set the `maxspeed` to a value depending on the gene. Radius is calculated depending on that value. The bigger the gene value (ranges from 0-1) the bigger the balls. Use `ofMap` again to set the `maxspeed` dynamically using the `gene`. Smaller gene values should make the balls move fast (small balls move fast / big balls move slow). Have it range between 1 and 10.
  * Do the same for curerate. Small balls are healthier and should be cured faster. Have it range from 3 to 1.
  * Currently if one ball is on the way to recovery and it's touching a sick ball it gets back to being gravely ill. Same thing happens to it if it touches a healthy ball. The act of infecting someone makes it go back to square one. Modify the program so that balls that are currently infected can't be re-infected (dropped to 0). Also modify the program so that the ill ball make the healthy one sick, but it doesn't go back to being gravely ill, it continues at its current rate of illness.
3. __Clinic:__
  * Create your own class called `Clinic` which should manifest itself on the screen as a semitransparent square in the center (you decide the size, but make it realtively small). When balls pass through there they get instantly cured. Add another class variable on the `Ball` class so that if a healthy ball passes through the clinic it gets vaccination and then its color is other than white or black (you choose). You'll probably need to modify the ball class to include a `bool vaccinated` variable which turns on when the ball has been vaccinated. You'll then create an object of type `Clinic` inside your `BallSystem` class and have the `BallSystem` class check inside its `update()` function which balls are inside.
  * You could add further realism by keeping count how many times each ball has come into contact with infected people `int infectedContacts` and when they reach above 5 then the `bool vaccinated` goes to false and they are as vulnerable as others.
4. __Prettier balls:__ Instead of using balls you could use the shapes generated from the _noisySun_/_shapeFromAgents_ example in week 5 (numbers generators) to make them better looking and more like organisms.


## Further exploration (at home):
* How about drawing lines between balls if they are closer than x pixels from each other? See p.180 of the openFrameworks book in the repository. Alternatively you can use [ofxVoronoi](https://github.com/vanderlin/ofxVoronoi) to create insteresting patterns.
