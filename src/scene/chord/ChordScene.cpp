#include "ChordScene.h"
#include "Squidbox.h"

ChordScene::ChordScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = CHORD_SCENE;
  root = NOTE_C4;
  scale = MAJOR_SCALE;
  chordType = TRIAD;
}

void ChordScene::init()
{
  Serial.println("ChordScene init");
}

void ChordScene::playChord(int index, bool on)
{
  int *notes = scale->getNotesFromChord(root, index, chordType);
  for (int i = 0; i < chordType.numNotes; i++)
  {
    if (on)
    {
      BLEMidiServer.noteOn(0, notes[i], 127);
      Serial.printf("Note %d on %d\n", i, notes[i]);
    }
    else
    {
      BLEMidiServer.noteOff(0, notes[i], 127);
      Serial.printf("Note %d off %d\n", i, notes[i]);
    }
  }
}

void ChordScene::update()
{
  if (BLEMidiServer.isConnected())
  {
    for (int i = 0; i < NUM_BUTTONS; i++)
    {
      Button *button = squidbox->getButton(i);
      if (squidbox->getButton(i)->isPressed())
      {
        playChord(i, true);
      }
      else if (squidbox->getButton(i)->isReleased())
      {
        playChord(i, false);
      }
    }
  }
}