#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Screen
{
private:
  const int WIDTH = 128;
  const int HEIGHT = 64;
  const int SCREEN_ADDRESS = 0x3C;
  Adafruit_SSD1306 display;

public:
  Screen();
  void clear();
  void update();
  Adafruit_SSD1306 *getDisplay();
};