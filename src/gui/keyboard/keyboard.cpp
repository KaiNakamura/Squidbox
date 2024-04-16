#include "Keyboard.h"
#include "Squidbox.h"

Keyboard::Keyboard(Squidbox *squidbox)
{
  this->squidbox = squidbox;
}

void Keyboard::printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys)
{
  int whiteKeyPos = 2; // Initial position of the first white key
    int blackKeyPos = 8; // Initial position of the first black key
    Adafruit_SSD1306* display = this->squidbox->getScreen()->getDisplay();

  // Create an array that keeps teh starting position of each key indexed by the key index and then fill in the keys after the piano is printed
   
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      int rootIndex = keyIndex % 12;
      if (rootIndex != 1 && rootIndex != 6 && rootIndex != 8 && rootIndex != 3 && rootIndex != 10)
      {
        // Draw white key
        display->drawRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        whiteKeyPos = whiteKeyPos + whiteKeyWidth;
      }
    }

    // Draw black keys
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      int rootIndex = keyIndex % 12;
      if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8)
      {
        (*display).fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + whiteKeyWidth;
      }
      else if (rootIndex == 3 || rootIndex == 10)
      {
        (*display).fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + 2*whiteKeyWidth;
      }
    }
  }