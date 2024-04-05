#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Screen
{
private:
  const int WHITE_KEY_WIDTH = 10; // 1/10 of the screen for 10 white keys
  const int WHITE_KEY_HEIGHT = 20; // 1/3 height of screen
  const int BLACK_KEY_WIDTH = 10; // 1/3 width of white keys
  const int BLACK_KEY_HEIGHT = 8; // 4/10 of height of white keys
  const int ST77XX_WHITE = 0xFFFF;
  const int ST77XX_BLACK = 0x0000;
  const int ST77XX_ORANGE = 0xFD20;
  const int WIDTH = 128;
  const int HEIGHT = 64;
  const int SCREEN_ADDRESS = 0x3C;
  Adafruit_SSD1306 display;

public:
  Screen();
  void clear();
  void update();
  Adafruit_SSD1306 *getDisplay();
  void printKeyboard(int rootNote, String chordType);

};