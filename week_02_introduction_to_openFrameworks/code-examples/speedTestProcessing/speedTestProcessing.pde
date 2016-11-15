void setup() {
  size(1024, 768);
  noStroke();
}

void draw() {
  background(0);
  frame.setTitle("fps: " + frameRate);

  for (int x=0; x<5000; x++) {
    ellipse(random(width), random(height), 10,10);
  }  
}
