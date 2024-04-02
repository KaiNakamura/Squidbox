#include "Squidbox.h"

Squidbox::Squidbox()
{
  BLEMidiServer.begin("Squidbox");
  BLEMidiServer.enableDebugging();
  joystick = new Joystick(PIN_JOYSTICK_X, PIN_JOYSTICK_Y, PIN_JOYSTICK_BUTTON);
  knob = new Knob(PIN_KNOB_A, PIN_KNOB_B, PIN_KNOB_BUTTON);
  buttons[0] = new Button(PIN_BUTTON_0);
  buttons[1] = new Button(PIN_BUTTON_1);
  buttons[2] = new Button(PIN_BUTTON_2);
  buttons[3] = new Button(PIN_BUTTON_3);
  buttons[4] = new Button(PIN_BUTTON_4);
  buttons[5] = new Button(PIN_BUTTON_5);
  buttons[6] = new Button(PIN_BUTTON_6);
  buttons[7] = new Button(PIN_BUTTON_7);
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

Button **Squidbox::getButtons()
{
  return buttons;
}

Button *Squidbox::getButton(int index)
{
  return buttons[index];
}