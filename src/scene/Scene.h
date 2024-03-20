#include "SceneType.h"

class Scene
{
protected:
  SceneType type;

public:
  virtual void setup();
  virtual void loop();
};