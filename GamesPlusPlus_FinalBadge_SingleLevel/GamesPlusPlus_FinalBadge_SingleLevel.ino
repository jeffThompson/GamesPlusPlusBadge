
/*
 GAMES++ BADGE
 Jeff Thompson:    hardware, coding              www.jeffreythompson.org
 Alex Myers:       interaction/level design      www.alexmyers.info
 
 A non-visual Rougelike-like for games++, a 10-hour intensive game
 jam held at the Bemis Center in Omaha, Nebraska, USA on Nov 10, 2012.
 
 The badge runs on an ATtiny85 chip and can easily be hacked to run
 other games - the source code here is well-commented to make hacking
 and/or full-scale redesign.
 
 Since the badge runs on a 3V battery, the motor pulses are much less
 powerful than when run off the Arduino: analogWrite can be felt at 250-175,
 150 is barely felt - less than that is not felt at all
 
 See the 'Schematic' tab for more details, or the 'SchematicAndPCB' folder
 for the full Eagle and PCB files.
 
 To automatically create levels for this game, see the 'LevelDesign'
 folder.
 
 www.driftstation.org/gamesplusplus
 */


// fancy board (with USB)?
boolean fancy = true;

// level stored as 2d array
int whichLevel = 1;               // level to start at (1-5)
byte level[14][14] = {
  {3, 4, 3, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1},
  {2, 3, 3, 3, 3, 1, 2, 2, 1, 2, 2, 1, 1, 2},
  {2, 2, 3, 3, 3, 1, 2, 2, 1, 2, 1, 1, 1, 2},
  {2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2},
  {2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 2, 1, 2, 2},
  {3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
  {1, 3, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 3},
  {1, 3, 3, 3, 3, 3, 3, 2, 2, 1, 2, 2, 2, 3},
  {1, 3, 3, 3, 1, 1, 1, 3, 2, 2, 3, 2, 2, 3},
  {1, 3, 1, 1, 1, 1, 3, 3, 3, 2, 2, 2, 2, 2},
  {3, 3, 1, 2, 2, 2, 3, 1, 1, 1, 1, 2, 2, 2},
  {2, 2, 2, 1, 1, 2, 1, 3, 3, 3, 3, 2, 1, 1},
  {2, 2, 2, 3, 3, 0, 3, 3, 1, 1, 2, 3, 2, 2},
  {1, 1, 2, 3, 3, 2, 1, 1, 1, 2, 2, 2, 2, 1}
};
const int width = 14;             // width of the level
const int height = 14;            // ditto height

// player coordinates
int x, y;

// pins
const int motor = 0;         // ATtiny: 0, Arduino: 13
const int buttons = 3;       // ATtiny: 3, Arduino 0
const int led = 1;           // on "fancy badges" only
char prevDir = ' ';          // store previous button state (prevents retriggering)

// intro to be played as morse code at the start
boolean morseIntro = true;   // disable to NOT play the intro
// "games plus plus"
// char intro[] = {
//   "--. .- -- . ... .--. .-.. ..- ... .--. .-.. ..- ..." };
  
// "you have been blinded and thrown in a dungeon..."
char intro[] = { 
"-.-- --- ..- .... .- ...- . -... . . -. -... .-.. .. -. -.. . -.. .- -. -.. - .... .-. --- .-- -. .. -. .- -.. ..- -. --. . --- -. .-.-.-" };


void setup() {
  pinMode(motor, OUTPUT);    // set motor to output
  
  // led is currently just a power indicator
  // uncomment for "fancy badges", otherwise may draw power needlessly
  if (fancy) {
    pinMode(led, OUTPUT);
  }

  // get player coords based on level
  setPosition();  

  // play the intro text as Morse Code at the start
  if (morseIntro) {
    morseCode(intro, sizeof(intro));
  }

  // if testing on regular Arduino, print the level over USB
  // comment out or delete for final code on ATtiny
  // Serial.begin(9600);
  // printLevel();

}

void loop() {
  char dir = checkButtons();    // are buttons pressed?
  if (dir != prevDir) {         // if we've pressed the button again...
    movePlayer(dir);            // move the player (space is ignored)
    // printLevel();            // if testing, print level over USB - COMMENT OUT FOR ATtiny
  }
  prevDir = dir;                // keep track of previous button-state
  delay(50);                    // keep "frame rate" reasonable
}
