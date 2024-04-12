#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox) : Scene(squidbox, nullptr)
{
  type = MAIN_SCENE;

  MenuItem *chordMenuItem = new MenuItem("Chords", this);
  chordMenuItem->setCallback(switchToChordScene);

  MenuItem *joystickCalibratorMenuItem = new MenuItem("Joystick Calibrator", this);
  joystickCalibratorMenuItem->setCallback(switchToJoystickCalibratorScene);

  MenuItem **menuItems = new MenuItem *[2];
  menuItems[0] = chordMenuItem;
  menuItems[1] = joystickCalibratorMenuItem;

  menu = new Menu("Squidbox", 2, menuItems, NULL_SCENE);
}

void MainScene::switchToChordScene(Scene *scene)
{
  Serial.println("switchToChordScene");
  scene->getSquidbox()->switchTo(CHORD_SCENE);
}

void MainScene::switchToJoystickCalibratorScene(Scene *scene)
{
  Serial.println("switchToJoystickCalibratorScene");
  scene->getSquidbox()->switchTo(JOYSTICK_CALIBRATOR_SCENE);
}

void MainScene::init()
{
  Scene::init();
}

void MainScene::update()
{
  Scene::update();
}