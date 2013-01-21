/* ok, a little confusing:

   0 o 0
   o x o
   0 o 0
   
   0 = always on and NOT controlled via pins
   o = PWM leds (can be walls, player, or nothing
   x = either off or player (never a wall)
   
   since we only have 4 PWM pins and a total of 5 pins (when we have 4 buttons)
   we simply couldn't run the entire matrix - since the four corner LEDs are
   always walls, this works great!
*/

// TO DO: PWM pin managment

/*
GAMES++ BADGE (ie: Rougelike-like in 3x3 matrix)
 Jeff Thompson | 2012 | www.jeffreythompson.org
 
 Prototype for games++ badge - to be run on a microcontroller, 9-LED
 display, and four directional buttons.
 
 TO DO: 
 + better collision detection with walls
 + two key pressed = plusses again
 
 IDEAS:
 + count # of one direction - thresh reached and something happens
 + hit the wall too many times and an enemy appears (or walls move in)
 + can we go outside (trees? ocean?)
 + win? escape?
 + enemies?
 + fadeout?
 + if we can't PWM, then blink player?
 
 */

// basic variables!
int px = 100;        // pixel size
int spacer = 13;     // space between pixels

// player
int x, y;                      // player position
boolean blinkPlayer = false;   // blink the player?
int playerBlinkTime = 500;     // ms (don't need to keep track of time*)
long playerStartTime;          // store time of previous change
boolean playerBlink = true;    // toggle visibility of player

// probability that there will be a door on a given wall
float doorProb = 0.6;      // 0.1 = 10%, 0.9 = 90% chance

// store walls as a 2d array (0=nothing, 1=wall)
int walls[3][3] = { 
  {
    0,0,0  }
  , {
    0,0,0  }
  , {
    0,0,0  } 
};

// "colors" (ie: brightness)
int litColor = 255;    // player color
int pwmColor = 100;    // wall color

// startup plus
boolean startup = true;    // flag for startup animation
long plusStartTime;
int plusDur = 2000;

// pins (buttons are on A0 and A1)
int doorPins[] = {     // these MUST be PWM pins since the player may occupy
  7, 2, 3, 4 };
int ctrPin = 8;        // not PWM (since it can only be player or off)

void setup() {

  // output is analogWrite so nothing to do here
  // we read the buttons (2 per pin) as analog values, so ditto

  // start you in center
  x = 1;
  y = 1;
  playerStartTime = millis();

  // start random level
  newLevel(int(random(4)));    // seed door, or just pick a number...
  plusStartTime = millis();
}

void loop() {

  // draw + at startup
  if (startup) {
    if (plusStartTime+plusDur < millis()) {
      startup = false;
    }
    drawPlus();
  }

  // when done, start the level
  else {

    // check buttons
    int upDown = analogRead(0);
    int rightLeft = analogRead(1);
    buttonPressed(upDown, rightLeft);

    // turn off all pixels
    for (int i=0; i<3; i++) {
      for (int j=0; j<3; j++) {
        drawPx(i, j, 0);
      }
    }

    // draw walls
    drawWalls();

    // draw player
    if (blinkPlayer) {      // if we want to blink the player, do it
      if (playerStartTime + playerBlinkTime < millis()) {
        playerBlink = !playerBlink;
        playerStartTime = millis();
      }
      if (playerBlink) {
        drawPx(x, y, litColor);
      }
    }
    else {    // otherwise, draw as usual
      drawPx(x, y, litColor);
    }
  }
}


