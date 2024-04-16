#include "MenuItem.h"

MenuItem::MenuItem(const char *name) : name(name), selectCallback(nullptr), knobLeftCallback(nullptr), knobRightCallback(nullptr) {}

MenuItem::MenuItem() : MenuItem("") {}

const char *MenuItem::getName()
{
  return name;
}

void MenuItem::setName(const char *name)
{
  this->name = name;
}

void MenuItem::setOnSelectCallback(CallbackFunction cb, void *arg)
{
  selectCallback = cb;
  selectArg = arg;
}

void MenuItem::setOnKnobLeftCallback(CallbackFunction cb, void *arg)
{
  knobLeftCallback = cb;
  knobLeftArg = arg;
}

void MenuItem::setOnKnobRightCallback(CallbackFunction cb, void *arg)
{
  knobRightCallback = cb;
  knobRightArg = arg;
}

void MenuItem::onSelect()
{
  if (selectCallback)
  {
    selectCallback(selectArg);
  }
}

void MenuItem::onKnobLeft()
{
  if (knobLeftCallback)
  {
    knobLeftCallback(knobLeftArg);
  }
}

void MenuItem::onKnobRight()
{
  if (knobRightCallback)
  {
    knobRightCallback(knobRightArg);
  }
}

Ascii MenuItem::getPrefix()
{
  if (knobLeftCallback || knobRightCallback)
  {
    return ASCII_DOUBLE_VERTICAL_ARROW;
  }
  return ASCII_RIGHT_FAT_ARROW;
}