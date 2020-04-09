#include <QTRSensors.h>
#include "variables.h"
String path_to_next_destination = "";
int junctionIndex = 0;


void setup() {
  // Moters
  pinMode(lf, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(rf, OUTPUT);
  pinMode(rb, OUTPUT);
  pinMode(lPWM, OUTPUT);
  pinMode(rPWM, OUTPUT);

  // Sonar
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  Serial.begin(9600);
  atHome();
}

void loop() {
  path_to_next_destination = createPath(currentPosition, destination);
  go();
  




  //  path_to_next_destination += "123";
  //  Serial.print("***********   ");
  //  Serial.println(path_to_next_destination.length() + 1);
  //  Serial.println(path_to_next_destination);
}
