#include "MenuItem.h"

MenuItem::MenuItem(const char *name, Scene *scene) : name(name), scene(scene), callback(nullptr) {}

const char *MenuItem::getName()
{
  return name;
}

void MenuItem::setName(const char *name)
{
  this->name = name;
}

void MenuItem::setCallback(CallbackFunction cb)
{
  callback = cb;
}

void MenuItem::onSelect()
{
  if (callback)
  {
    callback(scene);
  }
}