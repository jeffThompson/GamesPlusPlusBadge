
// rumble the motor for different actions and terrains
void rumble(int tile) {

  // floor - a short pit-pat
  if (tile == 0) {
    digitalWrite(motor, HIGH);
    delay(50);
    digitalWrite(motor, LOW);
    delay(100);
    digitalWrite(motor, HIGH);
    delay(30);
    digitalWrite(motor, LOW);
  }

  // wall - abrupt bump
  else if (tile == 1) {
    digitalWrite(motor, HIGH);
    delay(60);
    digitalWrite(motor, LOW);
  }

  // sand - dragging feet, slushy
  else if (tile == 2) {
    for (int i=0; i<5; i++) {          // shuffle
      analogWrite(motor, i*20 + 60);
      delay(50);
    }
    digitalWrite(motor, LOW);
    delay(100);
    digitalWrite(motor, HIGH);         // bump
    delay(30);
    digitalWrite(motor, LOW);
  }

  // death waves
  else if (tile == -1) {
    
    // or, for exponential:
    // pow(val/10, 1.73);
    // www.brendan-admi.blogspot.com/2011/11/exponential-mapping-in-arduino-all-men.html

    // wave up
    for (int i=0; i<10; i++) {
      int intensity = map(i, 0,10, 100, wavePeak);    // from min (100) to peak (up to 255)
      analogWrite(motor, intensity);
      int waveLen = map(i, 0,10, 5,500);
      delay(waveLen);                                 // longer at the crest
      
    }

    // sharp peak
    digitalWrite(motor, HIGH);
    delay(20);

    // wave down
    for (int i=9; i>=0; i--) {
      int intensity = map(i, 10,0, wavePeak, 10);     // back down to 100
      analogWrite(motor, intensity);
      int waveLen = map(i, 10,0, 100, 5);
      delay(waveLen);
    }
  }
  
  // fadeout wave
  else if (tile == -2) {
    for (int i=60; i<255; i++) {    // ramp up...
      analogWrite(motor, i);
      delay(5);
    }
    for (int i=255; i>=0; i-=1) {   // and slowly fade out
      analogWrite(motor, i);
      delay(30);
    }
  }
}






