#include "Keyboard.h"
#include "Squidbox.h"

Keyboard::Keyboard(Squidbox *squidbox) : squidbox(squidbox) {
  this->keys = new Key *[NOTE_G9];

  // Create notes
  for (Note note = NOTE_A0; note < NOTE_G9; note = getNextNote(note)) {
    keys[note] = new Key();
    keys[note]->setNote(note);
  }

  // Set keys as white and black
  setWhiteKeys();
  setBlackKeys();
}

void Keyboard::setWhiteKeys() {
  for (Note note = NOTE_A0; note < NOTE_G9; note = getNextNote(note)) {
    int rootIndex = note % 12;
    if (rootIndex != 1 && rootIndex != 6 && rootIndex != 8 && rootIndex != 3 &&
        rootIndex != 10) {
      keys[note]->setWhite(true);
    }
  }
}

void Keyboard::setBlackKeys() {
  for (Note note = NOTE_A0; note < NOTE_G9; note = getNextNote(note)) {
    int rootIndex = note % 12;
    if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8 || rootIndex == 3 ||
        rootIndex == 10) {
      keys[note]->setWhite(false);
    }
  }
}

void Keyboard::drawWhiteKey(Note note, int xPosition) {
  Screen *screen = squidbox->getScreen();
  Adafruit_SSD1306 *display = screen->getDisplay();

  if (keys[note]->isDown()) {
    display->fillRect(xPosition, STARTING_KEY_Y, WHITE_KEY_WIDTH,
                      WHITE_KEY_HEIGHT, WHITE);
  } else {
    display->drawRect(xPosition, STARTING_KEY_Y, WHITE_KEY_WIDTH,
                      WHITE_KEY_HEIGHT, WHITE);
  }
}

void Keyboard::drawBlackKey(Note note, int xPosition) {
  Screen *screen = squidbox->getScreen();
  Adafruit_SSD1306 *display = screen->getDisplay();

  if (keys[note]->isDown()) {
    display->fillRect(xPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH,
                      BLACK_KEY_HEIGHT, WHITE);
  } else {
    display->fillRect(xPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH,
                      BLACK_KEY_HEIGHT, BLACK);
    display->drawRect(xPosition, STARTING_KEY_Y, BLACK_KEY_WIDTH,
                      BLACK_KEY_HEIGHT, WHITE);
  }
}

void Keyboard::update(Note root) {
  unsigned long currentTime = millis();
  unsigned long elapsed = currentTime - lastUpdate;

  // Draw keyboard if enough time has passed since the last update
  if (elapsed >= 1000 / REFRESH_RATE) {
    draw(root);
    lastUpdate = currentTime;
  }
}
void Keyboard::draw(Note root) {
  Screen *screen = squidbox->getScreen();

  // Clear portion of the screen that contains the keyboard
  screen->getDisplay()->fillRect(0, STARTING_KEY_Y, Screen::WIDTH,
                                 WHITE_KEY_HEIGHT, BLACK);

  int whiteKeyPosition = 2; // Initial position of the first white key
  int blackKeyPosition = 8; // Initial position of the first black key

  // Draw white keys
  Note note = root;
  for (int i = 0; i < NUM_KEYS_TO_DRAW; i++) {
    if (keys[note]->isWhite()) {
      drawWhiteKey(note, whiteKeyPosition);

      // Increment pixel location for white keys
      whiteKeyPosition += WHITE_KEY_WIDTH + 1;
    }
    note = getNextNote(note);
  }

  // Draw black keys
  note = root;
  for (int i = 0; i < NUM_KEYS_TO_DRAW; i++) {
    if (!keys[note]->isWhite()) {
      drawBlackKey(note, blackKeyPosition);

      // Increment pixel location for black keys, extra if black key is E or B
      int rootIndex = note % 12;
      if (rootIndex == 1 || rootIndex == 6 || rootIndex == 8) {
        blackKeyPosition += WHITE_KEY_WIDTH + 1;
      } else if (rootIndex == 3 || rootIndex == 10) {
        blackKeyPosition += 2 * WHITE_KEY_WIDTH + 2;
      }
    }
    note = getNextNote(note);
  }

  // Update screen
  screen->update();
}

void Keyboard::setKeyDown(Note note, bool down) { setKeyDown(note, down); }

void Keyboard::setKeyDown(int note, bool down) { keys[note]->setDown(down); }
