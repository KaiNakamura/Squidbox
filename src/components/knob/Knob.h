#pragma once

#include <Arduino.h>
#include <ESP_Knob.h>

class Knob
{
private:
  int buttonPin;
  ESP_Knob *knob;

public:
  Knob(int aPin, int bPin, int buttonPin);

  /**
   * @brief Returns if the knob is pressed
   *
   * @return bool
   */
  bool isPressed();

  int getCount();

  void clearCount();
};