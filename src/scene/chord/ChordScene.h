#pragma once

#include "scene/Scene.h"

class ChordScene : public Scene
{
public:
  ChordScene(Squidbox *squidbox);
  void playChord(int buttonPin, int note1, int note2, int note3);
  void init();
  void update();
};
