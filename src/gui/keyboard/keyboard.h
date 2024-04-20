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
   Key** keys;
   Squidbox* squidbox;
   void drawKey(Key* key, int x, int y);
   void drawWhiteKey(Note root, int whiteKeyPosition, int numKeys);
   void drawBlackKey(Note root, int blackKeyPosition, int numKeys);
   void setWhiteKeys(); 
   void setBlackKeys();
   
public:
   Keyboard(Squidbox* squidbox);
   void printKeyboard(Note root, int numKeys);
   void setKeyDown(Note note, bool down);
};

