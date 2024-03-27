#include "ChordScene.h"
#include "Squidbox.h"

ChordScene::ChordScene(Squidbox *squidbox)
{
  this->squidbox = squidbox;
  type = CHORD_SCENE;
}

void ChordScene::init()
{
  Serial.println("ChordScene init");
}

void ChordScene::update()
{
}