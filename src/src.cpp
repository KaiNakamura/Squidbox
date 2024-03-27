#include <Arduino.h>
#include "Squidbox.h"

Squidbox *squidbox;

void setup()
{
  // Enables Serial Communication with baudRate of 115200
  Serial.begin(115200);

  squidbox = new Squidbox();
  squidbox->init();
}

void loop()
{
  squidbox->update();
}
