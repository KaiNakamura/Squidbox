#include "ChordScene.h"
#include "Squidbox.h"
#include "util/MIDI.h"

ChordScene::ChordScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = CHORD_SCENE;
}

void ChordScene::init()
{
  Serial.println("ChordScene init");
}

void ChordScene::playChord(int buttonPin, int note1, int note2, int note3)
{
  if (squidbox->getButton(buttonPin)->isPressed() && !squidbox->getButton(buttonPin)->getWasPressed())
  {
    Serial.println("Button pressed");
    BLEMidiServer.noteOn(0, note1, 127);
    BLEMidiServer.noteOn(0, note2, 127);
    BLEMidiServer.noteOn(0, note3, 127);
    Serial.println("On " + String(buttonPin) + " " + String(note1) + " " + String(note2) + " " + String(note3));
    squidbox->getButton(buttonPin)->setWasPressed(true);
  }
  else if (!squidbox->getButton(buttonPin)->isPressed() && squidbox->getButton(buttonPin)->getWasPressed())
  {
    BLEMidiServer.noteOff(0, note1, 127);
    BLEMidiServer.noteOff(0, note2, 127);
    BLEMidiServer.noteOff(0, note3, 127);
    Serial.println("Off " + String(buttonPin) + " " + String(note1) + " " + String(note2) + " " + String(note3));
    squidbox->getButton(buttonPin)->setWasPressed(false);
  }
}

void ChordScene::update()
{
  if (BLEMidiServer.isConnected())
  {
    // If we've got a connection, full velocity (127)
    // A Major Diatonic Chords
    playChord(1, NOTE_A6, NOTE_CSHARP7, NOTE_E7);      // A6, C#7, E7
    playChord(2, NOTE_B6, NOTE_D7, NOTE_FSHARP7);      // B6, D7, F#7
    playChord(3, NOTE_CSHARP7, NOTE_E7, NOTE_GSHARP7); // C#7, E7, G#7
    playChord(4, NOTE_D7, NOTE_FSHARP7, NOTE_A7);      // D7, F#7, A7
    playChord(5, NOTE_E7, NOTE_GSHARP7, NOTE_B7);      // E7, G#7, B7
    playChord(6, NOTE_FSHARP7, NOTE_A7, NOTE_C8);      // F#7, A7, C8
    playChord(7, NOTE_GSHARP7, NOTE_B7, NOTE_D8);      // G#7, B7, D8
    playChord(8, NOTE_A7, NOTE_CSHARP8, NOTE_E8);      // A7, C#8, E8
  }
}