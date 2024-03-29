#pragma once

#include <Arduino.h>

class Button
{
private:
  int pin;
  bool wasPressed;

public:
  Button(int pin);
  bool isPressed();
  bool getWasPressed();
  void setWasPressed(bool wasPressed);
};