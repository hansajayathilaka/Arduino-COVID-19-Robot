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
#define lf 4
#define lb 5
#define rf 6
#define rb 7
#define rPWM 9
#define lPWM 10

// Sonar
#define trigPin 51
#define echoPin 49

long junkDelay;
