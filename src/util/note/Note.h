#pragma once

/**
 * @brief Enum representing MIDI note numbers.
 *
 * This enum represents the MIDI note numbers for the notes in several octaves,
 * from A0 to G9. The numbers correspond to the MIDI standard, where A0 is 21
 * and G9 is 127.
 */
enum Note {
  NOTE_A0 = 21,
  NOTE_ASHARP0 = 22,
  NOTE_B0 = 23,
  NOTE_C1 = 24,
  NOTE_CSHARP1 = 25,
  NOTE_D1 = 26,
  NOTE_DSHARP1 = 27,
  NOTE_E1 = 28,
  NOTE_F1 = 29,
  NOTE_FSHARP1 = 30,
  NOTE_G1 = 31,
  NOTE_GSHARP1 = 32,
  NOTE_A1 = 33,
  NOTE_ASHARP1 = 34,
  NOTE_B1 = 35,
  NOTE_C2 = 36,
  NOTE_CSHARP2 = 37,
  NOTE_D2 = 38,
  NOTE_DSHARP2 = 39,
  NOTE_E2 = 40,
  NOTE_F2 = 41,
  NOTE_FSHARP2 = 42,
  NOTE_G2 = 43,
  NOTE_GSHARP2 = 44,
  NOTE_A2 = 45,
  NOTE_ASHARP2 = 46,
  NOTE_B2 = 47,
  NOTE_C3 = 48,
  NOTE_CSHARP3 = 49,
  NOTE_D3 = 50,
  NOTE_DSHARP3 = 51,
  NOTE_E3 = 52,
  NOTE_F3 = 53,
  NOTE_FSHARP3 = 54,
  NOTE_G3 = 55,
  NOTE_GSHARP3 = 56,
  NOTE_A3 = 57,
  NOTE_ASHARP3 = 58,
  NOTE_B3 = 59,
  NOTE_C4 = 60,
  NOTE_CSHARP4 = 61,
  NOTE_D4 = 62,
  NOTE_DSHARP4 = 63,
  NOTE_E4 = 64,
  NOTE_F4 = 65,
  NOTE_FSHARP4 = 66,
  NOTE_G4 = 67,
  NOTE_GSHARP4 = 68,
  NOTE_A4 = 69,
  NOTE_ASHARP4 = 70,
  NOTE_B4 = 71,
  NOTE_C5 = 72,
  NOTE_CSHARP5 = 73,
  NOTE_D5 = 74,
  NOTE_DSHARP5 = 75,
  NOTE_E5 = 76,
  NOTE_F5 = 77,
  NOTE_FSHARP5 = 78,
  NOTE_G5 = 79,
  NOTE_GSHARP5 = 80,
  NOTE_A5 = 81,
  NOTE_ASHARP5 = 82,
  NOTE_B5 = 83,
  NOTE_C6 = 84,
  NOTE_CSHARP6 = 85,
  NOTE_D6 = 86,
  NOTE_DSHARP6 = 87,
  NOTE_E6 = 88,
  NOTE_F6 = 89,
  NOTE_FSHARP6 = 90,
  NOTE_G6 = 91,
  NOTE_GSHARP6 = 92,
  NOTE_A6 = 93,
  NOTE_ASHARP6 = 94,
  NOTE_B6 = 95,
  NOTE_C7 = 96,
  NOTE_CSHARP7 = 97,
  NOTE_D7 = 98,
  NOTE_DSHARP7 = 99,
  NOTE_E7 = 100,
  NOTE_F7 = 101,
  NOTE_FSHARP7 = 102,
  NOTE_G7 = 103,
  NOTE_GSHARP7 = 104,
  NOTE_A7 = 105,
  NOTE_ASHARP7 = 106,
  NOTE_B7 = 107,
  NOTE_C8 = 108,
  NOTE_CSHARP8 = 109,
  NOTE_D8 = 110,
  NOTE_DSHARP8 = 111,
  NOTE_E8 = 112,
  NOTE_F8 = 113,
  NOTE_FSHARP8 = 114,
  NOTE_G8 = 115,
  NOTE_GSHARP8 = 116,
  NOTE_A8 = 117,
  NOTE_ASHARP8 = 118,
  NOTE_B8 = 119,
  NOTE_C9 = 120,
  NOTE_CSHARP9 = 121,
  NOTE_D9 = 122,
  NOTE_DSHARP9 = 123,
  NOTE_E9 = 124,
  NOTE_F9 = 125,
  NOTE_FSHARP9 = 126,
  NOTE_G9 = 127
};

/**
 * @brief Get the next note in the sequence.
 *
 * @param note The current note.
 * @param minNote The minimum note in the sequence.
 * @param maxNote The maximum note in the sequence.
 * @param wrap Whether to wrap around to the beginning of the sequence when the
 * end is reached.
 * @return The next note in the sequence.
 */
Note getNextNote(Note note, Note minNote, Note maxNote, bool wrap);

/**
 * @brief Get the previous note in the sequence.
 *
 * @param note The current note.
 * @param minNote The minimum note in the sequence.
 * @param maxNote The maximum note in the sequence.
 * @param wrap Whether to wrap around to the end of the sequence when the
 * beginning is reached.
 * @return The previous note in the sequence.
 */
Note getPreviousNote(Note note, Note minNote, Note maxNote, bool wrap);

/**
 * @brief Get the next note in the sequence, without wrapping.
 *
 * @param note The current note.
 * @param minNote The minimum note in the sequence.
 * @param maxNote The maximum note in the sequence.
 * @return The next note in the sequence, or the maximum note if the current
 * note is the maximum.
 */
Note getNextNote(Note note, Note minNote, Note maxNote);

/**
 * @brief Get the previous note in the sequence, without wrapping.
 *
 * @param note The current note.
 * @param minNote The minimum note in the sequence.
 * @param maxNote The maximum note in the sequence.
 * @return The previous note in the sequence, or the minimum note if the current
 * note is the minimum.
 */
Note getPreviousNote(Note note, Note minNote, Note maxNote);

/**
 * @brief Get the next note in the sequence, with a specified wrap setting.
 *
 * @param note The current note.
 * @param wrap Whether to wrap around to the beginning of the sequence when the
 * end is reached.
 * @return The next note in the sequence.
 */
Note getNextNote(Note note, bool wrap);

/**
 * @brief Get the previous note in the sequence, with a specified wrap setting.
 *
 * @param note The current note.
 * @param wrap Whether to wrap around to the end of the sequence when the
 * beginning is reached.
 * @return The previous note in the sequence.
 */
Note getPreviousNote(Note note, bool wrap);

/**
 * @brief Get the next note in the sequence, without wrapping.
 *
 * @param note The current note.
 * @return The next note in the sequence, or the maximum note if the current
 * note is the maximum.
 */
Note getNextNote(Note note);

/**
 * @brief Get the previous note in the sequence, without wrapping.
 *
 * @param note The current note.
 * @return The previous note in the sequence, or the minimum note if the current
 * note is the minimum.
 */
Note getPreviousNote(Note note);

/**
 * @brief Convert a note to a string.
 *
 * @param note The note to convert.
 * @return A string representation of the note.
 */
const char *noteToString(Note note);

/**
 * @brief Array representing the starting note of each octave.
 *
 * This array contains the starting note (C) of each octave, from C1 to C8.
 */
extern Note OCTAVES[];

/**
 * @brief Constant representing the number of octaves.
 *
 * This constant is set to 8, representing the number of octaves from C1 to C8.
 */
const int NUM_OCTAVES = 8;