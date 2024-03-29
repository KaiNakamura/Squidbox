#include "Knob.h"

Knob::Knob(int aPin, int bPin, int buttonPin)
{
  this->buttonPin = buttonPin;
  pinMode(buttonPin, INPUT_PULLUP);
  knob = new ESP_Knob(aPin, bPin);
  knob->begin();
}

bool Knob::isPressed()
{
  return !digitalRead(buttonPin);
}

int Knob::getCount()
{
  return knob->getCountValue();
}

void Knob::clearCount()
{
  knob->clearCountValue();
}