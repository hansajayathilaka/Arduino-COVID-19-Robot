void drive(int lMoter, int rMoter){
  if(lMoter > 0){
    digitalWrite(lf, HIGH);
    digitalWrite(lb, LOW);
    analogWrite(lPWM, lMoter);
  } else {
    digitalWrite(lf, LOW);
    digitalWrite(lb, HIGH);
    analogWrite(lPWM, abs(lMoter));
  }

  if(rMoter > 0){
    digitalWrite(rf, HIGH);
    digitalWrite(rb, LOW);
    analogWrite(rPWM, rMoter);
  } else {
    digitalWrite(rf, LOW);
    digitalWrite(rb, HIGH);
    analogWrite(rPWM, abs(rMoter));
  }
}
