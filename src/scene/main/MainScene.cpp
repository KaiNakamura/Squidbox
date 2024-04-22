#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  type = MAIN_SCENE;

  MenuItem *chordMenuItem =
      new SwitchSceneMenuItem("Chords", squidbox, CHORD_SCENE);
  MenuItem *noteMenuItem =
      new SwitchSceneMenuItem("Notes", squidbox, NOTE_SCENE);
  MenuItem *drumMenuItem =
      new SwitchSceneMenuItem("Drums", squidbox, DRUM_SCENE);

  MenuItem **menuItems = new MenuItem *[3];
  menuItems[0] = chordMenuItem;
  menuItems[1] = noteMenuItem;
  menuItems[2] = drumMenuItem;

  menu = new Menu("Squidbox", 3, menuItems);
}

void MainScene::init() { Scene::init(); }

void MainScene::update() { Scene::update(); }