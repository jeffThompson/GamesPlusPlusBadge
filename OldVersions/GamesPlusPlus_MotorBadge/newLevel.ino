
// create a new, random level
void newLevel(char dir) {

  // generate random doors
  boolean doors[4];
  for (int i=0; i<4; i++) {
    doors[i] = random(100) < doorProb;
  }

  // update position to other side of room
  // and put a door there
  if (dir == 'n') {
    y = 4;
    doors[2] = true;
  }
  else if (dir == 'e') {
    x = 0;
    doors[3] = true;
  }
  else if (dir == 's') {
    y = 0;
    doors[0] = true;
  }
  else if (dir == 'w') {
    x = 4;
    doors[1] = true;
  }

  // put a door on the north wall
  if (doors[0]) {
    room[0][2] = 0;
  }
  else {
    room[0][2] = 1;
  }

  // ditto east
  if (doors[1]) {
    room[2][4] = 0;
  }
  else {
    room[2][4] = 1;
  }

  // ditto south
  if (doors[2]) {
    room[4][2] = 0;
  }
  else {
    room[4][2] = 1;
  }

  // ditto west
  if (doors[3]) {
    room[2][0] = 0;
  }
  else {
    room[2][0] = 1;
  }
  
  // draw an exit door?
  boolean exit = random(100) < exitProb;
  if (exit) {
    room[2][4] = 2;
  }

  // print the level we've just created...
  if (printDebug) {
    printLevel();
  }
}
