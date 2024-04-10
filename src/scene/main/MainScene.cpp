#include "MainScene.h"
#include "Squidbox.h"

void MainScene::switchToChordScene(Scene *scene)
{
  scene->getSquidbox()->switchTo(CHORD_SCENE);
}

MainScene::MainScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = MAIN_SCENE;

  MenuItem chordMenuItem = MenuItem("Chords", this);
  chordMenuItem.setCallback(switchToChordScene);

  this->menu = new Menu("Squidbox", 1, new MenuItem[1]{chordMenuItem});
}

void MainScene::init()
{
  Serial.println("MainScene init");
}

void MainScene::update()
{
  menu->update(squidbox);
}