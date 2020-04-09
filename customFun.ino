//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

void updateVal() {
  qtraTest.read(sensorValues);
}

bool s(byte val) {
  if (sensorValues[val] >= 650)
    return 1;
  else
    return 0;
}

byte sumSensors() {
  updateVal();
  byte num = 0;
  for (byte x = 0; x < NUM_SENSORS; x++) {
    num = num + s(x);
  }
  return num;
}

//long turnError() {
//  unsigned int sensors[NUM_SENSORS];
//  int position = qtra.readLine(sensors);
//  int error = position - 3500;
//  //  error = error / 500;
//  return (error);
//}

float distance () {
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 1500);
  distance = (duration / 2.0) / 29.1;
  if (distance == 0)
    distance = 20.0;
  else
    distance = constrain(distance, 0, 20);
  return distance;
}
