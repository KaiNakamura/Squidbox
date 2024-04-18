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

bool Key::getIsDown() {
    return this->isDown;
}

void Key::setIsDown(bool isDown) {
    this->isDown = isDown;
}

bool Key::getIsWhite() {
    return this->isWhite;
}

void Key::setIsWhite(bool isWhite) {
    this->isWhite = isWhite;
}

Note Key::getNote() {
    return this->note;
}

void Key::setNote(Note note) {
    this->note = note;
}

int Key::getX() {
    return this->x;
}

void Key::setX(int x) {
    this->x = x;
}

int Key::getY() {
    return this->y;
}

void Key::setY(int y) {
    this->y = y;
}

