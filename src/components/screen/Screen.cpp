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
      int rootIndex = keyIndex % 12;
      if (rootIndex != 1 && rootIndex != 6 && rootIndex != 8 && rootIndex != 13 && rootIndex != 15 && rootIndex != 3 && rootIndex != 10)
      {
        // Draw white key
        display.drawRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        whiteKeyPos = whiteKeyPos + whiteKeyWidth;
      }
    }

    // Draw black keys
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      int rootIndex = keyIndex % 12;
      if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8 || rootIndex == 13 || rootIndex == 15)
      {
        display.fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display.drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + whiteKeyWidth;
      }
      else if (rootIndex == 3 || rootIndex == 10)
      {
        display.fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display.drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + 2*whiteKeyWidth;
      }
    }
  }