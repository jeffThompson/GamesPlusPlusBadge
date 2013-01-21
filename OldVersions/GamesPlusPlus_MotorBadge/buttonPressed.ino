
// read the buttons and move the player
char buttonPressed() {

  // if this returns a space, we know we didn't move
  char whichDir = ' ';

  // up/north
  n = digitalRead(buttons[0]);
  if (n == LOW && n != pn) {
    whichDir = 'n';
  }

  // right/east
  e = digitalRead(buttons[1]);
  if (e == LOW && e != pe) {
    whichDir = 'e';
  }

  // down/south
  s = digitalRead(buttons[2]);
  if (s == LOW && s != ps) {
    whichDir = 's';
  }

  // left/west
  w = digitalRead(buttons[3]);
  if (w == LOW && w != pw) {
    whichDir = 'w';
  }

  // update previous variables
  pn = n;
  pe = e;
  ps = s;
  pw = w;
  
  return whichDir;
}


