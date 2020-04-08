String createPath(char Start, char End) {
  String fullPath;
  switch (Start) {
    case '1':
      fullPath = pathsFromRooms[0];
      break;
    case '2':
      fullPath = pathsFromRooms[1];
      break;
    case '3':
      fullPath = pathsFromRooms[2];
      break;
    case '4':
      fullPath = pathsFromRooms[3];
      break;
    case '5':
      fullPath = pathsFromRooms[4];
      break;
    case '6':
      fullPath = pathsFromRooms[5];
      break;
  }

  fullPath += "B";

  switch (End) {
    case '1':
      fullPath += pathsForRooms[0];
      break;
    case '2':
      fullPath += pathsForRooms[1];
      break;
    case '3':
      fullPath += pathsForRooms[2];
      break;
    case '4':
      fullPath += pathsForRooms[3];
      break;
    case '5':
      fullPath += pathsForRooms[4];
      break;
    case '6':
      fullPath += pathsForRooms[5];
      break;
  }
  Serial.println(fullPath);
  String shortPath = calShortPath(fullPath);
  Serial.println(shortPath);
  return shortPath;
}

String calShortPath(String path) {
  bool backFound = true;
  String tempPath = "";

  while (backFound) {
    int i = 0;
    int count = path.length();
    while (i < count) {
      if ((path[i] == 'R') && (path[i + 1] == 'B') && (path[i + 2] == 'R')) {               //RBR = S
        tempPath += 'S';
        i = i + 2;
      }
      else if ((path[i] == 'R') && (path[i + 1] == 'B') && (path[i + 2] == 'S')) {          //RBS = L
        tempPath += 'L';
        i = i + 2;
      }
      else if ((path[i] == 'R') && (path[i + 1] == 'B') && (path[i + 2] == 'L')) {          //RBL = B
        tempPath += 'B';
        i = i + 2;
      }
      else if ((path[i] == 'S') && (path[i + 1] == 'B') && (path[i + 2] == 'R')) {          //SBR = L
        tempPath += 'L';
        i = i + 2;
      }
      else if ((path[i] == 'S') && (path[i + 1] == 'B') && (path[i + 2] == 'S')) {          //SBS = B
        tempPath += 'B';
        i = i + 2;
      }
      else if ((path[i] == 'S') && (path[i + 1] == 'B') && (path[i + 2] == 'L')) {          //SBL = R
        tempPath += 'R';
        i = i + 2;
      }
      else if ((path[i] == 'L') && (path[i + 1] == 'B') && (path[i + 2] == 'R')) {          //LBR = B
        tempPath += 'B';
        i = i + 2;
      }
      else if ((path[i] == 'L') && (path[i + 1] == 'B') && (path[i + 2] == 'S')) {          //LBS = R
        tempPath += 'R';
        i = i + 2;
      }
      else if ((path[i] == 'L') && (path[i + 1] == 'B') && (path[i + 2] == 'L')) {          //LBL = S
        tempPath += 'S';
        i = i + 2;
      }
      else {
        tempPath += path[i];
      }
      i++;
    }

    path = tempPath;
    tempPath = "";
    Serial.println(path);

    if (path.indexOf('B') == -1) {
      backFound = false;
    }
  }
  return path;
}
