void ofApp::star(float x, float y, float radius1, float radius2, int npoints) {
  float angle = 360.0 / npoints;
  float halfAngle = angle/2.0;

  ofSetPolyMode(OF_POLY_WINDING_NONZERO);
  ofBeginShape();
  for (float a = 0; a < 360.0; a += angle)
  {
    float sx = x + cos(ofDegToRad(a)) * radius2;
    float sy = y + sin(ofDegToRad(a)) * radius2;
    ofVertex(sx, sy);
    sx = x + cos(ofDegToRad(a+halfAngle)) * radius1;
    sy = y + sin(ofDegToRad(a+halfAngle)) * radius1;
    ofVertex(sx, sy);
  }
  ofEndShape();
}
