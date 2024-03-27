#include "Knob.h"

void onKnobLeftEventCallback(int count, void *usr_data)
{
  Serial.printf("Detect left event, count is %d\n", count);
}

void onKnobRightEventCallback(int count, void *usr_data)
{
  Serial.printf("Detect right event, count is %d\n", count);
}

void onKnobHighLimitEventCallback(int count, void *usr_data)
{
  Serial.printf("Detect high limit event, count is %d\n", count);
}

void onKnobLowLimitEventCallback(int count, void *usr_data)
{
  Serial.printf("Detect low limit event, count is %d\n", count);
}

void onKnobZeroEventCallback(int count, void *usr_data)
{
  Serial.printf("Detect zero event, count is %d\n", count);
}

Knob::Knob(int aPin, int bPin, int buttonPin)
{
  this->buttonPin = buttonPin;
  knob = new ESP_Knob(aPin, bPin);
  knob->begin();
  knob->attachLeftEventCallback(onKnobLeftEventCallback);
  knob->attachRightEventCallback(onKnobRightEventCallback);
  knob->attachHighLimitEventCallback(onKnobHighLimitEventCallback);
  knob->attachLowLimitEventCallback(onKnobLowLimitEventCallback);
  knob->attachZeroEventCallback(onKnobZeroEventCallback);
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