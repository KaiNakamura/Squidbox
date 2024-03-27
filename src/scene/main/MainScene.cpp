#include "MainScene.h"
#include "Squidbox.h"

MainScene::MainScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = MAIN_SCENE;
}

void MainScene::init()
{
  Serial.println("MainScene init");
}

void MainScene::update()
{
}