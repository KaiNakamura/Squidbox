#include "tests.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("Test begin");

  UNITY_BEGIN();

  // Testing LED indicators --------------------------------------------------
  before_blinkTest();
  RUN_TEST(blink_test);
  delay(1000);

  UNITY_END();
}

void loop()
{
}
