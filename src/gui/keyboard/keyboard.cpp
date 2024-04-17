#include "Keyboard.h"
#include "Squidbox.h"

Keyboard::Keyboard(Squidbox *squidbox)
{
  this->squidbox = squidbox;
}

void Keyboard::setKeys(Key* keys)
{
  this->keys = keys;
}

void Keyboard::printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys, Note rootNote)
{
    int whiteKeyPos = 2; // Initial position of the first white key
    int blackKeyPos = 8; // Initial position of the first black key
    Screen *screen = squidbox->getScreen();
    Adafruit_SSD1306* display = screen->getDisplay();
    Key keys[numKeys];

  // Create an array that keeps teh starting position of each key indexed by the key index and then fill in the keys after the piano is printed
   
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      // Iterate note to next note when index changes
      Note currNote = rootNote;
      for (int i = 0; i < keyIndex; i++) {
        currNote = getNextNote(currNote);
      }

      int rootIndex = keyIndex % 12;
      if (checkNoteColorWhite(currNote))
      {
        // Draw white key
        display->drawRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        whiteKeyPos = whiteKeyPos + whiteKeyWidth;
        keys[keyIndex] = Key(true, currNote, whiteKeyPos, keyboardLocation);
      }
    }

    // Draw black keys
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      Note currNote = rootNote;
      // for loop needs to be removed
      for (int i = 0; i < keyIndex; i++) {
        currNote = getNextNote(currNote);
      }

      int rootIndex = keyIndex % 12;
      if (checkNoteColorConsecutiveBlack(currNote))
      {
        display->fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + whiteKeyWidth;
      }
      else if (checkNoteColorGapBlack(currNote))
      {
        display->fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        blackKeyPos = blackKeyPos + 2*whiteKeyWidth;
      }
    }

    screen->update();
  }