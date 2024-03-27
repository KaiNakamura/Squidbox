#pragma once

#include <Arduino.h>

enum Direction
{
  NONE,
  UP,
  RIGHT,
  DOWN,
  LEFT,
};

class Joystick
{
private:
  const float JOYSTICK_DEADZONE = 0.1;
  const int X_CENTER = 2863;
  const int Y_CENTER = 2832;
  int xPin;
  int yPin;
  int buttonPin;
  static float map(float x, float inMin, float inMax, float outMin, float outMax);
  static float convertRawValue(int raw, int center);

public:
  Joystick(int xPin, int yPin, int buttonPin);

  /**
   * @brief Gets the raw x value between 0 and 1023
   *
   * @return int
   */
  int getRawX();

  /**
   * @brief Gets the raw y value between 0 and 1023
   *
   * @return int
   */
  int getRawY();

  /**
   * @brief Gets the x value between -1 and 1
   *
   * @return float
   */
  float getX();

  /**
   * @brief Gets the y value between -1 and 1
   *
   * @return float
   */
  float getY();

  /**
   * @brief Returns if the joystick is pressed
   *
   * @return bool
   */
  bool isPressed();

  /**
   * @brief Returns the direction that the joystick is facing
   *
   * @return Direction
   */
  Direction getDirection();
};