#include "Squidbox.h"

Squidbox::Squidbox()
{
  BLEMidiServer.begin("Squidbox");
  BLEMidiServer.enableDebugging();

  // TODO: Move pins to config/pins.h
  joystick = new Joystick(14, 27, 26);
  knob = new Knob(34, 35, 0);
}

void Squidbox::init()
{
  scenes[MAIN_SCENE] = new MainScene(this);
  scenes[CHORD_SCENE] = new ChordScene(this);
  scenes[JOYSTICK_CALIBRATOR_SCENE] = new JoystickCalibratorScene(this);
  scenes[KNOB_SCENE] = new KnobScene(this);
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

Knob *Squidbox::getKnob()
{
  return knob;
}