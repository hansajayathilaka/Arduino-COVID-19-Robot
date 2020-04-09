void atHome() {
  while (true) {
    // reseave code
    char temp = recieveData();
    if (temp != '_') {
      destination = temp;
      path_to_next_destination = createPath(currentPosition, destination) + "B";
      junctionIndex = 0;
    }
  }
}
