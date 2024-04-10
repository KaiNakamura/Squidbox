#pragma once

#include <functional>
#include "scene/Scene.h"

class MenuItem
{
public:
  using CallbackFunction = std::function<void(Scene *)>;

  MenuItem(const char *name);
  const char *getName();
  void setName(const char *name);
  void setCallback(CallbackFunction cb);
  void onSelect(Scene *scene);

private:
  const char *name;
  CallbackFunction callback;
};