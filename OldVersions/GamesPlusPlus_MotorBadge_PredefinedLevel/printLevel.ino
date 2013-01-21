
// if specified, print level - X is the player
// note, this will not break when compiling for the
// ATtiny85, since it has no serial...

void printLevel() {
  
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);

  /*
  // iterate the level
  for (int ry=0; ry<height; ry++) {

    // some padding at left side of row
    // Serial.print("");

    for (int rx=0; rx<width; rx++) {

      // player
      if (rx == x && ry == y) {
        Serial.print("X");
      }

      // room
      int tile = level[ry][rx];

      if (tile == 0) {
        Serial.print(" ");    
      }
      else if (tile == 1) {
        Serial.print("+");
      }
      else if (tile == 2) {
        Serial.print(".");
      }
      else if (tile == 3) {
        Serial.print("W");
      }
    }

    // new line
    Serial.println("");
  }

  // space for next printLevel
  Serial.println("");
  */
}

