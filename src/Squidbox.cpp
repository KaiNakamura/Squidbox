#include "Squidbox.h"

Squidbox::Squidbox()
{
  BLEMidiServer.begin("Squidbox");
  BLEMidiServer.enableDebugging();
  joystick = new Joystick(14, 27, 26);

  button1 = new Button(15);
  button2 = new Button(13);
  button3 = new Button(4);
  button4 = new Button(16);
  button5 = new Button(17);
  button6 = new Button(5);
  button7 = new Button(18);
  button8 = new Button(19);

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

Button *Squidbox::getButton(int index)
{
  switch(index) {
        case 1:
            return this->button1;
        case 2:
            return this->button2;
        case 3:
            return this->button3;
        case 4:
            return this->button4;
        case 5:
            return this->button5;
        case 6:
            return this->button6;
        case 7:
            return this->button7;
        case 8:
            return this->button8;
        default:
            return this->button1;
  }
}