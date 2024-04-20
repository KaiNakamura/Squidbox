#pragma once

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

class Screen {
private:
  const int WIDTH = 128; // OLED display width, in pixels
  const int HEIGHT = 64; // OLED display height, in pixels
  const int SCREEN_ADDRESS = 0x3C;
  Adafruit_SSD1306 display;

public:
  Screen();
  void clear();
  void update();
  Adafruit_SSD1306 *getDisplay();
  void printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys);

};