#include "DrumScene.h"
#include "Squidbox.h"

DrumScene::DrumScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  menu = new Menu("Drums", MAIN_SCENE);

  octaveMenuItem = new OctaveMenuItem();

  MenuItem **menuItems = new MenuItem *[1];
  menuItems[0] = octaveMenuItem;

  menu = new Menu("Drums", 1, menuItems, MAIN_SCENE);
}

void DrumScene::init() { Scene::init(); }

void DrumScene::update() {
  Scene::update();

  // Check if any of the buttons are pressed
  for (int i = 0; i < NUM_BUTTONS; i++) {
    Button *button = squidbox->getButton(i);
    if (squidbox->getButton(i)->isPressed()) {
      playDrum(i, true);
    } else if (squidbox->getButton(i)->isReleased()) {
      playDrum(i, false);
    }
  }
}

void DrumScene::playDrum(int index, bool on) {
  Note octave = octaveMenuItem->getNote();
  int note = octave + index;

  // Play notes
  if (on) {
    BLEMidiServer.noteOn(0, note, 127);
  } else {
    BLEMidiServer.noteOff(0, note, 127);
  }
}