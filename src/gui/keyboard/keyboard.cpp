#include "Keyboard.h"
#include "Squidbox.h"

Keyboard::Keyboard(Squidbox *squidbox)
{
  this->squidbox = squidbox;
}


void Keyboard::drawKey(Note note, Key keys[], int numKeys)
{
  Screen *screen = squidbox->getScreen();
  Adafruit_SSD1306* display = screen->getDisplay();
  for (int i = 0; i < numKeys; i++)
  {
    Serial.println(keys[i].getNote()); 
    if (keys[i].getNote() == note)
    {
      if (keys[i].getIsWhite())
      {
        //display->fillRect(keys[i].getX(), keys[i].getY(), WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, WHITE);
      }
      else
      {
        display->fillRect(keys[i].getX(), keys[i].getY(), BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
      }
    }
  }
  
}


void Keyboard::printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys, Note rootNote, Note chordNotes[])
{
    int whiteKeyPos = 2; // Initial position of the first white key
    int blackKeyPos = 8; // Initial position of the first black key
    Screen *screen = squidbox->getScreen();
    Adafruit_SSD1306* display = screen->getDisplay();
    Key keys[numKeys];

  // Create an array that keeps the starting position of each key indexed by the key index and then fill in the keys after the piano is printed
   
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      // Iterate note to next note when index changes
      Note currNote = rootNote;
      for (int i = 0; i < keyIndex; i++) {
        currNote = getNextNote(currNote);
      }

       // Draw white keys
      int rootIndex = currNote % 12;
      if (rootIndex != 1 && rootIndex != 6 && rootIndex != 8 && rootIndex != 3 && rootIndex != 10) 
      {
        if (currNote == chordNotes[0] || currNote == chordNotes[1] || currNote == chordNotes[2]) {
          display->fillRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        }
        else {
          display->drawRect(whiteKeyPos, keyboardLocation, whiteKeyWidth, whiteKeyHeight, WHITE);
        }
        keys[keyIndex] = Key(true, currNote, whiteKeyPos, keyboardLocation);
        whiteKeyPos = whiteKeyPos + whiteKeyWidth + 1;
      }
    }

    // Draw black keys
    for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
    {
      Note currNote = rootNote;
      for (int i = 0; i <= keyIndex; i++) {
        currNote = getNextNote(currNote);
      }

      int rootIndex = currNote % 12;
      if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8)
      {
        display->fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        keys[keyIndex] = Key(false, currNote, blackKeyPos, keyboardLocation);
        blackKeyPos = blackKeyPos + whiteKeyWidth + 1;
      }
      else if (rootIndex == 3 || rootIndex == 10)
      {
        display->fillRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, BLACK);
        display->drawRect(blackKeyPos, keyboardLocation, blackKeyWidth, blackKeyHeight, WHITE);
        keys[keyIndex] = Key(false, currNote, blackKeyPos, keyboardLocation);
        blackKeyPos = blackKeyPos + 2*whiteKeyWidth + 2;
      }
    }

    for (int i = 0; i < 3; i++)
    {
      drawKey(chordNotes[i], keys, numKeys);
    }

    screen->update();
  }