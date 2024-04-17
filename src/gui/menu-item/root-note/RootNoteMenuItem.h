#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/note/Note.h"

class RootNoteMenuItem : public MenuItem {
private:
  static const Note MIN_NOTE = NOTE_C1;
  static const Note MAX_NOTE = NOTE_C7;
  static const Note START_NOTE = NOTE_C4;
  static void onKnobLeft(void *arg);
  static void onKnobRight(void *arg);
  void updateName();
  Note root;

public:
  RootNoteMenuItem();
  Note getRootNote();
};