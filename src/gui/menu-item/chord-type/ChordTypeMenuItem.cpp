#include "ChordTypeMenuItem.h"

ChordTypeMenuItem::ChordTypeMenuItem() : MenuItem(), chordTypeIndex(0) {
  // Set the callbacks for when the knob is turned left or right
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);

  // Update the name of the menu item to reflect the current chord type
  updateName();
}

void ChordTypeMenuItem::updateName() {
  // Set the name of the menu item to the name of the current chord type
  setName(getChordType()->name);
}

void ChordTypeMenuItem::onKnobLeft(void *arg) {
  // Cast the argument to a ChordTypeMenuItem pointer
  ChordTypeMenuItem *self = static_cast<ChordTypeMenuItem *>(arg);

  // Decrease the chord type index, but don't let it go below 0
  self->chordTypeIndex = max(self->chordTypeIndex - 1, 0);

  // Update the name of the menu item to reflect the new chord type
  self->updateName();
}

void ChordTypeMenuItem::onKnobRight(void *arg) {
  // Cast the argument to a ChordTypeMenuItem pointer
  ChordTypeMenuItem *self = static_cast<ChordTypeMenuItem *>(arg);

  // Increase the chord type index, but don't let it go above the number of
  // chord types minus 1
  self->chordTypeIndex = min(self->chordTypeIndex + 1, NUM_CHORD_TYPES - 1);

  // Update the name of the menu item to reflect the new chord type
  self->updateName();
}

ChordType *ChordTypeMenuItem::getChordType() {
  // Return the chord type at the current index
  return CHORD_TYPES[chordTypeIndex];
}