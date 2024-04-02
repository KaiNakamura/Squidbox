#include "KnobScene.h"
#include "Squidbox.h"

KnobScene::KnobScene(Squidbox *squidbox)
{
  type = KNOB_SCENE;
  this->squidbox = squidbox;
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

void KnobScene::init()
{
  Serial.println("KnobScene init");
  Knob *knob = squidbox->getKnob();
  knob->attachLeftEventCallback(leftCallback);
  knob->attachRightEventCallback(rightCallback);
  knob->setEventUserData(this);
}

void KnobScene::update()
{
}