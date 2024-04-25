#pragma once

#include <Arduino.h>

/**
 * @enum Direction
 * @brief Enum for joystick directions.
 */
enum Direction {
  NONE,  ///< No direction.
  UP,    ///< Up direction.
  RIGHT, ///< Right direction.
  DOWN,  ///< Down direction.
  LEFT,  ///< Left direction.
};

/**
 * @brief Convert direction to string.
 * @param direction The direction to convert.
 * @return The string representation of the direction.
 */
const char *directionToString(Direction direction);

/**
 * @class Joystick
 * @brief A class that represents a 2-axis joystick.
 */
class Joystick {
private:
  const float JOYSTICK_DEADZONE = 0.5;    ///< Deadzone for the joystick.
  const int X_CENTER = 1848;              ///< Center X value for the joystick.
  const int Y_CENTER = 1868;              ///< Center Y value for the joystick.
  const int X_MIN = 0;                    ///< Minimum X value for the joystick.
  const int Y_MIN = 0;                    ///< Minimum Y value for the joystick.
  const int X_MAX = 4095;                 ///< Maximum X value for the joystick.
  const int Y_MAX = 4095;                 ///< Maximum Y value for the joystick.
  int xPin;                               ///< X pin for the joystick.
  int yPin;                               ///< Y pin for the joystick.
  int buttonPin;                          ///< Button pin for the joystick.
  bool wasLeft, wasRight, wasUp, wasDown; ///< Previous direction states.

  /**
   * @brief Map function for joystick values.
   * @details This function maps a value from one range to another. It is used
   * to convert the raw joystick values to a more usable range.
   * @param x The value to map.
   * @param inMin The lower bound of the value's current range.
   * @param inMax The upper bound of the value's current range.
   * @param outMin The lower bound of the value's target range.
   * @param outMax The upper bound of the value's target range.
   * @return The mapped value.
   */
  static float map(float x, float inMin, float inMax, float outMin,
                   float outMax);

  /**
   * @brief Convert raw joystick values.
   * @details This function converts the raw joystick values to a more usable
   * range. It uses the map function to do this.
   * @param raw The raw joystick value to convert.
   * @param center The center value of the joystick.
   * @param min The minimum value of the joystick.
   * @param max The maximum value of the joystick.
   * @return The converted joystick value.
   */
  static float convertRawValue(int raw, int center, int min, int max);

public:
  /**
   * @brief Constructs a new Joystick object.
   * @param xPin The X pin for the joystick.
   * @param yPin The Y pin for the joystick.
   * @param buttonPin The button pin for the joystick.
   */
  Joystick(int xPin, int yPin, int buttonPin);

  /**
   * @brief Gets the raw x value between 0 and 1023.
   * @return The raw x value.
   */
  int getRawX();

  /**
   * @brief Gets the raw y value between 0 and 1023.
   * @return The raw y value.
   */
  int getRawY();

  /**
   * @brief Gets the x value between -1 and 1.
   * @return The x value.
   */
  float getX();

  /**
   * @brief Gets the y value between -1 and 1.
   * @return The y value.
   */
  float getY();

  /**
   * @brief Checks if the joystick is pressed.
   * @return True if the joystick is pressed, false otherwise.
   */
  bool isPressed();

  /**
   * @brief Gets the direction that the joystick is facing.
   * @return The direction of the joystick.
   */
  Direction getDirection();

  /**
   * @brief Checks if left was just inputted on the joystick.
   * @return True if left was just inputted, false otherwise.
   */
  bool wasLeftJustInputted();

  /**
   * @brief Checks if right was just inputted on the joystick.
   * @return True if right was just inputted, false otherwise.
   */
  bool wasRightJustInputted();

  /**
   * @brief Checks if up was just inputted on the joystick.
   * @return True if up was just inputted, false otherwise.
   */
  bool wasUpJustInputted();

  /**
   * @brief Checks if down was just inputted on the joystick.
   * @return True if down was just inputted, false otherwise.
   */
  bool wasDownJustInputted();
};
