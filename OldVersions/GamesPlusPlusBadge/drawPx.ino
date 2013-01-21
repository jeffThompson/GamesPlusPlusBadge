
void drawPx(int _x, int _y, int bright) {
  
  // position in matrix, brightness
  analogWrite(ledPins[x * y+3], bright);
}
