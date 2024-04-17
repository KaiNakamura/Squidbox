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

const char *directionToString(Direction direction);

class Joystick
{
private:
  const float JOYSTICK_DEADZONE = 0.5;
  const int X_CENTER = 1848;
  const int Y_CENTER = 1868;
  const int X_MIN = 0;
  const int Y_MIN = 0;
  const int X_MAX = 4095;
  const int Y_MAX = 4095;
  int xPin;
  int yPin;
  int buttonPin;
  bool wasLeft, wasRight, wasUp, wasDown;
  static float map(float x, float inMin, float inMax, float outMin, float outMax);
  static float convertRawValue(int raw, int center, int min, int max);

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

  /**
   * @brief Returns if left was just inputted on the joystick
   *
   * @return true if left was just inputted
   * @return false if left was not just inputted
   */
  bool wasLeftJustInputted();

  /**
   * @brief Returns if right was just inputted on the joystick
   *
   * @return true if right was just inputted
   * @return false if right was not just inputted
   */
  bool wasRightJustInputted();

  /**
   * @brief Returns if up was just inputted on the joystick
   *
   * @return true if up was just inputted
   * @return false if up was not just inputted
   */
  bool wasUpJustInputted();

  /**
   * @brief Returns if down was just inputted on the joystick
   *
   * @return true if down was just inputted
   * @return false if down was not just inputted
   */
  bool wasDownJustInputted();
};