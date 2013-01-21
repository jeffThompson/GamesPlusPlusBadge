
// draw the walls programmatically!
void drawWalls() {

  // corners should just be written as ON/OFF
  // this saves us precious PWM pins!
  for (int i=0; i<4; i++) {
    digitalWrite(
  
  // iterate wall array, if 1 draw wall
  for (int wy=0; wy<3; wy++) {
    for (int wx=0; wx<3; wx++) {

      // if there is a wall in this spot (1)
      if (walls[wx][wy] == 1) {

        // draw a pixel
        drawPx(wx, wy, pwmColor);
      }
    }
  }
}

