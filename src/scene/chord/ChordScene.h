#pragma once

#include "scene/Scene.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"
#include "gui/menu-item/root-note/RootNoteMenuItem.h"
#include "gui/menu-item/scale/ScaleMenuItem.h"

class ChordScene : public Scene
{
private:
  ChordType chordType;
  const int STARTING_KEY_Y = 40;
  const int WHITE_KEY_WIDTH = 8; 
  const int WHITE_KEY_HEIGHT = 20;
  const int BLACK_KEY_WIDTH = 5; 
  const int BLACK_KEY_HEIGHT = 12; 
  MenuItem *connectedMenuItem;
  MenuItem *rootMenuItem;
  MenuItem *scaleMenuItem;
  RootNoteMenuItem *rootMenuItem;
  ScaleMenuItem *scaleMenuItem;
  static const Note MIN_NOTE = NOTE_C1;
  static const Note MAX_NOTE = NOTE_C7;

public:
  ChordScene(Squidbox *squidbox);
  void init() override;
  void update() override;
  void playChord(int index, bool on);
};
