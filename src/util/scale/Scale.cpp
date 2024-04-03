#include "Scale.h"

Scale *MAJOR_SCALE = new Scale("Major", 7, new int[7]{0, 2, 4, 5, 7, 9, 11});
Scale *MINOR_SCALE = new Scale("Minor", 7, new int[7]{0, 2, 3, 5, 7, 8, 10});
Scale *MAJOR_PENTATONIC_SCALE = new Scale("Major Pentatonic", 5, new int[5]{0, 2, 4, 7, 9});
Scale *MINOR_PENTATONIC_SCALE = new Scale("Mino Pentatonic", 5, new int[5]{0, 3, 5, 7, 10});

Scale::Scale(char *name, int numNotes, int *semitones)
{
  this->name = name;
  this->numNotes = numNotes;
  this->semitones = semitones;
}

const char *Scale::getName()
{
  return name;
}

int Scale::getNote(int root, int index)
{
  if (index < 0)
  {
    Serial.printf("Error: Scale semitone not found with index %d\n", index);
  }
  int octaves = index / numNotes;
  return root + semitones[index % numNotes] + 12 * octaves;
}

int *Scale::getNotesFromChord(int root, int index, ChordType chord)
{
  int *notes = new int[chord.numNotes];
  for (int i = 0; i < chord.numNotes; i++)
  {
    notes[i] = getNote(root, index + chord.offsets[i]);
  }
  return notes;
}