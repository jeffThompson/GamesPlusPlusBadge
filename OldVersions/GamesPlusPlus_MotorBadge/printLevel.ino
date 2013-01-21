
// if specified, print level - X is the player
// note, this will not break when compiling for the
// ATtiny85, since it has no serial...

void printLevel() {
  
  // iterate the level
  for (int ry=0; ry<5; ry++) {
    
    // some padding at left side of row
    Serial.print("   ");
    
    for (int rx=0; rx<5; rx++) {

      // player
      if (rx == x && ry == y) {
        Serial.print("X");
      }
      
      // room
      else {
        if (room[ry][rx] == 0) {
          Serial.print(" ");
        }
        else if (room[ry][rx] == 1) {
          Serial.print("+");
        }
        else if (room[ry][rx] == 2) {
          Serial.print("O");
        }
      }
      Serial.print("  ");
    }
    
    // new line
    Serial.println("");
  }
  
  // space for next printLevel
  Serial.println("");
}
