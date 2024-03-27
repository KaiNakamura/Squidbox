#include "Squidbox.h"

Squidbox::Squidbox()
{
  Serial.println("Hello from Squidbox!");
  joystick = new Joystick(14, 27, 26);
}

void Squidbox::init()
{
  scenes[MAIN_SCENE] = new MainScene(this);
  scenes[CHORD_SCENE] = new ChordScene(this);
  scenes[JOYSTICK_CALIBRATOR_SCENE] = new JoystickCalibratorScene(this);
  scenes[currentScene]->init();
}

void Squidbox::update()
{
  scenes[currentScene]->update();
}

void Squidbox::switchTo(SceneType scene)
{
  if (scene != currentScene)
  {
    currentScene = scene;
    scenes[currentScene]->init();
  }
}

Joystick *Squidbox::getJoystick()
{
  return joystick;
}