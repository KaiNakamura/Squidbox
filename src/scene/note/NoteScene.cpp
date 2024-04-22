#include "NoteScene.h"
#include "Squidbox.h"

NoteScene::NoteScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  type = CHORD_SCENE;

  rootMenuItem = new RootNoteMenuItem();
  scaleMenuItem = new ScaleMenuItem();

  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = rootMenuItem;
  menuItems[1] = scaleMenuItem;

  menu = new Menu("Chords", 2, menuItems, MAIN_SCENE);

  keyboard = new Keyboard(squidbox);
}

void NoteScene::init() { Scene::init(); }

void NoteScene::update() {
  Scene::update();

  // Check if any of the buttons are pressed
  for (int i = 0; i < NUM_BUTTONS; i++) {
    Button *button = squidbox->getButton(i);
    if (squidbox->getButton(i)->isPressed()) {
      playNote(i, true);
    } else if (squidbox->getButton(i)->isReleased()) {
      playNote(i, false);
    }
  }

  // Update keyboard
  keyboard->update(rootMenuItem->getRootNote());
}

void NoteScene::playNote(int index, bool on) {
  // TODO: Fix bug where switching root while chord playing causes notes to hang

  // Get scale, root note, and chord type from menu items
  Scale *scale = scaleMenuItem->getScale();
  Note root = rootMenuItem->getRootNote();

  // Get notes in chord
  int note = scale->getNote(root, index);

  // Play notes
  keyboard->setKeyDown(note, on);
  if (on) {
    BLEMidiServer.noteOn(0, note, 127);
  } else {
    BLEMidiServer.noteOff(0, note, 127);
  }
}