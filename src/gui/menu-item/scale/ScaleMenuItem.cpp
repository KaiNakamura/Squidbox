#include "ScaleMenuItem.h"

ScaleMenuItem::ScaleMenuItem() : MenuItem(), scaleIndex(0) {
  // Set the callbacks for when the knob is turned left or right
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);

  // Update the name of the menu item to reflect the current scale
  updateName();
}

void ScaleMenuItem::updateName() {
  // Set the name of the menu item to the name of the current scale
  setName(getScale()->getName());
}

void ScaleMenuItem::onKnobLeft(void *arg) {
  // Cast the argument to a ScaleMenuItem pointer
  ScaleMenuItem *self = static_cast<ScaleMenuItem *>(arg);

  // Decrease the scale index, but don't let it go below 0
  self->scaleIndex = max(self->scaleIndex - 1, 0);

  // Update the name of the menu item to reflect the new scale
  self->updateName();
}

void ScaleMenuItem::onKnobRight(void *arg) {
  // Cast the argument to a ScaleMenuItem pointer
  ScaleMenuItem *self = static_cast<ScaleMenuItem *>(arg);

  // Increase the scale index, but don't let it go above the number of scales
  // minus 1
  self->scaleIndex = min(self->scaleIndex + 1, Scale::NUM_SCALES - 1);

  // Update the name of the menu item to reflect the new scale
  self->updateName();
}

Scale *ScaleMenuItem::getScale() {
  // Return the scale at the current index
  return Scale::SCALES[scaleIndex];
}