#pragma once

#include "gui/keyboard/Keyboard.h"
#include "gui/menu-item/root-note/RootNoteMenuItem.h"
#include "gui/menu-item/scale/ScaleMenuItem.h"
#include "scene/Scene.h"
#include "util/ChordType.h"
#include "util/note/Note.h"
#include "util/scale/Scale.h"

class ChordScene : public Scene {
private:
  ChordType chordType;
  RootNoteMenuItem *rootMenuItem;
  ScaleMenuItem *scaleMenuItem;
  Keyboard *keyboard;
  static const Note MIN_NOTE = NOTE_C1;
  static const Note MAX_NOTE = NOTE_C7;

public:
  ChordScene(Squidbox *squidbox);
  void init() override;
  void update() override;
  void playChord(int index, bool on);
};