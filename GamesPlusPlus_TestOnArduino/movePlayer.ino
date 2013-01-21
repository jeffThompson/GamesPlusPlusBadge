
// if array key is pressed, check for
// collission with a wall and move player
void movePlayer(char dir) {

  // north
  if (dir == 'n') {
    if (y-1 < 0) {                       // if you move offscreen...
      y--;                               // fall into the ocean...
      death = true;                      // and die!
    }
    else {
      rumble(level[y-1][x]);             // play the appropriate rumble-interface
      if (level[y-1][x] != 1) {          // if next tile is NOT a wall
        y--;                             // move player
      }
    }
  }

  // south
  if (dir == 's') {
    if (y+1 > height-1) {
      y++;
      death = true;
    }
    else {
      rumble(level[y+1][x]);
      if (level[y+1][x] != 1) {
        y++;
      }
    }
  }

  // east
  if (dir == 'e') {
    if (x+1 > width-1) {
      x++;
      death = true;
    }
    else {
      rumble(level[y][x+1]);
      if (level[y][x+1] != 1) {
        x++;
      }
    }
  }

  // west
  if (dir == 'w') {
    if (x-1 < 0) {
      x--;
      death = true;
    }
    else {
      rumble(level[y][x-1]);
      if (level[y][x-1] != 1) {
        x--;
      }
    }
  }
}





