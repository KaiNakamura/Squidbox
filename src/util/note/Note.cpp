#include "Note.h"

Note OCTAVES[] = {NOTE_C1, NOTE_C2, NOTE_C3, NOTE_C4,
                  NOTE_C5, NOTE_C6, NOTE_C7, NOTE_C8};

Note getNextNote(Note note, Note minNote, Note maxNote, bool wrap) {
  // Check if the current note is the maximum note
  if (note == maxNote) {
    // If it is, and wrap is enabled, return the minimum note
    // Otherwise, return the maximum note (i.e., stay on the same note)
    return wrap ? minNote : maxNote;
  } else {
    // If the current note is not the maximum note, increment the note
    // The modulo operation ensures that we stay within the valid range of notes
    return static_cast<Note>((note % maxNote) + 1);
  }
}

Note getPreviousNote(Note note, Note minNote, Note maxNote, bool wrap) {
  // Check if the current note is the minimum note
  if (note == minNote) {
    // If it is, and wrap is enabled, return the maximum note
    // Otherwise, return the minimum note (i.e., stay on the same note)
    return wrap ? maxNote : minNote;
  } else {
    // If the current note is not the minimum note, decrement the note
    return static_cast<Note>(note - 1);
  }
}

Note getNextNote(Note note, Note minNote, Note maxNote) {
  // Call the previous function with wrap set to false
  return getNextNote(note, minNote, maxNote, false);
}

Note getPreviousNote(Note note, Note minNote, Note maxNote) {
  // Call the previous function with wrap set to false
  return getPreviousNote(note, minNote, maxNote, false);
}

Note getNextNote(Note note, bool wrap) {
  // Call the previous function with minNote set to NOTE_A0 and maxNote set to
  // NOTE_G9
  return getNextNote(note, NOTE_A0, NOTE_G9, wrap);
}

Note getPreviousNote(Note note, bool wrap) {
  // Call the previous function with minNote set to NOTE_A0 and maxNote set to
  // NOTE_G9
  return getPreviousNote(note, NOTE_A0, NOTE_G9, wrap);
}

Note getNextNote(Note note) {
  // Call the previous function with wrap set to false
  return getNextNote(note, false);
}

Note getPreviousNote(Note note) {
  // Call the previous function with wrap set to false
  return getPreviousNote(note, false);
}

const char *noteToString(Note note) {
  // Define the names of the notes
  static const char *noteNames[] = {
      "A0",     "A#/Bb0", "B0",     "C1",     "C#/Db1", "D1",     "D#/Eb1",
      "E1",     "F1",     "F#/Gb1", "G1",     "G#/Ab1", "A1",     "A#/Bb1",
      "B1",     "C2",     "C#/Db2", "D2",     "D#/Eb2", "E2",     "F2",
      "F#/Gb2", "G2",     "G#/Ab2", "A2",     "A#/Bb2", "B2",     "C3",
      "C#/Db3", "D3",     "D#/Eb3", "E3",     "F3",     "F#/Gb3", "G3",
      "G#/Ab3", "A3",     "A#/Bb3", "B3",     "C4",     "C#/Db4", "D4",
      "D#/Eb4", "E4",     "F4",     "F#/Gb4", "G4",     "G#/Ab4", "A4",
      "A#/Bb4", "B4",     "C5",     "C#/Db5", "D5",     "D#/Eb5", "E5",
      "F5",     "F#/Gb5", "G5",     "G#/Ab5", "A5",     "A#/Bb5", "B5",
      "C6",     "C#/Db6", "D6",     "D#/Eb6", "E6",     "F6",     "F#/Gb6",
      "G6",     "G#/Ab6", "A6",     "A#/Bb6", "B6",     "C7",     "C#/Db7",
      "D7",     "D#/Eb7", "E7",     "F7",     "F#/Gb7", "G7",     "G#/Ab7",
      "A7",     "A#/Bb7", "B7",     "C8",     "C#/Db8", "D8",     "D#/Eb8",
      "E8",     "F8",     "F#/Gb8", "G8",     "G#/Ab8", "A8",     "A#/Bb8",
      "B8",     "C9",     "C#/Db9", "D9",     "D#/Eb9"};

  // Check if the note is within the valid range
  if (note >= NOTE_A0 && note <= NOTE_G9) {
    // If it is, return the name of the note
    return noteNames[note - NOTE_A0];
  } else {
    // If it's not, return "Unknown"
    return "Unknown";
  }
}
