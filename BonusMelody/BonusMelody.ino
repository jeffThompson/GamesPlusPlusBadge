/*
GAMES++ BADGE: BONUS MELODY!
 Jeff Thompson | 2012 | www.jeffreythompson.org
 
 A bonus melody - the "Games++ Theme" if you will - played
 using the badge's motor.
 */

int notes[] = { 
  60, 120, 193, 160, 215, 193, 60, 193 };
const int noteDuration = 250;
const int motor = 13;

void setup() {
  pinMode(motor, OUTPUT);

  // intro
  for (int i=0; i<4; i++) {
    playNote(120);
    digitalWrite(motor, LOW);
    delay(250);
  }
  delay(500);
}

void loop() {

  // play melody
  for (int i=0; i<8; i++) {

    // sometimes play a high note as last
    // 80% chance of being played
    if (i==7 && random(100) > 80) {
      playNote(255);
    }

    // otherwise, play as normal
    else {
      playNote(notes[i]);
    }
  }
}

void playNote(int freq) {
  analogWrite(motor, freq);
  delay(noteDuration); 
}





