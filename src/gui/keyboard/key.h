#pragma once 

#include "scene/Scene.h"
#include "util/note/Note.h"
#include "util/ChordType.h"
#include "util/scale/Scale.h"

class Key {
   private:
      bool down;
      bool white;
      Note note;
   
   public: 
      Key();
      Key(bool down, bool white, Note note);
      bool isDown();
      void setDown(bool down);
      bool isWhite();
      void setWhite(bool white);
      Note getNote();
      void setNote(Note note);
      void draw(Note note);
};