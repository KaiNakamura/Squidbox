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
      bool getIsDown();
      void setIsDown(bool isDown);
      bool getIsWhite();
      void setIsWhite(bool isWhite);
      Note getNote();
      void setNote(Note note);
      int getX();
      void setX(int x);
      int getY();
      void setY(int y);
      Key();
      Key(bool isWhite, Note note, int x, int y);
      void draw(Note note);
};