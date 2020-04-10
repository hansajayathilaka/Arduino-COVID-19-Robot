#include <QTRSensors.h>
// Include RedioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Dependancy
#include <SPI.h>

#include "variables.h"

QTRSensorsAnalog qtraTest((unsigned char[]) {
  A0, A1, A2, A6, A3, A4, A5
},
7, 4, 2);
unsigned int sensorValues[7];

String path_to_next_destination = "";
int junctionIndex = 0;

RH_ASK rf_driver;


void setup() {
  // Moters
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);

  // Sonar
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  rf_driver.init();

  Serial.begin(9600);
  Serial.println("Begin....!");
  delay(2000);
  sCalibrate();
  delay(2000);
  //  atHome();
}

void loop() {
  //  PID();
  //  drive(0, 100);
  //  Serial.println(recieveData());
  //  go();
  updateVal();
  for (int i = 0; i < 7; i++) {
    //    Serial.print(s(i));
    Serial.print(s(i));
    Serial.print('\t');
  }
  Serial.println();
  //  path_to_next_destination = createPath(currentPosition, destination);

}
