int const turnDelay = 350;     //delay to make a 90 degrees turn

bool turn(bool left, bool right, bool straight, bool back, bool error) {
  switch (path_to_next_destination[junctionIndex]) {
    case 'L':
      if (left == 1){
        turnLeft();
        junctionIndex++;
      } else {
        error = true;
      }
      break;
    case 'R':
      if (right == 1){
        turnRight();
        junctionIndex++;
      } else {
        error = true;
      }
      break;
    case 'S':
      if (straight == 1){
        turnStraight();
        junctionIndex++;
      } else {
        error = true;
      }
      break;
    case 'B':
      if (back == 1){
        drive(0, 0);
        atTheDoor();
        turnBack();
      } else {
        error = true;
      }
      break;
  }
  if (error) {
    // Error Code
  }
}


void turnRight() {
  drive(100, -100);

  delay(turnDelay);

  updateVal();
  while (s(2) == 0) {
    updateVal();
  }
  drive(0, 0);
}

void turnLeft() {
  drive(-100, 100);

  delay(turnDelay);

  updateVal();
  while (s(5) == 0) {
    updateVal();
  }
  drive(0, 0);
}

void turnStraight() {
  drive(100, 100);
  delay(20);
  drive(0, 0);
}

void turnBack() {
  drive(100, 100);
  delay(300);

  drive(-100, 100);
  delay(500);

  updateVal();
  while (s(5) == 0) {
    updateVal();
  }
  drive(0, 0);
}
