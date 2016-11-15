/*

This is how you use the cubic interpolation helper function

*/

ArrayList<PVector> pos;  // the position of the particle

void setup(){

  size(512,512);
  frameRate(30);
  pos = new ArrayList<PVector>();
  for(int i = 0; i < 4; i ++){
   pos.add(new PVector(random( -width/2, width/2),random(-height/2, height/2)));
  }
  
}

void draw(){

  //random positions
  if(frameCount%30 == 0){
    pos.remove(0);
    pos.add(new PVector(random( -width/2, width/2), 
              random( -height/2, height/2)));  
  }
  
  float p = (float)frameCount%30/30;
  PVector c_pos = new PVector(0,0);

  c_pos.x = cubicInterpolate(pos.get(0).x, pos.get(1).x, pos.get(2).x, pos.get(3).x, p);
  c_pos.y = cubicInterpolate(pos.get(0).y, pos.get(1).y, pos.get(2).y, pos.get(3).y, p);
    
  //the code to actually draw the particle
  
  background(0);
  pushMatrix();
  translate(width/2, height/2);
  ellipse(c_pos.x,c_pos.y,10,10);
  popMatrix();
  
}



//interpolation helper functions

float linearInterpolate(float a, float b, float p){
  return a * (1-p) + b * p;
}

float cosineInterpolate(float a, float b , float p){
  
  float propRad = p * PI + PI; // convert p into a radians value between PI & 2_PI
                              // this is the bit of the cosine curve we want to use
                          
  float cosP = cos(propRad) * 0.5 + 0.5; //the cos function gives us values from -1 to 1 
                                         //so we need to translate and scale
                                         
  return  a * ( 1- cosP) + b * cosP; //now scale by the real values
}


float cubicInterpolate(float v0, float v1, float v2, float v3, float p){

  /*
  This method gives very smooth results indeed, but you pay for it in speed.
  Whereas before, the interpolation functions took three inputs,
  the cubic interpolation takes five. 
  Instead of just a and b, you now need the point before a and the point after b
  */
  
  /*
  Along with p as before, these are: 
  v0 = the point before a
  v1 = the point a
  v2 = the point b
  v3 = the point after b
  */
  
  // creates a curve around the four points
  
  float P = (v3 - v2) - (v0 - v1);
  float Q = (v0 - v1) - P;
  float R = v2 - v0;
  float S = v1;
  float v = P * pow(p, 3) + Q * pow(p, 2) + R * p + S;

  return v;
}
