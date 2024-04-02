#pragma once

#include "scene/Scene.h"
#include "components/knob/Knob.h"

class KnobScene : public Scene
{
private:
  static void leftCallback(int count, void *usr_data);
  static void rightCallback(int count, void *usr_data);

public:
  KnobScene(Squidbox *squidbox);
  void init();
  void update();
};