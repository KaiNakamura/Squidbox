#pragma once

#include "components/knob/Knob.h"
#include "scene/Scene.h"

class KnobScene : public Scene {
private:
  static void leftCallback(int count, void *usr_data);
  static void rightCallback(int count, void *usr_data);

public:
  KnobScene(Squidbox *squidbox);
  void init() override;
  void update() override;
};