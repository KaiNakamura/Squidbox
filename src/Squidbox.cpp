#include "Squidbox.h"

Squidbox::Squidbox()
{
  BLEMidiServer.begin("Squidbox");
  BLEMidiServer.enableDebugging();
  joystick = new Joystick(14, 27, 26);

  Button button1 = Button(15);
  Button button2 = Button(16);
  Button button3 = Button(17);
  Button button4 = Button(18);
  Button button5 = Button(19);
  Button button6 = Button(20);
  Button button7 = Button(21);
  Button button8 = Button(22);

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