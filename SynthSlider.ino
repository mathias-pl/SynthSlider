//www.elegoo.com
//2016.12.08
#include "SR04.h"
#include "pitches.h"

#define BUTTON_PIN 2
#define SPEAKER_PIN 4
#define ECHO_PIN 11
#define TRIG_PIN 12

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long distance;

int melody[] = {
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  pinMode(SPEAKER_PIN, OUTPUT);//initialize the buzzer pin as an output

  Serial.begin(9600);
  delay(1000);
}

void play_sound() {
  tone(8, melody[distance], 100);
}

void loop() {
   distance = sr04.Distance() - 1;

   if (digitalRead(BUTTON_PIN) == LOW) {
    play_sound();
   }
}
