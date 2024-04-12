#include "Button.h"

Button::Button(int pin) : pin(pin)
{
  pinMode(pin, INPUT_PULLUP);
  wasDown = false;
  wasUp = true;
}

bool Button::isDown()
{
  return !digitalRead(pin);
}

bool Button::isPressed()
{
  bool down = isDown();
  bool pressed = down && !wasDown;
  wasDown = down;
  return pressed;
}

bool Button::isReleased()
{
  bool up = !isDown();
  bool released = up && !wasUp;
  wasUp = up;
  return released;
}