
// play morse code from a char array, noted in quotes
// we use analogWrite to make a more sing-song like reading
void morseCode(char text[], int len) {

  // times for dot and dash
  // normal Morse Code has word separators, we skip them here
  const int dot = 100;
  const int dash = 250;
  const int spacer = 50;
  const int wspacer = 200;

  for (int c = 0; c<len; c++) {
    
    if (text[c] == '.') {
      analogWrite(motor, 60);
      delay(dot);
    }
    else if (text[c] == '-') {
      analogWrite(motor, 120);
      delay(dash);
    }
    else if (text[c] == ' ') {
      delay(wspacer);
    }
    digitalWrite(motor, LOW);
    
    /*
    if (text[c] == '.') {              // short
      digitalWrite(motor, HIGH);
      delay(dot);
      digitalWrite(motor, LOW);
      delay(spacer);
    }
    else if (text[c] == '-') {         // long
      digitalWrite(motor, HIGH);
      delay(dash);
      digitalWrite(motor, LOW);
      delay(spacer);
    }
    else if (text[c] == ' ') {         // letter spacer
      delay(wspacer);
    }
    */
    
  }

  delay(1000);         // a final delay before starting the level
}
