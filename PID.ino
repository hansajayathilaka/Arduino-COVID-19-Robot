float Kp = 0.09;
float Kd = 0.3;
int rightMaxSpeed  =  180;
int leftMaxSpeed   =  180;
int rightBaseSpeed =  130;
int leftBaseSpeed  =  130;
int lastError = 0;

#define NUM_SENSORS             5  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading
#define EMITTER_PIN             2  // emitter is controlled by digital pin 2

// sensors 0 through 5 are connected to analog inputs 0 through 5, respectively
QTRSensorsAnalog qtra((unsigned char[]) {
  A1, A2, A6, A3, A4
},
NUM_SENSORS, NUM_SAMPLES_PER_SENSOR, EMITTER_PIN);


void PID() {
  unsigned int sensors[NUM_SENSORS];
  int position = qtra.readLine(sensors, QTR_EMITTERS_ON , 0);    //, QTR_EMITTERS_ON , 1
  int error = position - 2000;
  Serial.print(error);
  Serial.print('\t');
  for (int i = 0; i < 5; i++) {
    Serial.print(sensors[i]);
    Serial.print('\t');
  }
  Serial.println();

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed - motorSpeed;
  int leftMotorSpeed = leftBaseSpeed + motorSpeed;

  rightMotorSpeed = constrain(rightMotorSpeed, -rightMaxSpeed, rightMaxSpeed);
  leftMotorSpeed = constrain(leftMotorSpeed, -leftMaxSpeed, leftMaxSpeed);

  drive(leftMotorSpeed, rightMotorSpeed);
}
