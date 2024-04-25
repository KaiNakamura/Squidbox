#include "Key.h"

Key::Key(Note note, bool white) : note(note), white(white), down(false) {}

bool Key::isDown() { return this->down; }

void Key::setDown(bool down) { this->down = down; }

bool Key::isWhite() { return this->white; }

void Key::setWhite(bool white) { this->white = white; }

Note Key::getNote() { return this->note; }

void Key::setNote(Note note) { this->note = note; }
