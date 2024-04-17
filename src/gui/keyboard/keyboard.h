#pragma once
#include "scene/Scene.h"
#include "gui/Keyboard/Key.h"
#include "components/screen/Screen.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

const int STARTING_KEY_Y = 40;
const int WHITE_KEY_WIDTH = 8; 
const int WHITE_KEY_HEIGHT = 20;
const int BLACK_KEY_WIDTH = 5; 
const int BLACK_KEY_HEIGHT = 12; 

class Keyboard
{
private:
   Key* keys;
   Squidbox* squidbox;

public:
   Keyboard(Squidbox* squidbox);
   void setKeys(Key* keys);
   void printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys, Note rootNote);
};
