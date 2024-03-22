#include "SceneManager.h"

SceneManager::SceneManager()
{
  Serial.println("Hello from SceneManager!");
  scenes[currentScene]->init();
}

void SceneManager::update()
{
  scenes[currentScene]->update();
}

void SceneManager::switchTo(SceneType scene)
{
  if (scene != currentScene)
  {
    currentScene = scene;
    scenes[currentScene]->init();
  }
}