
/*

 GAMES++ BADGE: MOTOR
 Jeff Thompson | 2012 | www.jeffreythompson.org
 
 IDEAS:
 + motor runs diff on diff terrain (floor low rumble) - battery concern? timer?
 + tunnels - 111
 000
 111
 + go outside? just open for a long while
 + ocean? waves of pulses?
 + enemies? hit count? death?
 + win?
 + on an island - to leave you go into the water, waves get higher, you drown: only way to end
 */

int buttons[] = {
  5,4,2,3};
int motorLED = 13;

// door probability (0-100%)
int doorProb = 60;        // regular door to another room
int exitProb = 50;        // exit door to beach (ie: exit)

// rumble times
int floorDur = 75;
int wallDur = 0;
int sandDur = 100;

int x,y;
int n, e, s, w;
int pn, pe, ps, pw;

// y first, x second (weird, yes)
int room[5][5] = { { 1,1,1,1,1 },
                   { 1,0,0,0,1 },
                   { 0,0,0,0,0 },
                   { 1,0,0,0,1 },
                   { 1,1,1,1,1 } };

// intro: "you have been blinded and thrown in a dungeon..."
char intro[] = { "-.-- --- ..- .... .- ...- . -... . . -. -... .-.. .. -. -.. . -.. .- -. -.. - .... .-. --- .-- -. .. -. .- -.. ..- -. --. . --- -. .-.-.-" };

// parts of the game (sort of levels)
boolean morseIntro = false;    // start at the intro
boolean dungeon = true;      // are we in the dungeon?
boolean beach = false;        // are we on the beach?
boolean ocean = false;        // are we in the ocean?

boolean printDebug = true;


void setup() {

  // set pins
  pinMode(motorLED, OUTPUT);
  for (int i=0; i<4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  // initialize other variables
  x = 2;
  y = 2;
  pn = pe = ps = pw = LOW;

  // show the level via USB
  if (printDebug) {
    Serial.begin(9600);
    printLevel();
  }
}

void loop() {

  // depending on where we are in the game
  // run different code (intro, etc)
  
  // play the intro text as morse code
  if (morseIntro) {
    morseCode(intro, sizeof(intro));
    morseIntro = false;
    dungeon = true;
  }
  
  // in the dungeon (where we start)
  else if (dungeon) {
    char dir = buttonPressed();  // check if a button has been pressed
    if (dir != ' ') {            // if it has (ie: not blank)
      dungeonLevel(dir);         // show the dungeon!
    }
  }
  
  // gone outside? on the beach
  else if (beach) {
    char dir = buttonPressed();
    if (dir != ' ') {
      beachLevel(dir);
    }
  }
  
  // past the beach and into the ocean?
  else if (ocean) {
    
  }
  
  delay(100);
}

