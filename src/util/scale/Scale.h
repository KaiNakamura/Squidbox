#pragma once

#include <Arduino.h>
#include "util/ChordType.h"

class Scale
{
private:
  const char *name;
  int numNotes;
  int *semitones;

public:
  Scale(const char *name, int numNotes, int *semitones);
  const char *getName();
  int getNote(int root, int index);
  int *getNotesFromChord(int root, int index, ChordType chord);
};

extern Scale *MAJOR_SCALE;
extern Scale *MINOR_SCALE;
extern Scale *MAJOR_PENTATONIC_SCALE;
extern Scale *MINOR_PENTATONIC_SCALE;