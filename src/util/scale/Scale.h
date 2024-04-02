#pragma once

#include <Arduino.h>
#include "util/ChordType.h"

class Scale
{
private:
  int numNotes;
  int *semitones;

public:
  Scale(int numNotes, int *semitones);
  int getNote(int root, int index);
  int *getNotesFromChord(int root, int index, ChordType chord);
};

extern Scale *MAJOR_SCALE;
extern Scale *MINOR_SCALE;