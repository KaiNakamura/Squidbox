#include "Squidbox.h"

Squidbox::Squidbox()
{
  Serial.println("Hello from Squidbox!");
  sceneManager = new SceneManager();
  joystick = new Joystick(14, 27, 26);
}

void Squidbox::update()
{
  sceneManager->update();
  Serial.printf("(%d, %d), (%f, %f), %d\n", joystick->getRawX(), joystick->getRawY(), joystick->getX(), joystick->getY(), joystick->getDirection());
}