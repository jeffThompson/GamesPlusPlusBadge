
// rumble the motor for different actions and terrains
void rumble(int onTime, int offTime, int numVibes) {
  for (int i=0; i<numVibes; i++) {
    digitalWrite(motorLED, HIGH);
    delay(onTime);
    digitalWrite(motorLED, LOW);
    delay(offTime);
  }
}



