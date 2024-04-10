#include "MainScene.h"
#include "Squidbox.h"

void switchToChordScene(Scene *scene)
{
}

MainScene::MainScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;

  MenuItem chordMenuItem = MenuItem("Chords");
  chordMenuItem.setCallback(switchToChordScene);

  this->menu = new Menu("Squidbox", 3, new MenuItem[1]{chordMenuItem});
  type = MAIN_SCENE;
}

void MainScene::init()
{
  Serial.println("MainScene init");
}

void MainScene::update()
{
  menu->update(squidbox);
}
