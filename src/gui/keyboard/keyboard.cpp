#include "Keyboard.h"
#include "Squidbox.h"

Keyboard::Keyboard(Squidbox *squidbox)
{
  Note currNote = NOTE_A0;
  this->keys = new Key*[128]; // Allocate memory for array of pointers
  for (int i = 0; i < 128; i++) {
    keys[i] = new Key(); // Allocate memory for each Key object
    if (i >= 21) {
      keys[i]->setNote(currNote); 
      currNote = getNextNote(currNote);
    }
  }
  setWhiteKeys();
  setBlackKeys();
  this->squidbox = squidbox;
}

void Keyboard::setWhiteKeys() {
  Note currNote = NOTE_A0;
  for (int i = 21; i <= 127; i++) {
    int rootIndex = currNote % 12;
    if (rootIndex != 1 && rootIndex != 6 && rootIndex != 8 && rootIndex != 3 && rootIndex != 10) 
    {
      keys[currNote]->setWhite(true); // down, white, note
    }
    currNote = getNextNote(currNote);
  }
}

void Keyboard::setBlackKeys() {
  Note currNote = NOTE_A0;
  for (int i = 21; i <= 127; i++) {
    int rootIndex = currNote % 12;
    if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8 || rootIndex == 3 || rootIndex == 10) 
    {
      keys[currNote]->setWhite(false); // down, white, note
    }
    currNote = getNextNote(currNote);
  }
}


void Keyboard::setKeyDown(Note note, bool down)
{
  keys[note]->setDown(down);
}

void Keyboard::drawWhiteKey(Note note, int whiteKeyPosition, int numKeys)
{
  Screen *screen = squidbox->getScreen();
  Adafruit_SSD1306* display = screen->getDisplay();

  for (int i = 0; i < numKeys; i++)
  {
    if (keys[note]->isDown()) {
      display->fillRect(whiteKeyPosition, STARTING_KEY_Y, WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, WHITE);
    }
    else {
      display->drawRect(whiteKeyPosition, STARTING_KEY_Y, WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, WHITE);
    }
  }
}


void Keyboard::drawBlackKey(Note note, int blackKeyPosition, int numKeys)
{
  Screen *screen = squidbox->getScreen();
  Adafruit_SSD1306* display = screen->getDisplay();

  for (int i = 0; i < numKeys; i++)
  {
    if (keys[note]->isDown()) {
      display->fillRect(blackKeyPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
    }
    else {
      display->fillRect(blackKeyPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, BLACK);
      display->drawRect(blackKeyPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
    }
  }
}



void Keyboard::printKeyboard(Note rootNote, int numKeys)
{
  Screen *screen = squidbox->getScreen();
  int whiteKeyPosition = 2; // Initial position of the first white key
  int blackKeyPosition = 8; // Initial position of the first black key
  Note currNote = rootNote;
  
  for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
  {     
    // Draw white keys
    if (keys[currNote]->isWhite()) {
      drawWhiteKey(currNote, whiteKeyPosition, numKeys);
      whiteKeyPosition += WHITE_KEY_WIDTH + 1; //Move pixel location for white keys
    }
    currNote = getNextNote(currNote);
  }

  currNote = rootNote; //Reset notes
  for (int keyIndex = 0; keyIndex < numKeys; keyIndex++)
  {
    // Draw black keys
    if (!keys[currNote]->isWhite()) {
      drawBlackKey(currNote, blackKeyPosition, numKeys);
      int rootIndex = currNote % 12;
    
      // position of black keys
      if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8)
      {
        blackKeyPosition += WHITE_KEY_WIDTH + 1;
      }
      else if (rootIndex == 3 || rootIndex == 10)
      {
        blackKeyPosition += 2*WHITE_KEY_WIDTH + 2;
      }
    }
    currNote = getNextNote(currNote);
  }
  screen->update();
}