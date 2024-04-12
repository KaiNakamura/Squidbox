#include "ChordScene.h"
#include "Squidbox.h"

ChordScene::ChordScene(Squidbox *squidbox) : Scene(squidbox, nullptr)
{
  type = CHORD_SCENE;
  root = NOTE_C4;
  scale = MAJOR_SCALE;
  chordType = TRIAD;

  connectedMenuItem = new MenuItem(this);
  rootMenuItem = new MenuItem(this);
  scaleMenuItem = new MenuItem(this);

  MenuItem **menuItems = new MenuItem *[3];
  menuItems[0] = connectedMenuItem;
  menuItems[1] = rootMenuItem;
  menuItems[2] = scaleMenuItem;

  menu = new Menu("Chords", 3, menuItems, MAIN_SCENE);
}

void ChordScene::init()
{
  Scene::init();
  Serial.println("ChordScene::init");
  Knob *knob = squidbox->getKnob();
  knob->attachLeftEventCallback(onKnobLeft);
  knob->attachRightEventCallback(onKnobRight);
  knob->setEventUserData(this);
}

void ChordScene::update()
{
  Scene::update();

  // Update menu items
  rootMenuItem->setName(noteToString(root));
  scaleMenuItem->setName(scale->getName());

  // TODO: Does not update to "Not Connected" when disconnected for some reason
  connectedMenuItem->setName(BLEMidiServer.isConnected() ? "Connected" : "Not Connected");

  // Check if the OK button is pressed
  if (squidbox->getOkButton()->isPressed())
  {
    toggleScale();
  }

  // Check if any of the buttons are pressed
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
