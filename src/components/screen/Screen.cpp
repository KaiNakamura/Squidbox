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

void Screen::printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight)
{
  int whiteKeyPos = 2; // Initial position of the first white key
  int blackKeyPos = 8; // Initial position of the first black key

 
    for (int keyIndex = 0; keyIndex < 17; keyIndex++)
    {
      if (keyIndex != 1 && keyIndex != 6 && keyIndex != 8 && keyIndex != 13 && keyIndex != 15 && keyIndex != 3 && keyIndex != 10)
      {
        // Draw white key
        display.drawRect(whiteKeyPos, STARTING_KEY_Y, WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, WHITE);
        whiteKeyPos = whiteKeyPos + WHITE_KEY_WIDTH + 1;
      }
    }
    // Draw black keys filled black
    for (int keyIndex = 0; keyIndex < 17; keyIndex++)
    {
      if (keyIndex == 1 || keyIndex == 6 || keyIndex == 8 || keyIndex == 13 || keyIndex == 15)
      {
        display.fillRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, BLACK);
        blackKeyPos = blackKeyPos + WHITE_KEY_WIDTH + 1;
      }
      else if (keyIndex == 3 || keyIndex == 10)
      {
        display.fillRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, BLACK);
        blackKeyPos = blackKeyPos + 2*WHITE_KEY_WIDTH + 2*1;
      }
    }
    
    // Draw black keys outline
    blackKeyPos = 8; // Resset to initial position of the first black key
    for (int keyIndex = 0; keyIndex < 17; keyIndex++)
    {
      int note = keyIndex;

      if (keyIndex == 1 || keyIndex == 6 || keyIndex == 8 || keyIndex == 13 || keyIndex == 15)
      {
        display.drawRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
        blackKeyPos = blackKeyPos + WHITE_KEY_WIDTH + 1;
      }
      else if (keyIndex == 3 || keyIndex == 10)
      {
        display.drawRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
        blackKeyPos = blackKeyPos + 2*WHITE_KEY_WIDTH + 2*1;
      }
    }


  }