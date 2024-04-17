#pragma once

struct ChordType {
  int numNotes;
  int *offsets;
};

// TODO: Maybe change to semitones and not index offsets (doesn't work with
// pentatonic)
static const ChordType TRIAD = {3, new int[3]{0, 2, 4}};
static const ChordType SEVENTH = {4, new int[4]{0, 2, 4, 6}};