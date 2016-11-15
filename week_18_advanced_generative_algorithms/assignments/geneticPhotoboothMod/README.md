# Genetic Photobooth modification
In this assignment you'll have to study the code provided in the Genetic Photobooth example and modify it to use different shapes / primary elements.

### Ideas to explore:
* __Idea 1:__ Replace the triangles as a gene/unit and use circles or ellipses instead. How big would the size of the gene in that case be? How about 5 for color (RGBAA), 2 for location (x,y), 1 or 2 for width, height (circle vs. ellipse). That's a total of: 8-9. You shouldn't need to change the DNA class, but only the `getPhenotype()` function of the `Individual()` class. See how circles look in greyscale in [this video](https://www.youtube.com/watch?v=dO05XcXLxGs) of an evolving Darwin painting.
* __Idea 2:__ How about using letters of various colors and size in order to reproduce the image taken? A rough estimate is that the gene in that case would be 9. Color (RGBAA) would take 5 again, 2 for location (x,y), 1 for size and 1 to represent the type of letter in the image.
