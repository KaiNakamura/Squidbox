#pragma once

#include <Arduino.h>

class Button
{
private:
  int pin;
  bool wasDown;
  bool wasUp;

public:
  Button(int pin);
  bool isDown();
  bool isPressed();
  bool isReleased();
};