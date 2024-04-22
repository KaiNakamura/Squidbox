#include "ChordTypeMenuItem.h"

ChordTypeMenuItem::ChordTypeMenuItem() : MenuItem(), chordTypeIndex(0) {
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);
  updateName();
}

void ChordTypeMenuItem::updateName() { setName(getChordType()->name); }

void ChordTypeMenuItem::onKnobLeft(void *arg) {
  ChordTypeMenuItem *self = static_cast<ChordTypeMenuItem *>(arg);
  self->chordTypeIndex = max(self->chordTypeIndex - 1, 0);
  self->updateName();
}

void ChordTypeMenuItem::onKnobRight(void *arg) {
  ChordTypeMenuItem *self = static_cast<ChordTypeMenuItem *>(arg);
  self->chordTypeIndex = min(self->chordTypeIndex + 1, NUM_CHORD_TYPES - 1);
  self->updateName();
}

ChordType *ChordTypeMenuItem::getChordType() {
  return CHORD_TYPES[chordTypeIndex];
}