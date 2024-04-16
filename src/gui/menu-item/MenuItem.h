#pragma once

#include <functional>
#include "util/Ascii.h"

class Scene;

class MenuItem
{
public:
  using CallbackFunction = std::function<void(void *)>;

  MenuItem(const char *name);
  MenuItem();
  const char *getName();
  void setName(const char *name);
  void setOnSelectCallback(CallbackFunction cb, void *arg = nullptr);
  void setOnKnobLeftCallback(CallbackFunction cb, void *arg = nullptr);
  void setOnKnobRightCallback(CallbackFunction cb, void *arg = nullptr);
  void onSelect();
  void onKnobLeft();
  void onKnobRight();
  Ascii getPrefix();

private:
  const char *name;
  Scene *scene;
  CallbackFunction selectCallback, knobLeftCallback, knobRightCallback;
  void *selectArg, *knobLeftArg, *knobRightArg;
};