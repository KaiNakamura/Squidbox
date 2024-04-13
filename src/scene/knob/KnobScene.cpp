#include "KnobScene.h"
#include "Squidbox.h"

KnobScene::KnobScene(Squidbox *squidbox) : Scene(squidbox, nullptr)
{
  type = KNOB_SCENE;
  menu = new Menu("Squidbox", MAIN_SCENE);
}

void KnobScene::init()
{
  Scene::init();
  Knob *knob = squidbox->getKnob();
  knob->attachLeftEventCallback(leftCallback);
  knob->attachRightEventCallback(rightCallback);
  knob->setEventUserData(this);
}

void KnobScene::update()
{
  Scene::update();
}

void KnobScene::leftCallback(int count, void *usr_data)
{
  KnobScene *self = static_cast<KnobScene *>(usr_data);
  int count2 = self->squidbox->getKnob()->getCount();
  Serial.printf("Detect left event, count is %d, squidbox count is %d\n", count, count2);
}

void KnobScene::rightCallback(int count, void *usr_data)
{
  KnobScene *self = static_cast<KnobScene *>(usr_data);
  int count2 = self->squidbox->getKnob()->getCount();
  Serial.printf("Detect right event, count is %d, squidbox count is %d\n", count, count2);
}