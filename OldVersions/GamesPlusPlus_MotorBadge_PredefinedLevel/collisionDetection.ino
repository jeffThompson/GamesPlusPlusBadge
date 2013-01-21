
// move player within the dungeon level
int collisionDetection(char dir) {

  int next;
  
  if (dir == 'n') {
    next = level[y-1][x];
  }
  else if (dir == 'e') {
    next = level[y][x+1];
  }
  else if (dir == 's') {
    next = level[y+1][x];
  }
  else if (dir == 'w') {
    next = level[y][x-1];
  }
  
  return next;
  
  
  /*
  // north
  if (dir == 'n') {
    if (y-1 < 0) {
      // new level
      rumble(floorDur, 0, 1);
    }
    else {
      if (level[y-1][x] == 0) {
        y -= 1;
        rumble(floorDur, 0, 1);
      }
      else {
        rumble(wallDur, 0, 1);
      }
    }
  }

  // east
  else if (dir == 'e') {
    if (x+1 > 4) {
      // new level
      rumble(floorDur, 0, 1);
    }
    else {
      if (level[y][x+1] == 0) {
        x += 1;
        rumble(floorDur, 0, 1);
      }
      
      // move outside!
      else if (level[y][x+1] == 2) {
        x = 0;
        dungeon = false;
        beach = true;
        rumble(floorDur, 0, 1);
      }
      else {
        rumble(wallDur, 0, 1);
      }
    }
  }

  // south
  else if (dir == 's') {
    if (y+1 > 4) {
      // new level
      rumble(floorDur, 0, 1);
    }
    else {
      if (level[y+1][x] == 0) {
        y += 1;
        rumble(floorDur, 0, 1);
      }
      else {
        rumble(wallDur, 0, 1);
      }
    }
  }

  // west
  else if (dir == 'w') {
    if (x-1 < 0) {
      // new level
      rumble(floorDur, 0, 1);
    }
    else {
      if (level[y][x-1] == 0) {
        x -= 1;
        rumble(floorDur, 0, 1);
      }
      else {
        rumble(wallDur, 0, 1);
      }
    }
  }

  // if specified, print the level and player position
  if (printDebug) {
    printLevel();
  }
  */
}
