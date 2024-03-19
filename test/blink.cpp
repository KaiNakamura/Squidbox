
#include "tests.h"

void before_blinkTest()
{
  pinMode(PIN_LED_BUILT_IN, OUTPUT);
}

void blink_test()
{
  for (int i = 0; i < 3; i++)
  {
    Serial.printf("Running the blink code on pin %d for %d\n", PIN_LED_BUILT_IN, i);
    digitalWrite(PIN_LED_BUILT_IN, HIGH);
    TEST_ASSERT_EQUAL(digitalRead(PIN_LED_BUILT_IN), HIGH);
    delay(1000);

    digitalWrite(PIN_LED_BUILT_IN, LOW);
    TEST_ASSERT_EQUAL(digitalRead(PIN_LED_BUILT_IN), LOW);
    delay(400);
  }
}
