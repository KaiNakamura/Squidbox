#pragma once

#include <Arduino.h>

const float JOYSTICK_DEADZONE = 0.025;

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
  int xPin;
  int yPin;
  int switchPin;
  static float convertRawValue(int raw);

public:
  Joystick(int xPin, int yPin, int switchPin);

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
   * @brief Returns 1 if the joystick is pressed, otherwise 0
   *
   * @return int
   */
  int isPressed();

  /**
   * @brief Returns the direction that the joystick is facing
   *
   * @return Direction
   */
  Direction getDirection();
};