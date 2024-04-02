#include "Note.h"

Note getNextNote(Note note, Note minNote, Note maxNote)
{
  // Increment the note value, wrapping around from maxNote to minNote
  return (note == maxNote) ? minNote : static_cast<Note>((note % maxNote) + 1);
}

Note getPreviousNote(Note note, Note minNote, Note maxNote)
{
  // Decrement the note value, wrapping around from minNote to maxNote
  return (note == minNote) ? maxNote : static_cast<Note>(note - 1);
}

Note getNextNote(Note note)
{
  // Increment the note value, wrapping around from G9 to A0
  return getNextNote(note, NOTE_A0, NOTE_G9);
}

Note getPreviousNote(Note note)
{
  // Decrement the note value, wrapping around from A0 to G9
  return getPreviousNote(note, NOTE_A0, NOTE_G9);
}