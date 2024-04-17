#include "key.h"

Key::Key() {
    this->isDown = false;
    this->isWhite = false;
    this->note = NOTE_C6;
    this->x = 0;
    this->y = 0;

}
Key::Key(bool isWhite, Note note, int x, int y) {
    this->isDown = false;
    this->isWhite = isWhite;
    this->note = note;
    this->x = x;
    this->y = y;
}

void draw(Note note) { 
}