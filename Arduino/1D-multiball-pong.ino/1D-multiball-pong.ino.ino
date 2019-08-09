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
const byte N3[11] = {0, 1, 2, 3, 4, 5, 7, 9, 10, 12, 14};
const byte N4[9] = {0, 1, 2, 3, 4,7,12,13,14};
const byte N5[11] = {0, 9, 10, 1, 2, 7, 12, 13, 4, 5, 14};
const byte N6[12] = {0, 1, 2, 4, 5, 7, 9, 10, 11, 12, 13, 14};
const byte N7[7] = {0, 1, 2, 3, 4, 5, 14};
const byte N8[13] = {0, 9, 10, 1, 11, 2, 7, 12, 3, 13, 4, 5, 14};
const byte N9[12] = {0, 9, 10, 3, 1, 2, 7, 12, 13, 4, 5, 14};


Adafruit_NeoPixel track(40, GAME_TRACK_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_1(15, PLAYER1_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel display_2(15, PLAYER2_DISPLAY_PIN, NEO_GRB + NEO_KHZ800);
unsigned long last=0,nowis=0;
volatile int ball=0;
void p1() {
  //player 1 used his racket
  noTone(SPEEKER_PIN); 
  ball++;
  ball%=10;
  if (ball)  tone(SPEEKER_PIN, 1760, 100);  
  else tone(SPEEKER_PIN, 1480, 100);
  showScore1(ball);
}

void p2() {
  //player 2 used his racket
  noTone(SPEEKER_PIN); 
  ball++;
  ball%=10;
  tone(SPEEKER_PIN, 1480, 100);
  showScore2(ball);

}

void showScore1(int score){
  
  Serial.println(ball);
  disp1off();
  switch (score) {
    case 0: 
    for (uint8_t i=0; i<sizeof(N0); i++){
      display_1.setPixelColor(N0[i],display_1.Color(255,0,0));
      }
    break;
    case 1:  
    for (uint8_t i=0; i<sizeof(N1); i++){
      display_1.setPixelColor(N1[i],display_1.Color(255,0,0));
      }
    break;
    case 2:  
    for (uint8_t i=0; i<sizeof(N2); i++){
      display_1.setPixelColor(N2[i],display_1.Color(255,0,0));
      }
    break;
    case 3:  
    for (uint8_t i=0; i<sizeof(N3); i++){
      display_1.setPixelColor(N3[i],display_1.Color(255,0,0));
      }
    break;
    case 4:  
    for (uint8_t i=0; i<sizeof(N4); i++){
      display_1.setPixelColor(N4[i],display_1.Color(255,0,0));
      }
    break;
    case 5:  
    for (uint8_t i=0; i<sizeof(N5); i++){
      display_1.setPixelColor(N5[i],display_1.Color(255,0,0));
      }
    break;
    case 6:  
    for (uint8_t i=0; i<sizeof(N6); i++){
      display_1.setPixelColor(N6[i],display_1.Color(255,0,0));
      }
    break;
    case 7:  
    for (uint8_t i=0; i<sizeof(N7); i++){
      display_1.setPixelColor(N7[i],display_1.Color(255,0,0));
      }
    break;
    case 8:  
    for (uint8_t i=0; i<sizeof(N8); i++){
      display_1.setPixelColor(N8[i],display_1.Color(255,0,0));
      }
    break;
    case 9:  
    for (uint8_t i=0; i<sizeof(N9); i++){
      display_1.setPixelColor(N9[i],display_1.Color(255,0,0));
      }
    break;
    } 
  
  display_1.show();
  }

void showScore2(int score){
  
  Serial.println(ball);
  disp2off();
  switch (score) {
    case 0: 
    for (uint8_t i=0; i<sizeof(N0); i++){
      display_2.setPixelColor(N0[i],display_2.Color(0,0,255));
      }
    break;
    case 1:  
    for (uint8_t i=0; i<sizeof(N1); i++){
      display_2.setPixelColor(N1[i],display_2.Color(0,0,255));
      }
    break;
    case 2:  
    for (uint8_t i=0; i<sizeof(N2); i++){
      display_2.setPixelColor(N2[i],display_2.Color(0,0,255));
      }
    break;
    case 3:  
    for (uint8_t i=0; i<sizeof(N3); i++){
      display_2.setPixelColor(N3[i],display_2.Color(0,0,255));
      }
    break;
    case 4:  
    for (uint8_t i=0; i<sizeof(N4); i++){
      display_2.setPixelColor(N4[i],display_2.Color(0,0,255));
      }
    break;
    case 5:  
    for (uint8_t i=0; i<sizeof(N5); i++){
      display_2.setPixelColor(N5[i],display_2.Color(0,0,255));
      }
    break;
    case 6:  
    for (uint8_t i=0; i<sizeof(N6); i++){
      display_2.setPixelColor(N6[i],display_2.Color(0,0,255));
      }
    break;
    case 7:  
    for (uint8_t i=0; i<sizeof(N7); i++){
      display_2.setPixelColor(N7[i],display_2.Color(0,0,255));
      }
    break;
    case 8:  
    for (uint8_t i=0; i<sizeof(N8); i++){
      display_2.setPixelColor(N8[i],display_2.Color(0,0,255));
      }
    break;
    case 9:  
    for (uint8_t i=0; i<sizeof(N9); i++){
      display_2.setPixelColor(N9[i],display_2.Color(0,0,255));
      }
    break;
    } 
  
  display_2.show();
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
  attachInterrupt(digitalPinToInterrupt(PLAYER1_RACKET_PIN), p1, FALLING);
  attachInterrupt(digitalPinToInterrupt(PLAYER2_RACKET_PIN), p2, FALLING);
  tone(SPEEKER_PIN, 1760, 150);
  delay(250);
  tone(SPEEKER_PIN, 1047, 150);
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
