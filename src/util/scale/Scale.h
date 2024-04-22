#pragma once

#include "util/ChordType.h"
#include <Arduino.h>

class Scale {
private:
  const char *name;
  int numNotes;
  int *semitones;

public:
  static Scale *MAJOR;
  static Scale *MINOR;
  static Scale *DORIAN;
  static Scale *PHRYGIAN;
  static Scale *LYDIAN;
  static Scale *MIXOLYDIAN;
  static Scale *LOCRIAN;
  static Scale *HARMONIC_MINOR;
  static Scale *HARMONIC_MAJOR;
  static const int NUM_SCALES = 9;
  static Scale *SCALES[];
  Scale(const char *name, int numNotes, int *semitones);
  const char *getName();
  int getNote(int root, int index);
  int *getNotesFromChord(int root, int index, ChordType *chord);
};
