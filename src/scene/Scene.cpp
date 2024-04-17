#include "Scene.h"
#include "Squidbox.h"

Scene::Scene(Squidbox *squidbox, Menu *menu) : squidbox(squidbox), menu(menu) {}

Squidbox *Scene::getSquidbox()
{
  return squidbox;
}

void Scene::init()
{
  Knob *knob = squidbox->getKnob();
  knob->detachLeftEventCallback();
  knob->detachRightEventCallback();
  knob->setEventUserData(menu);
  knob->attachLeftEventCallback(menu->onKnobLeft);
  knob->attachRightEventCallback(menu->onKnobRight);
  
}

void Scene::update()
{
  menu->update(squidbox);
}