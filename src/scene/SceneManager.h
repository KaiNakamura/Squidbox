#pragma once

#include "scene/Scene.h"
#include "scene/main-scene/MainScene.h"
#include "scene/chord-scene/ChordScene.h"

class SceneManager
{
private:
  Scene *scenes[NUM_SCENES] = {new MainScene(), new ChordScene()};
  int currentScene = MAIN_SCENE;

public:
  SceneManager();
  void update();
  void switchTo(SceneType scene);
};