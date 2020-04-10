String pathsForRooms[] = {
  "L",
  "SR",
  "SSL",
  "SSSR",
  "SSSSL",
};

String pathsFromRooms[] = {
  "R",
  "LS",
  "RSS",
  "LSSS",
  "RSSSS",
};

char currentPosition = '0';
char destination;

// Moters
#define rf 4
#define rb 3
#define lf 5
#define lb 6

// Sonar
#define trigPin 51
#define echoPin 49

long junkDelay;
