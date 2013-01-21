
// play morse code from a char array, noted in quotes
void morseCode(char text[], int len) {

  // times for dot and dash
  // normal Morse Code has word separators, we skip them here
  int dot = 100;
  int dash = 250;
  int spacer = 50;
  int wspacer = 200;

  for (int c = 0; c<len; c++) {

    if (text[c] == '.') {              // short
      digitalWrite(motorLED, HIGH);
      delay(dot);
      digitalWrite(motorLED, LOW);
      delay(spacer);
    }
    else if (text[c] == '-') {         // long
      digitalWrite(motorLED, HIGH);
      delay(dash);
      digitalWrite(motorLED, LOW);
      delay(spacer);
    }
    else if (text[c] == ' ') {         // letter spacer
      delay(wspacer);
    }
  }

  delay(1000);         // a final delay before starting the level
}
