#include "MenuItem.h"

MenuItem::MenuItem(const char *name)
    : name(name), selectCallback(nullptr), knobLeftCallback(nullptr),
      knobRightCallback(nullptr) {}

MenuItem::MenuItem() : MenuItem("") {}

const char *MenuItem::getName() { return name; }

void MenuItem::setName(const char *name) { this->name = name; }

void MenuItem::setOnSelectCallback(CallbackFunction cb, void *arg) {
  selectCallback = cb;
  selectArg = arg;
}

void MenuItem::setOnKnobLeftCallback(CallbackFunction cb, void *arg) {
  knobLeftCallback = cb;
  knobLeftArg = arg;
}

void MenuItem::setOnKnobRightCallback(CallbackFunction cb, void *arg) {
  knobRightCallback = cb;
  knobRightArg = arg;
}

void MenuItem::onSelect() {
  // If a select callback is set, call it with the provided argument
  if (selectCallback) {
    selectCallback(selectArg);
  }
}

void MenuItem::onKnobLeft() {
  // If a knob left callback is set, call it with the provided argument
  if (knobLeftCallback) {
    knobLeftCallback(knobLeftArg);
  }
}

void MenuItem::onKnobRight() {
  // If a knob right callback is set, call it with the provided argument
  if (knobRightCallback) {
    knobRightCallback(knobRightArg);
  }
}

Ascii MenuItem::getPrefix() {
  // If either a knob left or knob right callback is set, return the double
  // vertical arrow Otherwise, return the right fat arrow
  if (knobLeftCallback || knobRightCallback) {
    return ASCII_DOUBLE_VERTICAL_ARROW;
  }
  return ASCII_RIGHT_FAT_ARROW;
}