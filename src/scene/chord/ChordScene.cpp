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
  Knob *knob = squidbox->getKnob();
  knob->attachLeftEventCallback(onKnobLeft);
  knob->attachRightEventCallback(onKnobRight);
  knob->setEventUserData(this);
}

void ChordScene::onKnobLeft(int count, void *usr_data)
{
  ChordScene *self = static_cast<ChordScene *>(usr_data);
  if (count % 2 == 0)
  {
    self->root = getPreviousNote(self->root, self->MIN_NOTE, self->MAX_NOTE);
  }
}

void ChordScene::onKnobRight(int count, void *usr_data)
{
  ChordScene *self = static_cast<ChordScene *>(usr_data);
  if (count % 2 == 0)
  {
    self->root = getNextNote(self->root, self->MIN_NOTE, self->MAX_NOTE);
  }
}

void ChordScene::playChord(int index, bool on)
{
  int *notes = scale->getNotesFromChord(root, index, chordType);
  for (int i = 0; i < chordType.numNotes; i++)
  {
    if (on)
    {
      BLEMidiServer.noteOn(0, notes[i], 127);
    }
    else
    {
      BLEMidiServer.noteOff(0, notes[i], 127);
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