#pragma once
#include "scene/Scene.h"
#include "gui/keyboard/key.h"
#include "components/screen/Screen.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

class Keyboard
{
private:
   Key* keys;

public:
   Keyboard();
   void printKeyboard(int keyboardLocation, int whiteKeyWidth, int whiteKeyHeight, int blackKeyWidth, int blackKeyHeight, int numKeys);
};
