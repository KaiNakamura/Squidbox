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

void Screen::printKeyboard(int rootNote, String chordType)
{
  int whiteKeyPos = 2; // Initial position of the first white key
  int blackKeyPos = 8; // Initial position of the first black key

 
    for (int keyIndex = 0; keyIndex < 17; keyIndex++)
    {
      int note = keyIndex;
      bool isPlayedNote = false;

      // Check if the current note is part of the chord based on the chord type
      if (chordType == "Major")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 4) || (note == rootNote + 7);
      }
      if (chordType == "Minor")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 3) || (note == rootNote + 7);
      }
      if (chordType == "Diminished")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 3) || (note == rootNote + 6);
      }

      if (keyIndex != 1 && keyIndex != 6 && keyIndex != 8 && keyIndex != 13 && keyIndex != 15 && keyIndex != 3 && keyIndex != 10)
      {
        // Draw white key
        display.drawRect(whiteKeyPos, STARTING_KEY_Y, WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, WHITE);
        whiteKeyPos = whiteKeyPos + WHITE_KEY_WIDTH + 1;
      }
    }
    // Draw black keys
    for (int keyIndex = 0; keyIndex < 17; keyIndex++)
    {
      int note = keyIndex;
      bool isPlayedNote = false;

      // Check if the current note is part of the chord based on the chord type
      if (chordType == "Major")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 4) || (note == rootNote + 7);
      }
      if (chordType == "Minor")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 3) || (note == rootNote + 7);
      }
      if (chordType == "Dinminshed")
      {
        isPlayedNote = (note == rootNote) || (note == rootNote + 3) || (note == rootNote + 6);
      }

      if (keyIndex == 1 || keyIndex == 6 || keyIndex == 8 || keyIndex == 13 || keyIndex == 15)
      {
        display.fillRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
        blackKeyPos = blackKeyPos + WHITE_KEY_WIDTH + 1;
      }
      else if (keyIndex == 3 || keyIndex == 10)
      {
        display.fillRect(blackKeyPos, STARTING_KEY_Y, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, WHITE);
        blackKeyPos = blackKeyPos + 2*WHITE_KEY_WIDTH + 2*1;
      }
    }
  }