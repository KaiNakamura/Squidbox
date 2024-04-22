#include "OctaveMenuItem.h"

OctaveMenuItem::OctaveMenuItem() : MenuItem(), octaveIndex(0) {
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);
  updateName();
}

void OctaveMenuItem::updateName() { setName(noteToString(getNote())); }

void OctaveMenuItem::onKnobLeft(void *arg) {
  OctaveMenuItem *self = static_cast<OctaveMenuItem *>(arg);
  self->octaveIndex = max(self->octaveIndex - 1, 0);
  self->updateName();
}

void OctaveMenuItem::onKnobRight(void *arg) {
  OctaveMenuItem *self = static_cast<OctaveMenuItem *>(arg);
  self->octaveIndex = min(self->octaveIndex + 1, NUM_OCTAVES - 1);
  self->updateName();
}

Note OctaveMenuItem::getNote() { return OCTAVES[octaveIndex]; }