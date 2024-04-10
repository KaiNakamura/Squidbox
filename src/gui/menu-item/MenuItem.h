#pragma once

#include <functional>
#include "scene/Scene.h"

class MenuItem
{
public:
  using CallbackFunction = std::function<void(Scene *)>;

  MenuItem(const char *name, Scene *scene);
  const char *getName();
  void setName(const char *name);
  void setCallback(CallbackFunction cb);
  void onSelect();

private:
  const char *name;
  Scene *scene;
  CallbackFunction callback;
};