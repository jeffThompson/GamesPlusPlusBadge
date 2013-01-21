
// check for buttons - move that direction
// if we're now offscreen, reset the character's
// position and generate a new level with a door
// where we came in (ie: enter N, new door S)

void buttonPressed(int upDown, int rightLeft) {

  boolean pressed = false;
  int dir = 0;

  // check if a button is pressed - if so, break and update!
  // 0=UP, 1=RIGHT, 2=DOWN, 3=LEFT (like CSS order)  
  if (upDown >= 120 && upDown <= 130) {
    dir = 0;
    pressed = true;
  }
  else if (upDown >= 245 && upDown <= 255) {
    dir = 2;
    pressed = true;
  }
  else if (rightLeft >= 120 && rightLeft <= 130) {
    dir = 1;
    pressed = true;
  }
  else if (rightLeft >= 245 && rightLeft <= 255) {
    dir = 3;
    pressed = true;
  }

  // if pressed, update
  if (pressed) {
    if (dir == 0) {
      y -= 1;                // move
      if (y < 0) {           // if beyond the screen
        y = 2;               // set to other side of the screen
        newLevel(0);         // make a new level with a door on the previous side
      }
      if (hitWall(x, y)) {   // check for collision with the wall
        y += 1;              // an ugly hack - we can do better...
      }
    }

    if (dir == 1) {
      x += 1;
      if (x > 2) {
        x = 0;
        newLevel(1);
      }
      if (hitWall(x, y)) {
        x -= 1;
      }
    }

    if (dir == 2) {
      y += 1;
      if (y > 2) {
        y = 0;
        newLevel(2);
      }
      if (hitWall(x, y)) {
        y -= 1;
      }
    }

    if (dir == 3) {
      x -= 1;
      if (x < 0) {
        x = 2;
        newLevel(3);
      }
      if (hitWall(x, y)) {
        x += 1;
      }
    }
  }
}

boolean hitWall(int wx, int wy) {

  if (walls[wx][wy] == 1) {
    return true;
  }

  // otherwise, return false (no collision)
  return false;
}




