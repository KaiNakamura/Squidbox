#pragma once

/**
 * @struct ChordType
 * @brief This struct represents a type of musical chord.
 *
 * A chord type is defined by its name, the number of notes it contains, and the
 * offsets of these notes.
 */
struct ChordType {
  const char *name; ///< The name of the chord type
  int numNotes;     ///< The number of notes in the chord type
  int *offsets;     ///< The offsets of the notes in the chord type
};

/// A triad chord type
static ChordType TRIAD = {"Triad", 3, new int[3]{0, 2, 4}};

/// A seventh chord type
static ChordType SEVENTH = {"Seventh", 4, new int[4]{0, 2, 4, 6}};

/// A sixth chord type
static ChordType SIXTH = {"Sixth", 4, new int[4]{0, 2, 4, 5}};

/// A fifth (power chord) type
static ChordType FIFTH = {"Fifth (Power Chord)", 2, new int[2]{0, 4}};

/// A fourth chord type
static ChordType FOURTH = {"Fourth", 2, new int[2]{0, 3}};

/// A third chord type
static ChordType THIRD = {"Third", 2, new int[2]{0, 2}};

/// A single note chord type
static ChordType SINGLE_NOTE = {"Single Note", 1, new int[1]{0}};

/// The total number of chord types
static const int NUM_CHORD_TYPES = 7;

/// An array of all chord types
static ChordType *CHORD_TYPES[] = {&TRIAD,  &SEVENTH, &SIXTH,      &FIFTH,
                                   &FOURTH, &THIRD,   &SINGLE_NOTE};