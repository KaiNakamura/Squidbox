#include "KnobScene.h"
#include "Squidbox.h"

KnobScene::KnobScene(Squidbox *squidbox)
{
  type = KNOB_SCENE;
  this->squidbox = squidbox;
}

void KnobScene::init()
{
  Serial.println("KnobScene init");
}

void KnobScene::update()
{
  Knob *knob = squidbox->getKnob();

  if (knob->isPressed())
  {
    Serial.println("Knob pressed");
  }

  Serial.printf("%d\n", knob->getCount());
}