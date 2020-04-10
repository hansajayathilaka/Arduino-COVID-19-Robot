bool sensorCount() {
  int a = analogRead(A6);
  int b = analogRead(A7);
  if ((a > 60) || (b > 60)) {
    return 1;
  } else {
    return 0;
  }
}
