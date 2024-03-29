#include "Button.h"

Button::Button(int pin)
{
  wasPressed = false;
  this->pin = pin;
  pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed()
{
  return !digitalRead(pin);
}

bool Button::getWasPressed() {
  return this->wasPressed;
}

void Button::setWasPressed(bool wasPressed) {
   this->wasPressed = wasPressed;
}