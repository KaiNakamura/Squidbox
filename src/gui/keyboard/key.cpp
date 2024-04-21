#include "Key.h"

Key::Key() {
  this->down = false;
  this->white = false;
  this->note = NOTE_A0;
}

Key::Key(bool down, bool white, Note note) {
  this->down = false;
  this->white = white;
  this->note = note;
}

bool Key::isDown() { return this->down; }

void Key::setDown(bool down) { this->down = down; }

bool Key::isWhite() { return this->white; }

void Key::setWhite(bool white) { this->white = white; }

Note Key::getNote() { return this->note; }

void Key::setNote(Note note) { this->note = note; }
