import java.io.*; // for the loadPatternFilenames() function
import processing.opengl.*; // for OPENGL rendering
import jp.nyatla.nyar4psg.*; // the NyARToolkit Processing library
import processing.video.*;
import codeanticode.gsvideo.*; // the GSVideo library

String camPara = "/home/theodoros/sketchbook/PATTERN_FILES/camera_para.dat";
String patternPath = "/home/theodoros/sketchbook/PATTERN_FILES";
int numMarkers = 10;
int currentMarker=7;
MultiMarker nya;

Movie mov;
GSCapture cam;

void setup() {
  size(640, 480, OPENGL); // the sketch will resize correctly, so for example setting it to 1920 x 1080 will work as well
  
  nya = new MultiMarker(this, width, height, camPara, NyAR4PsgConfig.CONFIG_DEFAULT);
  // set the delay after which a lost marker is no longer displayed. by default set to something higher, but here manually set to immediate.
  nya.setLostDelay(1);
  String[] patterns = loadPatternFilenames(patternPath);
  // for the selected number of markers, add the marker for detection
  // create an individual color and scale for that marker (= box)
  for (int i=0; i<numMarkers; i++)
  {
    nya.addARMarker(patternPath + "/" + patterns[i], 80);
  }

  cam = new GSCapture(this, 640, 480, 30);
  cam.start();
  
//  mov = new Movie(this, "hector.mov");
  mov = new Movie(this, "capture.m4v");
  mov.loop();
  mov.pause();
}

void draw()
{
  if (cam.available())
  {
    cam.read();
    background(cam);
    image(cam, 0, 0, width, height); // display the image at the width and height of the sketch window
    nya.detect(cam); // detect markers in the input image at the correct resolution (incorrect resolution will give assertion error)
    drawImage(); // draw boxes on the detected markers (3D)
  }
}


void drawImage()
{
  // set the AR perspective uniformly, this general point-of-view is the same for all markers
  nya.setARPerspective();

  if (nya.isExistMarker(currentMarker)==true)
  { 
    mov.play();
    //println("hello");
    setMatrix(nya.getMarkerMatrix(currentMarker)); // = 7.gif
    scale(1, -1); // turn things upside down to work intuitively for Processing users
    imageMode(CENTER);
    image(mov, -2, -2, 85, 85);
  }
  else
  {
    mov.pause();
  }
  
  perspective();
}


// this function loads .patt filenames into a list of Strings based on a full path to a directory (relies on java.io)
String[] loadPatternFilenames(String path) {
  File folder = new File(path);
  FilenameFilter pattFilter = new FilenameFilter() {
    public boolean accept(File dir, String name) {
      return name.toLowerCase().endsWith(".patt");
    }
  };
  return folder.list(pattFilter);
}

void movieEvent(Movie mov) {
  mov.read();
}

void mousePressed()
{
  println(currentMarker);
  currentMarker++; 
}
