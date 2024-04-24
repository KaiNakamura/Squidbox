#include "ChordScene.h"
#include "Squidbox.h"

ChordScene::ChordScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  type = CHORD_SCENE;

  rootMenuItem = new RootNoteMenuItem();
  scaleMenuItem = new ScaleMenuItem();
  chordTypeMenuItem = new ChordTypeMenuItem();

  MenuItem **menuItems = new MenuItem *[3];
  menuItems[0] = rootMenuItem;
  menuItems[1] = scaleMenuItem;
  menuItems[2] = chordTypeMenuItem;

  menu = new Menu("Chords", 3, menuItems, MAIN_SCENE);

  keyboard = new Keyboard(squidbox);
}

void ChordScene::init() { Scene::init(); }

void ChordScene::update() {
  Scene::update();

  // Check if any of the buttons are pressed
  for (int i = 0; i < NUM_BUTTONS; i++) {
    Button *button = squidbox->getButton(i);
    if (squidbox->getButton(i)->isPressed()) {
      playChord(i, true);
    } else if (squidbox->getButton(i)->isReleased()) {
      playChord(i, false);
    }
  }

  // Update keyboard
  keyboard->update(rootMenuItem->getRootNote());
}

void ChordScene::playChord(int index, bool on) {
  // TODO: Fix bug where switching root while chord playing causes notes to hang

  // Get scale, root note, and chord type from menu items
  Scale *scale = scaleMenuItem->getScale();
  Note root = rootMenuItem->getRootNote();
  ChordType *chordType = chordTypeMenuItem->getChordType();

  // Get notes in chord
  int *notes = scale->getNotesFromChord(root, index, chordType);

  // Play notes
  for (int i = 0; i < chordType->numNotes; i++) {
    keyboard->setKeyDown(notes[i], on);
    if (on) {
      BLEMidiServer.noteOn(0, notes[i], 127);
      Serial.println("note sent: ");
      Serial.println(notes[i]);
    } else {
      BLEMidiServer.noteOff(0, notes[i], 127);
    }
  }
}