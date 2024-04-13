#include "key.h"

Key::Key(bool isWhite, Note note, int x, int y) {
    this->isDown = false;
    this->isWhite = isWhite;
    this->note = note;
    this->x = x;
    this->y = y;
}

void draw(Note note) { 
}