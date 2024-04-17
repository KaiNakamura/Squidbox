#include "Scale.h"

Scale *Scale::MAJOR = new Scale("Major", 7, new int[7]{0, 2, 4, 5, 7, 9, 11});
Scale *Scale::MINOR = new Scale("Minor", 7, new int[7]{0, 2, 3, 5, 7, 8, 10});
Scale *Scale::DORIAN = new Scale("Dorian", 7, new int[7]{0, 2, 3, 5, 7, 9, 10});
Scale *Scale::PHRYGIAN =
    new Scale("Phrygian", 7, new int[7]{0, 1, 3, 5, 7, 8, 10});
Scale *Scale::LYDIAN = new Scale("Lydian", 7, new int[7]{0, 2, 4, 6, 7, 9, 11});
Scale *Scale::MIXOLYDIAN =
    new Scale("Mixolydian", 7, new int[7]{0, 2, 4, 5, 7, 9, 10});
Scale *Scale::LOCRIAN =
    new Scale("Locrian", 7, new int[7]{0, 1, 3, 5, 6, 8, 10});
Scale *Scale::HARMONIC_MINOR =
    new Scale("Harmonic Minor", 7, new int[7]{0, 2, 3, 5, 7, 8, 11});
Scale *Scale::HARMONIC_MAJOR =
    new Scale("Harmonic Major", 7, new int[7]{0, 2, 4, 5, 7, 8, 11});
Scale *Scale::SCALES[] = {
    Scale::MAJOR,    Scale::MINOR,          Scale::DORIAN,
    Scale::PHRYGIAN, Scale::LYDIAN,         Scale::MIXOLYDIAN,
    Scale::LOCRIAN,  Scale::HARMONIC_MINOR, Scale::HARMONIC_MAJOR};

Scale::Scale(const char *name, int numNotes, int *semitones)
    : name(name), numNotes(numNotes), semitones(semitones) {}

const char *Scale::getName() { return name; }

int Scale::getNote(int root, int index) {
  if (index < 0) {
    Serial.printf("Error: Scale semitone not found with index %d\n", index);
  }
  int octaves = index / numNotes;
  return root + semitones[index % numNotes] + 12 * octaves;
}

int *Scale::getNotesFromChord(int root, int index, ChordType chord) {
  int *notes = new int[chord.numNotes];
  for (int i = 0; i < chord.numNotes; i++) {
    notes[i] = getNote(root, index + chord.offsets[i]);
  }
  return notes;
}