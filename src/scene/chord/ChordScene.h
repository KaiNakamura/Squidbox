#pragma once

#include "scene/Scene.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

class ChordScene : public Scene
{
private:
  Note root;
  Scale *scale;
  ChordType chordType;
  static const Note MIN_NOTE = NOTE_A0;
  static const Note MAX_NOTE = NOTE_G8;
  static void onKnobLeft(int count, void *usr_data);
  static void onKnobRight(int count, void *usr_data);

public:
  ChordScene(Squidbox *squidbox);
  void playChord(int index, bool on);
  void init();
  void update();
};
