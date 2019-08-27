#include <Adafruit_NeoPixel.h>

#define PLAYER1_RACKET_PIN 2
#define PLAYER2_RACKET_PIN 3
#define PLAYER1_FUNC_PIN 4
#define PLAYER2_FUNC_PIN 5
#define GAME_TRACK_PIN 6
#define PLAYER1_DISPLAY_PIN 7
#define SPEEKER_PIN 8
#define PLAYER2_DISPLAY_PIN 9
/* 
 * 14 5 4 | 14 5 4 |    5  | 14 5 4 | 14 5 4 | 14   4 | 14 5 4 | 14 5 4 | 14 5 4 | 14 5 4 | 14 5 4 |
 * 13 6 3 | 13   3 | 13 6  |      3 |      3 | 13   3 | 13     | 13     |      3 | 13   3 | 13   3 |
 * 12 7 2 | 12   2 |    7  | 12 7 2 | 12 7 2 | 12 7 2 | 12 7 2 | 12 7 2 |      2 | 12 7 2 | 12 7 2 | 
 * 11 8 1 | 11   1 |    8  | 11     |      1 |      1 |      1 | 11   1 |      1 | 11   1 |      1 |
 * 10 9 0 | 10 9 0 |    9  | 10 9 0 | 10 9 0 |      0 | 10 9 0 | 10 9 0 |      0 | 10 9 0 | 10 9 0 |
 *  
 *  
 *  
*/
const byte N0[12] = {0, 1, 2, 3, 4, 5,          9, 10, 11, 12, 13, 14};
const byte N1[6]  = {               5, 6, 7, 8, 9,             13    };
const byte N2[11] = {0,    2, 3, 4, 5,    7,    9, 10, 11, 12,     14};
const byte N3[11] = {0, 1, 2, 3, 4, 5,    7,    9, 10,     12,     14};
const byte N4[9]  = {0, 1, 2, 3, 4,       7,               12, 13, 14};
const byte N5[11] = {0, 1, 2,    4, 5,    7,    9, 10,     12, 13, 14};
const byte N6[12] = {0, 1, 2,    4, 5,    7,    9, 10, 11, 12, 13, 14};
const byte N7[7]  = {0, 1, 2, 3, 4, 5,                             14};
const byte N8[13] = {0, 1, 2, 3, 4, 5,    7,    9, 10, 11, 12, 13, 14};
const byte N9[12] = {0, 1, 2, 3, 4, 5,    7,    9, 10,     12, 13, 14};


