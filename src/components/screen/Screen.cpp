#include "Screen.h"

Screen::Screen() : display(WIDTH, HEIGHT, &Wire, -1)
{
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.cp437(true);
  clear();
}

void Screen::clear()
{
  display.clearDisplay();
}

void Screen::update()
{
  display.display();
}

Adafruit_SSD1306 *Screen::getDisplay()
{
  return &display;
}

void Screen::printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys)
{
  int whiteKeyPos = 2; // Initial position of the first white key
  int blackKeyPos = 8; // Initial position of the first black key

 
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      if (keyIndex != 1 && keyIndex != 6 && keyIndex != 8 && keyIndex != 13 && keyIndex != 15 && keyIndex != 3 && keyIndex != 10)
      {
        // Draw white key
        display.drawRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        whiteKeyPos = whiteKeyPos + whiteKeyWidth;
      }
    }
    // Draw black keys filled black
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      if (keyIndex == 1 || keyIndex == 6 || keyIndex == 8 || keyIndex == 13 || keyIndex == 15)
      {
        display.fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display.drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + whiteKeyWidth + 1;
      }
      else if (keyIndex == 3 || keyIndex == 10)
      {
        display.fillRect(blackKeyPos, keyboardLocation, whiteKeyWidth, blackKeyHeight, BLACK);
        display.drawRect(blackKeyPos, keyboardLocation, whiteKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + 2*whiteKeyWidth + 2*1;
      }
    }
  }