/*
GAMES++ BADGE - TEST LEVEL
 Jeff Thompson | 2012 | www.jeffreythompson.org
 
 Parse a simple Rouge-like level made from an image file and play.
 
 IMAGE RULES:
 color   rgb              which tile here?
 white   (255,255,255)    floor
 blue    (0,0,255)        rubble
 black   (0,0,0)          wall
 yellow  (255,255,0)      sand
 green   (0,255,0)        drop
 red     (255,0,0)        player start position
 
 */


// VARIABLES TO CHANGE
int whichLevel = 9;
String filename = "ATtinyLevels/" + nf(whichLevel, 2) + ".png";  // level image file to load!
int levelFontSize = 15;             // just what it says
int pad = 50;                       // side padding (px)

// other level variables
PImage img;                         // image file
int[][] level;                      // stores the level as a 2d array
int w, h;                           // level's dimensions

// player
int x, y;

// other (death, font, time)
boolean ocean = false;
PImage skull;
PFont font;
long m;
String[] saveLevel = new String[1];

void setup() {

  font = loadFont("Monospaced-24.vlw");  // create font
  textFont(font, levelFontSize);         // set up display...
  textAlign(CENTER, CENTER);
  noStroke();
  smooth();
  fill(255);

  // load image and parse level to array
  img = loadImage(filename);
  w = img.width;
  h = img.height;
  parseLevel();

  size(int(textWidth('+')) * w * 3 + pad*2, levelFontSize/2 * h * 3 + pad*2);
  m = millis();
  skull = loadImage("skull.png");
}

void draw() {

  background(0);

  // intro
  if (m + 3500 > millis()) {
    textFont(font, levelFontSize*2);
    text("YOU HAVE BEEN BLINDED AND\nTHROWN IN A DUNGEON", width/2, height/2);
  }

  // gameplay
  else if (!ocean) {
    textFont(font, levelFontSize);
    String s = "";
    for (int ly = 0; ly<w; ly++) {
      for (int lx = 0; lx<h; lx++) {

        int l = level[ly][lx];

        // player
        if (lx == x && ly == y) {
          s += " X ";
        }

        // floor
        else if (l == 0) {
          s += "   ";
        }

        // rubble
        else if (l == 3) {
          s += ":::";
        }

        // wall
        else if (l == 1) {
          s += " + ";
        }

        // beach
        else if (l == 2) {
          s += " . ";
        }

        // drop
        else if (l == 4) {
          s += "[ ]";
        }
      }

      // after each line, add a newline character
      s += "\n";
    }

    // display the text!
    text(s, width/2, height/2);
  }

  // death
  else {
    textFont(font, levelFontSize*2);
    text("WAVES CRASH OVER YOU, CRUSHING YOUR TINY\nFRAME IN THEIR HEFT... YOU ARE NOW DEAD", width/2, height*0.33);
    image(skull, width/2-img.width*2, height*0.63-img.height/2);
  }
}

void keyPressed() {
  if (key == CODED) {

    // north
    if (keyCode == UP ) {
      if (y <= 0) {          // if outisde the bounds...
        ocean = true;        // your're dead!
      }
      else if (level[y-1][x] != 1) {
        if (level[y-1][x] == 4 && whichLevel > 1) {
          whichLevel--;
          img = loadImage("levels/" + nf(whichLevel, 2) + ".png");
          parseLevel();
        }
        y--;
      }
    }

    // south
    if (keyCode == DOWN) {
      if (y >= h-1) {
        ocean = true;
      }
      else if (level[y+1][x] != 1) {
        if (level[y+1][x] == 4 && whichLevel > 1) {
          whichLevel--;
          img = loadImage("levels/" + nf(whichLevel, 2) + ".png");
          parseLevel();
        }
        y++;
      }
    }

    // east
    if (keyCode == RIGHT) {
      if (x >= w-1) {
        ocean = true;
      }
      else if (level[y][x+1] != 1) {
        if (level[y][x+1] == 4 && whichLevel > 1) {
          whichLevel--;
          img = loadImage("levels/" + nf(whichLevel, 2) + ".png");
          parseLevel();
        }
        x++;
      }
    }

    if (keyCode == LEFT) {
      if (x <= 0) {
        ocean = true;
      }
      else if (level[y][x-1] != 1) {
        if (level[y][x-1] == 4 && whichLevel > 1) {
          whichLevel--;
          img = loadImage("levels/" + nf(whichLevel, 2) + ".png");
          parseLevel();
        }
        x--;
      }
    }
  }
}

void parseLevel() {

  println("\nLEVEL " + whichLevel + ":");
  
  img.loadPixels();
  level = new int[h][w];
  saveLevel[0] = "// level stored as 2d array\n";
  saveLevel[0] += "int whichLevel = " + whichLevel + ";\n";
  saveLevel[0] += "const int level[" + h + "][" + w + "] = {\n";

  for (int ly = 0; ly < h; ly++) {

    saveLevel[0] += "  {";
    for (int lx = 0; lx < w; lx++) {

      // check color and add to row
      color c = img.pixels[lx + ly*img.width];

      // wall
      if (c == color(0)) {
        level[ly][lx] = 1;
        saveLevel[0] += "1";
      }
      // floor
      else if (c == color(255)) {
        level[ly][lx] = 0;
        saveLevel[0] += "0";
      }
      // rubble
      else if (c == color(0, 0, 255)) {
        level[ly][lx] = 3;
        saveLevel[0] += "3";
      }
      // player (just print position)
      else if (c == color(255, 0, 0)) {
        level[ly][lx] = 0;
        saveLevel[0] += "0";
        x = lx;
        y = ly;
        println("  player start:     " + x + ", " + y);
      }
      // beach
      else if (c == color(255, 255, 0)) {
        level[ly][lx] = 2;
        saveLevel[0] += "2";
      }
      // drop
      else if (c == color(0, 255, 0)) {
        level[ly][lx] = 4;
        saveLevel[0] += "4";
      }
      // if not last element in row, add a comma
      if (lx != w-1) {
        saveLevel[0] += ", ";
      }
    }

    // end of line: close array and add comma
    if (ly != h-1) {
      saveLevel[0] += "},\n";
    }
    else {
      saveLevel[0] += "}\n";
    }
  }

  // finish array and save to file (with player starting coordinates)
  saveLevel[0] += "};";
  saveLevel[0] += "\n\n// dimensions of the level\nconst int width = " + img.width + ";\nconst int height = " + img.height + ";";
  saveLevel[0] += "\n\n// player starting coordinates\nint x = " + x + ";\nint y = " + y + ";";
  String outputFilename = filename.substring(0, filename.lastIndexOf('.'));    // remove extension
  saveStrings(outputFilename + ".txt", saveLevel);
}

