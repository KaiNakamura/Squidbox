#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

class Screen {
private:
  const static int SCREEN_ADDRESS = 0x3C;
  Adafruit_SSD1306 display;

public:
  const static int WIDTH = 128; // OLED display width, in pixels
  const static int HEIGHT = 64; // OLED display height, in pixels
  Screen();
  void clear();
  void update();
  Adafruit_SSD1306 *getDisplay();
};