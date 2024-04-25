#pragma once

#include "esp_sleep.h"
#include <Arduino.h>

/**
 * @class Button
 * @brief A class that represents a button.
 */
class Button {
private:
  int pin;      ///< The GPIO pin the button is connected to.
  bool wasDown; ///< true if the button was down at the last check.
  bool wasUp;   ///< true if the button was up at the last check.

public:
  /**
   * @brief Construct a new Button object.
   * @param pin The GPIO pin the button is connected to.
   */
  Button(int pin);

  /**
   * @brief Check if the button is currently down.
   * @return true if the button is down, false otherwise.
   */
  bool isDown();

  /**
   * @brief Check if the button was pressed since the last check.
   * @return true if the button was pressed, false otherwise.
   */
  bool isPressed();

  /**
   * @brief Check if the button was released since the last check.
   * @return true if the button was released, false otherwise.
   */
  bool isReleased();
};