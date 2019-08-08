#include <Adafruit_NeoPixel.h>

#define PLAYER1_RACKET_PIN 2
#define PLAYER2_RACKET_PIN 3
#define PLAYER1_FUNC_PIN 4
#define PLAYER2_FUNC_PIN 5
#define GAME_TRACK_PIN 6
#define PLAYER1_DISPLAY_PIN 7
#define SPEEKER_PIN 8
#define PLAYER2_DISPLAY_PIN 9

const byte N0[12] = {0, 9, 10, 1, 11, 2, 12, 3, 13, 4, 5, 14};
const byte N1[6] =  {5, 6, 7, 8, 9, 13};
const byte N2[11] = {0, 9, 10, 11, 2, 7, 12, 3, 4, 5, 14};
const byte N3[11] = {0, 9, 10, 11, 2, 7, 12, 13, 4, 5, 14};
const byte N4[9] = {0, 10, 1, 11, 2, 7, 12, 13, 14};
const byte N5[11] = {0, 9, 10, 1, 2, 7, 12, 13, 4, 5, 14};
const byte N6[12] = {0, 1, 2, 4, 5, 7, 9, 10, 11, 12, 13, 14};
const byte N7[7] = {0, 1, 2, 3, 4, 5, 14};
const byte N8[13] = {0, 9, 10, 1, 11, 2, 7, 12, 3, 13, 4, 5, 14};
const byte N9[12] = {0, 9, 10, 1, 11, 2, 7, 12, 13, 4, 5, 14};


Adafruit_NeoPixel track(40, GAME_TRACK_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_1(15, PLAYER1_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_2(15, PLAYER2_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
void p1() {
  //player 1 used his racket
}

void p2() {
  //player 2 used his recket
}
void setup() {
  // put your setup code here, to run once:
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
  attachInterrupt(digitalPinToInterrupt(PLAYER1_RACKET_PIN), p1, FALLING);
  attachInterrupt(digitalPinToInterrupt(PLAYER2_RACKET_PIN), p2, FALLING);
  tone(SPEEKER_PIN, 1760, 150);
  delay(250);
  tone(SPEEKER_PIN, 880, 150);
}

void loop() {
  // put your main code here, to run repeatedly:

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
