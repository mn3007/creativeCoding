#Week 2 - Introduction to openFrameworks

## Topics
* intro to programming
* intro openFrameworks
* C++ compiling + IDEs
* running your first project
  * directory structure
  * code structure
* basic shapes and commands
* student presentations:
 * Ewa: [earthcode](http://www.1010.co.uk/org/earthcode.html) + [gig](http://www.apiarystudios.org/2015/08/experimental-electronics-presents-earthvoice/)
 * Yiannis: [Kimchi and Chips - 483 lines](http://www.kimchiandchips.com/#483lines)

## Lab assignment:
Make sure you have openFrameworks + XCode (Mac) or codeblocks (Linux) installed. If not follow the directions from week 1. Then finish the following assignments:
* __gitlab__: make sure you're on both repositories, change your notification settings on the "workshops in creative coding" repo to "watch".
* __setup SparkleShare__: Once you've gained access to both repositories click on [gitlab_sparkleshare_instructions.md](/week 2 - introduction to openFrameworks/gitlab_sparkleshare_instructions.md) to continue.
* __compile the projectGenerator:__
  * __Mac:__ Go to the openFrameworks folder and click on "Apps" and then "ProjectGenerator" folder. Then double click on the `projectGeneratorSimple.xcodeproj` file and click the top left "PLAY" button in the top left to compile it. The projectGenerator is now compiled. Whenever you want to start a project go to the `apps/projectGenerator/projectGeneratorSimple/bin` directory of your openFrameoworks folder and double click on the `projectGeneratorSimple` executable. For each of the following exercises create a new project.
  * __GNU/Linux:__ open a terminal and `cd` into your openFrameworks folder. Then type `cd apps/projectGenerator/projectGeneratorSimple/` and press _enter_. Type `make`. The projectGenerator should now have compiled. Whenever you want to start a project go to the `apps/projectGenerator/projectGeneratorSimple/bin` directory of your openFrameoworks folder and double click on the `projectGeneratorSimple` executable. For each of the following exercises create a new project.
* __shapeStack__
* __circle trails__
* __make your own drawing__: draw your portrait, a robot, an engine (or something you like) using only 2D primitives. Draw first a quick outline on paperand then transfer it to openFrameworks. More on 2D primitives [here](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofCurveVertices). __IMPORTANT:__ Before you leave class, update your files on sparkleshare to include the code + a _small_ screenshot of the drawing you coded, to make sure you know how to upload the upcoming homework assignments.

## Homework assignment:
* pick a painting and program it in ofx using only [2D primitives](http://openframeworks.cc/documentation/graphics/ofGraphics.html#show_ofCurveVertices). Examples: [Kadinsky](https://www.google.com/search?q=kadinsky&tbm=isch&gws_rd=ssl#), [Mondrian](https://www.google.com/search?q=kadinsky&tbm=isch&gws_rd=ssl#tbm=isch&q=mondrian). Once you're done take a _small_ screenshot of the painting and update your page on sparkleshare to include the code + the image.
* built some of the examples that come with ofx
* Read [ofx introduction](http://openframeworks.cc/tutorials/introduction/000_introduction.html)
* Read: [ofx chapter 1](http://openframeworks.cc/tutorials/introduction/001_chapter1.html) (up to & including section 4.4)
* Read the [cplus_plus_basics](http://openframeworks.cc/ofBook/chapters/cplusplus_basics.html) up to & including the section "Beyond Hello World".

## Further Reading / useful links:
- [About oF](http://openframeworks.cc/about/)
- [OF structure](http://openframeworks.cc/ofBook/chapters/setup_and_project_structure.html)
- why do we need header files? http://www.cplusplus.com/forum/articles/10627/
- [video about ofx/Processing](https://www.youtube.com/watch?v=eBV14-3LT-g)
- [openFrameworks for Processing users](http://openframeworks.cc/tutorials/first%20steps/002_openFrameworks_for_processing_users.html)
- [Addons](http://ofxaddons.com/) for openFrameworks
