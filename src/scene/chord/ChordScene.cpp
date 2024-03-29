#include "ChordScene.h"
#include "Squidbox.h"


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
    playChord(1, 93, 97, 100); //A6, C#7, E7
    playChord(2, 95, 98, 102); //B6, D7, F#7
    playChord(3, 97, 101, 104); //C#7, E7, G#7
    playChord(4, 98, 102, 105); //D7, F#7, A7
    playChord(5, 100, 104, 107); //E7, G#7, B7
    playChord(6, 101, 105, 108); //F#7, A7, C8
    playChord(7, 104, 107, 110); //G#7, B7, D8
    playChord(8, 105, 109, 112); //A7, C#8, E8
    
  }
}