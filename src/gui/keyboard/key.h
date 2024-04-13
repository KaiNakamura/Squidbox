#pragma once 


#include "scene/Scene.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

class Key {
   private:
      bool isDown;
      bool isWhite;
      Note note;
      int x, y; 
   
   public: 
      Key(bool isWhite, Note note, int x, int y);
      void draw(Note note);
};