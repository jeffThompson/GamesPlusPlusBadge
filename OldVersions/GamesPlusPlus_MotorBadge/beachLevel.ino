
void beachLevel(char dir) {

  if (dir == 'n') {
    y -= 1;
    if (y < 0) {
      y = 4;
    }
    rumble(sandDur, sandDur, 2);
  }

  else if (dir == 'e') {
    x++;
    if (x > 4) {
      x = 0;
    }
    rumble(sandDur, sandDur, 2);
  }

  else if (dir == 's') {
    y++;
    if (y > 4) {
      y = 0;
    }
    rumble(sandDur, sandDur, 2);
  }

  else if (dir == 'w') {
    x -= 1;
    if (x < 0) {
      x = 4;
    }
    rumble(sandDur, sandDur, 2);
  }

  if (printDebug) {
    for (int i=0; i<5; i++) {
      for (int j=0; j<5; j++) {
        if (i == y && j == x) {
          Serial.print("X");
        }
        else {
          Serial.print(".");
        }
        Serial.print("  ");
      }
      Serial.println("");
    }
    
    // space between level updates
    Serial.println("");
  }

}

