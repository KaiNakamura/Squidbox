#include "ButtonScene.h"
#include "Squidbox.h"

ButtonScene::ButtonScene(Squidbox *squidbox)
{
  type = BUTTON_SCENE;
  this->squidbox = squidbox;
}

void ButtonScene::init()
{
  Serial.println("ButtonScene init");
}

void ButtonScene::update()
{
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