#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/ChordType.h"
#include <Arduino.h>

class ChordTypeMenuItem : public MenuItem {
private:
  static void onKnobLeft(void *arg);
  static void onKnobRight(void *arg);
  void updateName();
  int chordTypeIndex;

public:
  ChordTypeMenuItem();
  ChordType *getChordType();
};