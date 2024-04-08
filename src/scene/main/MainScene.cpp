#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  this->menu = new Menu("Squidbox", 3, new MenuItem[3]{
                                           MenuItem("Chords"),
                                           MenuItem("Joystick"),
                                           MenuItem("Knob"),
                                       });
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