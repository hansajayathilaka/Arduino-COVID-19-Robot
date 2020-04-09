void drive(int lMoter, int rMoter){
  if(lMoter > 0){
    analogWrite(lf, lMoter);
    analogWrite(lb, 0);
  } else {
    analogWrite(lf, 0);
    analogWrite(lb, abs(lMoter));
  }

  if(rMoter > 0){
    analogWrite(rf, rMoter);
    analogWrite(rb, 0);
  } else {
    analogWrite(rf, 0);
    analogWrite(rb, abs(rMoter));
  }
}