Adafruit_NeoPixel track(40, GAME_TRACK_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_1(15, PLAYER1_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_2(15, PLAYER2_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
unsigned long last = 0, nowis = 0;
struct Ball {
  uint32_t   color;
  int8_t pos;
  int8_t dir;
  uint16_t speed;
};
Ball balls[3];
uint8_t activeBalls = 0;
uint8_t activePlayers = 0;
uint8_t scorePlayer1 = 0;
uint8_t scorePlayer2 = 0;
bool onePlays = false;
bool twoPlays = false;

uint32_t cols[3] = {0x00ff0000, 0x0000ff00, 0x000000ff};

void func1() { // Player one pressed their button
  tone(SPEEKER_PIN, 880, 100);
  uint8_t ab = 0;
  if (activePlayers == 0) {
    activePlayers = 1;
    onePlays = true;
    showScore1();
    disp2off();
    display_2.show();
    activeBalls = 1;
    balls[ab].color = cols[ab];
    balls[ab].dir = 1;
    balls[ab].pos = 0;
    balls[ab].speed = 0;
  } else if ((activeBalls) && (balls[0].speed == 0)) {
    if ((activePlayers == 1) && (balls[0].dir == 1)) {
      activeBalls = (activeBalls < 3) ? activeBalls + 1 : activeBalls;
      ab = activeBalls - 1;
      balls[ab].color = cols[ab];
      balls[ab].dir = 1;
      balls[ab].pos = 0;
      balls[ab].speed = 0;
    } else if ((activePlayers == 1) && (balls[0].dir == -1)) {
      onePlays = true;
      showScore1();
      activePlayers = 2;
    }
  }
}

void func2() { // Player two pressed their button
  tone(SPEEKER_PIN, 880, 100);
  uint8_t ab = 0;
  if (activePlayers == 0) {
    activePlayers = 1;
    activeBalls = 1;
    twoPlays = true;
    showScore2();
    disp1off();
    display_1.show();
    balls[ab].color = cols[ab];
    balls[ab].dir = -1;
    balls[ab].pos = 39;
    balls[ab].speed = 0;
  } else if ((activeBalls) && (balls[0].speed == 0)) {
    if ((activePlayers == 1) && (balls[0].dir == -1)) {
      activeBalls = (activeBalls < 3) ? activeBalls + 1 : activeBalls;
      ab = activeBalls - 1;
      balls[ab].color = cols[ab];
      balls[ab].dir = -1;
      balls[ab].pos = 39;
      balls[ab].speed = 0;
    } else if ((activePlayers == 1) && (balls[0].dir == 1)) {
      activePlayers = 2;
      twoPlays = true;
      showScore2();
    }
  }
}

uint8_t calls = 0;
void doballs() {
  calls++;
  calls %= 5;
  trackoff();  
  for (int i = 0; i < activeBalls; i++) {//separtate balls that have been glued together
    for (int j = i+1; j < activeBalls; j++) {
        if ((balls[i].pos!=39)&&(balls[i].pos!=0))
        if ((balls[i].pos==balls[j].pos)&&(balls[i].dir==balls[j].dir)&&(balls[i].speed==balls[j].speed))balls[j].pos++;
    }
  }
  for (int i = 0; i < activeBalls; i++) {
    /*
      Serial.print("Ball# "); Serial.print(i + 1);
      Serial.print(" pos=  "); Serial.print(balls[i].pos);
      Serial.print(" speed= "); Serial.print(balls[i].speed);
      Serial.print(" dir= "); Serial.println(balls[i].dir);
      // */
    if (balls[i].speed > calls) {
      balls[i].pos += balls[i].dir; //speed == 0 never moves, speed == 1 moves once in 5 calls, speed 5 or higher always moves
      //Serial.print(" Pos=  "); Serial.println(balls[i].pos);
      if (balls[i].pos < 0) player2scores(i);
      else if (balls[i].pos > 39) player1scores(i);
    }
    track.setPixelColor(balls[i].pos, track.getPixelColor(balls[i].pos) | balls[i].color); //mix colors if two are at same position
  }
  track.show();
}


void player2scores(int i) {
  if (onePlays) {
    noTone(SPEEKER_PIN);
    tone(SPEEKER_PIN, 500, 300);
    balls[i].color = cols[i];
    balls[i].dir = -1;
    balls[i].pos = 39;
    balls[i].speed = 0;
    if (!twoPlays) {
      balls[i].dir = 1;
      balls[i].pos = 0;
    }
    scorePlayer2++;
    if (scorePlayer2 > 9) p2wins();
    else if (twoPlays) showScore2(); else {scorePlayer1=scorePlayer2;showScore1();}
  } else { //reflect if no other player there
    balls[i].color = cols[i];
    balls[i].dir = 1;
    balls[i].pos = 0;
  }
}

void player1scores(int i) {
  if (twoPlays) {
    noTone(SPEEKER_PIN);
    tone(SPEEKER_PIN, 500, 300);
    balls[i].color = cols[i];
    balls[i].dir = 1;
    balls[i].pos = 0;
    if (!onePlays) {
      balls[i].dir = -1;
      balls[i].pos = 39;
    }
    balls[i].speed = 0;
    scorePlayer1++;
    if (scorePlayer1 > 9) p1wins();
    else if (onePlays) showScore1(); else {scorePlayer2=scorePlayer1;showScore2();}
  } else { //reflect if no other player there
    balls[i].color = cols[i];
    balls[i].dir = -1;
    balls[i].pos = 39;
  }
}

void p1() {
  //player 1 used his racket
  if (!onePlays) return; //you don't play go home!
  noTone(SPEEKER_PIN);
  bool ok = false;
  for (int i = 0; i < activeBalls; i++) {
    if (balls[i].dir == -1) {
      if (balls[i].pos < 6) {
        ok = true;
        balls[i].dir = 1;
        balls[i].speed = 6 - balls[i].pos;
      }
    } else if (balls[i].pos == 0) { //a new ball
      balls[i].speed = 1;
      ok = true;
      break;//only one at a time
    }
  }
  if (ok) tone(SPEEKER_PIN, 1760, 100);
  else {
    tone(SPEEKER_PIN, 500, 300);
    scorePlayer2++;
    if (scorePlayer2 > 9) p2wins();
    else if (twoPlays) showScore2(); else {scorePlayer1=scorePlayer2;showScore1();}
  }
}

void p2() {

  //player 2 used his racket
  if (!twoPlays) return; //you don't play go home!
  noTone(SPEEKER_PIN);
  bool ok = false;
  for (int i = 0; i < activeBalls; i++) {
    if (balls[i].dir == 1) {
      if (balls[i].pos > 34) {
        ok = true;
        balls[i].dir = -1;
        balls[i].speed = 6 - (39 - balls[i].pos);
      }
    } else if (balls[i].pos == 39) { //a new ball
      balls[i].speed = 1;
      ok = true;
      break;//only one at a time
    }
  }
  if (ok) tone(SPEEKER_PIN, 1480, 100);
  else {
    tone(SPEEKER_PIN, 500, 300);
    scorePlayer1++;
    if (scorePlayer1 > 9) p1wins();
    else if (onePlays) showScore1(); else {scorePlayer2=scorePlayer1;showScore2();}
  }
}

void showScore1() {

  disp1off();
  switch (scorePlayer1) {
    case 0:
      for (uint8_t i = 0; i < sizeof(N0); i++) {
        display_1.setPixelColor(N0[i], display_1.Color(255, 0, 0));
      }
      break;
    case 1:
      for (uint8_t i = 0; i < sizeof(N1); i++) {
        display_1.setPixelColor(N1[i], display_1.Color(255, 0, 0));
      }
      break;
    case 2:
      for (uint8_t i = 0; i < sizeof(N2); i++) {
        display_1.setPixelColor(N2[i], display_1.Color(255, 0, 0));
      }
      break;
    case 3:
      for (uint8_t i = 0; i < sizeof(N3); i++) {
        display_1.setPixelColor(N3[i], display_1.Color(255, 0, 0));
      }
      break;
    case 4:
      for (uint8_t i = 0; i < sizeof(N4); i++) {
        display_1.setPixelColor(N4[i], display_1.Color(255, 0, 0));
      }
      break;
    case 5:
      for (uint8_t i = 0; i < sizeof(N5); i++) {
        display_1.setPixelColor(N5[i], display_1.Color(255, 0, 0));
      }
      break;
    case 6:
      for (uint8_t i = 0; i < sizeof(N6); i++) {
        display_1.setPixelColor(N6[i], display_1.Color(255, 0, 0));
      }
      break;
    case 7:
      for (uint8_t i = 0; i < sizeof(N7); i++) {
        display_1.setPixelColor(N7[i], display_1.Color(255, 0, 0));
      }
      break;
    case 8:
      for (uint8_t i = 0; i < sizeof(N8); i++) {
        display_1.setPixelColor(N8[i], display_1.Color(255, 0, 0));
      }
      break;
    case 9:
      for (uint8_t i = 0; i < sizeof(N9); i++) {
        display_1.setPixelColor(N9[i], display_1.Color(255, 0, 0));
      }
      break;
  }

  display_1.show();
}

void showScore2() {

  disp2off();
  switch (scorePlayer2) {
    case 0:
      for (uint8_t i = 0; i < sizeof(N0); i++) {
        display_2.setPixelColor(N0[i], display_2.Color(0, 0, 255));
      }
      break;
    case 1:
      for (uint8_t i = 0; i < sizeof(N1); i++) {
        display_2.setPixelColor(N1[i], display_2.Color(0, 0, 255));
      }
      break;
    case 2:
      for (uint8_t i = 0; i < sizeof(N2); i++) {
        display_2.setPixelColor(N2[i], display_2.Color(0, 0, 255));
      }
      break;
    case 3:
      for (uint8_t i = 0; i < sizeof(N3); i++) {
        display_2.setPixelColor(N3[i], display_2.Color(0, 0, 255));
      }
      break;
    case 4:
      for (uint8_t i = 0; i < sizeof(N4); i++) {
        display_2.setPixelColor(N4[i], display_2.Color(0, 0, 255));
      }
      break;
    case 5:
      for (uint8_t i = 0; i < sizeof(N5); i++) {
        display_2.setPixelColor(N5[i], display_2.Color(0, 0, 255));
      }
      break;
    case 6:
      for (uint8_t i = 0; i < sizeof(N6); i++) {
        display_2.setPixelColor(N6[i], display_2.Color(0, 0, 255));
      }
      break;
    case 7:
      for (uint8_t i = 0; i < sizeof(N7); i++) {
        display_2.setPixelColor(N7[i], display_2.Color(0, 0, 255));
      }
      break;
    case 8:
      for (uint8_t i = 0; i < sizeof(N8); i++) {
        display_2.setPixelColor(N8[i], display_2.Color(0, 0, 255));
      }
      break;
    case 9:
      for (uint8_t i = 0; i < sizeof(N9); i++) {
        display_2.setPixelColor(N9[i], display_2.Color(0, 0, 255));
      }
      break;
  }

  display_2.show();
}


// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  if (wait > 0)
    for (int i = 0; i < track.numPixels(); i++) { // For each pixel in strip...
      track.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      track.show();                          //  Update strip to match
      delay(wait);                           //  Pause for a moment
    } else for (int i = track.numPixels() - 1; i > -1; i--) { // For each pixel in strip...
      track.setPixelColor(i, color);         //  Set pixel's color (in RAM)
      track.show();                          //  Update strip to match
      delay(-wait);                           //  Pause for a moment
    }
}

void p1wins() {
  onePlays = false;
  twoPlays = false;
  activePlayers = 0;
  activeBalls = 0;
  scorePlayer2 = 0;
  scorePlayer1 = 0;
  trackoff();
  colorWipe(0x00ff0000, 15);
  trackoff();
  colorWipe(0x00ff0000, 15);
  trackoff();
  track.show();
  showScore1();
  showScore2();
}

void p2wins() {
  onePlays = false;
  twoPlays = false;
  activePlayers = 0;
  activeBalls = 0;
  scorePlayer2 = 0;
  scorePlayer1 = 0;
  trackoff();
  colorWipe(0x000000ff, -15);
  trackoff();
  colorWipe(0x000000ff, -5);
  trackoff();
  track.show();
  showScore1();
  showScore2();

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  track.begin();
  track.show();
  track.setBrightness(64);
  display_1.begin();
  display_1.show();
  display_1.setBrightness(64);
  display_2.begin();
  display_2.show();
  display_2.setBrightness(64);
  pinMode(PLAYER1_RACKET_PIN, INPUT_PULLUP);
  pinMode(PLAYER2_RACKET_PIN, INPUT_PULLUP);
  pinMode(PLAYER1_FUNC_PIN, INPUT_PULLUP);
  pinMode(PLAYER2_FUNC_PIN, INPUT_PULLUP);
  tone(SPEEKER_PIN, 1760, 150);
  delay(250);
  tone(SPEEKER_PIN, 1047, 150);
  attachInterrupt(digitalPinToInterrupt(PLAYER1_RACKET_PIN), p1, FALLING);
  attachInterrupt(digitalPinToInterrupt(PLAYER2_RACKET_PIN), p2, FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  static int F1 = HIGH, F2 = HIGH;
  int f1 = digitalRead(PLAYER1_FUNC_PIN);
  int f2 = digitalRead(PLAYER2_FUNC_PIN);
  if ((f1 == LOW) && (F1 == HIGH)) func1();
  if ((f2 == LOW) && (F2 == HIGH)) func2();
  unsigned long nowis = millis();
  static unsigned long nextTime = 0ul;
  if ((nowis - nextTime) > 40ul) {
    doballs();
    nextTime = nowis;
  }
  F1 = f1;
  F2 = f2;
}


const uint32_t black = 0;

void trackoff() {
  for (int m = 0; m < track.numPixels(); m++) {
    track.setPixelColor(m, black);
  }
}

void disp1off() {
  for (int m = 0; m < display_1.numPixels(); m++) {
    display_1.setPixelColor(m, black);;
  }
}

void disp2off() {
  for (int m = 0; m < display_2.numPixels(); m++) {
    display_2.setPixelColor(m, black);
  }
}
