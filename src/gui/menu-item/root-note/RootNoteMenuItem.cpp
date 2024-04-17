#include "RootNoteMenuItem.h"

RootNoteMenuItem::RootNoteMenuItem() : MenuItem(), root(START_NOTE) {
  setOnKnobLeftCallback(onKnobLeft, this);
  setOnKnobRightCallback(onKnobRight, this);
  updateName();
}

void RootNoteMenuItem::updateName() { setName(noteToString(root)); }

void RootNoteMenuItem::onKnobLeft(void *arg) {
  RootNoteMenuItem *self = static_cast<RootNoteMenuItem *>(arg);
  self->root = getPreviousNote(self->root, self->MIN_NOTE, self->MAX_NOTE);
  self->updateName();
}

void RootNoteMenuItem::onKnobRight(void *arg) {
  RootNoteMenuItem *self = static_cast<RootNoteMenuItem *>(arg);
  self->root = getNextNote(self->root, self->MIN_NOTE, self->MAX_NOTE);
  self->updateName();
}

Note RootNoteMenuItem::getRootNote() { return root; }