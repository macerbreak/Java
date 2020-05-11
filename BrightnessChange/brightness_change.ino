#include "Arduino.h"
#include "TimerThree-1.1.0/TimerThree.h"

const int PIN_LED_1 = 5;
const int PIN_LED_2 = 6;
const int PIN_LED_3 = 9;
const int POTENTIOMETER = A0;
const double pi = 3.14;

double k;
double t;

void setup() {
    pinMode(PIN_LED_1, OUTPUT);
    pinMode(PIN_LED_2, OUTPUT);
    pinMode(PIN_LED_3, OUTPUT);
    pinMode(POTENTIOMETER, INPUT);
    Timer3.initialize(16000);
    Timer3.attachInterrupt(func);
}

void func() {
    t = double(millis()) / double(1000);
    k = analogRead(POTENTIOMETER) / double(100);
    analogWrite(PIN_LED_1, 255 * (sin(k * t) + 1) / 2);
    analogWrite(PIN_LED_2, 255 * (sin(k * t + 2 * pi / 3) + 1) / 2);
    analogWrite(PIN_LED_3, 255 * (sin(k * t + 4 * pi / 3) + 1) / 2);
}


void loop() {
}