#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

/**
 * @class Screen
 * @brief A class that represents a screen.
 */
class Screen {
private:
  const static int SCREEN_ADDRESS = 0x3C; ///< The I2C address of the screen.
  Adafruit_SSD1306 display;               ///< The display object.

public:
  const static int WIDTH = 128; ///< OLED display width, in pixels.
  const static int HEIGHT = 64; ///< OLED display height, in pixels.

  /**
   * @brief Construct a new Screen object.
   */
  Screen();

  /**
   * @brief Clear the screen.
   */
  void clear();

  /**
   * @brief Update the screen.
   */
  void update();

  /**
   * @brief Get the display object.
   * @return A pointer to the display object.
   */
  Adafruit_SSD1306 *getDisplay();
};