
// move player within the dungeon level
void dungeonLevel(char dir) {

  // north
  if (dir == 'n') {
    if (y-1 < 0) {
      newLevel('n');
      rumble(floorDur, 0, 1);
    }
    else {
      if (room[y-1][x] == 0) {
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
      newLevel('e');
      rumble(floorDur, 0, 1);
    }
    else {
      if (room[y][x+1] == 0) {
        x += 1;
        rumble(floorDur, 0, 1);
      }
      
      // move outside!
      else if (room[y][x+1] == 2) {
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
      newLevel('s');
      rumble(floorDur, 0, 1);
    }
    else {
      if (room[y+1][x] == 0) {
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
      newLevel('w');
      rumble(floorDur, 0, 1);
    }
    else {
      if (room[y][x-1] == 0) {
        x -= 1;
        rumble(floorDur, 0, 1);
      }
      else {
        rumble(wallDur, 0, 1);
      }
    }
  }

  // if specified, print the room and player position
  if (printDebug) {
    printLevel();
  }
}
