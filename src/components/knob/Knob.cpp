#include "Knob.h"

Knob::Knob(int aPin, int bPin, int buttonPin) : buttonPin(buttonPin)
{
  pinMode(buttonPin, INPUT_PULLUP);
  knob = new ESP_Knob(aPin, bPin);
  knob->begin();
}

// TODO: This function does not currently work, something with the wiring is messed up
bool Knob::isPressed()
{
  return digitalRead(buttonPin);
}

// TODO: For some reason the knob count increases by 2 for every click, should be changed to 1 per click
int Knob::getCount()
{
  return knob->getCountValue();
}

void Knob::clearCount()
{
  knob->clearCountValue();
}

void Knob::setEventUserData(void *usr_data)
{
  // Ignore that they mispelled Data as Date in the ESP_Knob library...
  knob->setEventUserDate(usr_data);
}

void Knob::attachLeftEventCallback(std::function<void(int, void *)> callback)
{
  knob->attachLeftEventCallback(callback);
}

void Knob::detachLeftEventCallback(void)
{
  knob->detachLeftEventCallback();
}

void Knob::attachRightEventCallback(std::function<void(int, void *)> callback)
{
  knob->attachRightEventCallback(callback);
}

void Knob::detachRightEventCallback(void)
{
  knob->detachRightEventCallback();
}
