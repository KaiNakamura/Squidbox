#pragma once

#include "scene/Scene.h"
#include "util/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

class ChordScene : public Scene
{
private:
  Note root;
  Scale *scale;
  ChordType chordType;

public:
  ChordScene(Squidbox *squidbox);
  void playChord(int index, bool on);
  void init();
  void update();
};
