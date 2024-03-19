#include <Arduino.h>
#include "define.h"

// This is to hide non-test related source code.
// https://docs.platformio.org/en/latest/plus/unit-testing.html
#ifndef UNIT_TEST

void setup()
{
  // Enables Serial Communication with baudRate of 115200
  Serial.begin(115200);
  Serial.println("Initializing Squidbox");

  pinMode(PIN_LED_BUILT_IN, OUTPUT);
}

void loop()
{
  digitalWrite(PIN_LED_BUILT_IN, HIGH);
  Serial.println("HIGH");
  delay(1000);
  digitalWrite(PIN_LED_BUILT_IN, LOW);
  Serial.println("LOW");
  delay(1000);
}

#endif
