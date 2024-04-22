#pragma once

#include "gui/menu-item/octave/OctaveMenuItem.h"
#include "scene/Scene.h"
#include "util/note/Note.h"

class DrumScene : public Scene {
private:
  OctaveMenuItem *octaveMenuItem;

public:
  DrumScene(Squidbox *squidbox);
  void init() override;
  void update() override;
  void playDrum(int index, bool on);
};