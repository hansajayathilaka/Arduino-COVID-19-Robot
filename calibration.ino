//  s(0)  s(1)  {{{  s(2)  s(3)  }}}  s(4)  s(5)  \\
//================================================\\
//               {{{A}}}    {{{B}}}               \\

void sCalibrate() {
  int calibrateVariable = 80;       // should be devided by 5
  int calibrateSpeed = 80;

  for (int i = 0; i < calibrateVariable; i++) {         // 50
    if (i < calibrateVariable / 5) {                    // 10
      drive(0, 0);
    }
    else if (i < 2 * calibrateVariable / 5) {           // 20
      drive(-calibrateSpeed, calibrateSpeed);
    }
    else if (i < 4 * calibrateVariable / 5) {           // 40
      drive(calibrateSpeed, -calibrateSpeed);
    }
    else {
      drive(-calibrateSpeed, calibrateSpeed);
    }
    qtra.calibrate();
    qtraTest.calibrate();
  }
  drive(0, 0);


  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtra.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtra.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  for (int i = 0; i < 6; i++) {
    Serial.print(qtraTest.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();

  for (int i = 0; i < 6; i++) {
    Serial.print(qtraTest.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
}
