#include "Screen.h"

Screen::Screen() : display(WIDTH, HEIGHT, &Wire, -1) {
  // Begin the display with the given parameters.
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  // Set the character set to Code Page 437 (which includes the ASCII
  // characters).
  display.cp437(true);
  // Clear the display.
  clear();
}

void Screen::clear() { display.clearDisplay(); }

void Screen::update() { display.display(); }

Adafruit_SSD1306 *Screen::getDisplay() { return &display; }