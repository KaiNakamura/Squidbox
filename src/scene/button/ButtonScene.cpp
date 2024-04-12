#include "ButtonScene.h"
#include "Squidbox.h"

ButtonScene::ButtonScene(Squidbox *squidbox) : Scene(squidbox, nullptr)
{
  type = BUTTON_SCENE;
  menu = new Menu("Squidbox", MAIN_SCENE);
}

void ButtonScene::init()
{
  Scene::init();
}

void ButtonScene::update()
{
  Scene::update();
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    Button *button = squidbox->getButton(i);
    if (button->isPressed())
    {
      Serial.printf("Button %d was pressed\n", i);
    }
    if (button->isReleased())
    {
      Serial.printf("Button %d was released\n", i);
    }
  }
}