
#include "tests.h"

void before_blinkTest()
{
  pinMode(PIN_LED_INBUILT, OUTPUT);
}

void blink_test()
{
  for (int i = 0; i < 3; i++)
  {
    Serial.printf("Running the blink code on pin %d for %d\n", PIN_LED_INBUILT, i);
    digitalWrite(PIN_LED_INBUILT, HIGH);
    TEST_ASSERT_EQUAL(digitalRead(PIN_LED_INBUILT), HIGH);
    delay(1000);

    digitalWrite(PIN_LED_INBUILT, LOW);
    TEST_ASSERT_EQUAL(digitalRead(PIN_LED_INBUILT), LOW);
    delay(400);
  }
}
