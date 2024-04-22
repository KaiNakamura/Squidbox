#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  type = MAIN_SCENE;

  MenuItem *chordMenuItem =
      new SwitchSceneMenuItem("Chords", squidbox, CHORD_SCENE);
  MenuItem *noteMenuItem =
      new SwitchSceneMenuItem("Notes", squidbox, NOTE_SCENE);
  MenuItem *joystickCalibratorMenuItem = new SwitchSceneMenuItem(
      "Joystick Calibrator", squidbox, JOYSTICK_CALIBRATOR_SCENE);

  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = chordMenuItem;
  menuItems[1] = noteMenuItem;

  menu = new Menu("Squidbox", 2, menuItems);
}

void MainScene::init() { Scene::init(); }

void MainScene::update() { Scene::update(); }