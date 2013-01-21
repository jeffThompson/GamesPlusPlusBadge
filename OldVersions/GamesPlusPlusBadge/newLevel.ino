
// which door did we come through?
// 0=N, 1=E, 2=S, 3=W
// ex: if we entered a north door (0), create one in the
// south of the new level (2)

void newLevel(int cameThrough) {

  // four variables - one for each direction
  boolean doors[] = { false, false, false, false };

  // create random doors
  for (int i=0; i<4; i++) {
    doors[i] = random(1) < doorProb;
  }

  // make sure the one we came through is also a door
  switch (cameThrough) {
  case 0: 
    doors[2] = true; 
    break;
  case 1: 
    doors[3] = true; 
    break;
  case 2: 
    doors[0] = true; 
    break;
  case 3: 
    doors[1] = true; 
    break;
  }

  // generate level array - first fill blank
  for (int i=0; i<3; i++) {
    for (int j=0; j<3; j++) {
      walls[i][j] = 0;
    }
  }

  // then make walls
  for (int i=0; i<3; i++) {
    walls[i][0] = 1;    // N
    walls[i][2] = 1;    // S
  }
  for (int i=0; i<3; i++) {
    walls[0][i] = 1;    // W
    walls[2][i] = 1;    // E
  }

  // if they exist, draw the doors (back to 0);
  // NORTH
  if (doors[0]) {
    walls[1][0] = 0;
  }

  // EAST
  if (doors[1]) {
    walls[2][1] = 0;
  }

  // SOUTH
  if (doors[2]) {
    walls[1][2] = 0;
  }

  // WEST
  if (doors[3]) {
    walls[0][1] = 0;
  }
}

