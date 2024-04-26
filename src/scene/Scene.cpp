#include "Scene.h"
#include "Squidbox.h"

Scene::Scene(Squidbox *squidbox, Menu *menu) : squidbox(squidbox), menu(menu) {}

Squidbox *Scene::getSquidbox() { return squidbox; }

void Scene::init() {
  // Clear the screen of the squidbox
  squidbox->getScreen()->clear();

  // Get the knob from the squidbox
  Knob *knob = squidbox->getKnob();

  // Detach any existing event callbacks from the knob
  knob->detachLeftEventCallback();
  knob->detachRightEventCallback();

  // Set the user data for the knob events to the menu
  knob->setEventUserData(menu);

  // Attach the left and right event callbacks to the knob
  knob->attachLeftEventCallback(menu->onKnobLeft);
  knob->attachRightEventCallback(menu->onKnobRight);
}

void Scene::update() {
  // Draw the menu on the squidbox
  menu->drawMenu(squidbox);
}