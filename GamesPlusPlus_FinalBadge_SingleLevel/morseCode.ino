
// play morse code from a char array, noted in quotes
// we use analogWrite to make a more sing-song like reading

// parse your own! note that dot/dash/space only, no word separator
// // www.morsecode.scphillips.com/jtranslator.html

void morseCode(char text[], int len) {

  // times for dot, dash, and space
  // normal Morse Code has word separators, we skip them here

  // 3V durations
  // const int dot = 150;
  // const int dash = 350;
  // const int space = 200;
  // const int morseIntensity = 255;

  // 5V durations
  const int dot = 50;
  const int dash = 100;
  const int space = 200;
  const int morseIntensity = 100;

  for (int c = 0; c<len; c++) {

    // button pressed? quit running the morse sequence
    int b = analogRead(buttons);
    if (b > 20) {
      return;
    }

    // DOT
    if (text[c] == '.') {
      analogWrite(motor, morseIntensity);
      if (fancy) {
        digitalWrite(led, HIGH);
      }
      delay(dot);
      if (fancy) {
        digitalWrite(led, LOW);
        delay(20);
      }
    }

    // DASH
    else if (text[c] == '-') {
      analogWrite(motor, morseIntensity);
      if (fancy) {
        digitalWrite(led, HIGH);
      }
      delay(dash);
      if (fancy) {
        digitalWrite(led, LOW);
        delay(20);
      }
    }

    // SPACE
    else if (text[c] == ' ') {
      digitalWrite(motor, LOW);
      digitalWrite(led, LOW);
      delay(space);
    }
  }

  // a final delay before starting the level
  delay(1000);
}



