//  s(0)  s(1)  s(2)  {{{ s(3)  s(4)  }}}  s(5)  s(6)  s(7)  \\
//===========================================================\\
//                    {{{A}}}     {{{B}}}                    \\

int const goDelay   = 40;     //delay to goto the end of the line
int const lineDelay = 75;     //delay to cross a line

void go() {
  while (true) {
    PID();

    bool error = 0;
    bool left = 0;
    bool right = 0;
    bool straight = 0;
    bool back = 0;

    updateVal();
    if (sumSensors() == 0) {     // Error Ditected
      error = 1;
    }

    else if ((s(0) == 1) && (s(1) == 1) && (s(2) == 1) && (s(3) == 1) && (s(4) == 1) && (s(7) == 0)) {      // Left detection
      junkDelay = millis();
      drive(130, 130);
      updateVal();
      while ((s(0) == 1) && (s(1) == 1) && (s(2) == 1) && (s(3) == 1) && (s(7) == 0)) {
        updateVal();
      }
      if (millis() - junkDelay > lineDelay) {
        left = 1;
        drive(150, 150);
        junkDelay = millis();
        straight = 1;
        while (millis() - junkDelay < goDelay) {
          updateVal();
          if ((s(3) == 0) && (s(4) == 0)) {
            straight = 0;
            break;
          }
        }
      }
      drive(0, 0);
    }





    else if ((s(0) == 0) && (s(3) == 1) && (s(4) == 1) && (s(5) == 1) && (s(6) == 1) && (s(7) == 1)) {      // Right detection
      junkDelay = millis();
      drive(130, 130);
      updateVal();
      while ((s(0) == 0) && (s(3) == 1) && (s(4) == 1) && (s(5) == 1) && (s(6) == 1) && (s(7) == 1)) {
        updateVal();
      }
      if (millis() - junkDelay > lineDelay) {
        right = 1;

        drive(150, 150);
        junkDelay = millis();
        straight = 1;
        while (millis() - junkDelay < goDelay) {
          updateVal();
          if ((s(3) == 0) && (s(4) == 0)) {
            straight = 0;
            break;
          }
        }
        drive(0, 0);
      }
    }





    else if (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {                                          // T detection
      junkDelay = millis();
      drive(130, 130);
      updateVal();
      while (((s(0) == 1) || (s(1) == 1)) && ((s(6) == 1) || (s(7) == 1))) {
        updateVal();
      }
      if (millis() - junkDelay > 40) {
        left = 1;
        right = 1;
        if (millis() - junkDelay > 200) {                                                                             // Back Detection
          back = 1;
          left = 0;
          right = 0;
        }
        drive(0, 0);
      }
    }


    if (error + left + right + straight + back != 0) {
      turn(left, right, straight, back, error);
    }
  }
}
