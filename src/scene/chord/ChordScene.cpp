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

// TODO: Add switching between all scales and chord types
void ChordScene::toggleScale()
{
  if (scale == MAJOR_SCALE)
  {
    scale = MINOR_SCALE;
  }
  else
  {
    scale = MAJOR_SCALE;
  }
}

void ChordScene::update()
{
  // Set display
  Screen *screen = squidbox->getScreen();
  screen->clear();
  screen->getDisplay()->setTextSize(2);
  screen->getDisplay()->setTextColor(WHITE);
  screen->getDisplay()->setCursor(0, 0);

  // Check if bluetooth is connected
  if (!BLEMidiServer.isConnected())
  {
    screen->getDisplay()->println("Waiting...");
    screen->update();
    return;
  }

  if (squidbox->getOkButton()->isPressed())
  {
    toggleScale();
  }

  // Button code
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

  // Screen code
  screen->getDisplay()->printf("%s\n", toString(root));
  screen->getDisplay()->printf("%s\n", scale->getName());

  // Draw keyboard
  screen->printKeyboard(STARTING_KEY_Y, WHITE_KEY_WIDTH, WHITE_KEY_HEIGHT, BLACK_KEY_WIDTH, BLACK_KEY_HEIGHT, 24);

  screen->update();

}