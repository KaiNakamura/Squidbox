#include "OctaveMenuItem.h"

OctaveMenuItem::OctaveMenuItem() : MenuItem(), octaveIndex(0) {
  // Set the callbacks for when the knob is turned left or right
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);

  // Update the name of the menu item to reflect the current octave
  updateName();
}

void OctaveMenuItem::updateName() {
  // Set the name of the menu item to the string representation of the current
  // note
  setName(noteToString(getNote()));
}

void OctaveMenuItem::onKnobLeft(void *arg) {
  // Cast the argument to an OctaveMenuItem pointer
  OctaveMenuItem *self = static_cast<OctaveMenuItem *>(arg);

  // Decrease the octave index, but don't let it go below 0
  self->octaveIndex = max(self->octaveIndex - 1, 0);

  // Update the name of the menu item to reflect the new octave
  self->updateName();
}

void OctaveMenuItem::onKnobRight(void *arg) {
  // Cast the argument to an OctaveMenuItem pointer
  OctaveMenuItem *self = static_cast<OctaveMenuItem *>(arg);

  // Increase the octave index, but don't let it go above the number of octaves
  // minus 1
  self->octaveIndex = min(self->octaveIndex + 1, NUM_OCTAVES - 1);

  // Update the name of the menu item to reflect the new octave
  self->updateName();
}

Note OctaveMenuItem::getNote() {
  // Return the note at the current octave index
  return OCTAVES[octaveIndex];
}