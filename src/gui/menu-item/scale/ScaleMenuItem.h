#pragma once

#include "gui/menu-item/MenuItem.h"
#include "util/scale/Scale.h"

class ScaleMenuItem : public MenuItem {
private:
  static void onKnobLeft(void *arg);
  static void onKnobRight(void *arg);
  void updateName();
  int scaleIndex;

public:
  ScaleMenuItem();
  Scale *getScale();
};