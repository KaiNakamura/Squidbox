#pragma once
#include "components/screen/Screen.h"
#include "gui/keyboard/Key.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"
#include <Arduino.h>

class Keyboard {
private:
  const static int STARTING_KEY_Y = 40;
  const static int WHITE_KEY_WIDTH = 8;
  const static int WHITE_KEY_HEIGHT = 20;
  const static int BLACK_KEY_WIDTH = 5;
  const static int BLACK_KEY_HEIGHT = 12;
  const static int NUM_KEYS_TO_DRAW = 24;
  const static int REFRESH_RATE = 20; // Hz
  Key **keys;
  Squidbox *squidbox;
  unsigned long lastUpdate;
  void setWhiteKeys();
  void setBlackKeys();
  void drawWhiteKey(Note root, int xPosition);
  void drawBlackKey(Note root, int xPosition);

public:
  Keyboard(Squidbox *squidbox);
  void update(Note root);
  void draw(Note root);
  void setKeyDown(Note note, bool down);
  void setKeyDown(int note, bool down);
};
