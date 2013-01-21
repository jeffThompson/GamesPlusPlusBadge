
/*
 GAMES++ BADGE: MOTOR
 Jeff Thompson | 2012 | www.jeffreythompson.org
 
 TO DO:
 optimize level array to be char unsigned char (1 byte, 0-255)
 
 22x22
 100 x 5
 36 x 14
 16 x 32
 
 */

boolean printDebug = true;
boolean playMorseIntro = true;

int buttons[] = {
  5,4,2,3};
int motorLED = 13;

// rumble times
int floorDur = 75;
int wallDur = 0;
int sandDur = 100;

int x,y;
int n, e, s, w;
int pn, pe, ps, pw;

// y first, x second
const int width = 36;
const int height = 14;
int level[height][width];    // rows first, items in row second - see tab for details

// intro: "you have been blinded and thrown in a dungeon..."
char intro[] = { 
  "-.-- --- ..- .... .- ...- . -... . . -. -... .-.. .. -. -.. . -.. .- -. -.. - .... .-. --- .-- -. .. -. .- -.. ..- -. --. . --- -. .-.-.-" };

boolean ocean = false;


void setup() {

  // set pins
  pinMode(motorLED, OUTPUT);
  for (int i=0; i<4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);

  // initialize other variables
  x = 18;
  y = 6;
  pn = pe = ps = pw = LOW;

  // load level
  loadLevel();

  // show the level via USB
  if (printDebug) {
    Serial.begin(9600);
    printLevel();
  }

  // play the intro text as morse code
  if (playMorseIntro) {
    morseCode(intro, sizeof(intro));
  }
}


void loop() {

  // check if a button has been pressed
  char dir = buttonPressed();
  Serial.println(x);

  // in the dungeon (where we start)
  if (!ocean) {  
    if (dir != ' ') {                                // if it has (ie: not blank)

      int next = collisionDetection(dir);
      movePlayer(dir, next);
      
      Serial.print(x);
      Serial.print(", ");
      Serial.print(y);
      Serial.print(" -- ");
      Serial.println(level[y][x]);
      
      if (printDebug) {
        printLevel();
      }
    }
  }

  // ocean = death
  else {

  }

  delay(100);
}

void movePlayer(char dir, int next) {

  // north
  if (dir == 'n' && next != 1) {
    y--;
    if (next == 0) {
      rumble(floorDur, 0,1);
    }
    else if (next == 2) {
      rumble(sandDur, sandDur, 2);
    }
    else if (next == 3) {
      ocean = true;
    }
  }

  // east
  if (dir == 'e' && next != 1) {
    x++;
    if (next == 0) {
      rumble(floorDur, 0,1);
    }
    else if (next == 2) {
      rumble(sandDur, sandDur, 2);
    }
    else if (next == 3) {
      ocean = true;
    }
  }

  // south
  if (dir == 's' && next != 1) {
    y++;
    if (next == 0) {
      rumble(floorDur, 0,1);
    }
    else if (next == 2) {
      rumble(sandDur, sandDur, 2);
    }
    else if (next == 3) {
      ocean = true;
    }
  }

  // west
  if (dir == 'w' && next != 1) {
    x--;
    if (next == 0) {
      rumble(floorDur, 0,1);
    }
    else if (next == 2) {
      rumble(sandDur, sandDur, 2);
    }
    else if (next == 3) {
      ocean = true;
    }
  }
}









