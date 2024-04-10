#include "MenuItem.h"

MenuItem::MenuItem(const char *name) : name(name), callback(nullptr) {}

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

void MenuItem::onSelect(Scene *scene)
{
  if (callback)
  {
    callback(scene);
  }
}