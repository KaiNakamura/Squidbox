#include "Squidbox.h"

Squidbox::Squidbox()
{
  Serial.println("Hello from Squidbox!");
  sceneManager = new SceneManager();
}

void Squidbox::update()
{
  sceneManager->update();
}