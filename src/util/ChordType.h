#pragma once

struct ChordType {
  const char *name;
  int numNotes;
  int *offsets;
};

// TODO: Maybe change to semitones and not index offsets? (doesn't work with
// pentatonic, but isn't a huge deal)
static ChordType TRIAD = {"Triad", 3, new int[3]{0, 2, 4}};
static ChordType SEVENTH = {"Seventh", 4, new int[4]{0, 2, 4, 6}};
static ChordType FIFTH = {"Fifth (Power Chord)", 2, new int[2]{0, 4}};
static ChordType SIXTH = {"Sixth", 4, new int[4]{0, 2, 4, 5}};
static ChordType FOURTH = {"Fourth", 2, new int[2]{0, 3}};
static ChordType THIRD = {"Third", 2, new int[2]{0, 2}};
static ChordType SINGLE_NOTE = {"Single Note", 1, new int[1]{0}};
static const int NUM_CHORD_TYPES = 7;
static ChordType *CHORD_TYPES[] = {&TRIAD,  &SEVENTH, &FIFTH,      &SIXTH,
                                   &FOURTH, &THIRD,   &SINGLE_NOTE};