# Superformula genetic sculptor
Using the principles behind genetic algorithms develop a piece of software where the artist selects which superformula shapes (or L-System plants, or Lissajous curves) have the right to breed, shaping the outcome of the process.
__Important:__ Get a feeling for how this works by opening the _Nature Of Code Faces interactiveselection_ example provided in class.

### General steps:
* The techniques used are the same as with the _geneticPhotobooth_, only this time instead of having the organisms be evaluated based on some _objective_ fitness function (how similar they are to the input image) they are evaluated based on an _subjective_ one, the choices the artist makes.
* To start off, 8 superformula shapes are randomly generated (you'll use the `Individual` and `DNA` class for that). Once they are generated they are displayed on the canvas, each in their own square. You could make your life easier by having the superformula shape be generated inside the `getPhenotype()` function of the `Individual()` class, which returns an image in the first place. You could then loop over the Individuals of the `Population` class and display them on the canvas.
* The `ofApp()` class will be tracking the mouse and when a mouse is over one of these images generated it will add to that image's (that Individual's) `fitness` score.
* You'll then need to add a button which once you vote for the images you like most, generates the next generation being bias towards the fitter shapes.

### Ideas for further extension
So far your gene size for the superformular was probably 9:
* 3 for RGB
* 4 for m, n1, n2, n3 superformula parameters
* 1 for size
* 1 for layers
How about including movement as part of the feature space? Consider adding 8 more elements in the gene:
* 4 numbers for each superformula parameters that specify the maximum movement from the original location the parameter is allowed to take
* 4 numbers signifying step size in the noise function. Remember: the greater steps we take on the x-axis in the noise function the faster the changes are. Smaller steps create a slower change.

### Turning it into an online collaborative art piece
Similar to the concept behind [Electric sheep](http://electricsheep.org/about) use the code you developed in previous steps to develop superformula organisms collaboratively.
* Write an OSC superformula server where the votes from the previous steps come in and are added to each character. Once every player has pressed the "generate" button then the new generation is calculated and the genes are sent via OSC broadcast to all the clients.
* Write an OSC superformula client that connects to the server and receives the latest genes for _x_ number of organisms. It displays them on the screen and allows the user to vote for the most likeable organisms. When the user has voted, he presses a "send" button to send the fitness scores of each superformula organism to the server to collate with the fitness scores from the other participants and calculate the next generation.
* To keep it fast and fun, the server auto-generates the next set of organism every 1 minute. Clients that connect in the 45th second have only 15 seconds to make up their minds and send their votes.
