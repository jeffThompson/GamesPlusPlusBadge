
// play morse code from a char array, noted in quotes
// we use analogWrite to make a more sing-song like reading

// parse your own! note that dot/dash/space only, no word separator
// // www.morsecode.scphillips.com/jtranslator.html

void morseCode(char text[], int len) {

  // times for dot, dash, and space
  // normal Morse Code has word separators, we skip them here
  const int dot = 150;
  const int dash = 350;
  const int space = 200;

  for (int c = 0; c<len; c++) {

    // button pressed? quit running the morse sequence
    int b = analogRead(buttons);
    if (b > 20) {
      return;
    }

    // pulse the next character
    if (text[c] == '.') {
      analogWrite(motor, 255);
      delay(dot);
    }
    else if (text[c] == '-') {
      analogWrite(motor, 255);
      delay(dash);
    }
    else if (text[c] == ' ') {
      delay(space);
    }
    digitalWrite(motor, LOW);
    delay(250);
  }

  delay(1000);         // a final delay before starting the level
}

