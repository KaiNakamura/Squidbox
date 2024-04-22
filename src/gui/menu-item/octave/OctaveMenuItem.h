#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/note/Note.h"
#include <Arduino.h>

class OctaveMenuItem : public MenuItem {
private:
  static void onKnobLeft(void *arg);
  static void onKnobRight(void *arg);
  void updateName();
  int octaveIndex;

public:
  OctaveMenuItem();
  Note getNote();
};