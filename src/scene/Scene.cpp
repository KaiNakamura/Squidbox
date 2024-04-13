#include "Scene.h"
#include "gui/menu/Menu.h"
#include <Arduino.h>

Scene::Scene(Squidbox *squidbox, Menu *menu) : squidbox(squidbox), menu(menu) {}

Squidbox *Scene::getSquidbox()
{
  return squidbox;
}

void Scene::init()
{
}

void Scene::update()
{
  menu->update(squidbox);
}