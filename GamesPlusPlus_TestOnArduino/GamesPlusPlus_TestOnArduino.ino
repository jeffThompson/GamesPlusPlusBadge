/*
GAMES++ BADGE:    ROUGELIKE
 Jeff Thompson:    hardware, coding              www.jeffreythompson.org
 Alex Myers:       interaction/level design      www.alexmyers.info
 
 THIS IS THE TEST CODE FOR RUNNING ON AN ARDUINO BOARD - THE ACTUAL
 BADGE RUNS ON A 3V BATTERY, SO THE PULSES ARE MUCH SOFTER
 
 For details, see the 'FinalBadge' code...
 
 www.driftstation.org/gamesplusplus
 */


// level stored as 2d array
const byte level[5][5] = {
{2,2,2,2,2},
{2,1,0,1,2},
{2,1,0,1,2},
{2,1,1,1,2},
{2,2,2,2,2},
};
const int width = 5;         // width of the level
const int height = 5;        // ditto height

// player starting coordinates (determined in level file)
int x = 2;
int y = 2;

boolean death = false;        // are we dead yet?
const int numWaves = 10;      // number of waves before simply stopping
int wavePeak;

// pins
const int motor = 13;       // ATtiny: 0, Arduino: 13
const int buttons = 0;      // ATtiny: 3, Arduino 0

// intro to be played as morse code at the start
// "you have been blinded and thrown in a dungeon..."
boolean morseIntro = false;
char intro[] = { 
  "-.-- --- ..- .... .- ...- . -... . . -. -... .-.. .. -. -.. . -.. .- -. -.. - .... .-. --- .-- -. .. -. .- -.. ..- -. --. . --- -. .-.-.-" };


void setup() {                
  pinMode(motor, OUTPUT);    // set motor to output

  // intialize USB connection - for Arduino only
  // comment out or delete for ATtiny upload
  Serial.begin(9600);
  printLevel();

  // play the intro text as Morse Code at the start
  if (morseIntro) {
    morseCode(intro, sizeof(intro));
  }

}

void loop() {

  // if not dead yet, go to regular gameplay
  if (!death) {
    char dir = checkButtons();    // are buttons pressed?
    if (dir != ' ') {             // if not space (ie: pressed)
      movePlayer(dir);            // move the player
      printLevel();               // if available, print the level via USB...
    }
    delay(50);                    // keep "frame rate" reasonable
  }

  // we ARE dead? make pulsing waves
  else {
    for (int i=0; i<numWaves; i++) {                       // make series of waves...
      wavePeak = map(i, 0,numWaves, 60,255);               // increase the intensity of the waves
      rumble(-1);                                          // rumble it!
      digitalWrite(motor, LOW);                            // set pin low
      int timeBetween = map(wavePeak, 60,255, 500, 50);
      delay(timeBetween);                                  // gap between
    }
    rumble(-2);                                            // fadeout wave
    while(1) {                                             // and run endlessly until reset, stopping the game
    }
  }
}
