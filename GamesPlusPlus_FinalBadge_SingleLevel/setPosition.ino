
// set x/y position for player, depending on which level is loaded

void setPosition() {
  
  // set to new level; if at the portal, respawn at the start x/y
  if (whichLevel == 1) {          // rubble dungeon
    x = 5;
    y = 12;
  }
  else if (whichLevel == 2) {     // checkboard/columns
    x = 0;
    y = 13;
  }
  else if (whichLevel == 3) {     // criss-cross
    x = 2;
    y = 0;
  }
  else if (whichLevel == 4) {     // figure-8
    x = 6;
    y = 6;
  }
  else if (whichLevel == 5) {     // spiral
    x = 6;
    y = 6;
  }
}




