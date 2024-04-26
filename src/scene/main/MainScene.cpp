#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox) : Scene(squidbox, nullptr) {
  // Create new menu items for each scene
  MenuItem *chordMenuItem =
      new SwitchSceneMenuItem("Chords", squidbox, CHORD_SCENE);
  MenuItem *noteMenuItem =
      new SwitchSceneMenuItem("Notes", squidbox, NOTE_SCENE);
  MenuItem *drumMenuItem =
      new SwitchSceneMenuItem("Drums", squidbox, DRUM_SCENE);
  MenuItem *quitMenuItem = new QuitMenuItem(squidbox);

  // Create an array of menu items
  MenuItem **menuItems = new MenuItem *[4];
  menuItems[0] = chordMenuItem;
  menuItems[1] = noteMenuItem;
  menuItems[2] = drumMenuItem;
  menuItems[3] = quitMenuItem;

  // Create a new menu with the menu items
  menu = new Menu("Squidbox", 4, menuItems);
}