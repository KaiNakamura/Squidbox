#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Screen
{
private:
  const int STARTING_KEY_Y = 40;

  const int WHITE_KEY_WIDTH = 8; 
  const int WHITE_KEY_HEIGHT = 20;

  const int BLACK_KEY_WIDTH = 5; 
  const int BLACK_KEY_HEIGHT = 12; 
  
  const int ST77XX_WHITE = 0xFFFF;
  const int ST77XX_BLACK = 0x0000;
  const int ST77XX_ORANGE = 0xFD20;
  const int WIDTH = 128; // OLED display width, in pixels
  const int HEIGHT = 64; // OLED display height, in pixels
  const int SCREEN_ADDRESS = 0x3C;
  Adafruit_SSD1306 display;

public:
  Screen();
  void clear();
  void update();
  Adafruit_SSD1306 *getDisplay();
  void printKeyboard(int rootNote, String chordType);

};