#include "RootNoteMenuItem.h"

RootNoteMenuItem::RootNoteMenuItem() : MenuItem(), root(START_NOTE) {
  // Set the callbacks for when the knob is turned left or right
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);

  // Update the name of the menu item to reflect the current root note
  updateName();
}

void RootNoteMenuItem::updateName() {
  // Set the name of the menu item to the string representation of the current
  // root note
  setName(noteToString(root));
}

void RootNoteMenuItem::onKnobLeft(void *arg) {
  // Cast the argument to a RootNoteMenuItem pointer
  RootNoteMenuItem *self = static_cast<RootNoteMenuItem *>(arg);

  // Decrease the root note, but don't let it go below the minimum note
  self->root = getPreviousNote(self->root, self->MIN_NOTE, self->MAX_NOTE);

  // Update the name of the menu item to reflect the new root note
  self->updateName();
}

void RootNoteMenuItem::onKnobRight(void *arg) {
  // Cast the argument to a RootNoteMenuItem pointer
  RootNoteMenuItem *self = static_cast<RootNoteMenuItem *>(arg);

  // Increase the root note, but don't let it go above the maximum note
  self->root = getNextNote(self->root, self->MIN_NOTE, self->MAX_NOTE);

  // Update the name of the menu item to reflect the new root note
  self->updateName();
}

Note RootNoteMenuItem::getRootNote() {
  // Return the current root note
  return root;
}