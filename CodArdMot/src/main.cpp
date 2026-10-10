#include <Arduino.h>

#define POUT 5

const unsigned long dt = 15;

unsigned long t0 = 0;
unsigned long t1 = 0;
bool state = false;

void setup() {
  pinMode(POUT, OUTPUT);
  digitalWrite(POUT, LOW);
  t0 = millis();
}

void loop() {
  t1 = millis();

  if ((t1 - t0) >= dt) {
    state = !state;
    digitalWrite(POUT, state ? HIGH : LOW);
    t0 = t1;
  }
}
